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
#include <cstdint>
#include <vector>
#include <mutex>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"
#include "../util/ThreadControl.h"
#include "../util/SimpleQueue.h"

#include "../xns/XNS.h"

#include "../server/Session.h"

#include "Packet.h"
#include "Client.h"

namespace spp {
//
using Session = server::Session;
using Host    = xns::Host;
using Socket  = xns::Socket;

//
// Connection
//
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
    static const constexpr auto     RETRANSMIT_INTERVAL = std::chrono::milliseconds(500);
    static const constexpr uint32_t RETRANSMIT_COUNT_MAX = 20;

    Session  session;

    Host     host;
    Socket   socket;

    uint16_t srcID;  // connectionID of this side
    uint16_t dstID;  // connectionID of other side

    uint16_t seq;

    SeqRange rxRange;
    SeqRange txRange;

    PacketQueue receiveQueue;    // hold received packet
    PacketQueue retransmitQueue; // hold retransmit packet

    uint16_t            clientSeq;
    SimpleQueue<Packet> clientQueue;

    ThreadControl       clientThread;

    Client*   client;

    bool    attentionFlag;
    uint8_t attentionValue;

    Connection(const Connection& that) :
        session(that.session),
        host(that.host), socket(that.socket),
        srcID(that.srcID), dstID(that.dstID),
        seq(that.seq), rxRange(that.rxRange), txRange(that.txRange),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        clientSeq(that.clientSeq), clientQueue(that.clientQueue), client(that.client),
        attentionFlag(that.attentionFlag), attentionValue(that.attentionValue) {}

    Connection(Connection&& that) :
        session(that.session),
        host(that.host), socket(that.socket),
        srcID(that.srcID), dstID(that.dstID),
        seq(that.seq), rxRange(that.rxRange), txRange(that.txRange),
        receiveQueue(that.receiveQueue), retransmitQueue(that.retransmitQueue),
        clientSeq(that.clientSeq), clientQueue(that.clientQueue), client(that.client),
        attentionFlag(that.attentionFlag), attentionValue(that.attentionValue) {}

    Connection(Session session_, uint16_t srcID_, uint16_t dstID_) :
        session(session_),
        host(session.dstHost()), socket(session.dstSocket()),
        srcID(srcID_), dstID(dstID_),
        seq(0),
        clientSeq(0),
        attentionFlag(false), attentionValue(0) {}

    std::string toString() {
        return std_sprintf("{%04X  %04X  %d  %d  %d}", srcID, dstID, seq, txRange.ack, txRange.alloc);
    }

    void set(Client* client);

    // for client
    bool hasAttention();
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
    void remove  (Connection* connection);

    Connection* get(uint16_t srcID, uint16_t dstID);
    Connection* get(const Host& host, uint16_t dstID);
};

inline Connections connections;
}
