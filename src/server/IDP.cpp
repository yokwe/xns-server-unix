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
void process(ByteBuffer& rxRaw, ByteBuffer& tx, server::Context& context) {
    using Checksum   = xns::IDP::Checksum;
    using PacketType = xns::IDP::PacketType;

    constexpr auto HEADER_LENGTH_IN_BYTE = xns::IDP::HEADER_LENGTH_IN_BYTE;
    constexpr auto computeChecksum = xns::IDP::computeChecksum;
    xns::IDP transmit;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        xns::IDP receive;
        rxRaw.read(receive);

        auto rx = rxRaw.byteRange(0, receive.length);
        // to adjust pos of rx, read receiveIDP again
        rx.read(receive);

        auto remains = rx.rangeRemains();
        logger.info("IDP  >>  %s  (%d) %s", receive.toString(), remains.byteLimit(), remains.toString());

        // sanity check
        if (receive.checksum != xns::IDP::Checksum::NOCHECK) {
            auto checksum = computeChecksum(rx.data(), 2, rx.byteLimit());
            if (receive.checksum != checksum) {
                logger.warn("checksum error  %s  %s", xns::IDP::toString(receive.checksum), xns::IDP::toString(checksum));
                return;
            }
        }

        switch(receive.packetType) {
        case PacketType::RIP:
            RIP::process(remains, payload, context);
            break;
        case PacketType::ECHO:
            Echo::process(remains, payload, context);
            break;
        case PacketType::ERROR_:
            Error::process(remains, payload, context);
            break;
        case PacketType::PEX:
            PEX::process(remains, payload, context);
            break;
        case PacketType::SPP:
            SPP::process(remains, payload, context);
            break;
        case PacketType::BOOT:
            Boot::process(remains, payload, context);
            break;
        default:
            ERROR()
        }
        
        payload.flip();
        if (payload.empty()) return;

        transmit.checksum    = Checksum::NOCHECK;
        // Garbage Byte, which is included in the Checksum, but not in the Length
        transmit.length      = HEADER_LENGTH_IN_BYTE + payload.byteLimit();
        transmit.control     = 0;
        transmit.packetType  = receive.packetType;
        transmit.dst.network = receive.src.network;
        transmit.dst.host    = receive.src.host;
        transmit.dst.socket  = receive.src.socket;
        transmit.src.network = static_cast<Network>(context.net);
        transmit.src.host    = context.me;
        transmit.src.socket  = receive.dst.socket;
    }

    tx.write(transmit);
    tx.write(payload.toSpan());
    // make even length
    if (tx.byteLimit() & 1) tx.put8(0);
    tx.flip();
    // update checksum
    auto checksum = computeChecksum(tx.data(), 2, tx.byteLimit());
    tx.write(checksum);
}

}