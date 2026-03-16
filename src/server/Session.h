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
 // Session.h
 //

#pragma once

#include <chrono>

#include "../xns/Ethernet.h"
#include "../xns/PEX.h"
#include "../xns/IDP.h"
#include "../xns/SPP.h"
#include "../xns/Error.h"


namespace server {
//
struct Context;
struct ThreadTransmit;

struct Session {
    using steady_clock = std::chrono::steady_clock;
    Context&        context;
    ThreadTransmit& threadTransmit;
    uint64_t        startTime; // milli seconds

    // received headers
    xns::Ethernet rxEthernet;
    xns::IDP      rxIDP;
    xns::PEX      rxPEX;
    xns::SPP      rxSPP;

    Session(Context& context_, ThreadTransmit& threadTransmit_) :
        context(context_),
        threadTransmit(threadTransmit_),
        startTime(milliTime()) {}

    static uint64_t milliTime() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    template<typename T>
    uint64_t duration() {
        return milliTime() - startTime;
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

}