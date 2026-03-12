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
#include <unordered_map>
#include <utility>

#include "../util/ThreadQueue.h"
#include "../util/net.h"
#include "../util/ByteBuffer.h"

#include "../xns/XNS.h"
#include "../xns/RIP.h"
#include "../xns/Ethernet.h"
#include "../xns/IDP.h"
#include "../xns/Error.h"
#include "../xns/PEX.h"

#include "../courier/Config.h"

#include "SPP.h"

#include "Config.h"

namespace server {
//
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

struct Session {
    using steady_clock = std::chrono::steady_clock;
    Context&                 context;
    ThreadTransmit&          threadTransmit;
    steady_clock::time_point startTime;

    // received headers
    xns::Ethernet rxEthernet;
    xns::IDP      rxIDP;
    xns::PEX      rxPEX;
    xns::SPP      rxSPP;

    Session(Context& context_, ThreadTransmit& threadTransmit_) :
        context(context_),
        threadTransmit(threadTransmit_),
        startTime(std::chrono::steady_clock::now()) {}

    template<typename T>
    uint64_t duration() {
        return std::chrono::duration_cast<T>(steady_clock::now() - startTime).count();
    }
    uint64_t durationMilli() {
        return duration<std::chrono::milliseconds>();
    }

    void send(const xns::Ethernet& header, const ByteBuffer& body);
    void send(const xns::IDP&      header, const ByteBuffer& body);

    void send(const xns::SPP&      header, const ByteBuffer& body);
    void send(const xns::SPP&      header) {
        send(header, ByteBuffer{});
    }

    void sendEther(const ByteBuffer& body);
    void sendIDP  (const ByteBuffer& body);
    void sendError(xns::Error::ErrorNumber errorNumber, uint16_t errorParameter = 0);
    void sendPEX(const ByteBuffer& body);
};

// CallContext for service
struct CallContext {
    Session&         session;
    SPP::Connection& connection;

    CallContext(Session& session_, SPP::Connection& connection_) : session(session_), connection(connection_) {}
};


// create IDP not wellknown socket
uint16_t allocateSocket();
void     freeSocket(uint16_t value);


void listenerRIP  (Session&, ByteBuffer&);
void listenerECHO (Session&, ByteBuffer&);
void listenerERROR(Session&, ByteBuffer&);
void listenerTIME (Session&, ByteBuffer&);
void listenerCHS  (Session&, ByteBuffer&);


class Server {
public:
    using Listener = std::function<void(Session&, ByteBuffer&)>;

    void listen(uint16_t socket, Listener listener);
    void unlisten(uint16_t socket);

    void listen(xns::Socket socket, Listener listener) {
        listen(std::to_underlying(socket), listener);
    }
    void unlisten(xns::Socket socket) {
        unlisten(std::to_underlying(socket));
    }

    void process(Session& session, ByteBuffer& rx); // for ethernet packet

private:
    std::unordered_map<uint16_t, Listener> listenerMap;
};


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
