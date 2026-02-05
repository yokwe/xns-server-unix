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
class Error : public HasToString {
public:
    enum class ErrorNumber : uint16_t {
        ENUM_NAME_VALUE(ErrorNumber, UNSPEC,               0)
        ENUM_NAME_VALUE(ErrorNumber, BAD_CHECKSUM,         1)
        ENUM_NAME_VALUE(ErrorNumber, NO_SOCKET,            2)
        ENUM_NAME_VALUE(ErrorNumber, RESOURCE_LIMIT,       3)
    
        ENUM_NAME_VALUE(ErrorNumber, LISTEN_REJECT,        4)
        ENUM_NAME_VALUE(ErrorNumber, INVALID_PACKET_TYPE,  5)
        ENUM_NAME_VALUE(ErrorNumber, PROTOCOL_VIOLATION,   6)
    
        ENUM_NAME_VALUE(ErrorNumber, UNSPECIFIED_IN_ROUTE, 01000)
        ENUM_NAME_VALUE(ErrorNumber, INCONSISTENT,         01001)
        ENUM_NAME_VALUE(ErrorNumber, CANT_GET_THERE,       01002)
        ENUM_NAME_VALUE(ErrorNumber, EXCESS_HOPS,          01003)
        ENUM_NAME_VALUE(ErrorNumber, TOO_BIG,              01004)
    
        ENUM_NAME_VALUE(ErrorNumber, CONGESTION_WARNING,   01005)
        ENUM_NAME_VALUE(ErrorNumber, CONGESTION_DISCARD,   01006)
    };
    static std::string toString(ErrorNumber value);

    ErrorNumber errorNumber;
    uint16_t    errorParameter;

    Error() : errorNumber(ErrorNumber::UNSPEC), errorParameter(0) {}

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(errorNumber, errorParameter);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(errorNumber, errorParameter);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %d}", toString(errorNumber), errorParameter);
    }

};

}
