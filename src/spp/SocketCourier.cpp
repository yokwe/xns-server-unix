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
 // SocketCourier.cpp
 //

#include <chrono>
#include <thread>
 
#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/XNS.h"
#include "../xns/SPP.h"

#include "Connection.h"
#include "SocketSPP.h"
#include "SocketCourier.h"


namespace spp {
//

void SocketCourierClient::process(Session& session, ByteBuffer&rx, bool& stopped) {
    stopped = false;
    if (session.rxIDP.packetType != xns::IDP::PacketType::SPP)    ERROR()

    xns::SPP   rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto sst = rxHeader.sst;
    auto srcID = rxHeader.dstID;
    auto dstID = rxHeader.srcID;

    logger.info("SPP  %s  %04X  %-10s  %s", xns::toString(socket), rxHeader.seq, xns::SPP::toString(sst), toString(state));

    auto* connection = connections.get(srcID, dstID);
    if (connection == 0) {
        logger.warn("Unexpected srcID dstID  %04X  %04X", srcID, dstID);
        return;
    }

    if (state == State::NEW) {
        if (rxHeader.seq == 0 && rxHeader.dstID != 0) {
            state = State::OPEN;
        } else {
            ERROR()
        }
    }

    if (sst == SST::CLOSE) {
        closeCount++;
        if (closeCount == 1) {
            state = State::CLOSE;
            connection->receiveQueue.clear();
            connection->retransmitQueue.clear();
            // increment ack and alloc
            connection->txRange++;
            // send close
            connection->transmitClose();
        } else if (closeCount < 99) {
            // send close
            connection->transmitClose();
        } else {
            // Unexpected situation
            logger.info("SSP  %s  %s  UNEXPECTED CLOSE COUNT", xns::toString(socket), xns::SPP::toString(sst));
            stopAtTime = Listener::time_point::min(); // stop as soon as possible
        }
    } else if (sst == SST::CLOSE_REPLY) {
        if (state == State::CLOSE) {
            state = State::CLOSE_REPLY;
            connection->retransmitQueue.clear();
            connection->receiveQueue.clear();
            connection->seq++;
            connection->txRange++;
            stopAtTime = Listener::Clock::now() + CLOSE_REPLY_TIMEOUT; // stop after CLOSE_REPLY_TIMEOUT
        }
        if (state != State::CLOSE_REPLY) ERROR()

        // send close reply
        connection->transmitCloseReply();
    } else {
        if ((state == State::CLOSE || state == State::CLOSE_REPLY) && !rxHeader.system()) {
            // Unexpected situation
            logger.info("SSP  %s  %s  UNEXPECTED state", xns::toString(socket), xns::SPP::toString(sst));
            stopAtTime = Listener::time_point::min(); // stop as soon as possible
        } else {
            connection->receive(rxHeader, rxbb);
        }
    }
}

void SocketCourierClient::stop() {
    auto* connection = connections.get(srcID, dstID);
    connection->receiveQueue.clear();
    connection->retransmitQueue.clear();
    // stop client
    connection->client->stop();
    // remove connection from connections
    connections.remove(connection);
}

}