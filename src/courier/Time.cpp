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
 // Time.cpp
 //

 #include <utility>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "Time.h"

#undef  ENUM_NAME_VALUE
#define ENUM_NAME_VALUE(enum,name,value) { enum :: name, #name },

namespace xns::courier::Time {
//
std::string toString(Version value) {
    static std::unordered_map<Version, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Version, CURRENT, 2)
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}
std::string toString(Type value) {
    static std::unordered_map<Type, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Type, REQUEST,  1)
        ENUM_NAME_VALUE(Type, RESPONSE, 2)    
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}
std::string toString(Direction value) {
    static std::unordered_map<Direction, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Direction, WEST, 0)
        ENUM_NAME_VALUE(Direction, EAST, 1)
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}
std::string toString(Tolerance value) {
    static std::unordered_map<Tolerance, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(Tolerance, UNKNOWN, 0)
        ENUM_NAME_VALUE(Tolerance, KNOWN,   1)
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}
std::string toString(DST value) {
    static std::unordered_map<DST, std::string, ScopedEnumHash> map = {
        ENUM_NAME_VALUE(DST, NO, 0)
    };
    return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
}

}