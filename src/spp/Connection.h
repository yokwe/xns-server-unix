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

#include "../xns/XNS.h"

#include "../server/Session.h"

#include "Packet.h"
#include "Client.h"

namespace spp {
//
using Session = server::Session;
using Socket  = xns::Socket;

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

    SeqRange() : ack(0), alloc(3) {}
    SeqRange(uint16_t ack_, uint16_t alloc_) : ack(ack_), alloc(alloc_) {}

    // COPY
    SeqRange(const SeqRange&)              = default;
    SeqRange& operator = (const SeqRange&) = default;

    // postfix ++ operator
    SeqRange operator++(int) {
        auto ret = *this;
        ack++;
        alloc++;
        return ret;
    }

    // before return true when seq is before ack
    bool isBefore(uint16_t seq) {
        return xns::SPP::isBefore(seq, ack);
    }
    // contains return true when seq is within [ack .. alloc]
    bool contains(uint16_t seq) {
        return !(xns::SPP::isBefore(seq, ack) || xns::SPP::isBefore(alloc, seq));
    }
};
class Connection {
public:
    static const constexpr int NO_ATTENTION = -1;
    static const constexpr auto RETRANSMIT_INTERVAL = std::chrono::milliseconds(500);

    Session  session;

    Socket   socket;
    uint16_t srcID;
    uint16_t dstID;
    uint32_t key;

    uint16_t seq;

    SeqRange rxRange;
    SeqRange txRange;

    PacketQueue receiveQueue;    // hold received packet
    PacketQueue retransmitQueue; // hold retransmit packet

    ThreadControl       clientThread;

    Client*   client;

    int attentionValue;

    Connection(const Connection& that) :
        session(that.session),
        socket(that.socket), srcID(that.srcID), dstID(that.dstID), key(that.key),
        seq(that.seq), rxRange(that.rxRange), txRange(that.txRange),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        client(that.client),
        attentionValue(that.attentionValue) {}

    Connection(Connection&& that) :
        session(that.session),
        socket(that.socket), srcID(that.srcID), dstID(that.dstID), key(that.key),
        seq(that.seq), rxRange(that.rxRange), txRange(that.txRange),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        client(that.client),
        attentionValue(that.attentionValue) {}

    Connection(Session session_, Socket(socket_), uint16_t srcID_, uint16_t dstID_) :
        session(session_),
        socket(socket_), srcID(srcID_), dstID(dstID_), key(getKey(srcID_, dstID_)),
        seq(0),
        attentionValue(NO_ATTENTION) {}

    std::string toString() {
        return std_sprintf("{%08X  %d  %d  %d}", key, seq, txRange.ack, txRange.alloc);
    }

    void set(Client* client);

    // for client
    int  attention(); // return attention value
    void retransmit(bool snedAck = false);
    void maintainRetransmit();

    void transmitUser(bool sendAck, bool endOfMessage, SST sst, Data& data) {
        transmit(sendAck, false, endOfMessage, sst, data);
        queue   (sendAck, false, endOfMessage, sst, data);
        seq++;
    }
    void transmitUser(bool sendAck, bool endOfMessage, SST sst) {
        Data data;
        transmitUser(sendAck, endOfMessage, sst, data);
    }
    void transmitUser(bool sendAck, bool endOfMessage, SST sst, ByteBuffer& bb) {
        Data data = bb.toVector();
        transmitUser(sendAck, endOfMessage, sst, data);
    }
    void transmitAttention(uint8_t value) {
        Data data = { value };
        transmit(false, true, false, SST::DATA, data);
        queue   (false, true, false, SST::DATA, data);
        seq++;
    }
    void transmitSystemAck() {
        transmitRaw(true, false, false, false, SST::DATA);    
    }
    void transmitClose() {
        transmitRaw(false, false, false, false, SST::CLOSE);
    }
    void transmitCloseReply() {
        transmitRaw(false, false, false, false, SST::CLOSE_REPLY);
    }

    // from network
    void receive(const xns::SPP& header, const ByteBuffer& body);

private:
    void queue   (bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data);
    void transmit(bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data) {
        transmitRaw(false, sendAck, attention, endOfMessage, sst, data);
    }

    void transmitRaw(bool system, bool sendAck, bool attention, bool endOfMessage, SST sst, Data& data);
    void transmitRaw(bool system, bool sendAck, bool attention, bool endOfMessage, SST sst) {
        Data data;
        transmitRaw(system, sendAck, attention, endOfMessage, sst, data);
    }
    
    void transmitRaw(Packet& packet);

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

    Connection* getByDstID(uint16_t dstID);
};

inline Connections connections;
}
