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
// Connection.h
//

#pragma once

#include <chrono>
#include <cstdint>
#include <vector>
#include <mutex>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"
#include "../util/ThreadControl.h"
#include "../util/SimpleQueue.h"

#include "../server/Session.h"

#include "Packet.h"
#include "Client.h"

namespace spp {
//
using Session = server::Session;

//
// Connection
//
static inline uint32_t getKey(uint16_t srcID, uint16_t dstID) {
    return (srcID << 16) | dstID;
}
static inline uint32_t getKey(const xns::SPP& rxHeader) {
    return getKey(rxHeader.dstID, rxHeader.srcID); // intentionally reverse src and dst
}

struct SeqRange {
    uint16_t ack;
    uint16_t alloc;

    SeqRange() : ack(0), alloc(0) {}
    SeqRange(uint16_t ack_, uint16_t alloc_) : ack(ack_), alloc(alloc_) {}

    // COPY
    SeqRange(const SeqRange&)              = default;
    SeqRange& operator = (const SeqRange&) = default;

    // before return true when seq is before ack
    bool before(uint16_t seq) {
        return xns::SPP::isBefore(seq, ack);
    }
    // within return true when seq is in [ack .. alloc]
    bool within(uint16_t seq) {
        return !(xns::SPP::isBefore(seq, ack) || xns::SPP::isBefore(alloc, seq));
    }
};

class Connection {
public:
    static const constexpr int NO_ATTENTION = -1;
    static const constexpr auto RETRANSMIT_INTERVAL = std::chrono::milliseconds(500);

    enum class State {
        NEW, OPEN, CLOSE, CLOSE_REPLY,
    };
    std::string toString(State value) {
        static std::unordered_map<State, std::string, ScopedEnumHash> map = {
            {State::NEW,         "NEW"},
            {State::OPEN,        "OPEN"},
            {State::CLOSE,       "CLOSE"},
            {State::CLOSE_REPLY, "CLOSE_REPLY"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
    }

    State    state;
    Session  session;

    uint16_t srcID;
    uint16_t dstID;
    uint32_t key;

    uint16_t seq;

    SeqRange rxrange;
    SeqRange txrange;

    PacketQueue receiveQueue;    // hold received packet
    PacketQueue retransmitQueue; // hold retransmit packet

    uint16_t            clientSeq;
    SimpleQueue<Packet> clientQueue;
    ThreadControl       clientThread;

    Client*   client;

    int attentionValue;

    Connection(const Connection& that) :
        state(that.state), session(that.session),
        srcID(that.srcID), dstID(that.dstID), key(that.key),
        seq(that.seq), rxrange(that.rxrange), txrange(that.txrange),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        clientSeq(0), clientQueue(that.clientQueue), client(that.client),
        attentionValue(that.attentionValue) {}

    Connection(Connection&& that) :
        state(that.state), session(that.session),
        srcID(that.srcID), dstID(that.dstID), key(that.key),
        seq(that.seq), rxrange(that.rxrange), txrange(that.txrange),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        clientSeq(that.clientSeq), clientQueue(that.clientQueue), client(that.client),
        attentionValue(that.attentionValue) {}

    Connection(Session session_, uint16_t srcID_, uint16_t dstID_) :
        state(State::NEW), session(session_),
        srcID(srcID_), dstID(dstID_), key(getKey(srcID_, dstID_)),
        seq(0),
        clientSeq(0), client(0),
        attentionValue(NO_ATTENTION) {}

    std::string toString() {
        return std_sprintf("{%s  %08X  %d  %d  %d  %d  %d}", toString(state), key, seq, txrange.ack, txrange.alloc, clientSeq, clientQueue.size());
    }

    void set(Client* client);

    // for client
    bool closed() {
        return state == State::CLOSE_REPLY;
    }
    int attention(); // return attention value
    void retransmit(bool snedAck = false);

    void transmitUser(bool sendAck, bool endOfMessage, SST sst, Data& data) {
        transmit(sendAck, false, endOfMessage, sst, data);
        queue(sendAck, false, endOfMessage, sst, data);
        seq++;
    }
    void transmitUser(bool sendAck, bool endOfMessage, SST sst) {
        Data data;
        transmit(sendAck, false, endOfMessage, sst, data);
        queue(sendAck, false, endOfMessage, sst, data);
        seq++;
    }
    void transmitUser(bool sendAck, bool endOfMessage, SST sst, ByteBuffer& bb) {
        auto data = bb.toVector();
        transmit(sendAck, false, endOfMessage, sst, data);
        queue(sendAck, false, endOfMessage, sst, data);
        seq++;
    }
    void transmitAttention(uint8_t value) {
        Data data = { value };
        queue(false, true, false, SST::DATA, data);
        transmit(false, true, false, SST::DATA, data);
        seq++;
    }
    void transmitSystemAck() {
        Data data;
        transmitRaw(true, false, false, false, SST::DATA, data);    
    }

    // from network
    void receive(const xns::SPP& header, const ByteBuffer& body);

private:
    void queue   (bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data);
    void transmitRaw(bool system, bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data);
    void transmit(bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data) {
        transmitRaw(false, sendAck, attention, endOfMessage, sst, data);
    }
    void transmitRaw(Packet& packet);

    void receiveDataBulk  (const xns::SPP& header, const ByteBuffer& body);
    void receiveClose     (const xns::SPP& header, const ByteBuffer& body);
    void receiveCloseReply(const xns::SPP& header, const ByteBuffer& body);

};


//
// Connections
//
struct Connections {
    using VECTOR = std::vector<Connection*>;

    static const constexpr uint32_t SIZE  = 10;
    static const constexpr uint32_t DELTA = 10;

    VECTOR      vector;
    std::mutex  mutex;

    Connections(uint32_t size = SIZE) : vector(size, 0) {}

    void add     (Connection* connection);
    void remove  (uint32_t key);
    bool contains(uint32_t key);

    Connection& get(uint32_t key);
    uint32_t size();

    uint16_t newSrcID(uint16_t dstID);
};

inline Connections connections;
}
