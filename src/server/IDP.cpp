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
 // IDP.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/IDP.h"

#include "Server.h"

namespace xns::server::IDP {
//
using R = xns::IDP;
using T = xns::IDP;
struct MyProcess : public Process<T> {
    void process(ByteBuffer& rx, ByteBuffer& tx, Context& context) override;
    void process(Param<T>& receive, Param<T>& transmit, Context& context) override;
};

void MyProcess::process(ByteBuffer& rx, ByteBuffer& tx, Context& context) {
    auto receive  = Param<xns::IDP>::receive(rx);
    auto transmit = Param<xns::IDP>::transmit();

    receive.body = receive.body.byteRange(0, receive.header.length - xns::IDP::HEADER_LENGTH_IN_BYTE);

    logger.info("IDP  >>  %s  (%d) %s", receive.header.toString(), receive.body.byteLimit(), receive.body.toString());

    // sanity check
    if (receive.header.checksum != xns::IDP::Checksum::NOCHECK) {
        auto checksum = xns::IDP::computeChecksum(rx.data(), 2, receive.header.length);
        if (receive.header.checksum != checksum) {
            logger.warn("checksum error  %s  %s", xns::IDP::toString(receive.header.checksum), xns::IDP::toString(checksum));
            return;
        }
    }

    // prepare transmit.header
    transmit.header.checksum    = xns::IDP::Checksum::NOCHECK;
    transmit.header.length      = 0;
    transmit.header.control     = 0;
    transmit.header.packetType  = receive.header.packetType;
    transmit.header.dst.network = receive.header.src.network;
    transmit.header.dst.host    = receive.header.src.host;
    transmit.header.dst.socket  = receive.header.src.socket;
    transmit.header.src.network = static_cast<Network>(context.net);
    transmit.header.src.host    = context.me;
    transmit.header.src.socket  = receive.header.dst.socket;

    process(receive, transmit, context);
    
    transmit.body.flip();
    if (transmit.body.empty()) return;

    // update length
    // Garbage Byte, which is included in the Checksum, but not in the Length
    transmit.header.length = xns::IDP::HEADER_LENGTH_IN_BYTE + transmit.body.byteLimit();

    tx.write(transmit.header);
    tx.write(transmit.body.toSpan());
    // to make even length data, add Garbage Byte if length is odd.
    if (tx.byteLimit() & 1) tx.put8(0);
    tx.flip();
    // update checksum
    // Garbage Byte, which is included in the Checksum, but not in the Length
    auto checksum = xns::IDP::computeChecksum(tx.data(), 2, tx.byteLimit());
    tx.write(checksum);

    logger.info("IDP  <<  %s  (%d) %s", transmit.header.toString(), transmit.body.byteLimit(), transmit.body.toString());
}

void MyProcess::process(Param<xns::IDP>& receive, Param<xns::IDP>& transmit, Context& context) {
    using PacketType = xns::IDP::PacketType;
    switch(receive.header.packetType) {
        case PacketType::RIP:
            RIP::process(receive.body, transmit.body, context);
            break;
        case PacketType::ECHO:
            Echo::process(receive.body, transmit.body, context);
            break;
        case PacketType::ERROR_:
            Error::process(receive.body, transmit.body, context);
            break;
        case PacketType::PEX:
            PEX::process(receive.body, transmit.body, context);
            break;
        case PacketType::SPP:
            SPP::process(receive.body, transmit.body, context);
            break;
        default:
            ERROR()
        }
}

static MyProcess myProcess;
void process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    myProcess.process(rx, tx, context);
}

}