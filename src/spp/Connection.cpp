/*******************************************************************************
 * Copyright (c) 2026, Yasuhiro Hasegawa
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

 
 //
 // Connection.cpp
 //

#include <algorithm>
#include <functional>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ThreadControl.h"

#include "../xns/SPP.h"

#include "../server/Server.h"

#include "Connection.h"
#include "Packet.h"

namespace spp {
//

using SST = xns::SPP::SST;


//
// Connection
//

//
// transmitXXX
//
void Connection::queue(bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data) {
    retransmitQueue.add(Packet{false, sendAck, attention, endOfMessage, sst, seq, data});
}
void Connection::transmitRaw(bool system, bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data) {
    xns::SPP txHeader;
    txHeader.system(system);
    txHeader.sendAck(sendAck);
    txHeader.attention(attention);
    txHeader.endOfMessage(endOfMessage);
    txHeader.sst   = sst;
    txHeader.srcID = srcID;
    txHeader.dstID = dstID;
    txHeader.seq   = seq;
    txHeader.ack   = txRange.ack;
    txHeader.alloc = txRange.alloc;

    ByteBuffer txbb = server::getByteBuffer();
    txbb.putVector(data);

    session.send(txHeader, txbb);
}

void Connection::transmitRaw(Packet& packet) {
    xns::SPP txHeader;
    txHeader.control = packet.control;
    txHeader.sst     = packet.sst;
    txHeader.srcID   = srcID;
    txHeader.dstID   = dstID;
    txHeader.seq     = packet.seq;
    txHeader.ack     = txRange.ack;
    txHeader.alloc   = txRange.alloc;

    ByteBuffer txbb(packet.data.data(), packet.data.size());
    session.send(txHeader, txbb);
}

void Connection::maintainRetransmit() {    
    PacketQueue::MapDeleteFunction function = [&](Packet& e) {
        // remove entry before rxRange
        auto ret = rxRange.isBefore(e.seq);
        if (ret) {
            logger.info("RETRANSMIT  REMOVE  %d", e.seq);
        }
        return ret;
    };
    retransmitQueue.mapDelete(function);    
}
void Connection::retransmit(bool sendAck) {    
    PacketQueue::MapFunction function = [&](Packet& e) {
        // transmit only within txRange
        if (txRange.contains(e.seq)) {
            transmitRaw(e);
            logger.info("RETRANSMIT  TRANSMIT %d", e.seq);
            sendAck = false;
        }
    };
    retransmitQueue.map(function);
    if (sendAck) transmitSystemAck();
}


//
// receiveXXX
//
void Connection::receive(const xns::SPP& header, const ByteBuffer& body) {
    // seq   -- seq of next data packet
    // ack   -- all packets with sequence numbers preceding ack have been acknowledged in other side
    // alloc -- other side can accept sequence number [ack..alloc]

    // record received ack and alloc in rxRange
    {
        bool rangeChanged = rxRange.ack != header.ack || rxRange.alloc != header.alloc;
        rxRange = {header.ack, header.alloc};
        if (rangeChanged) maintainRetransmit();    
    }

    auto sst = header.sst;

    // sepcial for system packet
    if (header.system()) {
        // sanity check
        if (sst != SST::DATA) ERROR()

        retransmit(header.sendAck());
        return;
    }

    logger.info("SST %s", xns::SPP::toString(header.sst));

    bool sendAck = header.sendAck();
    auto rxseq = header.seq;
    
    // add packet to receiveQueue if header.seq is in [ack .. alloc]
    if (txRange.contains(rxseq)) {
        if (receiveQueue.contains(rxseq)) {
            // already processed
            logger.info("DUP     %d  %s", rxseq, xns::SPP::toString(header.sst));
        } else {
            // add to receiveQueue
            auto seqVec = receiveQueue.add(Packet{header, body});
            logger.info("ACCEPT  %d", rxseq);
    
            // maintain txRange
            while(std::find(seqVec.begin(), seqVec.end(), txRange.ack) != seqVec.end()) {
                txRange++;
                sendAck = true;
                logger.info("NEW ACK %d", txRange.ack);
            }
        }
    } else {
        logger.info("rxRange  %d  %d", rxRange.ack, rxRange.alloc);
        logger.info("REJECT  %d  %s", rxseq, xns::SPP::toString(header.sst));
    }

    if (sendAck) transmitSystemAck();
}

int Connection::attention() {
    auto ret = attentionValue;
    if (0 <= attentionValue) {
        attentionValue = NO_ATTENTION;
    }
    return ret;
}

void Connection::set(Client* client_) {
    client = client_;
    
    ThreadControl::Function function = std::bind(&Client::run, client);
    clientThread.set("ClientThread", function);
}

//
// Connections
//

void Connections::add(Connection* connection) {
    std::lock_guard<std::mutex> lock(mutex);
    // sanity check
    // check duplicate key
    auto myKey = connection->key;
    for(auto* e: vector) {
        if (e && e->key == myKey) ERROR()
    }

    // if vector is full, resize vector with default value
    if (vector.capacity() == 0) {
        vector.resize(vector.size() + DELTA, 0);
    }
    // find first empty entry and store connection in it
    for(auto*& e: vector) {
        if (e == 0) {
            e = connection;
            return;
        }
    }
    ERROR()
}

void Connections::remove(uint32_t key) {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: vector) {
        if (e && key == e->key) {
            // delete Connection
            delete e;
            // set ZERO to element
            e = 0;
            return;
        }
    }
    ERROR()
}

bool Connections::contains(uint32_t key) {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto* e: vector) {
        if (e && key == e->key) return true;
    }
    return false;
}
Connection& Connections::get(uint32_t key) {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto* e: vector) {
        if (e && key == e->key) return *e;
    }
    ERROR()
}
uint32_t Connections::size() {
    std::lock_guard<std::mutex> lock(mutex);
    return vector.size();
}

Connection* Connections::getByDstID(uint16_t dstID) {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto* e: vector) {
        if (e && e->dstID == dstID) return e;
    }
    return 0;
}

}