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

#include <cstdint>
#include <list>
#include <mutex>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"
#include "../util/ThreadControl.h"
#include "../util/SimpleQueue.h"

#include "../server/Session.h"

#include "Packet.h"
#include "ConnectionClient.h"

namespace spp {
//
using Session = server::Session;

//
// Connection
//
class Connection {
public:
    static const constexpr int NO_ATTENTION = -1;
    static const constexpr auto RETRANSMIT_INTERVAL = std::chrono::seconds(5);

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

    uint16_t seq;
    uint16_t ack;
    uint16_t alloc;  // alloc == ack

    PacketQueue receiveQueue{4};     // hold received packet
    PacketQueue retransmitQueue{10}; // hold retransmit packet

    uint16_t            clientSeq;
    SimpleQueue<Packet> clientQueue;
    ThreadControl       clientThread;

    std::shared_ptr<ConnectionClient> client;

    int attentionValue;

    Connection(const Connection& that) :
        state(that.state), session(that.session), srcID(that.srcID), dstID(that.dstID),
        seq(that.seq), ack(that.ack), alloc(that.alloc),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        clientSeq(0), clientQueue(that.clientQueue), client(that.client),
        attentionValue(that.attentionValue) {}

    Connection(Connection&& that) :
        state(that.state), session(that.session), srcID(that.srcID), dstID(that.dstID),
        seq(that.seq), ack(that.ack), alloc(that.alloc),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        clientSeq(that.clientSeq), clientQueue(that.clientQueue), client(that.client),
        attentionValue(that.attentionValue) {}

    Connection(Session session_, uint16_t srcID_, uint16_t dstID_) :
        state(State::NEW), session(session_), srcID(srcID_), dstID(dstID_),
        seq(0), ack(0), alloc(0),
        clientSeq(0), client(0),
        attentionValue(NO_ATTENTION) {}

    std::string toString() {
        return std_sprintf("{%s  %04X  %04X  %d  %d  %d  %d  %d}", toString(state), srcID, dstID, seq, ack, alloc, clientSeq, clientQueue.size());
    }

    void set(std::shared_ptr<ConnectionClient> client);

    // from client
    void transmitSystem(bool sendAck) {
        Data data;
        transmitAndQueue(true, sendAck, false, false, SST::DATA, data);
    }
    void transmitAttention(uint8_t value) {
        Data data{value};
        transmitAndQueue(false, false, true, false, SST::DATA, data);
    }
    void transmitUser(bool sendAck, bool endOfMessage, SST sst, Data& data) {
        transmitAndQueue(false, sendAck, false, endOfMessage, sst, data);
    }
    void transmitUser(bool sendAck, bool endOfMessage, SST sst, ByteBuffer& bb) {
        auto data = bb.toVector();
        transmitAndQueue(false, sendAck, false, endOfMessage, sst, data);
    }

    // from network
    void receive(const xns::SPP& header, const ByteBuffer& body);

    void retransmit();

    void removeAcknowledged(uint16_t seq);

    int attention();

    bool closed() {
        return state == State::CLOSE_REPLY;
    }

private:
    void transmitAndQueue (bool system, bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data);
    void transmit         (bool system, bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data);

    void receiveSystem    (const xns::SPP& header, const ByteBuffer& body);
    void receiveDataBulk  (const xns::SPP& header, const ByteBuffer& body);
    void receiveClose     (const xns::SPP& header, const ByteBuffer& body);
    void receiveCloseReply(const xns::SPP& header, const ByteBuffer& body);

};


//
// Connections
//
struct Connections {
    static inline uint32_t getKey(const xns::SPP& rxHeader) {
        return getKey(rxHeader.dstID, rxHeader.srcID); // intentionally reverse src and dst
    }
    static inline uint32_t getKey(const Connection& connection) {
        return getKey(connection.srcID, connection.dstID);
    }
    static inline uint32_t getKey(uint16_t srcID, uint16_t dstID) {
        return (srcID << 16) | dstID;
    }

    ThreadControl threadControl;
    void start();
    void run();

    std::list<Connection> list;
    std::set<uint32_t>    set;
    std::mutex            mutex;

    void add(Connection& connection) {
        auto key = getKey(connection);
        if (contains(key)) ERROR()

        std::lock_guard<std::mutex> lock(mutex);
        set.emplace(key);
        list.emplace_back(connection);
    }
    
    void remove(uint32_t key) {
        static auto pred = [=](Connection& e){return key == getKey(e);};

        std::lock_guard<std::mutex> lock(mutex);
        set.erase(key);
        auto count = std::erase_if(list, pred);
        if (count == 0) ERROR()
    }

    bool contains(uint32_t key) {
        std::lock_guard<std::mutex> lock(mutex);
        return set.contains(key);
    }
    Connection& get(uint32_t key) {
        std::lock_guard<std::mutex> lock(mutex);
        for(auto& e: list) {
            if (key == getKey(e)) return e;
        }
        ERROR()
    }
    uint32_t size() {
        std::lock_guard<std::mutex> lock(mutex);
        return set.size();
    }
};

}
