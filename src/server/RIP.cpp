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
 // RIP.cpp
 //

#include <unordered_map>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/RIP.h"

#include "Server.h"

namespace xns::server::RIP {
//
using RIP     = xns::RIP;
using Delay   = xns::RIP::Delay;
using Type    = xns::RIP::Type;
using Network = xns::Network;
//
const auto MAX_PACKET_SIZE = xns::MAX_PACKET_SIZE;

static RIP request(RIP& rxHeader, Context& context) {
    logger.info("## %s", __func__);
    RIP txHeader;
    txHeader.type = Type::RESPONSE;
    for(const auto& e: rxHeader.entryList) {
        if (e.network == Network::ALL && e.delay == Delay::INFINITY) {
            for(const auto& [key, value] : context.routingMap) {
                txHeader.entryList.emplace_back(value.net, value.delay);
            }
        } else {
            if (context.routingMap.contains(e.network)) {
                const auto& entry = context.routingMap[e.network];
                txHeader.entryList.emplace_back(entry.net, entry.delay);
            }
        }
    }
    return txHeader;
}
RIP response(RIP& rxHeader, Context& context) {
    logger.info("## %s", __func__);
    RIP txHeader;
    // update context.routingMap
    for(const auto& e: rxHeader.entryList) {
        auto net = e.network;
        if (context.routingMap.contains(net)) {
            if (context.routingMap[net].delay != e.delay) {
                // update delay
                context.routingMap[net].delay = e.delay;
            }
        } else {
            // add entry
            auto name = std_sprintf("NET_%d", static_cast<uint32_t>(e.network));
            context.routingMap[net] = Routing(e.network, e.delay, name);
        }
    }

    return txHeader;
}

static std::unordered_map<RIP::Type, RIP (*)(RIP&, Context&)> map {
    {RIP::Type::REQUEST,  request},
    {RIP::Type::RESPONSE, response},
};


ByteBuffer process  (ByteBuffer& rx, Context& context) {
    RIP rxHeader;
    rx.read(rxHeader);
    auto rxbb = rx.rangeRemains();

    logger.info("RIP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    // sanity check
    if (!rxbb.empty()) ERROR();

    auto txHeader = map[rxHeader.type](rxHeader, context);
    auto tx = ByteBuffer::Net::getInstance(MAX_PACKET_SIZE);

    if (rxHeader.type == Type::REQUEST) {
        tx.write(txHeader);
        logger.info("RIP  <<  %s", txHeader.toString());
    }

    return tx;
}

}
