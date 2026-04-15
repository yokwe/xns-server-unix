/*******************************************************************************
 * Copyright (c) 2025, Yasuhiro Hasegawa
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
 // IDP.h
 //

#pragma once

#include <string>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "../xns/XNS.h"

namespace xns {
//
class IDP {
public:
    //   maxIDPBytesPerPacket: CARDINAL = 576; -- from APilot/15.0.1/NS/Friends/NSTypes.mesa
    static const constexpr uint32_t MAX_PACKET_SIZE_IN_BYTE = 576;
    static const constexpr uint32_t HEADER_SIZE_IN_BYTE     = 30;
    static const constexpr uint32_t MAX_BODY_SIZE_IN_BYTE   = MAX_PACKET_SIZE_IN_BYTE - HEADER_SIZE_IN_BYTE;


    enum class Checksum : uint16_t {
        ZERO    =      0,
        NOCHECK = 0xFFFF,
    };
    inline static std::string toString(Checksum value) {
        static std::unordered_map<Checksum, std::string, ScopedEnumHash> map = {
            {Checksum::ZERO,    "ZERO"},
            {Checksum::NOCHECK, "NOCHECK"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
    };

    enum class PacketType : uint8_t {
        RIP    = 1,
        ECHO   = 2,
        ERROR_ = 3,
        PEX    = 4,
        SPP    = 5,
        BOOT   = 6,
    };
    inline static std::string toString(PacketType value) {
        static std::unordered_map<PacketType, std::string, ScopedEnumHash> map = {
            {PacketType::RIP,    "RIP"},
            {PacketType::ECHO,   "ECHO"},
            {PacketType::ERROR_, "ERROR_"},
            {PacketType::PEX,    "PEX"},
            {PacketType::SPP,    "SPP"},
            {PacketType::BOOT,   "BOOT"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
    };
    
    static Checksum computeChecksum(const uint8_t* data, int start, int endPlusOne);

    Checksum       checksum;
    uint16_t       length;
    uint8_t        control;
    PacketType     packetType;

    NetworkAddress dst;
    NetworkAddress src;

    void read(const ByteBuffer& bb) {
        bb.read(checksum, length, control, packetType, dst, src);
    }
    void write(ByteBuffer& bb) const {
        bb.write(checksum, length, control, packetType, dst, src);
    }
    std::string toString() const {
        return std_sprintf("{%s  %d  %d  %s  %s  %s}",
            toString(checksum), length, control, toString(packetType), dst.toString(), src.toString());    
    }
};

}