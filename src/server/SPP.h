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
 // SPP.h
 //

#pragma once

#include <cstdint>
#include <list>
#include <unordered_map>

#include "../util/Util.h"

#include "../xns/SPP.h"

#include "Server.h"

namespace server::SPP {
//
inline const constexpr uint64_t GRACE_PERIOD_NEW_SESSION = 10; // unit is second
inline const constexpr uint64_t GRACE_PERIOD_EXPIRATION  = 60; // unit is second

struct Connection {
    static inline uint64_t newExpirationTime() {
        return Util::getSecondsSinceEpoch() + GRACE_PERIOD_NEW_SESSION;
    }
    static inline uint64_t nextExpirationTime() {
        return Util::getSecondsSinceEpoch() + GRACE_PERIOD_EXPIRATION;
    }

    uint64_t expirationTime;
    uint16_t socket;

    uint16_t srcID;   // connection id self
    uint16_t dstID;   // connection id other end
    uint16_t seq;
    uint16_t ack;
    uint16_t alloc;

    Connection(uint16_t socket_, uint16_t srcID_, uint16_t dstID_) :
        expirationTime(newExpirationTime()), socket(socket_), srcID(srcID_), dstID(dstID_), seq(0), ack(0), alloc(0) {}
    
    void updateExpirationTime() {
        expirationTime = nextExpirationTime();
    }
    bool expired(uint64_t now) {
        return expirationTime < now;
    }

    auto operator <=>(const Connection& that) {
        return this->srcID <=> that.srcID;
    }

    std::string toString() {
        return std_sprintf("{%5d  %04X  %04X  %d  %d  %d}", socket, srcID, dstID, seq, ack, alloc);
    }
};

struct Connections {
    std::unordered_map<uint32_t, Connection> map;

    static inline uint32_t getKey(const xns::SPP& rxHeader) {
        return getKey(rxHeader.dstID, rxHeader.srcID); // intentionally reverse src and dst
    }
    static inline uint32_t getKey(const Connection& connection) {
        return getKey(connection.srcID, connection.dstID);
    }
    static inline uint32_t getKey(uint16_t srcID, uint16_t dstID) {
        return (srcID << 16) | dstID;
    }
public:
    void maintain();

    uint32_t size() {
        return (uint32_t)map.size();
    }

    Connection allocate(uint16_t socket, const xns::SPP& spp);
    void free(const xns::SPP& spp);
    bool contains(const xns::SPP& spp);

    void update(const xns::SPP& spp);
    Connection get(const xns::SPP& spp);
};


}
