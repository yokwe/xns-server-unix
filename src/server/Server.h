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

#include <string>
#include <map>
#include <span>

#include "../util/ThreadQueue.h"
#include "../util/net.h"
#include "../util/ByteBuffer.h"

#include "../xns/Config.h"
#include "../xns/XNS.h"

namespace xns::server {
//
struct TransmitData {
    ByteBuffer tx;
    TransmitData() : tx(ByteBuffer::Net::getInstance(MAX_PACKET_SIZE)) {}
};
struct ThreadTransmit : public thread_queue::ThreadQueueProcessor<TransmitData> {
    net::Driver& driver;

    ThreadTransmit(net::Driver& driver_) : thread_queue::ThreadQueueProcessor<TransmitData>("ThreadTransmit"), driver(driver_) {}

    void process(const TransmitData& data) override {
        auto span = data.tx.toSpan();
        driver.transmit(span);
    }
};

struct ReceiveData {
    ByteBuffer rx;
    ReceiveData() : rx(ByteBuffer::Net::getInstance(MAX_PACKET_SIZE)) {}
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
        if (ret) data.rx.put(span);
        data.rx.flip();
        return ret;
    }
};

struct Routing {
    uint32_t    net;
    uint16_t    delay;
    std::string name;

    Routing(uint32_t net_, uint16_t delay_, const std::string& name_) : net(net_), delay(delay_), name(name_) {}
    Routing() : net(0), delay(0), name("") {}
};

struct Context {
    Config                      config;
    net::Driver*                driver;
    uint64_t                    me;
    uint32_t                    net;
    std::map<uint32_t, Routing> routingMap;

    Context() {
        config = xns::Config::getInstance();
        auto device = net::getDevice(config.server.interface);
        driver = net::getDriver(device);
        me     = config.server.address;
        net    = config.server.net;
        // build routingMap
        for(const auto& e: config.net) {
            Routing routing = Routing(e.net, e.delay, e.name);
            routingMap[e.net] = routing;
        }
    }
};

namespace IDP {
    void process  (ByteBuffer& rx, ByteBuffer& tx, Context& context);
}

namespace RIP {
    void process  (ByteBuffer& rx, ByteBuffer& tx, Context& context);
}
namespace Echo {
    void process  (ByteBuffer& rx, ByteBuffer& tx, Context& context);
}
namespace Error {
    void process  (ByteBuffer& rx, ByteBuffer& tx, Context& context);
}
namespace PEX {
    void process  (ByteBuffer& rx, ByteBuffer& tx, Context& context);
}
namespace SPP {
    void process  (ByteBuffer& rx, ByteBuffer& tx, Context& context);
}
namespace Boot {
    void process  (ByteBuffer& rx, ByteBuffer& tx, Context& context);
}

}
