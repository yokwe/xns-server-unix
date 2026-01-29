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
static std::unordered_map<xns::Network, xns::RIP::Delay> map;

ByteBuffer process  (ByteBuffer& rx, Context& context) {
    using Delay = xns::RIP::Delay;
    using Type = xns::RIP::Type;

    if (map.empty()) {
        for(auto& e: context.config.net) {
            auto net = static_cast<xns::Network>(e.net);
            auto delay = static_cast<xns::RIP::Delay>(e.delay);
            if (delay == xns::RIP::Delay::INFINITY) continue;
            map[net] = delay;
        }
    }

    xns::RIP txHeader;
    {
        xns::RIP rxHeader;
        rx.read(rxHeader);
        auto rxbb = rx.rangeRemains();

        logger.info("RIP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

        // sanity check
        if (rxHeader.type != Type::REQUEST) ERROR()
        if (!rxbb.empty()) ERROR();

        // build response
        txHeader.type = Type::RESPONSE;

        for(const auto& e: rxHeader.entryList) {
            if (e.network == xns::Network::ALL && e.delay == Delay::INFINITY) {
                for(const auto [network, delay] : map) {
                    txHeader.entryList.emplace_back(network, delay);
                }
            } else {
                if (map.contains(e.network)) {
                    txHeader.entryList.emplace_back(e.network, map[e.network]);
                }
            }
        }

        logger.info("RIP  <<  %s", txHeader.toString());
    }

    auto tx = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);
    tx.write(txHeader);

    return tx;
}

}
