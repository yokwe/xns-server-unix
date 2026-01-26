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
 // XNS.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/net.h"

#include "Config.h"

#include "XNS.h"

#undef  ENUM_NAME_VALUE
#define ENUM_NAME_VALUE(enum,name,value) { enum :: name, #name },

namespace xns {
//
static const Config* myConfig = 0;

void initialize(const Config* config) {
    myConfig = config;
}

std::string hostName(uint64_t address) {
    for(const auto& e: myConfig->host) {
        if (e.address == address) return e.name;
    }
    return net::toHexaDecimalString(address);
}
std::string toString(Network network) {
    auto net = static_cast<uint32_t>(network);
    for(const auto& e: myConfig->net) {
        if (e.net == net) return e.name;
    }
    return std_sprintf("%d", net);
}
std::string toString(Socket value) {
    static std::unordered_map<Socket, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Socket, UNKNOWN,    0)
        ENUM_NAME_VALUE(Socket, RIP,        1)
        ENUM_NAME_VALUE(Socket, ECHO,       2)
        ENUM_NAME_VALUE(Socket, ERROR_,     3)
        ENUM_NAME_VALUE(Socket, ENVOY,      4)
        ENUM_NAME_VALUE(Socket, COURIER,    5)
        ENUM_NAME_VALUE(Socket, CHS_OLD,    7)
        ENUM_NAME_VALUE(Socket, TIME,       8)
        ENUM_NAME_VALUE(Socket, BOOT,      10)
        ENUM_NAME_VALUE(Socket, DIAG,      19)
        ENUM_NAME_VALUE(Socket, CHS,       20)
        ENUM_NAME_VALUE(Socket, AUTH,      21)
        ENUM_NAME_VALUE(Socket, MAIL,      22)
        ENUM_NAME_VALUE(Socket, NET_EXEC,  23)
        ENUM_NAME_VALUE(Socket, WS_INFO,   24)
        ENUM_NAME_VALUE(Socket, BINDING,   28)
        ENUM_NAME_VALUE(Socket, GERM,      35)
        ENUM_NAME_VALUE(Socket, TELEDEBUG, 48)
        ENUM_NAME_VALUE(Socket, ALL,       0xFFFF)
    };
    return map.contains(value) ? map[value] : std_sprintf("%04X", static_cast<uint16_t>(value));
}

}
