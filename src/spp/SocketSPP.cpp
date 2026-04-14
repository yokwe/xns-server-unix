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
 // SocketSPP.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "Connection.h"

#include "SocketSPP.h"

namespace spp {
//

static uint16_t newConnectionID() {
    static uint16_t lastResult = 0;

    // Overflow period in second  is  65536 / (1000 / N)
    // Overflow period in minutes is  65536 / ((1000 / N) * 60)
    // When N = 30  Overflow time is 32.768 minutes
    constexpr uint64_t N = 30;
    auto milliseconds = std::chrono::milliseconds(std::chrono::steady_clock::now().time_since_epoch().count()).count();
    uint16_t result = milliseconds / N;
    // sanity check
    if (result == lastResult) {
        // if same result, wait N milliseconds to incremetn result
        std::this_thread::sleep_for(std::chrono::milliseconds(N));
        result++;
    }
    return lastResult = result;
}


void SocketSPP::process(Session& session, ByteBuffer&rx, bool& stopped) {
    stopped = false;
    if (session.rxIDP.packetType != xns::IDP::PacketType::SPP)    ERROR()

    xns::SPP   rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    // sanity check
    if (!rxHeader.system()) {
        logger.error("Unexpected NOT system packet");
        ERROR()
    }
    if (!rxbb.empty()) {
        logger.error("Unexpected rxbb is not empty");
        ERROR()
    }

    const uint16_t dstID = rxHeader.srcID;

    {
        auto oldConnection = connections.getByDstID(dstID);
        if (oldConnection) {
            auto& connection = *oldConnection;
            logger.info("SPP REOPEN %s  %s", name(), connection.toString());
            // set dst.socket to redirect socket
            session.rxIDP.dst.socket = connection.socket;
            // send packet
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            connection.transmitSystemAck();
            return;
        }
    }

    // add new connection
    const uint16_t srcID = newConnectionID();
    const uint32_t key   = getKey(srcID, dstID);

    // get new socket for srcSocket
    auto socket = socketManager->newSocket();

    // set dst.socket to redirect socket
    session.rxIDP.dst.socket = socket;

    // start listening new socket
    auto* clientListener = getListener(socket, key);
    socketManager->add(socket, clientListener);

    connections.add(new Connection(session, socket, srcID, dstID));    

    // get reference of connection from connections
    auto& connection = connections.get(key);

    // set client to connection
    connection.set(getClient(&connection));

    // start client thread
    connection.client->start();

    logger.info("SPP OPEN   %s  %s", name(), connection.toString());
    
    // send packet
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    connection.transmitSystemAck();
}

}