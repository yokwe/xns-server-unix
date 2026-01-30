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
class IDP : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
public:
    static constexpr int HEADER_LENGTH_IN_BYTE = 30;

    enum class Checksum : uint16_t {
        ENUM_NAME_VALUE(Checksum, ZERO,    0)       // plus  zero
        ENUM_NAME_VALUE(Checksum, NOCHECK, 0xFFFF)  // minus zero
    };
    static std::string toString(Checksum value);

    enum class PacketType : uint8_t {
        ENUM_NAME_VALUE(PacketType, RIP,    1)
        ENUM_NAME_VALUE(PacketType, ECHO,   2)
        ENUM_NAME_VALUE(PacketType, ERROR_, 3)
        ENUM_NAME_VALUE(PacketType, PEX,    4)
        ENUM_NAME_VALUE(PacketType, SPP,    5)
        ENUM_NAME_VALUE(PacketType, BOOT,   6)
    };
    static std::string toString(PacketType value);

    class NetworkAddress : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
    public:
        Network network;
        Host    host;
        Socket  socket;
    
        ByteBuffer& read(ByteBuffer& bb) override {
            bb.read(network, host, socket);
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) const override {
            bb.write(network, host, socket);
            return bb;
        }
        std::string toString() const override {
            return std_sprintf("%s-%s-%s", xns::toString(network), host.toString(), xns::toString(socket));
        }
    };
    
    static Checksum computeChecksum(const uint8_t* data, int start, int endPlusOne);

    Checksum       checksum;  // Checksum
    uint16_t       length;
    uint8_t        control;
    PacketType     packetType;      // Type

    NetworkAddress dst;
    NetworkAddress src;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(checksum, length, control, packetType, dst, src);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        bb.write(checksum, length, control, packetType, dst, src);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %d  %d  %s  %s  %s}",
            toString(checksum), length, control, toString(packetType), dst.toString(), src.toString());    
    }
};

}