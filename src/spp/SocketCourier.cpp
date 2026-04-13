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

#include "../util/Util.h"
#include <thread>
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/XNS.h"
#include "../xns/SPP.h"

#include "Connection.h"

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

    auto key = getKey(rxHeader);
    auto sst = rxHeader.sst;
    logger.info("SPP  %s  %08X  %s  %s", xns::toString(socket), key, xns::SPP::toString(sst), toString(state));

    if (!connections.contains(key)) ERROR()
    auto& connection = connections.get(key);

    if (state == State::NEW) {
        if (rxHeader.seq == 0) {
            state = State::OPEN;
        } else {
            ERROR()
        }
    }

    if (sst == SST::CLOSE) {
        closeCount++;
        if (closeCount == 1) {
            state = State::CLOSE;
            connection.receiveQueue.clear();
            connection.retransmitQueue.clear();
            // reduce window
            connection.txRange.alloc = connection.txRange.ack;
            connection.txRange++;
            // send close
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            connection.transmitClose();
        } else if (closeCount < 4) {
            // send close
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            connection.transmitClose();
        } else {
            // Unexpected situation
            logger.info("SSP  %s  %08X  %s  UNEXPECTED CLOSE COUNT", xns::toString(socket), key, xns::SPP::toString(sst));
            goto close_connection;
        }
    } else if (sst == SST::CLOSE_REPLY) {
        state = State::CLOSE_REPLY;
        connection.seq++;
        connection.txRange++;
        // send close reply
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        connection.transmitCloseReply();
        // send close reply again
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        connection.transmitCloseReply();
        goto close_connection;
    } else {
        if (state == State::CLOSE || state == State::CLOSE_REPLY) {
            // Unexpected situation
            logger.info("SSP  %s  %08X  %s  UNEXPECTED state", xns::toString(socket), key, xns::SPP::toString(sst));
            goto close_connection;
        } else {
            connection.receive(rxHeader, rxbb);
        }
    }
    return;

close_connection:
    connection.receiveQueue.clear();
    connection.retransmitQueue.clear();
    // stop client
    connection.client->stop();
    // remove connection from connections
    connections.remove(key);
    // notify SocketManager to stop listening this socket
    stopped = true;
}

}