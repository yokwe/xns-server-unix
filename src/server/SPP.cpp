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
 // SPP.cpp
 //

#include <chrono>
#include <utility>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/Debug.h"
#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

#include "Server.h"
#include "Connection.h"
#include "ConnectionClient.h"
#include "ConnectionClientCourier.h"

namespace server {
//

static Connections connections;

void startSPP() {
    connections.start();
}

//
// processXXX
//
void processSPP_OLD(Session& session, const ByteBuffer& rx) {
    if (session.rxIDP.packetType == xns::IDP::PacketType::ERROR_) {
        processERROR(session, rx);
        return;
    }
    if (session.rxIDP.packetType != xns::IDP::PacketType::SPP)    ERROR()

    xns::SPP   rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto key = Connections::getKey(rxHeader);
    if (!connections.contains(key)) ERROR()

    auto& connection = connections.get(key);
    logger.info("OLD   CONNECTION  %d  %s", connections.size(), connection.toString());
    connection.receive(rxHeader, rxbb);

    if (connection.closed()) {
        logger.info("CLOSE CONNECTION  %d  %s", connections.size(), connection.toString());
        
        // remove connection from connections
        connections.remove(key);

        // stop listening socket
        unlisten(session.rxIDP.dst.socket);
        
        // remove connection
        connection.clientThread.join();
    }
}

void processSPP_NEW(Session& session, const ByteBuffer& rx) {
    if (session.rxIDP.packetType == xns::IDP::PacketType::ERROR_) {
        processERROR(session, rx);
        return;
    }
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

    // copy dst.socket to dstSocket
    auto dstSocket = session.rxIDP.dst.socket;

    // allocate new socket
    auto srcSocket = allocateSocket();

    // set dst.socket to redirect socket
    // Constructor of Connectin copy session
    session.rxIDP.dst.socket = static_cast<xns::Socket>(srcSocket);

    // start listening new socket
    listen(srcSocket, processSPP_OLD);

    // add new connection
    uint16_t dstID = rxHeader.srcID;
    uint16_t srcID;
    for(;;) {
        srcID = (uint16_t)(std::chrono::system_clock::now().time_since_epoch().count() >> 10);
        auto key = Connections::getKey(srcID, dstID);
        if (!connections.contains(key)) break;
        logger.info("XX contains  %04X  %04X", srcID, dstID);
    }

    {
        Connection conn{session, srcID, dstID};
        connections.add(conn);    
    }
    // get reference of connection from connections
    auto& connection = connections.get(Connections::getKey(srcID, dstID));
    {
        std::shared_ptr<ConnectionClient> client = 0;
        if (dstSocket == Socket::COURIER) {
            client = std::make_shared<ConnectionClientCourier>(connection);
        } else {
            logger.info("socket  %d", std::to_underlying(dstSocket));
            ERROR()
        }
        // set client to connection
        connection.set(client);
        // start client thread
        connection.clientThread.start();
    }

    logger.info("NEW   CONNECTION  %d  %s", connections.size(), connection.toString());

    // send packet
    connection.transmitSystem(true);
}


}