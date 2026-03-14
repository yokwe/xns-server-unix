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

#include "../util/Util.h"


namespace spp {
//
using Block = std::vector<uint8_t>;

enum class Reason {
    normal, endOfMessage, sstChange, endOfStream, attention, timeout,
};
struct Result {
    Reason  reason;
    bool    endOfMessage;
    uint8_t sst;
};

struct NotImplementdException{
    std::string message;

    NotImplementdException(const std::string& message_) : message(message_) {}

    std::string toString() {
        return std_sprintf("{NotImplementdException %s}", message);
    }
};

class Stream {
public:
    virtual Result   get(Block& block) = 0;
    virtual void     put(const Block& block, bool endOfMessage = false, uint8_t sst = 0) = 0;

    void put(const Block& block, bool endOfMessage = false) {
        put(block, endOfMessage, 0);
    }

    virtual void     attention(uint8_t value) = 0;
    virtual int      attention() = 0; // return -1 when no attention

    virtual uint8_t  waitAttention() = 0;

    virtual uint32_t position() = 0;
    virtual void     position(uint32_t value) = 0;

    virtual uint32_t timeout() = 0;               // unit is milliseconds
    virtual void     timeout(uint32_t value) = 0; // unit is milliseconds
};

}
