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
 // RIP.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../server/Server.h"

#include "RIP.h"

#undef  ENUM_NAME_VALUE
#define ENUM_NAME_VALUE(enum,name,value) { enum :: name, #name },

namespace xns {
//
std::string RIP::toString(Type value) {
    static std::unordered_map<Type, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Type, REQUEST,  1)
        ENUM_NAME_VALUE(Type, RESPONSE, 2)    
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", static_cast<uint16_t>(value));
}

std::string RIP::toString(Delay value) {
    static std::unordered_map<Delay, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Delay, INFINITY_, 16)
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", static_cast<uint16_t>(value));
}

ByteBuffer& RIP::read(ByteBuffer& bb) {
    bb.read(type);
    for(;;) {
        if (bb.remains() == 0) break;
        Entry entry;
        bb.read(entry);
        entryList.push_back(entry);
    }
    return bb;
}
ByteBuffer& RIP::write(ByteBuffer& bb) const {
    bb.write(type);
    for(const auto& e: entryList) {
        bb.write(e);
    }
    return bb;
}
std::string RIP::toString() const {
    std::string string;
    for(const auto& e: entryList) {
        string += std_sprintf(" %s", e.toString());
    }
    return std_sprintf("{%s  %s}", toString(type), string.substr(1));
}

void RIP::process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    (void)tx; (void)context;

    RIP transmit;
    auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

    {
        RIP receive;
        rx.read(receive);

        logger.info("RIP  >>  %s", receive.toString());
    }
}

}
