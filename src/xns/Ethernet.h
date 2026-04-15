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

#include "XNS.h"


namespace xns {
//
class Ethernet {
public:
    enum class Type : uint16_t {
        XNS = 0x600,
        IP4 = 0x800,
        PUP = 0xA00,
    };
    static inline std::string toString(Type value) {
        static std::unordered_map<Type, std::string, ScopedEnumHash> map = {
            {Type::XNS, "XNS"},
            {Type::IP4, "IP4"},
            {Type::PUP, "PUP"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
    };

    Host dest;
    Host source;
    Type type;

    void read(const ByteBuffer& bb) {
        bb.read(dest, source, type);
    }
    void write(ByteBuffer& bb) const {
        bb.write(dest, source, type);
    }
    std::string toString() const {
        return std_sprintf("{%s  %s  %s}",dest.toString(), source.toString(), toString(type));
    }
};

}
