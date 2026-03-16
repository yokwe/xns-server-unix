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

#include "Session.h"
#include "Packet.h"

namespace server {
//

//
// Connection
//
class Connection {
public:
    Session  session;
    uint16_t srcID;
    uint16_t dstID;

    uint16_t seq;
    uint16_t ack;
    uint16_t alloc;  // alloc == ack

    uint16_t transmitSeq; // use for real transmission
    uint16_t receiveSeq;  // use for send data to client

    uint32_t timeout; // session maintenance

    PacketQueue rxQueue; // hold received packet
    PacketQueue txQueue; // hold transmiting packet

    std::mutex mutex;

    Connection(const Connection& that) :
        session(that.session), srcID(that.srcID), dstID(that.dstID),
        seq(that.seq), ack(that.ack), alloc(that.alloc),
        transmitSeq(that.transmitSeq), receiveSeq(that.receiveSeq),
        timeout(that.timeout), rxQueue(that.rxQueue), txQueue(that.txQueue) {}

    Connection(Connection&& that) :
        session(that.session), srcID(that.srcID), dstID(that.dstID),
        seq(that.seq), ack(that.ack), alloc(that.alloc),
        transmitSeq(that.transmitSeq), receiveSeq(that.receiveSeq),
        timeout(that.timeout), rxQueue(that.rxQueue), txQueue(that.txQueue) {}

    Connection(Session session_, uint16_t srcID_, uint16_t dstID_) :
        session(session_),
        srcID(srcID_),
        dstID(dstID_),
        seq(0),
        ack(0),
        alloc(0),
        transmitSeq(0),
        receiveSeq(0),
        timeout(0) {}
    Connection(Session session) : Connection(session, 0, 0) {}

    std::string toString() {
        return std_sprintf("{%04X  %04X  %d  %d  %d  %d  %d}", srcID, dstID, seq, ack, alloc, transmitSeq, receiveSeq);
    }

    // from client
    // NOTE transmitXXX just add packet to txQueue
    // FIXME needs another thread and server::Session for real transmit
    // FIXME response to system packet for packet retransmition
    void transmitSystem(bool sendAck) {
        Data data;
        transmit(0, true, sendAck, false, false, data);
    }
    void transmitAttention(uint8_t value) {
        Data data{value};
        transmit(0, false, false, true, false, data);
    }
    void transmitUser(uint8_t sst, bool sendAck, bool endOfMessage, Data& data) {
        transmit(sst, false, sendAck, false, endOfMessage, data);
    }

    // from network
    // NOTE receive is just add packet to rxQueue
    // FIXME needs another thread to send client
    // FIXME send system packet to ask packet retransmition
    void receive(const xns::SPP header, const ByteBuffer& body) {
        if (header.system()) {
            receiveSystem(header, body);
        } else {
            receiveUser(header, body);
        }
    }

private:
    void transmit(uint8_t sst, bool system, bool sendAck, bool attention, bool endOfMessage, Data& data);

    void receiveSystem(const xns::SPP header, const ByteBuffer& body);
    void receiveUser  (const xns::SPP header, const ByteBuffer& body);

    bool isBefore(uint16_t a, uint16_t b) {
        if (a < b) {
            // a = 10  b = 20  => true
            return true;
        } else if (a > b) {
            // a = 10     b = 5  => false
            // a = 65530  b = 5  => true
            auto diff = a - b;
            return 30000 < diff;
        } else {
            return false;
        }
    }
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

    std::list<Connection> list;
    std::set<uint32_t>    set;
    std::mutex            mutex;

    void add(Connection& connection) {
        auto key = getKey(connection);
        if (contains(key)) ERROR()

        std::lock_guard<std::mutex> lock(mutex);
        set.emplace(getKey(connection));
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
        return set.size();
    }
};

}
