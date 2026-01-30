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
 // Time.h
 //

#pragma once

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

namespace xns::courier::Time {
//
enum class Version : uint16_t {
    ENUM_NAME_VALUE(Version, CURRENT, 2)
};
std::string toString(Version value);

enum class Type : uint16_t {
    ENUM_NAME_VALUE(Type, REQUEST,  1)
    ENUM_NAME_VALUE(Type, RESPONSE, 2)    
};
std::string toString(Type value);

enum class Direction : uint16_t {
    ENUM_NAME_VALUE(Direction, WEST, 0)
    ENUM_NAME_VALUE(Direction, EAST, 1)
};
std::string toString(Direction value);

enum class Tolerance : uint16_t {
    ENUM_NAME_VALUE(Tolerance, UNKNOWN, 0)
    ENUM_NAME_VALUE(Tolerance, KNOWN,   1)
};
std::string toString(Tolerance value);

enum class DST : uint16_t {
    ENUM_NAME_VALUE(DST, NO, 0)
};
std::string toString(DST value);


class Request : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
public:
    Version version;
    Type    type;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(version, type);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb)  const override {
        bb.write(version, type);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %s}", Time::toString(version), Time::toString(type));
    }
};

class Response : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
public:
    Version   version;
    Type      type;
    uint32_t  time;             // current time between 12:00:00, 1 Jan. 1968 and 6:28:23, 6 Feb. 2104 inclusive
    Direction offsetDirection;
    uint16_t  offsetHours;
    uint16_t  offsetMinutes;
    DST       dstStart;
    DST       dstEnd;
    Tolerance tolerance;
    uint32_t  toleranceValue;   // if tolerance is KNOWN time error in unit of millisecond

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(version, type, time, offsetDirection, offsetHours, offsetMinutes, dstStart, dstEnd, tolerance, toleranceValue);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb)  const override {
        bb.write(version, type, time, offsetDirection, offsetHours, offsetMinutes, dstStart, dstEnd, tolerance, toleranceValue);
        return bb;
    }
    std::string toString() const override {
        uint32_t unixTime = Util::toUnixTime(time);
        std::string timeString = Util::toString(unixTime);

        return std_sprintf("{%s  %s  %s  %s  %dh%dm  %d-%d  %s-%d}",
            Time::toString(version), Time::toString(type), timeString,
            Time::toString(offsetDirection), offsetHours, offsetMinutes, dstStart, dstEnd,
            Time::toString(tolerance), toleranceValue);
    }
};

}
