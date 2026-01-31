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
 // Courier.h
 //

#pragma once

#include <string>
#include <cstdint>
#include <vector>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

namespace xns::courier {
//

//
// STRING
//
class STRING : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString  {
    static const constexpr uint32_t MAX_LENGTH = 65535;
    mutable std::string value;

public:
    ByteBuffer& read(ByteBuffer& bb) override {
        uint16_t length;
        bb.read(length);
        value.clear();
        for(uint16_t i = 0; i < length; i++) {
            value += bb.get8();
        }
        if (length & 1) bb.get8();
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        uint16_t length = value.length();
        bb.put16(length);
        for(uint8_t c: value) {
            bb.put8(c);
        }
        if (length & 1) bb.put8(0);
        return bb;
    }
    std::string toString() const override {
        return value.data();
    }

    // define operator =
    std::string operator = (const std::string& newValue) /*const*/ {
        if (MAX_LENGTH < newValue.length()) ERROR()
        value.clear();
        value.reserve(newValue.length());
        value += newValue;
        return value;
    }

    // cast to const char*
    operator const char* () const {
        return value.data();
    }
    // cast to const std::string&
    operator const std::string& () const {
        return value;
    }
};

template <class T, uint32_t N>
class ARRAY : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString  {
    static_assert(N <= 65535, "N is more than 65535");

    static const constexpr uint32_t MAX_LENGTH = 65535;
    mutable std::array<T, N> array;

public:
    ARRAY() {
        constexpr auto is_uint8_t  = std::is_same_v<T, uint8_t>;
        constexpr auto is_uint16_t = std::is_same_v<T, uint16_t>;
        constexpr auto is_uint32_t = std::is_same_v<T, uint32_t>;
        constexpr auto is_class    = std::is_class_v<T>;
        constexpr auto is_enum     = std::is_scoped_enum_v<T>;
    
        if (is_uint8_t || is_uint16_t || is_uint32_t) {
            // OK
        } else if constexpr (is_enum) {
            using UT = std::underlying_type_t<T>;
            constexpr auto ut_uint8_t  = std::is_same_v<UT, uint8_t>;
            constexpr auto ut_uint16_t = std::is_same_v<UT, uint16_t>;
            constexpr auto ut_uint32_t = std::is_same_v<UT, uint32_t>;
            if constexpr (ut_uint8_t || ut_uint16_t || ut_uint32_t) {
                // OK
            } else ERROR()
        } else if constexpr(is_class) {
            constexpr auto has_read  = std::is_base_of_v<HasRead, T>;
            constexpr auto has_write = std::is_base_of_v<HasWrite, T>;
            if (has_read && has_write) {
                // OK
            } else ERROR()
        } else ERROR()
    }
    ARRAY& operator =(const std::array<T, N>& that) {
        array = that;
        return *this;
    }
    
    uint32_t size() const {
        return N;
    }

    ByteBuffer& read(ByteBuffer& bb) override {
        for(uint32_t i = 0; i < N; i++) {
            T value;
            bb.read(value);
            array.at(i) = value;
        }
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        for(uint32_t i = 0; i < N; i++) {
            auto value = array.at(i);
            bb.write(value);
        }
        return bb;
    }
    std::string toString() const override {
        if (array.empty()) return "[]";
        std::string string;
        for(const auto& e: array) {
            string += std_sprintf(" %s", e.toString());
        }
        return std_sprintf("(%d) [%s]", array.size(), string.substr(1));
    }
};


template <class T>
class SEQUENCE : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString  {
    static const constexpr uint32_t MAX_LENGTH = 65535;
    mutable std::vector<T> vector;

public:
    SEQUENCE() {
        constexpr auto is_uint8_t  = std::is_same_v<T, uint8_t>;
        constexpr auto is_uint16_t = std::is_same_v<T, uint16_t>;
        constexpr auto is_uint32_t = std::is_same_v<T, uint32_t>;
        constexpr auto is_class    = std::is_class_v<T>;
        constexpr auto is_enum     = std::is_scoped_enum_v<T>;
    
        if (is_uint8_t || is_uint16_t || is_uint32_t) {
            // OK
        } else if constexpr (is_enum) {
            using UT = std::underlying_type_t<T>;
            constexpr auto ut_uint8_t  = std::is_same_v<UT, uint8_t>;
            constexpr auto ut_uint16_t = std::is_same_v<UT, uint16_t>;
            constexpr auto ut_uint32_t = std::is_same_v<UT, uint32_t>;
            if constexpr (ut_uint8_t || ut_uint16_t || ut_uint32_t) {
                // OK
            } else ERROR()
        } else if constexpr(is_class) {
            constexpr auto has_read  = std::is_base_of_v<HasRead, T>;
            constexpr auto has_write = std::is_base_of_v<HasWrite, T>;
            if (has_read && has_write) {
                // OK
            } else ERROR()
        } else ERROR()
    }
    SEQUENCE& operator =(const std::vector<T>& that) {
        if (MAX_LENGTH < that.size()) ERROR()
        vector = that;
        return *this;
    }
    
    uint32_t size() const {
        return vector.size();
    }

    ByteBuffer& read(ByteBuffer& bb) override {
        uint16_t size = bb.get16();
        for(uint32_t i = 0; i < size; i++) {
            T value;
            bb.read(value);
            vector.at(i) = value;
        }
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        uint16_t size = vector.size();
        bb.put16(size);
        for(uint32_t i = 0; i < size; i++) {
            auto value = vector.at(i);
            bb.write(value);
        }
        return bb;
    }
    std::string toString() const override {
        if (vector.empty()) return "[]";
        std::string string;
        for(const auto& e: vector) {
            string += std_sprintf(" %s", e.toString());
        }
        return std_sprintf("(%d) [%s]", vector.size(), string.substr(1));
    }
};
}
