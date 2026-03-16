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

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "Connection.h"

namespace server{
//

//
// Connection
//
void Connection::transmit(uint8_t sst, bool system, bool sendAck, bool attention, bool endOfMessage, Data& data) {
    if (!system) {
        if (rxQueue.contains(seq)) ERROR() // detect seq duplicate
        txQueue.add(Packet{seq, sst, system, sendAck, attention, endOfMessage, data});
        seq++;  // INCREMENT seq
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
    {
        auto rxack = header.ack; // seq before ack is acknowledged
        for(auto e: txQueue.seqSet()) {
            if (isBefore(e, rxack)) txQueue.remove(e);  // remove if seq is bofore ack
        }
    }

    if (header.sendAck()) {
        logger.info("SEND ACK  %d", ack);
        transmitSystem(false);
    }
}
void Connection::receiveUser(const xns::SPP header, const ByteBuffer& body) {
    // seq   -- seq of next data packet
    // ack   -- all packets with sequence numbers preceding ack have been acknowledged in other side
    // alloc -- other side can accept sequence number [ack..alloc]

    // add packet if header.seq is between ack and alloc
    {
        auto rxseq = header.seq;
        if (isBefore(rxseq, ack))   return; // return if rxseq is before ack    -- rxseq < ack
        if (isBefore(alloc, rxseq)) return; // return if alloc is bofore rxseq  -- alloc < rxseq

        if (rxQueue.contains(rxseq)) return; // return  if rxseq is in rxQueue

        // add to rxQueue
        rxQueue.add(Packet{header, body});
        logger.info("ACCEPT rxseq  %d", rxseq);

        // update ack/alloc
        bool ackModified = false;
        for(auto seqSet = rxQueue.seqSet(); seqSet.contains(ack);) {
            ack++;
            ackModified = true;
        }
        alloc = ack + 4;

        if (ackModified || header.sendAck()) {
            // send acknledge
            logger.info("SEND ACK  %d", ack);
            transmitSystem(false);
        }
    }

    // remove acknowledged packet in txQueue
    {
        auto rxack = header.ack; // seq before ack is acknowledged
        for(auto e: txQueue.seqSet()) {
            if (isBefore(e, rxack)) txQueue.remove(e);  // remove if seq is bofore ack
        }
    }
}

}