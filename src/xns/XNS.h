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

#undef INFINITY

namespace xns {
//
//
// Host
//
class Host {
    uint64_t value;
public:
    static const uint64_t BROADCAST         = 0xFFFF'FFFF'FFFF;
    static const uint64_t BFN_GVWIN_NETBOOT = 0x0000'AA00'0E60;

    Host() : value(0) {}
    Host(uint64_t value_) {
        value = value_;
    }
    operator uint64_t() const {
        return value;
    }

    bool isBroadcas() {
        return value == BROADCAST;
    }

    void read(const ByteBuffer& bb) {
        uint16_t word1;
        uint16_t word2;
        uint16_t word3;
        
        bb.read(word1, word2, word3);

        value = (uint64_t)word1 << 32 | (uint64_t)word2 << 16 | (uint64_t)word3;
    }
    void write(ByteBuffer& bb) const {
        uint16_t word1 = (uint16_t)(value >> 32);
        uint16_t word2 = (uint16_t)(value >> 16);
        uint16_t word3 = (uint16_t)(value >>  0);

        bb.write(word1, word2, word3);
    }
    std::string toString() const;

    bool operator == (const Host& that) const {
        return this->value == that.value;
    }
    bool operator == (uint64_t that) const {
        return this->value == that;
    }
};

//
// Network
//
enum class Network : uint32_t {
    UNKNOWN  = 0x0000'0000,
    ALL      = 0xFFFF'FFFF,
};
std::string toString(Network value);


//
// Socket
//
enum class Socket : uint16_t {
    UNKNOWN              =      0,
    RIP                  =      1,
    ECHO                 =      2,
    ERROR_               =      3,
    ENVOY                =      4,
    COURIER              =      5,
    CHS_OLD              =      7,
    TIME                 =      8,
    BOOT                 =     10,
    DIAG                 =     19,
    CHS                  =     20,
    AUTH                 =     21,
    MAIL                 =     22,
    NET_EXEC             =     23,
    WS_INFO              =     24,
    BINDING              =     28,
    GERM                 =     35,
    TELEDEBUG            =     48,
    MAX_WELLKNOWN_SOCKET =   3000,
    ALL                  = 0xFFFF,
};
inline std::string toString(Socket value) {
    static std::unordered_map<Socket, std::string, ScopedEnumHash> map = {
        {Socket::UNKNOWN,              "UNKNOWN"},
        {Socket::RIP,                  "RIP"},
        {Socket::ECHO,                 "ECHO"},
        {Socket::ERROR_,               "ERROR_"},
        {Socket::ENVOY,                "ENVOY"},
        {Socket::COURIER,              "COURIER"},
        {Socket::CHS_OLD,              "CHS_OLD"},
        {Socket::TIME,                 "TIME"},
        {Socket::BOOT,                 "BOOT"},
        {Socket::DIAG,                 "DIAG"},
        {Socket::CHS,                  "CHS"},
        {Socket::AUTH,                 "AUTH"},
        {Socket::MAIL,                 "MAIL"},
        {Socket::NET_EXEC,             "NET_EXEC"},
        {Socket::WS_INFO,              "WS_INFO"},
        {Socket::BINDING,              "BINDING"},
        {Socket::GERM,                 "GERM"},
        {Socket::TELEDEBUG,            "TELEDEBUG"},
        {Socket::MAX_WELLKNOWN_SOCKET, "MAX_WELLKNOWN_SOCKET"},
        {Socket::ALL,                  "ALL"},
    };
    return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
};

//
// NetworkAddress
//
class NetworkAddress {
public:
    Network network;
    Host    host;
    Socket  socket;

    void read(const ByteBuffer& bb) {
        bb.read(network, host, socket);
    }
    void write(ByteBuffer& bb) const {
        bb.write(network, host, socket);
    }
    std::string toString() const {
        return std_sprintf("%s-%s-%s", xns::toString(network), host.toString(), xns::toString(socket));
    }

    bool operator ==(const NetworkAddress& that) const {
        return this->network == that.network && this->host == that.host && this->socket == that.socket;
    }
};

//
// Operation
//
enum class Operation : uint16_t {
    REQUEST = 1,
    RESPONSE = 2,
};
inline std::string toString(Operation value) {
    static std::unordered_map<Operation, std::string, ScopedEnumHash> map = {
        {Operation::REQUEST,  "REQUEST"},
        {Operation::RESPONSE, "RESPONSE"},
    };
    
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}

//
// Delay
//
enum class Delay : uint16_t {
    INFINITY = 15,
};
inline std::string toString(Delay value) {
    static std::unordered_map<Delay, std::string, ScopedEnumHash> map = {
        {Delay::INFINITY, "INFINITY"},
    };
    
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}

//
// convenience operator
//
inline xns::Socket operator +(const xns::Socket a, const uint16_t b) {
    return static_cast<xns::Socket>(static_cast<uint16_t>(a) + b);
}

}