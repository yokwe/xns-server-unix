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
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

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
    if (!connections.contains(key)) ERROR()

    auto& connection = connections.get(key);

    auto sst = rxHeader.sst;
    if (sst == SST::CLOSE) {
        connection.receiveQueue.clear();
        connection.retransmitQueue.clear();
        logger.info("SSP CLOSE  %s", name());
        connection.transmitClose();
        connection.state = Connection::State::CLOSE;
    } else if (sst == SST::CLOSE_REPLY) {
        connection.receiveQueue.clear();
        connection.retransmitQueue.clear();
        logger.info("SSP CLOSE_REPLY  %s", name());
        connection.seq++;
        connection.transmitCloseReply();
        connection.state = Connection::State::CLOSE_REPLY;
        
        // stop client
        connection.client->stop();

        // remove connection from connections
        connections.remove(key);

        // notify SocketManager to stop listening this socket
        stopped = true;
    } else {
        connection.receive(rxHeader, rxbb);
    }
}

}