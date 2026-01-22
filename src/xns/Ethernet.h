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
 // Ethernet.h
 //

#pragma once

#include <cstdint>

#include "../util/ByteBuffer.h"

#include "Type.h"


namespace xns::ethernet {
//
class Frame : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
    static uint64_t to64(uint16_t a, uint16_t b, uint16_t c) {
        return (uint64_t)a << 32 | (uint64_t)b << 16 | (uint64_t)c;
    }
    static void from64(uint16_t& a, uint16_t& b, uint16_t& c, uint64_t value) {
        a = (uint16_t)(value >> 32);
        b = (uint16_t)(value >> 16);
        c = (uint16_t)(value >>  0);
    }

public:
    uint16_t  dest1;   // Host
    uint16_t  dest2;   // Host
    uint16_t  dest3;   // Host
    uint16_t  source1; // Host
    uint16_t  source2; // Host
    uint16_t  source3; // Host
    uint16_t  type;    // type

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(dest1, dest2, dest3, source1, source2, source3, type);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        bb.write(dest1, dest2, dest3, source1, source2, source3, type);
        return bb;
    }

    uint64_t dest() const {
        return to64(dest1, dest2, dest3);
    }
    uint64_t source() const {
        return to64(source1, source2, source3);
    }
    void dest(uint64_t value) {
        from64(dest1, dest2, dest3, value);
    }
    void source(uint64_t value) {
        from64(source1, source2, source3, value);
    }

    std::string toString() const override {
        return std_sprintf("{%s  %s  %s}", xns::hostname(dest()), xns::hostname(source()), xns::packetTypeName(type));
    }

};

}
