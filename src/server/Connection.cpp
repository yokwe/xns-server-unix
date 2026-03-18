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
#include <thread>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ThreadControl.h"

#include "Connection.h"

namespace server{
//

//
// Connection
//
void Connection::transmit(uint8_t sst, bool system, bool sendAck, bool attention, bool endOfMessage, Data& data) {
    if (!system) {
        std::lock_guard<std::mutex> lock(mutex);
        if (txQueue.contains(seq)) ERROR() // detect seq duplicate
        // add to txQueue for retransmit
        txQueue.add(Packet{seq, sst, system, sendAck, attention, endOfMessage, data});
        // NOTE increment seq
        seq++;
    }

    // send packet
    {
        xns::SPP txHeader;
        txHeader.system(system);
        txHeader.sendAck(sendAck);
        txHeader.attention(attention);
        txHeader.endOfMessage(endOfMessage);
        txHeader.srcID = srcID;
        txHeader.dstID = dstID;
        txHeader.seq   = seq;
        txHeader.ack   = ack;
        txHeader.alloc = alloc;
    
        ByteBuffer txbb;
        txbb.putVector(data);

        session.send(txHeader, txbb);
    }
}

void Connection::receiveSystem(const xns::SPP header, const ByteBuffer& body) {
    // seq   -- seq of next data packet
    // ack   -- all packets with sequence numbers preceding ack have been acknowledged in other side
    // alloc -- other side can accept sequence number [ack..alloc]

    // sanity check
    if (!body.empty()) ERROR()

    // remove acknowledged packet in txQueue
    removeAcknowledged(header.ack);

    bool sendAck = header.sendAck();
    if (sendAck) {
        logger.info("SEND ACK  %d", ack);
        transmitSystem(false);
    }
}
void Connection::receiveUser(const xns::SPP header, const ByteBuffer& body) {
    // seq   -- seq of next data packet
    // ack   -- all packets with sequence numbers preceding ack have been acknowledged in other side
    // alloc -- other side can accept sequence number [ack..alloc]

    // remove acknowledged packet in txQueue
    removeAcknowledged(header.ack);
    
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
        for(auto seqSet = rxQueue.seqSet(); seqSet.contains(ack);) {
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
}

int Connection::attention() {
    auto ret = attentionValue;
    if (0 <= attentionValue) {
        attentionValue = NO_ATTENTION;
    }
    return ret;
}


void Connection::retransmit() {
    std::lock_guard<std::mutex> lock(mutex);
    txQueue.retransmit(*this);
}

void Connection::removeAcknowledged(uint16_t rxack) {
    if (txQueue.empty()) return;

    std::lock_guard<std::mutex> lock(mutex);
    for(auto e: txQueue.seqSet()) {
        if (isBefore(e, rxack)) txQueue.remove(e);  // remove if seq is bofore ack
    }
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