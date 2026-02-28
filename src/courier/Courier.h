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

#include <initializer_list>
#include <string>
#include <cstdint>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

namespace courier {
//

//
// STRING
//
// use std::string for STRING

//
// ARRAY
//
// use std::aray for ARRAY
template<typename T, std::size_t N>
struct ARRAY {
private:
    std::array<T, N> data;
    std::size_t SIZE = N;
public:
    static_assert(N <= 65535UL, "Over size");

    ARRAY() {}
//    ARRAY(const ARRAY& that) = default;
    ARRAY(std::initializer_list<T> list) {
        auto size = list.size();
        if (size != SIZE) ERROR();

        int i = 0;
        for(auto& e: list) {
            data[i++] = e;
        }
    }

	T &operator[](std::size_t n) & {
        return data.at(n);
    }
	const T &operator[](std::size_t n) const & {
        return data.at(n);
    }
	T operator[](std::size_t n) const && {
		return std::move(data.at(n));
	}

    // read
    void read(const ByteBuffer& bb) {
        for(std::size_t i = 0; i < SIZE; i++) {
            T value;
            bb.read(value);
        }
    }
    // write
    void write(ByteBuffer& bb) const {
        for(std::size_t i = 0; i < SIZE; i++) {
            T value = data[i];
            bb.write(value);
        }
    }
    // toString
    std::string toString() const {
        std::string ret;
        ret += std_sprintf("(%d) [", SIZE);
        for(std::size_t i = 0; i < SIZE; i++) {
            if (i) ret += "  ";
            T value = data[i];
            ret += ::toString(value);
        }
        ret += "]";
        return ret;
    }
};

//
// SEQUENCE
//
// use std::vector for SEQUENCE
template<typename T, std::size_t N=65535>
struct SEQUENCE {
private:
    std::vector<T> data;
    std::size_t MAX_SIZE = N;
public:
    static_assert(N <= 65535UL, "Over limit");

    SEQUENCE() {}
//    SEQUENCE(const SEQUENCE& that) = default;
    SEQUENCE(std::initializer_list<T> list) {
        data.resize(list.size());

        int i = 0;
        for(auto& e: list) {
            data[i++] = e;
        }
    }

	T &operator[](std::size_t n) & {
        return data.at(n);
    }
	const T &operator[](std::size_t n) const & {
        return data.at(n);
    }
	T operator[](std::size_t n) const && {
		return std::move(data.at(n));
	}

    // read
    void read(const ByteBuffer& bb) {
        uint16_t size = bb.get16();
        if (MAX_SIZE < size) ERROR()
        data.resize(size);

        for(std::size_t i = 0; i < size; i++) {
            T value;
            bb.read(value);
            data[i] = value;
        }
    }
    // write
    void write(ByteBuffer& bb) const {
        size_t size = data.size();
        if (MAX_SIZE <size)  ERROR()

        bb.put16((uint16_t)size);
        for(std::size_t i = 0; i < size; i++) {
            T value = data.at(i);
            bb.write(value);
        }
    }
    // toString
    std::string toString() const {
        size_t size = data.size();

        std::string ret;
        ret += std_sprintf("(%d) [", size);
        for(std::size_t i = 0; i < size; i++) {
            if (i) ret += "  ";
            T value = data[i];
            ret += ::toString(value);
        }
        ret += "]";
        return ret;
    }
};


//
// BOOL for boolean
//
using BOOL = uint16_t;


//
// EMPTY_RECORD for empty record
//
struct EMPTY_RECORD {
    void read(const ByteBuffer&) {}
    void write(ByteBuffer&) const {}
    std::string toString() const { return ""; }
};


//
// Error
//
struct ErrorBase {
    const uint16_t    number;
    const std::string name;

    ErrorBase(uint16_t number_, const std::string& name_) : number(number_), name(name_) {}

    virtual void read(const ByteBuffer& bb)  = 0;
    virtual void write(ByteBuffer& bb) const = 0;
    virtual std::string toString() const = 0;
};

}
