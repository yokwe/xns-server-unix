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

#include "../server/Server.h"

#include "Echo.h"
#include "Error.h"
#include "IDP.h"
#include "PEX.h"
#include "RIP.h"
#include "SPP.h"

#undef  ENUM_NAME_VALUE
#define ENUM_NAME_VALUE(enum,name,value) { enum :: name, #name },

namespace xns {
//
std::string IDP::toString(Checksum value) {
    static std::unordered_map<Checksum, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Checksum, NOCHECK, 0)
    };
    return map.contains(value) ? map[value] : std_sprintf("%04X", static_cast<uint16_t>(value));
}

std::string IDP::toString(PacketType value) {
    static std::unordered_map<PacketType, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(PacketType, RIP,    1)
        ENUM_NAME_VALUE(PacketType, ECHO,   2)
        ENUM_NAME_VALUE(PacketType, ERROR_, 3)
        ENUM_NAME_VALUE(PacketType, PEX,    4)
        ENUM_NAME_VALUE(PacketType, SPP,    5)
        ENUM_NAME_VALUE(PacketType, BOOT,   6)
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", static_cast<uint8_t>(value));
}

std::string IDP::toString() const {
    return std_sprintf("{%s  %d  %d  %s  %s  %s}",
        IDP::toString(checksum), length, control, IDP::toString(packetType), dst.toString(), src.toString());
}

IDP::Checksum IDP::computeChecksum(const uint8_t* data, int start, int endPlusOne) {
    uint32_t s = 0;
    for(int i = start; i < endPlusOne;) {
        uint32_t w = (data[i++] & 0xFFFFU) << 8;
        w |= data[i++];

		// add w to s
		s += w;
		// if there is overflow, increment s
		if (0x10000U <= s) s = (s + 1) & 0xFFFFU;
		// shift left
		s <<= 1;
		// if there is overflow, increment s
		if (0x10000U <= s) s = (s + 1) & 0xFFFFU;
    }

    // From page 21 of INTERNET TRANSPORT PROTOCOLS
    // If the result of the checksumming operation is the one's complement value "minus zero" (177777 octal),
    // it should be converted to "plus zero" (0 octal).
    auto result = static_cast<Checksum>((uint16_t)s);
    return result == Checksum::NOCHECK ? Checksum::ZERO : result;
}

void IDP::process(ByteBuffer& rxRaw, ByteBuffer& tx, server::Context& context) {
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
                logger.warn("checksum error  %s  %s", toString(receive.checksum), toString(checksum));
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
            logger.info("BOOT");
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