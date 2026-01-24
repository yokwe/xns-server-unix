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
 // XNS.h
 //

#pragma once

#include <cstdint>
#include <string>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"
#include "../util/net.h"

#include "Config.h"

namespace xns {
//
const uint32_t MIN_PACKET_SIZE = net::minBytesPerEthernetPacket;
const uint32_t MAX_PACKET_SIZE = net::maxBytesPerEthernetPacket;;

void initialize(const config::Config* config);

std::string hostName(uint64_t address);
std::string netName(uint16_t net);


//
// Host
//
class Host : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
    uint64_t value;
public:
    static const uint64_t BROADCAST = 0xFFFF'FFFF'FFFF;

    Host() : value(0) {}
    Host(uint64_t value_) {
        value = value_;
    }
    operator uint64_t() const {
        return value;
    }

    ByteBuffer& read(ByteBuffer& bb) override {
        uint16_t word1;
        uint16_t word2;
        uint16_t word3;
        
        bb.read(word1, word2, word3);

        value = (uint64_t)word1 << 32 | (uint64_t)word2 << 16 | (uint64_t)word3;
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        uint16_t word1 = (uint16_t)(value >> 32);
        uint16_t word2 = (uint16_t)(value >> 16);
        uint16_t word3 = (uint16_t)(value >>  0);

        bb.write(word1, word2, word3);
        return bb;
    }
    std::string toString() const override {
        return xns::hostName(value);
    }
};

//
// Net
//
class Net : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
    uint32_t value;
public :
    Net() : value(0) {}
    Net(uint32_t value_) : value(value_) {}
    operator uint32_t() const {
        return value;
    }

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(value);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        bb.write(value);
        return bb;
    }
    std::string toString() const override {
         return xns::netName(value);
    }
};



}