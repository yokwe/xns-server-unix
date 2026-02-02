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

#include "../util/ThreadQueue.h"
#include "../util/net.h"
#include "../util/ByteBuffer.h"

#include "../xns/Config.h"
#include "../xns/XNS.h"
#include "../xns/RIP.h"

#include "../courier/Config.h"

namespace xns::server {
//
using Delay = xns::RIP::Delay;

template <class T>
struct HeaderBody {
    T          header;
    ByteBuffer body = ByteBuffer::Net::getInstance();

    HeaderBody(const T& header_, ByteBuffer& body_) : header(header_), body(body_) {}
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
        if (ret) data.rx.putSpan(span);
        data.rx.flip();
        return ret;
    }
};

struct Routing {
    Network     net;
    Delay       delay;
    std::string name;
};

struct Context {
    courier::Config            courier;
    xns::Config                config;
    net::Driver*               driver;
    uint64_t                   me;
    Network                    net;
    std::map<Network, Routing> routingMap;


    Context() {
        courier = courier::Config::getInstance();
        config = xns::Config::getInstance();
        auto device = net::getDevice(config.server.interface);
        driver = net::getDriver(device);
        me     = config.server.address;
        net    = static_cast<Network>(config.server.net);
        // build routingMap
        for(const auto& e: config.net) {
            auto net = static_cast<Network>(e.net);
            auto delay = static_cast<Delay>(e.delay);

            if (delay == Delay::INFINITY) continue;

            Routing routing(net, delay, e.name);
            routingMap[net] = routing;
        }
    }
};

namespace Ethernet {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}
namespace IDP {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}
namespace RIP {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}
namespace Echo {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}
namespace Error {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}
namespace PEX {
    ByteBuffer process  (ByteBuffer& rx, Context& context);

    ByteBuffer unspec   (ByteBuffer& rx, Context& context);
    ByteBuffer chs      (ByteBuffer& rx, Context& context);
    ByteBuffer teledebug(ByteBuffer& rx, Context& context);
}
namespace SPP {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}

namespace Time {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}
namespace CHS {
    ByteBuffer process  (ByteBuffer& rx, Context& context);
}

}
