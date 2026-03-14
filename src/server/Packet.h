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

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

namespace server {
//

using Data = std::vector<uint8_t>;

class Packet {
    static const uint16_t BIT_END_OF_RECORD = 0x8000;
    static const uint16_t BIT_ATTENTION     = 0x4000;

    union {
        uint32_t u;
        struct {
            uint32_t seq          : 16;
            uint32_t sst          :  8;
            uint32_t system       :  1;
            uint32_t sendAck      :  1;
            uint32_t attention    :  1;
            uint32_t endOfMessage :  1;
            uint32_t waitAck      :  1;  // hint for retrasmission
        };
    } flags;

public:
    Data     data;

    Packet(const xns::SPP& header, const ByteBuffer& bb) :
        Packet(
            header.seq,
            static_cast<uint16_t>(header.sst),
            header.systemPacket(),
            header.sendAck(),
            header.attention(),
            header.endOfMessage(),
            bb.toVector()) {}

    Packet(uint16_t seq, uint8_t sst, bool system, bool sendAck, bool attention, bool endOfMessage, const Data& data_) {
        flags.u            = 0;
        flags.seq          = seq;
        flags.sst          = sst;
        flags.system       = system;
        flags.sendAck      = sendAck;
        flags.attention    = attention;
        flags.endOfMessage = endOfMessage;
        flags.waitAck      = !system;

        data = data_;
    }

    // seq
    uint16_t seq() {
        return flags.seq;
    }
    void seq(uint16_t value) {
        flags.seq = value;
    }

    // sst
    uint8_t sst() {
        return flags.sst;
    }
    void sst(uint8_t value) {
        flags.sst = value;
    }

    // system
    bool system() {
        return flags.system;
    }
    void system(bool value) {
        flags.system = value ? 1 : 0;
    }

    // sendAck
    bool sendAck() {
        return flags.sendAck;
    }
    void sendAck(bool value) {
        flags.sendAck = value ? 1 : 0;
    }

    // attention
    bool attention() {
        return flags.attention;
    }
    void attention(bool value) {
        flags.attention = value ? 1 : 0;
    }

    // endOfMessage
    bool endOfMessage() {
        return flags.endOfMessage;
    }
    void endOfMessage(bool value) {
        flags.endOfMessage = value ? 1 : 0;
    }

    // waitAck
    bool waitAck() {
        return flags.waitAck;
    }
    void waitAck(bool value) {
        flags.waitAck = value ? 1 : 0;
    }

    std::string toString() {
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
    std::vector<Packet> vector;
    std::set<uint16_t>  set;

public:
    Packet& alloc(const xns::SPP& header, const ByteBuffer& bb) {
        // sanity check
        if (contains(header.seq)) ERROR()

        set.emplace(header.seq);
        vector.emplace_back(header, bb);
        return vector.back();
    }
    Packet& alloc(uint16_t seq, uint8_t sst, bool system, bool sendAck, bool attention, bool endOfMessage, const Data& data) {
        // sanity check
        if (contains(seq)) ERROR()

        set.emplace(seq);
        vector.emplace_back(seq, sst, system, sendAck, attention, endOfMessage, data);
        return vector.back();
    }
    void free(uint16_t seq) {
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

    bool contains(uint16_t seq) {
        return set.contains(seq);
    }

    Packet& get(uint16_t seq) {
        for(auto& e: vector) {
            if (e.seq() == seq) return e;
        }
        ERROR()
    }

    std::set<uint16_t> seqSet() {
        return set;
    }

    bool empty() {
        return vector.empty();
    }
    uint32_t size() {
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
