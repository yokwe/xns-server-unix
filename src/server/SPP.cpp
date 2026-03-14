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

#include "../util/Debug.h"
#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

#include "Server.h"
#include "Connection.h"

namespace server {
//

static Connections connections;

//
// processXXX
//
void processSPP_OLD(Session& session, const ByteBuffer& rx) {
    (void)session;
    xns::SPP   rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    if (!connections.contains(Connections::getKey(rxHeader))) ERROR()

    auto& connection = connections.get(Connections::getKey(rxHeader));
    logger.info("OLD  CONNECTION  %d  %s", connections.map.size(), connection.toString());
    connection.receive(rxHeader, rxbb);
}

void processSPP_NEW(Session& session, const ByteBuffer& rx) {
    xns::SPP   rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    // sanity check
    if (!rxHeader.systemPacket()) {
        logger.error("Unexpected NOT system packet");
        ERROR()
    }
    if (!rxbb.empty()) {
        logger.error("Unexpected rxbb is not empty");
        ERROR()
    }

    auto srcSocket = allocateSocket();
    if (connections.contains(Connections::getKey(srcSocket, rxHeader.srcID))) ERROR()

    // add listener
    listen(srcSocket, processSPP_OLD);

    // set socket to txHeader.src.socket to redirect
    // Need this before connection.allocate, because connection.allocate copy session
    session.rxIDP.dst.socket = static_cast<xns::Socket>(srcSocket);

    auto connection = connections.allocate(session, srcSocket, rxHeader.srcID);
    logger.info("NEW  CONNECTION  %d  %s", connections.map.size(), connection.toString());

    // send packet
    connection.transmitSystem(true);
}


}