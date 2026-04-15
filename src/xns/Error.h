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
 // Error.h
 //

#pragma once

#include <cstdint>
#include <string>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"


namespace xns {
//
class Error {
public:
    enum class ErrorNumber : uint16_t {
        UNSPEC               = 0,
        BAD_CHECKSUM         = 1,
        NO_SOCKET            = 2,
        RESOURCE_LIMIT       = 3,
    
        LISTEN_REJECT        = 4,
        INVALID_PACKET_TYPE  = 5,
        PROTOCOL_VIOLATION   = 6,
    
        UNSPECIFIED_IN_ROUTE = 01000,
        INCONSISTENT         = 01001,
        CANT_GET_THERE       = 01002,
        EXCESS_HOPS          = 01003,
        TOO_BIG              = 01004,
    
        CONGESTION_WARNING   = 01005,
        CONGESTION_DISCARD   = 01006,
    };
    static std::string toString(ErrorNumber value) {
        static std::unordered_map<ErrorNumber, std::string, ScopedEnumHash> map = {
            {ErrorNumber::UNSPEC,              "UNSPEC"},
            {ErrorNumber::BAD_CHECKSUM,        "BAD_CHECKSUM"},
            {ErrorNumber::NO_SOCKET,           "NO_SOCKET"},
            {ErrorNumber::RESOURCE_LIMIT,      "RESOURCE_LIMIT"},
        
            {ErrorNumber::LISTEN_REJECT,       "LISTEN_REJECT"},
            {ErrorNumber::INVALID_PACKET_TYPE, "INVALID_PACKET_TYPE"},
            {ErrorNumber::PROTOCOL_VIOLATION,  "PROTOCOL_VIOLATION"},
        
            {ErrorNumber::UNSPECIFIED_IN_ROUTE, "UNSPECIFIED_IN_ROUTE"},
            {ErrorNumber::INCONSISTENT,         "INCONSISTENT"},
            {ErrorNumber::CANT_GET_THERE,       "CANT_GET_THERE"},
            {ErrorNumber::EXCESS_HOPS,         "EXCESS_HOPS"},
            {ErrorNumber::TOO_BIG,             "TOO_BIG"},
        
            {ErrorNumber::CONGESTION_WARNING,  "CONGESTION_WARNING"},
            {ErrorNumber::CONGESTION_DISCARD,  "CONGESTION_DISCARD"},
            };
        return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
    }

    ErrorNumber errorNumber;
    uint16_t    errorParameter;

    Error() : errorNumber(ErrorNumber::UNSPEC), errorParameter(0) {}
    Error(ErrorNumber errorNumber_, uint16_t errorParameter_ = 0) : errorNumber(errorNumber_), errorParameter(errorParameter_) {}

    void read(const ByteBuffer& bb) {
        bb.read(errorNumber, errorParameter);
    }
    void write(ByteBuffer& bb) const {
        bb.write(errorNumber, errorParameter);
    }
    std::string toString() const {
        return std_sprintf("{%s  %d}", toString(errorNumber), errorParameter);
    }

};

}
