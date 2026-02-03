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
 // Server.cpp
 //


#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "Server.h"

namespace server {
//

static Context* context = 0;

Context::Context() {
    courier = courier::Config::getInstance();
    config = Config::getInstance();
    auto device = net::getDevice(config.server.interface);
    driver = net::getDriver(device);
    // delieved values
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
    // build networdkNameMap
    for(const auto& e: config.net) {
        networkNameMap[e.net] = e.name;
    }
    // build hostNameMap
    for(const auto& e: config.host) {
        hostNameMap[e.address] = e.name;
    }
    // set static uglobal variable context
    context = this;
}

std::string toStringNetwork(uint32_t value) {
    if (context == 0) ERROR()
    auto& map = context->networkNameMap;
    return map.contains(value) ? map[value] : std_sprintf("%u", value);
}
std::string toStringHost(uint64_t value) {
    if (context == 0) ERROR()
    auto& map = context->hostNameMap;
    return map.contains(value) ? map[value] : net::toHexaDecimalString(value);
}

}
