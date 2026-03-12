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
#include <unordered_map>

#include "../util/Util.h"

#include "../xns/XNS.h"
#include "../xns/SPP.h"

#include "Server.h"

namespace server::SPP {
//
using NetworkAddress = xns::NetworkAddress;

inline const constexpr uint64_t GRACE_PERIOD_NEW_SESSION = 10; // unit is second
inline const constexpr uint64_t GRACE_PERIOD_EXPIRATION  = 60; // unit is second

inline const constexpr uint32_t MAX_DATA_LENGTH = 534;  // maximum length of SPP body

struct Connection {
    static inline uint64_t newExpirationTime() {
        return Util::getSecondsSinceEpoch() + GRACE_PERIOD_NEW_SESSION;
    }
    static inline uint64_t nextExpirationTime() {
        return Util::getSecondsSinceEpoch() + GRACE_PERIOD_EXPIRATION;
    }

    enum class State {
        NEW,
        DATA,
        CLOSING,
        CLOSED,
    };
    inline std::string toString(State value) {
        static std::unordered_map<State, std::string, ScopedEnumHash> map = {
            {State::NEW,     "NEW"},
            {State::DATA,    "DATA"},
            {State::CLOSING, "CLOSING"},
            {State::CLOSED,  "CLOSED"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
    };

    State    state;
    uint64_t expirationTime;
    uint16_t srcSocket;
    uint16_t srcID;   // connection id self
    uint16_t dstID;   // connection id other end

    // sending information
    uint16_t txseq;
    // sequence number of sending packet -- transmit
    // for user packet sequqnce number of the packet
    // for system packe sequence number of next packet

    // receiving information
    uint16_t txack;
    // sequence number of next expecting packet -- receive
    uint16_t txalloc;
    // sequence number of accepting packet -- receive
    // [ack .. alloc] is accepting packe

    // received information
    uint16_t rxseq;
    uint16_t rxack;
    uint16_t rxalloc;

    Connection() :
        state(State::CLOSED), expirationTime(0), srcSocket(0), srcID(0), dstID(0),
        txseq(0), txack(0), txalloc(0),
        rxseq(0), rxack(0), rxalloc(0) {}

    Connection(uint16_t srcSocket_, uint16_t srcID_, const xns::SPP& rxHeader) :
        state(State::NEW), expirationTime(newExpirationTime()),
        srcSocket(srcSocket_), srcID(srcID_), dstID(rxHeader.srcID),
        txseq(0), txack(0), txalloc(0),
        rxseq(rxHeader.seq), rxack(rxHeader.ack), rxalloc(rxHeader.alloc) {}

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
        return std_sprintf("{%s  %04X  %04X  %04X  {%d  %d  %d}  {%d  %d  %d}}",
            toString(state), srcSocket, srcID, dstID, // must be toString(state)
            txseq, txack, txalloc,
            rxseq, rxack, rxalloc);
    }


    void writePacket() {
        txseq++;
    }
    void readPacket() {
        txack++;
        txalloc++;
    }
    xns::SPP spp(xns::SPP::SST sst, bool systemPacket = false, bool sendAck = false) {
        xns::SPP ret;

        ret.systemPacket(systemPacket);
        ret.sendAck(sendAck);

        ret.sst   = sst;
        ret.srcID = srcID;
        ret.dstID = dstID;
        ret.seq   = txseq;     // sequence of this packet
        ret.ack   = txack;     // sequence number of the next expected packet  OR  sequence number before this number was acknowledged
        ret.alloc = txalloc;   // sequence number

        return ret;
    }

    xns::SPP sppData(bool systemPacket = false, bool sendAck = false) {
        return spp(xns::SPP::SST::DATA, systemPacket, sendAck);
    }
    xns::SPP sppBuild(bool systemPacket = false, bool sendAck = false) {
        return spp(xns::SPP::SST::BULK, systemPacket, sendAck);
    }
    xns::SPP sppClose(bool systemPacket = false, bool sendAck = false) {
        return spp(xns::SPP::SST::CLOSE, systemPacket, sendAck);
    }
    xns::SPP sppCloseReply(bool systemPacket = false, bool sendAck = false) {
        return spp(xns::SPP::SST::CLOSE_REPLY, systemPacket, sendAck);
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

    void maintain();

    uint32_t size() {
        return (uint32_t)map.size();
    }

    Connection& allocate(uint16_t srcSocket, const xns::SPP& spp);
    void        update(const xns::SPP& spp);

    void        free(uint32_t key);
    bool        contains(uint32_t key);
    Connection& get(uint32_t key);
};

void listenerSPP  (server::Session&, const ByteBuffer&);

using Listener = std::function<void(Session&, const ByteBuffer&)>;

void listen(uint16_t socket, Listener listener);
void unlisten(uint16_t socket);

inline void listen(xns::Socket socket, Listener listener) {
    server::SPP::listen(std::to_underlying(socket), listener);
}
inline void unlisten(xns::Socket socket) {
    server::SPP::unlisten(std::to_underlying(socket));
}

}
