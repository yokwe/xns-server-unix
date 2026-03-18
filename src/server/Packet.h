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
// Packet.h
//


#pragma once

#include <chrono>
#include <cstdint>
#include <list>
#include <set>
#include <utility>
#include <algorithm>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

namespace server {
//
class Connection;

using Data = std::vector<uint8_t>;

class Packet {
    static const constexpr uint32_t BIT_SYSTEM         = 0x80'00'0000;
    static const constexpr uint32_t BIT_SEND_ACK       = 0x40'00'0000;
    static const constexpr uint32_t BIT_ATTENTION      = 0x20'00'0000;
    static const constexpr uint32_t BIT_END_OF_MESSAGE = 0x10'00'0000;
    static const constexpr uint32_t BIT_SST            = 0x00'FF'0000;
    static const constexpr uint32_t BIT_SEQ            = 0x00'00'FFFF;

    static const constexpr uint32_t SHIFT_SST = 16;

    void setFlags(uint16_t seq, uint8_t sst, bool system, bool sendAck, bool attention, bool endOfMessage) {
        flags = (sst << SHIFT_SST) | seq;
        if (system)       flags |= BIT_SYSTEM;
        if (sendAck)      flags |= BIT_SEND_ACK;
        if (attention)    flags |= BIT_ATTENTION;
        if (endOfMessage) flags |= BIT_END_OF_MESSAGE;
    }

    uint32_t flags;

public:
    std::chrono::steady_clock::time_point timestamp;
    Data     data;

    Packet(const xns::SPP& header, const ByteBuffer& bb) {
        timestamp = std::chrono::steady_clock::now();
        setFlags(header.seq, std::to_underlying(header.sst), header.system(), header.sendAck(), header.attention(), header.endOfMessage());
        data = bb.toVector();
    }
    Packet(uint16_t seq, uint8_t sst, bool system, bool sendAck, bool attention, bool endOfMessage, Data& data_) {
        timestamp = std::chrono::steady_clock::now();
        setFlags(seq, sst, system, sendAck, attention, endOfMessage);
        data = data_;
    }
    
    Packet() {
        timestamp = std::chrono::steady_clock::now();
        flags = 0;
    }

    // Copy
    Packet(const Packet&  that)             = default;
    Packet& operator = (const Packet& that) = default;
    // Move
    Packet(Packet&&  that)             = default;
    Packet& operator = (Packet&& that) = default;

    // seq
    uint16_t seq() const {
        return flags & BIT_SEQ;
    }
    void seq(uint16_t value) {
        flags = (flags & ~BIT_SEQ) | value;
    }

    // sst
    uint8_t sst() const {
        return (flags & BIT_SST) >> SHIFT_SST;
    }
    void sst(uint8_t value) {
        flags = (flags & ~BIT_SST) | (value << SHIFT_SST);
    }

    // system
    bool system() const {
        return flags & BIT_SYSTEM;
    }
    void system(bool value) {
        flags = (flags & ~BIT_SYSTEM) | (value ? BIT_SYSTEM : 0);
    }

    // sendAck
    bool sendAck() const {
        return flags & BIT_SEND_ACK;
    }
    void sendAck(bool value) {
        flags = (flags & ~BIT_SEND_ACK) | (value ? BIT_SEND_ACK : 0);
    }

    // attention
    bool attention() const {
        return flags & BIT_ATTENTION;
    }
    void attention(bool value) {
        flags = (flags & ~BIT_ATTENTION) | (value ? BIT_ATTENTION : 0);
    }

    // endOfMessage
    bool endOfMessage() const {
        return flags & BIT_END_OF_MESSAGE;
    }
    void endOfMessage(bool value) {
        flags = (flags & ~BIT_END_OF_MESSAGE) | (value ? BIT_END_OF_MESSAGE : 0);
    }

    std::string toString() const {
        return std_sprintf("{%04X  %02X  %s%s%s%s  %d}",
            seq(),
            sst(),
            system()       ? "S" : "_",
            sendAck()      ? "S" : "_",
            attention()    ? "A" : "_",
            endOfMessage() ? "E" : "_",
            data.size());
    }
};

class PacketQueue {
    std::list<Packet>  list;
    std::set<uint16_t> set;
    //       seq

    inline static auto RETRANSMIT_INTERVAL = std::chrono::seconds(5);
public:
    void add(const Packet& packet) {
        auto seq = packet.seq();
        if (set.contains(seq)) ERROR()

        set.emplace(seq);
        list.emplace_back(packet);
    }
    void remove(uint16_t seq) {
        static auto pred = [=](Packet& packet) { return packet.seq() == seq; };
        if (!set.contains(seq)) ERROR()

        set.erase(seq);
        std::erase_if(list, pred);
    }

    bool contains(uint16_t seq) const {
        return set.contains(seq);
    }

    Packet& get(uint16_t seq) {
        for(auto& e: list) {
            if (e.seq() == seq) return e;
        }
        ERROR()
    }

    std::set<uint16_t> seqSet() const {
        return set;
    }

    bool empty() const {
        return set.empty();
    }
    uint32_t size() const {
        return set.size();
    }
    Packet& front() {
        if (set.empty()) ERROR()
        return list.front();
    }
    Packet& back() {
        if (set.empty()) ERROR()
        return list.back();
    }

    // iterator support
    auto begin() {
        return list.begin();
    }
    auto end() {
        return list.end();
    }
    auto cbegin() {
        return list.cbegin();
    }
    auto cend() {
        return list.cend();
    }

    using Predicate = std::function<bool(const Packet&)>;
    uint32_t count_if(Predicate pred) {
        return std::count_if(list.begin(), list.end(), pred);
    }

    void retransmit(Connection& connection);
};

}
