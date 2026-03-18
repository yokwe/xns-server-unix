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
// ConnectionStream.h
//

#pragma once

#include <cstdint>

#include "Connection.h"
#include "Stream.h"

namespace server {
//
using Reason = stream::Reason;
using Result = stream::Result;

class ConnectionStream : public stream::Stream {
    Connection& connection;

    uint32_t timeoutValue   = 3'600'000; // unit is milliseconds

public:
    // sst value copied from xns::SPP::SST
    static const constexpr uint8_t DATA        =   0;
    static const constexpr uint8_t BULK        =   1;
    static const constexpr uint8_t CLOSE       = 254;
    static const constexpr uint8_t CLOSE_REPLY = 255;
    
    ConnectionStream(Connection& connection_);

    Result   get(Data& data) override;
    void     put(Data& data, bool endOfMessage = false, uint8_t sst = 0) override;

    void put(ByteBuffer& bb, bool endOfMessage = false, uint8_t sst = 0) {
        auto data = bb.toVector();
        put(data, endOfMessage, sst);
    }

    void     attention(uint8_t value) override;
    int      attention() override;  // return -1 when no attention

    uint32_t timeout() override;               // unit is milliseconds
    void     timeout(uint32_t value) override; // unit is milliseconds
};

}
