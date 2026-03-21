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

#include <chrono>
#include <functional>
#include <thread>

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
void Connection::transmit(bool system, bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data) {
    // send packet
    transmitRaw(system, sendAck, attention, endOfMessage, sst, data);

    // put packet in txQueue for retransmit
    if (!system) {
        std::lock_guard<std::mutex> lock(mutex);
        // add to txQueue for retransmit
        txQueue.add(Packet{system, sendAck, attention, endOfMessage, sst, seq, data});
        // NOTE increment seq
        seq++;
    }
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
    txHeader.ack   = ack;
    txHeader.alloc = alloc;

    ByteBuffer txbb = server::getByteBuffer();
    txbb.putVector(data);

    session.send(txHeader, txbb);
}

void Connection::receiveSystem(const xns::SPP& header, const ByteBuffer& body) {
    // seq   -- seq of next data packet
    // ack   -- all packets with sequence numbers preceding ack have been acknowledged in other side
    // alloc -- other side can accept sequence number [ack..alloc]

    // sanity check
    if (!body.empty()) {
        logger.info("SPP  >>  %s  (%d) %s", header.toString(), body.byteLimit(), body.toString());
        ERROR()
    }
    if (header.sst != SST::DATA) {
        logger.info("SPP  >>  %s  (%d) %s", header.toString(), body.byteLimit(), body.toString());
        ERROR()
    }

    // change state
    if (state == State::NEW) state = State::OPEN;

    // remove acknowledged packet in txQueue
    removeAcknowledged(header.ack);

    if (header.sendAck()) {
        logger.info("SEND ACK  %d", ack);
        transmitSystem(false);
    }
}
void Connection::receiveUser(const xns::SPP& header, const ByteBuffer& body) {
    // seq   -- seq of next data packet
    // ack   -- all packets with sequence numbers preceding ack have been acknowledged in other side
    // alloc -- other side can accept sequence number [ack..alloc]
    logger.info("%s  sst  %s  state  %s", __func__, ::toString(header.sst), toString(state));

    // remove acknowledged packet in txQueue
    removeAcknowledged(header.ack);
    
    if (header.sst == SST::CLOSE) {
        // sanity check
        if (state != State::OPEN) {
            logger.info("SPP  >>  %s  (%d) %s", header.toString(), body.byteLimit(), body.toString());
            logger.error("connection  %s", toString());
            ERROR()
        }

        // FIXME stop retransmit
        // FIXME change state to CLOSE
        logger.info("SST CLOSE");
        state = State::CLOSE;
        txQueue.clear();

        Data data;
        transmit(false, false, false, false, SST::CLOSE, data);
        return;
    }
    if (header.sst == SST::CLOSE_REPLY) {
        // sanity check
        if (state != State::CLOSE) {
            logger.info("SPP  >>  %s  (%d) %s", header.toString(), body.byteLimit(), body.toString());
            logger.error("connection  %s", toString());
            ERROR()
        }

        // FIXME connection is closed
        // FIXME remove this connection from connections
        // FIXME unlisten this socket
        logger.info("SST CLOSE_REPLY");
        state = State::CLOSE_REPLY;
        txQueue.clear();

        Data data;
        transmitRaw(false, false, false, false, SST::CLOSE_REPLY, data);
        seq++;
        return;
    }
    if (header.sst == SST::BULK) {
        // sanity check
        if (state != State::OPEN) {
            logger.error("connection  %s", toString());
            ERROR()
        }

        // FIXME
        logger.info("SST BULK");
        return;
    }

    if (header.sst == SST::DATA) {
        // sanity check
        if (state != State::OPEN) {
            logger.error("connection  %s", toString());
            ERROR()
        }

        logger.info("SST DATA");
        // add packet to rxQueue if header.seq is in [ack .. alloc]
        bool sendAck = header.sendAck();
        auto rxseq = header.seq;
        if (!isBefore(rxseq, ack) && !isBefore(alloc, rxseq) && !rxQueue.contains(rxseq)) {
            std::lock_guard<std::mutex> lock(mutex);
            // add to rxQueue
            rxQueue.add(Packet{header, body});
            logger.info("ACCEPT rxseq  %d", rxseq);
    
            // update attentionValue
            if (header.attention()) {
                if (body.byteRemains() != 1) ERROR()
                body.mark();
                attentionValue = body.get8();
                body.reset();
            }
    
            // update ack/alloc
            while(rxQueue.contains(ack)) {
                ack++;
                sendAck = true;
            }
            alloc = ack + 4;    
        }
    
        if (rxQueue.contains(clientSeq)) {
            std::lock_guard<std::mutex> lock(mutex);
            for (;;) {
                // send data to client
                auto& queue = rxQueue.get(clientSeq);
                logger.info("clientQueue  %04X", clientSeq);
                clientQueue.push(queue);
                clientSeq++;
                if (rxQueue.contains(clientSeq)) continue;
                break;
            }
        }
    
        if (sendAck) {
            // send acknledge
            logger.info("SEND ACK  %d", ack);
            transmitSystem(false);
        }

        return;
    }
}

int Connection::attention() {
    auto ret = attentionValue;
    if (0 <= attentionValue) {
        attentionValue = NO_ATTENTION;
    }
    return ret;
}


void Connection::retransmit() {
    auto now = std::chrono::steady_clock::now();
    PacketQueue::MapFunction function = [&](Packet& e) {
        if ((e.timestamp + RETRANSMIT_INTERVAL) < now) {
            // retransmit packet
            transmitRaw(e.system(), e.sendAck(), e.attention(), e.endOfMessage(), e.sst, e.data);
            logger.info("RETRANSMIT  %04X  %04X  %s", srcID, dstID, e.toString());

            // update timestmp
            e.timestamp += RETRANSMIT_INTERVAL;
        }
    };
    txQueue.map(function);
}

void Connection::removeAcknowledged(uint16_t ack) {
    PacketQueue::MapDeleteFunction function = [&](Packet& e) {
        return isBefore(e.seq, ack); // remove if seq is bofore ack
    };

    txQueue.mapDelete(function);
}


void Connection::set(std::shared_ptr<ConnectionClient> client_) {
    client = client_;
    
    ThreadControl::Function function = std::bind(&ConnectionClient::run, client);
    clientThread.set("ClientThread", function);
}

//
// Connections
//

void Connections::start() {
    std::function<void()> function = std::bind(&Connections::run, this);
    threadControl.set("Connection", function);
    threadControl.start();
}

void Connections::run() {
    auto ONE_SECOND = std::chrono::seconds(1);
    auto now = std::chrono::steady_clock::now();

    for(;;) {
        now += ONE_SECOND;
        std::this_thread::sleep_until(now);

        {
            std::lock_guard<std::mutex> lock(mutex);
            for(auto& e: list) {
                e.retransmit();
            }    
        }
    }
}

}