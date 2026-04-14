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
#include <functional>
#include <mutex>
#include <list>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

namespace spp {
//
// function alias
constexpr auto isBefore = xns::SPP::isBefore;

// type alias
using Clock      = std::chrono::steady_clock;
using Data       = std::vector<uint8_t>;
using SST        = xns::SPP::SST;

// forward declaration
class Connection;


class Packet {
public:
    uint8_t  control; // Control Bit
    SST      sst;     // Sub System Type
    uint16_t seq;
    Data     data;

    Packet(const xns::SPP& header, const ByteBuffer& bb) :
        control(header.control), sst(header.sst), seq(0), data(bb.toVector()) {}

    Packet(bool system_, bool sendAck_, bool attention_, bool endOfMessage_, SST sst_, uint16_t seq_, Data data_) :
        control(0), sst(sst_), seq(seq_), data(data_) {
        system(system_);
        sendAck(sendAck_);
        attention(attention_);
        endOfMessage(endOfMessage_);
    }
    
    Packet() : control(0), sst(SST::DATA), seq(0) {}

    // Copy
    Packet(const Packet&  that)             = default;
    Packet& operator = (const Packet& that) = default;

    // Move
    Packet(Packet&&  that)             = default;
    Packet& operator = (Packet&& that) = default;

    xns::SPP toSPP(uint16_t srcID_, uint16_t dstID_, uint16_t ack_, uint16_t alloc_) {
        return xns::SPP(control, sst, srcID_, dstID_, seq, ack_, alloc_);
    }

    bool system() const {
        return control & BIT_SYSTEM;
    }
    bool sendAck() const {
        return control & BIT_SEND_ACK;
    }
    bool attention() const {
        return control & BIT_ATTENTION;
    }
    bool endOfMessage() const {
        return control & BIT_END_OF_MESSAGE;
    }

    void system(bool newValue) {
        control = (control & ~BIT_SYSTEM)         | (newValue ? BIT_SYSTEM : 0);
    }
    void sendAck(bool newValue) {
        control = (control & ~BIT_SEND_ACK)       | (newValue ? BIT_SEND_ACK : 0);
    }
    void attention(bool newValue) {
        control = (control & ~BIT_ATTENTION)      | (newValue ? BIT_ATTENTION : 0);
    }
    void endOfMessage(bool newValue) {
        control = (control & ~BIT_END_OF_MESSAGE) | (newValue ? BIT_END_OF_MESSAGE : 0);
    }

    std::string toString() const {
        return std_sprintf("{%s%s%s%s  %s  %d  (%d)}",
            system()       ? "S" : "_",
            sendAck()      ? "S" : "_",
            attention()    ? "A" : "_",
            endOfMessage() ? "E" : "_",
            xns::SPP::toString(sst),
            seq,
            data.size());
    }

    friend auto operator<=>(const Packet& a, const Packet& b) {
        return xns::SPP::strong_order_seq(a.seq, b.seq);
    }

private:
    // format of control
    //   bit 0  system packet
    //   bit 1  sent acknowledgement
    //   bit 2  attention
    //   bit 3  end of message
    static const constexpr uint8_t BIT_SYSTEM         = 0x80;
    static const constexpr uint8_t BIT_SEND_ACK       = 0x40;
    static const constexpr uint8_t BIT_ATTENTION      = 0x20;
    static const constexpr uint8_t BIT_END_OF_MESSAGE = 0x10;
};


class PacketQueue {
    using LIST   = std::list<Packet>;
    using SEQVEC = std::vector<uint16_t>;

    int         count;
    LIST        list;
    std::mutex  mutex;

    inline SEQVEC seqVec() {
        SEQVEC ret;
        ret.reserve(list.size());
        for(auto& e: list) {
            ret.push_back(e.seq);
        }
        return ret;
    }
public:
    PacketQueue() : count(0), list() {}
    PacketQueue(const PacketQueue& that) : count(that.count), list(that.list) {}

    bool     contains(uint16_t seq);
    SEQVEC   add(const Packet& packet);
    bool     get(uint16_t seq, Packet& packet);

    void     clear();
    uint32_t size() {
        return count;
    }
    bool     empty() {
        return count == 0;
    }

    using MapFunction = std::function<void(Packet&)>;
    void map(MapFunction function);

    using MapDeleteFunction = std::function<bool(Packet&)>;
    void mapDelete(MapDeleteFunction function);

};

}
