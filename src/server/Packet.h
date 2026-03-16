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

#include <cstdint>
#include <algorithm>
#include <utility>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

namespace server {
//

using Data = std::vector<uint8_t>;

class Packet {
    static const constexpr uint32_t BIT_SYSTEM         = 0x80'00'0000;
    static const constexpr uint32_t BIT_SEND_ACK       = 0x40'00'0000;
    static const constexpr uint32_t BIT_ATTENTION      = 0x20'00'0000;
    static const constexpr uint32_t BIT_END_OF_MESSAGE = 0x10'00'0000;
    static const constexpr uint32_t BIT_WAIT_ACK       = 0x08'00'0000;
    static const constexpr uint32_t BIT_SST            = 0x00'FF'0000;
    static const constexpr uint32_t BIT_SEQ            = 0x00'00'FFFF;

    static const constexpr uint32_t SHIFT_SST = 16;

    uint32_t flags;

public:
    Data     data;

    Packet(const xns::SPP& header, const ByteBuffer& bb) {
        flags = 0;
        seq(header.seq);
        sst(std::to_underlying(header.sst));
        system(header.system());
        sendAck(header.sendAck());
        attention(header.attention());
        endOfMessage(header.endOfMessage());
        waitAck(!system());
        data = bb.toVector();
    }
    Packet(uint16_t seq_, uint8_t sst_, bool system_, bool sendAck_, bool attention_, bool endOfMessage_, Data& data_) {
        flags = 0;
        seq(seq_);
        sst(sst_);
        system(system_);
        sendAck(sendAck_);
        attention(attention_);
        endOfMessage(endOfMessage_);
        waitAck(!system_);
        data = data_;
    }

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

    // waitAck
    bool waitAck() const {
        return flags & BIT_WAIT_ACK;
    }
    void waitAck(bool value) {
        flags = (flags & ~BIT_WAIT_ACK) | (value ? BIT_WAIT_ACK : 0);
    }

    std::string toString() const {
        return std_sprintf("{%04X  %02X  %s%s%s%s%s  %d}",
            seq(),
            sst(),
            system()       ? "S" : "_",
            sendAck()      ? "S" : "_",
            attention()    ? "A" : "_",
            endOfMessage() ? "E" : "_",
            waitAck()      ? "W" : "_",
            data.size());
    }
};

class PacketQueue {
    std::vector<Packet> vector;
    std::set<uint16_t>  set;
    //       seq

public:
    void add(const Packet& packet) {
        auto seq = packet.seq();
        if (set.contains(seq)) ERROR()

        set.emplace(seq);
//        vector.emplace_back(packet);
        vector.push_back(packet);
    }
    void remove(uint16_t seq) {
        auto pred = [=](Packet& packet) { return packet.seq() == seq; };
        auto i = std::remove_if(vector.begin(), vector.end(), pred);
        if (i == vector.end()) ERROR()

        set.erase(seq);
        vector.erase(i);
    }
    void sort() {
        auto comp = [](auto& a, auto& b) {return a.seq() - b.seq();};
        std::sort(vector.begin(), vector.end(), comp);
    }

    bool contains(uint16_t seq) const {
        return set.contains(seq);
    }

    Packet& get(uint16_t seq) {
        for(auto& e: vector) {
            if (e.seq() == seq) return e;
        }
        ERROR()
    }

    std::set<uint16_t> seqSet() const {
        return set;
    }

    bool empty() const {
        return vector.empty();
    }
    uint32_t size() const {
        return vector.size();
    }
    Packet& front() {
        if (vector.empty()) ERROR()
        return vector.front();
    }
    Packet& back() {
        if (vector.empty()) ERROR()
        return vector.back();
    }
};

}
