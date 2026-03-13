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
 // Server.h
 //

#pragma once

#include <chrono>
#include <cstdint>
#include <functional>
#include <mutex>
#include <string>
#include <map>
#include <utility>

#include "../util/ThreadQueue.h"
#include "../util/net.h"
#include "../util/ByteBuffer.h"

#include "../xns/XNS.h"
#include "../xns/RIP.h"
#include "../xns/Ethernet.h"
#include "../xns/IDP.h"

#include "../courier/Config.h"

#include "Config.h"

namespace server {
//
struct Session;

using Delay   = xns::RIP::Delay;
using Host    = xns::Host;
using Network = xns::Network;

const uint32_t MIN_PACKET_SIZE = net::minBytesPerEthernetPacket;
const uint32_t MAX_PACKET_SIZE = net::maxBytesPerEthernetPacket;

inline ByteBuffer getByteBuffer() {
    return ByteBuffer(MAX_PACKET_SIZE);
}

struct Routing {
    Network     net;
    Delay       delay;
    std::string name;
};

struct Context {
    using RoutingMap     = std::map<Network, Routing>;
    using NetworkNameMap = std::map<uint32_t, std::string>;
    using HostNameMap    = std::map<uint64_t, std::string>;

    Config          config;
    courier::Config courier;
    net::Driver*    driver;
    // delieved values
    uint64_t        me;
    Network         net;
    RoutingMap      routingMap;
    NetworkNameMap  networkNameMap;
    HostNameMap     hostNameMap;

    Context();

private:
    std::mutex         mutex;
};


struct TransmitData {
    ByteBuffer tx;
    TransmitData(ByteBuffer tx_) : tx(tx_) {}
};
struct ThreadTransmit : public thread_queue::ThreadQueueProcessor<TransmitData> {
    net::Driver& driver;

    ThreadTransmit(net::Driver& driver_) : thread_queue::ThreadQueueProcessor<TransmitData>("ThreadTransmit"), driver(driver_) {}

    void process(const TransmitData& data) override {
        driver.transmit(data.tx.toSpan());
    }
};

struct ReceiveData {
    ByteBuffer rx;
    ReceiveData() : rx(getByteBuffer()) {}
};
struct ThreadReceive : public thread_queue::ThreadQueueProducer<ReceiveData> {
    net::Driver& driver;

    ThreadReceive(net::Driver& driver_) : thread_queue::ThreadQueueProducer<ReceiveData>("ThreadReceive"), driver(driver_) {}

    // produce return true when data has value
    bool produce(ReceiveData& data, std::chrono::milliseconds timeout) override{
        net::Driver::data_type span;
        int ret = driver.receive(span, timeout);
        data.rx.clear();
        // copy data from span to bb
        data.rx.putSpan(span);
        data.rx.flip();
        return ret;
    }
};


//
// Ethernet
//
void process(Session& session, ByteBuffer& rx);  // process ethernet packet


// CallContext for service
namespace SPP { struct Connection; } // forward declaration
struct CallContext {
    Session&         session;
    SPP::Connection& connection;

    CallContext(Session& session_, SPP::Connection& connection_) : session(session_), connection(connection_) {}
};


//
// Clearinghouse3
//
namespace Clearinghouse3 {
//
void enable();
void disable();
}


//
// Socket
//

// allocate and free of user socket -- not wellknown socket
uint16_t allocateSocket();
void     freeSocket(uint16_t value);


//
// Socket Listener
//
using Listener = std::function<void(Session&, const ByteBuffer&)>;

// Set Listener to socket
void listen(uint16_t socket, Listener listener);
inline void listen(xns::Socket socket, Listener listener) {
    listen(std::to_underlying(socket), listener);
}

// Unset Listener from socket
void unlisten(uint16_t socket);
inline void unlisten(xns::Socket socket) {
    unlisten(std::to_underlying(socket));
}

// listener for wellknown socket
void listenerRIP     (Session&, const ByteBuffer&);
void listenerECHO    (Session&, const ByteBuffer&);
void listenerERROR   (Session&, const ByteBuffer&);
void listenerCHS     (Session&, const ByteBuffer&);
void listenerTIME    (Session&, const ByteBuffer&);
void listenerCOURIER (Session&, const ByteBuffer&);


//
// toString()
//

std::string toStringNetwork(uint32_t value);
inline std::string toStringNetwork(Network value) {
    return toStringNetwork(std::to_underlying(value));
}

std::string toStringHost(uint64_t value);
inline std::string toStringHost(Host value) {
    return toStringHost((uint64_t)value);
}

std::string toString(const xns::Ethernet& value);
std::string toString(const xns::RIP& value);
std::string toString(const xns::IDP& value);

}
