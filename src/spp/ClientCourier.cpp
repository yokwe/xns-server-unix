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
// ClientCourier.cpp
//

#include <chrono>


#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../service/Services.h"

#include "Connection.h"
#include "Stream.h"
#include "ClientCourier.h"

namespace spp {
//
using Clock = std::chrono::steady_clock;

void ClientCourier::idle() {
    static Clock::time_point lastRetransmit = Clock::now();

    auto now = Clock::now();

    if (now < (lastRetransmit + Connection::RETRANSMIT_INTERVAL)) return;
    lastRetransmit += Connection::RETRANSMIT_INTERVAL;
    connection->retransmit();
}

void ClientCourier::run() {
    threadRunning = true;
    logger.info("START");
    stream.timeout(DEFUALT_TIMEOUT);

    Data rxdata;
    for(;;) {
        if (stopThread) break;
        auto result = stream.get(rxdata);
        if (result.reason == Reason::endOfStream) break;
        if (result.reason == Reason::timeout) {
            idle();
            continue;
        }
        
        ByteBuffer rx(rxdata.data(), rxdata.size());
        auto tx = service::services.callCourier(&stream, rx);
        auto txdata = tx.toVector();
        stream.put(txdata, xns::SPP::SST::DATA, true);
    }

    logger.info("STOP");
    threadRunning = false;
}

}