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

#include "../xns/XNS.h"

namespace courier::Time {
//
using Operation = xns::Operation;

enum class Version : uint16_t {
    CURRENT = 2,
};
inline std::string toString(Version value) {
    static std::unordered_map<Version, std::string, ScopedEnumHash> map = {
        {Version::CURRENT, "CURRENT"},
    };
    return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
}

class Request {
public:
    Version   version;
    Operation operation;

    void read(const ByteBuffer& bb) {
        bb.read(version, operation);
    }
    void write(ByteBuffer& bb) const {
        bb.write(version, operation);
    }
    std::string toString() const {
        return std_sprintf("{%s  %s}", Time::toString(version), xns::toString(operation));
    }
};

class Response {
public:
    enum class Direction : uint16_t {
        WEST = 0,
        EAST = 1,
    };
    static std::string toString(Direction value) {
        static std::unordered_map<Direction, std::string, ScopedEnumHash> map = {
            {Direction::WEST, "WEST"},
            {Direction::EAST, "EAST"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
    }

    enum class Tolerance : uint16_t {
        UNKNOWN = 0,
        KNOWN   = 1,
    };
    static std::string toString(Tolerance value) {
        static std::unordered_map<Tolerance, std::string, ScopedEnumHash> map = {
            {Tolerance::KNOWN,   "KNOWN"},
            {Tolerance::UNKNOWN, "UNKNOWN"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
    }

    enum class DST : uint16_t {
        NO = 0,
    };
    static std::string toString(DST value) {
        static std::unordered_map<DST, std::string, ScopedEnumHash> map = {
            {DST::NO,  "NO"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
    }

    Version   version;
    Operation operation;
    uint32_t  time;             // current time between 12:00:00, 1 Jan. 1968 and 6:28:23, 6 Feb. 2104 inclusive
    Direction offsetDirection;
    uint16_t  offsetHours;
    uint16_t  offsetMinutes;
    DST       dstStart;
    DST       dstEnd;
    Tolerance tolerance;
    uint32_t  toleranceValue;   // if tolerance is KNOWN time error in unit of millisecond

    void read(const ByteBuffer& bb) {
        bb.read(version, operation, time, offsetDirection, offsetHours, offsetMinutes, dstStart, dstEnd, tolerance, toleranceValue);
    }
    void write(ByteBuffer& bb) const {
        bb.write(version, operation, time, offsetDirection, offsetHours, offsetMinutes, dstStart, dstEnd, tolerance, toleranceValue);
    }
    std::string toString() const {
        uint32_t unixTime = Util::toUnixTime(time);
        std::string timeString = Util::toString(unixTime);

        return std_sprintf("{%s  %s  %s  %s  %dh%dm  %d-%d  %s-%d}",
            Time::toString(version), xns::toString(operation), timeString,
            toString(offsetDirection), offsetHours, offsetMinutes, dstStart, dstEnd,
            toString(tolerance), toleranceValue);
    }
};

}
