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
// ByteBuffer.h
//

#pragma once

#include <concepts>
#include <cstdint>
#include <memory>
#include <span>
#include <type_traits>
#include <utility>

#include "Util.h"

class ByteBuffer;
//
// concept
//
template<typename T>
concept has_read = requires (T& o, ByteBuffer& bb) {
    { o.read(bb)  } -> std::same_as<ByteBuffer&>;
};
template<typename T>
concept has_write = requires (T& o, ByteBuffer& bb) {
    { o.write(bb) } -> std::same_as<ByteBuffer&>;
};
template<typename T>
concept has_read_write = has_read<T> && has_write<T>;

template<typename T>
concept has_from_bb = requires (T& o, ByteBuffer& bb) {
    { from_bb(bb, o) } -> std::same_as<void>;
};
template<typename T>
concept has_to_bb = requires (T& o, ByteBuffer& bb) {
    { to_bb(bb, o) } -> std::same_as<void>;
};
template<typename T>
concept has_from_bb_to_bb = has_from_bb<T> && has_to_bb<T>;

template<typename T>
concept valid_for_bb_ = has_read_write<T> || has_from_bb_to_bb<T> || std::is_enum_v<T> || std::is_integral_v<T>;
template<typename T>
concept valid_for_bb = valid_for_bb_<std::remove_cvref_t<T>>;

class ByteBuffer {
    static const bool USE_MESA_BYTE_ORDER = false;

    static const uint32_t BYTES_PER_WORD = 2;
    static uint32_t toWordValue(uint32_t byteValue) {
        return (byteValue + BYTES_PER_WORD - 1) / BYTES_PER_WORD;
    }
    static uint32_t toByteValue(uint32_t wordValue) {
        return wordValue * BYTES_PER_WORD;
    }
    
    static inline const uint32_t BAD_MARK = ~0;

    std::shared_ptr<uint8_t[]> myStorage;

    uint8_t*  myData;
    uint32_t  myByteCapacity;  // cpacity of myData
    uint32_t  myBytePos;       // current position for read and write
    uint32_t  myByteLimit;     // written size
    uint32_t  myByteMark;

    ByteBuffer(uint8_t* data, uint32_t byteCapacity, uint32_t byteLimit) :
        myStorage(0), myData(data), myByteCapacity(byteCapacity), myBytePos(0), myByteLimit(byteLimit), myByteMark(BAD_MARK) {}
    ByteBuffer(std::shared_ptr<uint8_t[]> storage, uint32_t byteCapacity, uint32_t byteLimit) :
        myStorage(storage), myData(myStorage.get()), myByteCapacity(byteCapacity), myBytePos(0), myByteLimit(byteLimit), myByteMark(BAD_MARK) {}
    
    // valid range of myBytePos   is [0..myByteCapacity)
    // valid range of myByteLimit is [myBytePos..myByteCapacity)
    void checkBeforeRead(uint32_t byteSize);
    void checkBeforeWrite(uint32_t byteSize);
        
public:
    ByteBuffer() : ByteBuffer(0, 0, 0) {}
    ByteBuffer(uint8_t* data, uint32_t byteSize) : ByteBuffer(data, byteSize, byteSize) {}
    ByteBuffer(uint32_t byteSize) : ByteBuffer(std::make_shared<uint8_t[]>(byteSize), byteSize, 0) {}

    ~ByteBuffer() {
        myData          = 0;
        myByteCapacity  = 0;
        myBytePos       = 0;
        myByteLimit     = 0;
        myByteMark      = BAD_MARK;
    };

    static uint8_t highByte(uint16_t value) {
        return (uint8_t)(value >> 8);
    }
    static uint8_t lowByte(uint16_t value) {
        return (uint8_t)(value >> 0);
    }

    ByteBuffer byteRange(uint32_t byteOffset, uint32_t byteSize);
    ByteBuffer range(uint32_t wordOffset, uint32_t wordSize) {
        auto byteOffset  = toByteValue(wordOffset);
        auto byteSize = toByteValue(wordSize);
        return byteRange(byteOffset, byteSize);
    }
    ByteBuffer rangeRemains() {
        auto byteSize = byteRemains();
        return ByteBuffer(myData + myBytePos, byteSize, byteSize);
    }

    std::span<uint8_t> toSpan() const {
        return std::span<uint8_t>{myData, myByteLimit};
    }

    std::string toString() const {
        return toHexString(myByteLimit, myData);
    }

    const uint8_t* data() {
        return myData;
    }

    //
    // clear -- make ByteBufer ready for write
    //
    void clear() {
        myByteLimit = 0;
        myBytePos   = 0;
    }
    //
    // flip -- make ByteBuffer ready for read from start after write
    //
    void flip() {
        myByteLimit = myBytePos;
        myBytePos   = 0;
    }
    //
    // rewind -- make ByteBuffer ready for read from start
    //
    void rewind() {
        myBytePos = 0;
    }
    //
    // mark -- mark position for later reset
    //
    void mark();
    //
    // reset -- move to last mark position
    //
    void reset();


    //
    // capacity
    //
    uint32_t byteCapacity() {
        return myByteCapacity;
    }
    uint32_t capacity() {
        return toWordValue(byteCapacity());
    }
    //
    // pos
    //
    uint32_t bytePos() {
        return myBytePos;
    }
    uint32_t pos() {
        return toWordValue(bytePos());
    }
    //
    // limit
    //
    uint32_t byteLimit() const {
        return myByteLimit;
    }
    uint32_t limit() {
        return toWordValue(byteLimit());
    }
    bool empty() {
        return byteLimit() == 0;
    }
    //
    // remains
    //
    uint32_t byteRemains() {
        return myByteLimit - myBytePos;
    }
    uint32_t remains() {
        return toWordValue(byteRemains());
    }

    
    // getX
    // std::span<uint8_t> getSpan() {
    //     std::span<uint8_t> ret {myData + myBytePos, myByteLimit - myBytePos};
    //     myBytePos = myByteLimit;
    //     return ret;
    // }
    uint8_t get8() {
        checkBeforeRead(1);
        uint8_t ret = myData[myBytePos++];;
        return ret;
    }
    uint16_t get16() {
        checkBeforeRead(2);
        uint16_t ret = 0;
        ret |= myData[myBytePos++] <<  8;
        ret |= myData[myBytePos++] <<  0;
        return ret;
    }
    uint32_t get32() {
        checkBeforeRead(4);
        uint32_t ret = 0;
        if constexpr (USE_MESA_BYTE_ORDER) {
            ret |= myData[myBytePos++] <<  8;
            ret |= myData[myBytePos++] <<  0;
            ret |= myData[myBytePos++] << 24;
            ret |= myData[myBytePos++] << 16;
        } else {
            ret |= myData[myBytePos++] << 24;
            ret |= myData[myBytePos++] << 16;
            ret |= myData[myBytePos++] <<  8;
            ret |= myData[myBytePos++] <<  0;
        }
        return ret;
    }

    // putX
    void putSpan(const std::span<uint8_t>& span) {
        auto byteSize = span.size();
        if (byteSize == 0) return;

        checkBeforeWrite(byteSize);
        for(const auto e: span) {
            myData[myBytePos++] = e;
        }
        if (myByteLimit < myBytePos) myByteLimit = myBytePos;
    }
    void put8(uint8_t value) {
        checkBeforeWrite(1);
        myData[myBytePos++] = value;

        if (myByteLimit < myBytePos) myByteLimit = myBytePos;
    }
    void put16(uint16_t value) {
        checkBeforeWrite(2);
        myData[myBytePos++] = value >> 8;
        myData[myBytePos++] = value >> 0;

        if (myByteLimit < myBytePos) myByteLimit = myBytePos;
    }
    void put32(uint32_t value) {
        checkBeforeWrite(4);
        if constexpr (USE_MESA_BYTE_ORDER) {
            myData[myBytePos++] = value >>  8;
            myData[myBytePos++] = value >>  0;    
            myData[myBytePos++] = value >> 24;
            myData[myBytePos++] = value >> 16;
        } else {
            myData[myBytePos++] = value >> 24;
            myData[myBytePos++] = value >> 16;
            myData[myBytePos++] = value >>  8;
            myData[myBytePos++] = value >>  0;    
        }

        if (myByteLimit < myBytePos) myByteLimit = myBytePos;
    }

    //
    // read()
    //
    ByteBuffer& read() {
        return *this;
    }
    // unsigned
    ByteBuffer& read(uint8_t& value) {
        value = get8();
        return *this;
    }
    ByteBuffer& read(uint16_t& value) {
        value = get16();
        return *this;
    }
    ByteBuffer& read(uint32_t& value) {
        value = get32();
        return *this;
    }
    // signed
    ByteBuffer& read(int16_t& value) {
        value = (int16_t)get16();
        return *this;
    }
    ByteBuffer& read(int32_t& value) {
        value = (int32_t)get32();
        return *this;
    }
    // prohibit
    ByteBuffer& read(int64_t  value) = delete;
    ByteBuffer& read(uint64_t value) = delete;

    ByteBuffer& read(ByteBuffer& value) {
        value = rangeRemains();
        return *this;
    }

    template <class Head, class... Tail>
//    requires valid_for_bb<Head>
    ByteBuffer& read(Head&& head, Tail&&... tail) {
        // process head
        using T = std::remove_cvref_t<Head>;
        if constexpr (has_read_write<T>) {
            head.read(*this);
        } else if constexpr (has_from_bb_to_bb<T>) {
            from_bb(*this, head);
        } else if constexpr (std::is_enum_v<T>) {
            using U = std::underlying_type_t<T>;
            U value;
            read(value);
            head = static_cast<T>(value);
        } else if constexpr (std::is_integral_v<T>) {
            T value;
            read(value);
            head = value;
        } else {
            static_assert(false, "Unexptected");
            logger.info("##  %s  %d  %s", __func__, __LINE__, demangle(typeid(Head).name()));
            read(head);
        }
        // process tail
        return read(std::forward<Tail>(tail)...);
    }

    //
    // write()
    //
    ByteBuffer& write() {
        return *this;
    }
    // unsigned
    ByteBuffer& write(uint8_t value) {
        put8(value);
        return *this;
    }
    ByteBuffer& write(uint16_t value) {
        put16(value);
        return *this;
    }
    ByteBuffer& write(uint32_t value) {
        put32(value);
        return *this;
    }
    // signed
    ByteBuffer& write(int16_t value) {
        put16((uint16_t)value);
        return *this;
    }
    ByteBuffer& write(int32_t value) {
        put32((uint32_t)value);
        return *this;
    }
    // prohibit
    ByteBuffer& write(int64_t  value) = delete;
    ByteBuffer& write(uint64_t value) = delete;

    ByteBuffer& write(ByteBuffer& value) {
        putSpan(value.toSpan());
        return *this;
    }
    ByteBuffer& write(std::span<uint8_t> span) {
        putSpan(span);
        return *this;
    }

    template <class Head, class... Tail>
//    requires valid_for_bb<Head>
    ByteBuffer& write(Head&& head, Tail&&... tail) {
        // process head
        using T = std::remove_cvref_t<Head>;
        if constexpr (has_read_write<T>) {
            head.write(*this);
        } else if constexpr (has_from_bb_to_bb<T>) {
            to_bb(*this, head);
        } else if constexpr (std::is_enum_v<T>) {
            using U = std::underlying_type_t<T>;
            U value = static_cast<U>(head);
            write(value);
        } else if constexpr (std::is_integral_v<T>) {
            T value = (T)head;
            write(value);
        } else {
            static_assert(false, "Unexptected");
            logger.info("##  %s  %d  %s", __func__, __LINE__, demangle(typeid(Head).name()));
            write(head);
        }
        // process tail
        return write(std::forward<Tail>(tail)...);
    }
};

//
// std::string
//
inline void to_bb(ByteBuffer& bb, std::string& string) {
    int size = string.size();
    if (65535 < size) ERROR()
    bb.put16(size);
    for(int i = 0; i < size; i++) {
        uint8_t c = string[i];
        bb.put8(c);
    }
}
inline void from_bb(ByteBuffer& bb, std::string& string) {
    int size = bb.get16();
    if (65535 < size) ERROR()
    string.reserve(size);
    for(int i = 0; i < size; i++) {
        uint8_t c = bb.get8();
        string.push_back(c);
    }
}
//
// std::vector
//
template<typename T>
void to_bb(ByteBuffer& bb, std::vector<T>& vector) {
    int size = vector.size();
    if (65535 < size) ERROR()
    bb.put16(size);
    for(int i = 0; i < size; i++) {
        T value = vector[i];
        bb.write(value);
    }
}
template<typename T>
void from_bb(ByteBuffer& bb, std::vector<T>& vector) {
    int size = bb.get16();
    if (65535 < size) ERROR()
    vector.reserve(size);
    for(int i = 0; i < size; i++) {
        T value;
        bb.read(value);
        vector.push_back(value);
    }
}