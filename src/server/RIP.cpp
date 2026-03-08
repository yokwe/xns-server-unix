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

#include "../util/Debug.h"
#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/RIP.h"

#include "Server.h"

namespace server::RIP {
//
void process  (Session& session, ByteBuffer& rx) {
    // make reference
    auto& context = session.context;

    xns::RIP rxHeader;
    rx.read(rxHeader);
    auto rxbb = rx.rangeRemains();
    if constexpr (SHOW_PACKET_RIP) logger.info("RIP  >>  %s  (%d) %s", toString(rxHeader), rxbb.byteLimit(), rxbb.toString());

    // sanity check
    if (!rxbb.empty()) ERROR();

    if (rxHeader.type == xns::RIP::Type::REQUEST) {
        xns::RIP txHeader{xns::RIP::Type::RESPONSE};
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

        auto tx = getByteBuffer();
        tx.write(txHeader);
        if constexpr (SHOW_PACKET_RIP) logger.info("RIP  <<  %s", toString(txHeader));

        session.sendIDP(tx);
    }
}

}
