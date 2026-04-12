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
// StreamSPP.h
//

#pragma once

#include <cstdint>

#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

#include "Stream.h"

namespace spp {
//
using SST    = xns::SPP::SST;

// forward declaration
class Connection;

class StreamSPP : public Stream {
    static constexpr uint32_t TIMEOUT_VALUE = 3'600'000;

    Connection* connection;
    uint32_t    timeoutValue;
    uint16_t    seq;
    bool        attentionFlag;
    uint8_t     attentionValue;

public:
    StreamSPP(Connection* connection_): connection(connection_), timeoutValue(TIMEOUT_VALUE), seq(0), attentionFlag(false), attentionValue(0) {}

    Result   get(Data& data) override;
    void     put(Data& data, SST sst = SST::DATA, bool endOfMessage = false) override;

    void put(ByteBuffer& bb, SST sst = SST::DATA, bool endOfMessage = false) {
        auto data = bb.toVector();
        put(data, sst, endOfMessage);
    }

    void     attention(uint8_t value) override;
    bool     checkAttention() override;
    uint8_t  attention() override;

    uint32_t timeout() override;               // unit is milliseconds
    void     timeout(uint32_t value) override; // unit is milliseconds
};

}
