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

#include "IDP.h"

#undef  ENUM_NAME_VALUE
#define ENUM_NAME_VALUE(enum,name,value) { enum :: name, #name },

namespace xns {
//
std::string IDP::toString(Checksum checksum) {
    static std::unordered_map<Checksum, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Checksum, NOCHECK, 0)
    };
    return map.contains(checksum) ? map[checksum] : std_sprintf("%04X", static_cast<uint16_t>(checksum));
}

std::string IDP::toString(PacketType packetType) {
    static std::unordered_map<PacketType, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(PacketType, RIP,    1)
        ENUM_NAME_VALUE(PacketType, ECHO,   2)
        ENUM_NAME_VALUE(PacketType, ERROR_, 3)
        ENUM_NAME_VALUE(PacketType, PEX,    4)
        ENUM_NAME_VALUE(PacketType, SPP,    5)
        ENUM_NAME_VALUE(PacketType, BOOT,   6)
    };
    return map.contains(packetType) ? map[packetType] : std_sprintf("%d", static_cast<uint8_t>(packetType));
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

void IDP::process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    IDP transmitIDP;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        IDP receiveIDP;
        rx.read(receiveIDP);

        auto bb = rx.byteRange(0, receiveIDP.length);
        bb.read(receiveIDP);

        auto remains = bb.rangeRemains();
        logger.info("IDP  >>  %s  (%d) %s", receiveIDP.toString(), remains.byteLimit(), remains.toString());

        // sanity check
        if (receiveIDP.checksum != IDP::Checksum::NOCHECK) {
            auto checksum = computeChecksum(bb.data(), 2, bb.byteLimit());
            if (receiveIDP.checksum != checksum) {
                logger.warn("checksum error  %s  %s", toString(receiveIDP.checksum), toString(checksum));
                return;
            }
        }

        switch(receiveIDP.packetType) {
        case PacketType::RIP:
            break;
        case PacketType::ECHO:
            break;
        case PacketType::ERROR_:
            break;
        case PacketType::PEX:
            break;
        case PacketType::SPP:
            break;
        case PacketType::BOOT:
            break;
        default:
            ERROR()
        }
        
        payload.flip();
        if (payload.empty()) return;

        transmitIDP.checksum    = Checksum::NOCHECK;
        // Garbage Byte, which is included in the Checksum, but not in the Length
        transmitIDP.length      = HEADER_LENGTH_IN_BYTE + payload.byteLimit();
        transmitIDP.control     = 0;
        transmitIDP.packetType  = receiveIDP.packetType;
        transmitIDP.dst.network = receiveIDP.src.network;
        transmitIDP.dst.host    = receiveIDP.src.host;
        transmitIDP.dst.socket  = receiveIDP.src.socket;
        transmitIDP.src.network = static_cast<Network>(context.net);
        transmitIDP.src.host    = context.me;
        transmitIDP.src.socket  = receiveIDP.dst.socket;
    }

    tx.write(transmitIDP);
    tx.write(payload.toSpan());
    // make even length
    if (tx.byteLimit() & 1) tx.put8(0);
    tx.flip();
    // update checksum
    auto checksum = computeChecksum(tx.data(), 2, tx.byteLimit());
    tx.write(checksum);
}

}