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
 // Stream.h
 //

#pragma once

#include <vector>
#include <cstdint>

#include "../xns/SPP.h"

namespace spp {
//
using SST = xns::SPP::SST;

enum class Reason {
    normal, timeout, endOfStream,
};
inline std::string toString(Reason value) {
    static std::unordered_map<Reason, std::string, ScopedEnumHash> map = {
        {Reason::normal,       "normal"},
        {Reason::timeout,      "timeout"},
        {Reason::endOfStream,  "endOfStream"},
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}
struct Result {
    Reason reason;
    SST    sst;
    bool   endOfMessage;

    Result(Reason reason_, SST sst_, bool endOfMessage_) : reason(reason_), sst(sst_), endOfMessage(endOfMessage_) {}
    Result() : Result(Reason::normal, SST::DATA, false) {}

    std::string toString() {
        return std_sprintf("{%s  %s  %s}", ::toString(reason), ::toString(sst), endOfMessage ? "T" : "F");
    }
};

using Data = std::vector<uint8_t>;

class Stream {
public:
    
    virtual Result   get(Data& data) = 0;
    virtual void     put(Data& data, SST sst = SST::DATA, bool endOfMessage = false) = 0;

    virtual void     attention(uint8_t value) = 0;
    virtual bool     hasAttention() = 0;
    virtual uint8_t  attention() = 0; // return -1 when no attention

    virtual uint32_t timeout() = 0;               // unit is milliseconds
    virtual void     timeout(uint32_t value) = 0; // unit is milliseconds
};

}
