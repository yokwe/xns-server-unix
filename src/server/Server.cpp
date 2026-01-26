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
 // Server.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/Echo.h"
#include "../xns/Error.h"
#include "../xns/IDP.h"
#include "../xns/PEX.h"
#include "../xns/RIP.h"
#include "../xns/SPP.h"

#include "Server.h"

namespace xns::server {
//
void ECHO_process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    (void)rx; (void)tx; (void)context;
    // FIXME
    Echo transmit;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        Echo receive;
        rx.read(receive);

    }
    logger.info("Echo::process");
}


void ERROR_process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    (void)rx; (void)tx; (void)context;
    // FIXME
    Error transmit;
    logger.info("Echo::process");
}


void PEX_process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    (void)context;
    using ClientType = PEX::ClientType;

    PEX transmit;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        PEX receive;
        rx.read(receive);

        auto remains = rx.rangeRemains();
        logger.info("PEX  >>  %s  (%d) %s", receive.toString(), remains.byteLimit(), remains.toString());

        switch(receive.clientType) {
        case ClientType::UNSPEC:
            break;
        case ClientType::TIME:
//            processTime(remains, payload, context);
            break;
        case ClientType::CHS:
            break;
        case ClientType::TELEDEBUG:
            break;
        default:
            ERROR()
        }

        payload.flip();
        if (payload.empty()) return;

        transmit.id         = receive.id;
        transmit.clientType = receive.clientType;
    }

    tx.write(transmit);
    tx.write(payload.toSpan());
    tx.flip();
}


void RIP_process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    (void)tx; (void)context;

    RIP transmit;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        RIP receive;
        rx.read(receive);

        logger.info("RIP  >>  %s", receive.toString());
    }
}


void SPP_process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    (void)context;
    SPP transmit;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        SPP receive;
        rx.read(receive);

        auto remains = rx.rangeRemains();
        logger.info("SPP  >>  %s  (%d) %s", receive.toString(), remains.byteLimit(), remains.toString());

        // FIXME

        payload.flip();
        if (payload.empty()) return;

        // FIXME
        transmit.idDst = receive.idSrc;
        transmit.idSrc = receive.idDst;
    }

    tx.write(transmit);
    tx.write(payload.toSpan());
    tx.flip();
}


void BOOT_process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    (void)rx; (void)tx; (void)context;
}


void IDP_process(ByteBuffer& rxRaw, ByteBuffer& tx, server::Context& context) {
    constexpr auto HEADER_LENGTH_IN_BYTE = IDP::HEADER_LENGTH_IN_BYTE;
    constexpr auto computeChecksum = IDP::computeChecksum;
    using Checksum = IDP::Checksum;
    using PacketType = IDP::PacketType;
    IDP transmit;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        IDP receive;
        rxRaw.read(receive);

        auto rx = rxRaw.byteRange(0, receive.length);
        // to adjust pos of rx, read receiveIDP again
        rx.read(receive);

        auto remains = rx.rangeRemains();
        logger.info("IDP  >>  %s  (%d) %s", receive.toString(), remains.byteLimit(), remains.toString());

        // sanity check
        if (receive.checksum != IDP::Checksum::NOCHECK) {
            auto checksum = computeChecksum(rx.data(), 2, rx.byteLimit());
            if (receive.checksum != checksum) {
                logger.warn("checksum error  %s  %s", IDP::toString(receive.checksum), IDP::toString(checksum));
                return;
            }
        }

        switch(receive.packetType) {
        case PacketType::RIP:
            RIP_process(remains, payload, context);
            break;
        case PacketType::ECHO:
            ECHO_process(remains, payload, context);
            break;
        case PacketType::ERROR_:
            ERROR_process(remains, payload, context);
            break;
        case PacketType::PEX:
            PEX_process(remains, payload, context);
            break;
        case PacketType::SPP:
            SPP_process(remains, payload, context);
            break;
        case PacketType::BOOT:
            BOOT_process(remains, payload, context);
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
