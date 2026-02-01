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
#include <variant>
#include <vector>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

namespace xns::courier {
//

//
// STRING
//
class STRING : public HasRead, public HasWrite, public HasToString  {
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
    ByteBuffer& write(ByteBuffer& bb) override {
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

//
// ARRAY
//
template <class T, uint32_t N>
class ARRAY : public HasRead, public HasWrite, public HasToString  {
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
    ByteBuffer& write(ByteBuffer& bb) override {
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

//
// SEQUENCE
//
template <class T>
class SEQUENCE : public HasRead, public HasWrite, public HasToString  {
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
    ByteBuffer& write(ByteBuffer& bb) override {
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

//
// Message
//
enum class Type : uint16_t {
    ENUM_NAME_VALUE(Type, CALL,    0)
    ENUM_NAME_VALUE(Type, REJECT,  1)
    ENUM_NAME_VALUE(Type, RETURN,  2)
    ENUM_NAME_VALUE(Type, ABORT,   3)
};
std::string toString(Type value);

namespace protocol3{
//
struct CallMessage : public HasRead, public HasWrite, public HasToString {
    Type       type;
    uint16_t   transactionID;
    uint32_t   programNumber;
    uint16_t   versionNumber;
    uint16_t   procedureValue;
    ByteBuffer arg;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(type, transactionID, programNumber, versionNumber, procedureValue, arg);
        if (type != Type::CALL) ERROR()
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(type, transactionID, programNumber, versionNumber, procedureValue, arg);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %04X  %d  %d  %d  (%d) %s}",
            courier::toString(type), transactionID, programNumber, versionNumber, procedureValue, arg.byteLimit(), arg.toString());
    }
};
struct ReturnMessage : public HasRead, public HasWrite, public HasToString {
    Type       type;
    uint16_t   transactionID;
    ByteBuffer arg;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(type, transactionID, arg);
        if (type != Type::RETURN) ERROR()
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(type, transactionID, arg);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %04X  (%d) %s}",
            courier::toString(type), transactionID, arg.byteLimit(), arg.toString());
    }
};
struct AborrMessage : public HasRead, public HasWrite, public HasToString {
    Type       type;
    uint16_t   transactionID;
    uint16_t   errorValue;
    ByteBuffer arg;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(type, transactionID, errorValue, arg);
        if (type != Type::ABORT) ERROR()
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(type, transactionID, errorValue, arg);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %04X  (%d) %s}",
            courier::toString(type), transactionID, arg.byteLimit(), arg.toString());
    }
};

struct MessageType : public HasRead, public HasWrite, public HasToString {
    enum class Type : uint16_t {
        ENUM_NAME_VALUE(Type, CALL,    0)
        ENUM_NAME_VALUE(Type, REJECT,  1)
        ENUM_NAME_VALUE(Type, RETURN,  2)
        ENUM_NAME_VALUE(Type, ABORT,   3)
    };
    static std::string toString(Type value);

    struct CallMessage : public HasRead, public HasWrite, public HasToString {
        uint16_t transactionID;
        uint32_t programNumber;
        uint16_t versionNumber;
        uint16_t procedureValue;
        ByteBuffer arg = ByteBuffer::Net::getInstance();

        ByteBuffer& read(ByteBuffer& bb) override {
            bb.read(transactionID, programNumber, versionNumber, procedureValue);
            arg = bb.rangeRemains();
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) override {
            bb.write(transactionID, programNumber, versionNumber, procedureValue);
            bb.write(arg.toSpan());
            return bb;
        }
        std::string toString() const override {
            return std_sprintf("{%04X  %d  %d  %d  (%d) %s}",
                transactionID, programNumber, versionNumber, procedureValue, arg.byteLimit(), arg.toString());
        }
    };
    struct RejectMessage : public HasRead, public HasWrite, public HasToString {
        enum class Type : uint16_t {
            ENUM_NAME_VALUE(Type, NO_SUCH_PROGRAM_NUMBER,  0)
            ENUM_NAME_VALUE(Type, NO_SUCH_VERSION_NUMBER,  1)
            ENUM_NAME_VALUE(Type, NO_SUCH_PROCEDURE_VALUE, 2)
            ENUM_NAME_VALUE(Type, INALID_ARGUMENT,         3)
            ENUM_NAME_VALUE(Type, UNSPECIFIED_ERROR,  0xFFFF)
        };
        static std::string toString(Type value);

        struct ImplementedVersionNumbers: public HasRead, public HasWrite, public HasToString {
            uint16_t lowest;
            uint16_t highest;

            ByteBuffer& read(ByteBuffer& bb) override {
                return bb.read(lowest, highest);
            }
            ByteBuffer& write(ByteBuffer& bb) override {
                return bb.write(lowest, highest);
            }
            std::string toString() const override {
                return std_sprintf("{%d %d}", lowest, highest);
            }
        };

        Type type;
        std::variant<std::monostate, ImplementedVersionNumbers> variant;

        RejectMessage() : type(Type::UNSPECIFIED_ERROR) {}
        RejectMessage(Type type_) : type(type_) {}
        RejectMessage(const ImplementedVersionNumbers& variant_) : type(Type::NO_SUCH_VERSION_NUMBER), variant(variant_) {}

        bool isNO_SUCH_VERSION_NUMBER() {
            return type == Type::NO_SUCH_VERSION_NUMBER;
        }
        const ImplementedVersionNumbers& toImplementedVersionNumbers() {
            return std::get<ImplementedVersionNumbers>(variant);
        }

        ByteBuffer& read(ByteBuffer& bb) override {
            bb.read(type);
            switch(type) {
            case Type::NO_SUCH_VERSION_NUMBER:
            {
                ImplementedVersionNumbers implementedVersionNumbers;
                bb.read(implementedVersionNumbers);
                variant = implementedVersionNumbers;
            }
                break;
            case Type::NO_SUCH_PROGRAM_NUMBER:
            case Type::NO_SUCH_PROCEDURE_VALUE:
            case Type::INALID_ARGUMENT:
            case Type::UNSPECIFIED_ERROR:
                variant = std::monostate();
                break;
            default:
                ERROR()
            }
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) override {
            bb.write(type);
            switch(type) {
            case Type::NO_SUCH_VERSION_NUMBER:
                bb.write(std::get<ImplementedVersionNumbers>(variant));
                break;
            case Type::NO_SUCH_PROGRAM_NUMBER:
            case Type::NO_SUCH_PROCEDURE_VALUE:
            case Type::INALID_ARGUMENT:
            case Type::UNSPECIFIED_ERROR:
                break;
            default:
                ERROR()
            }
            return bb;
        }
        std::string toString() const override {
            switch(type) {
            case Type::NO_SUCH_VERSION_NUMBER:
            {
                auto t = std::get<ImplementedVersionNumbers>(variant);
                return std_sprintf("{%s  %s}", toString(type), t.toString());
            }
            case Type::NO_SUCH_PROGRAM_NUMBER:
            case Type::NO_SUCH_PROCEDURE_VALUE:
            case Type::INALID_ARGUMENT:
            case Type::UNSPECIFIED_ERROR:
                return std_sprintf("{%s}", toString(type));
            default:
                ERROR()
            }
        }
    };
    struct ReturnMessage : public HasRead, public HasWrite, public HasToString {
        uint16_t transactionID;
        ByteBuffer arg = ByteBuffer::Net::getInstance();

        ByteBuffer& read(ByteBuffer& bb) override {
            bb.read(transactionID);
            arg = bb.rangeRemains();
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) override {
            bb.write(transactionID);
            bb.write(arg.toSpan());
            return bb;
        }
        std::string toString() const override {
            return std_sprintf("{%04X  (%d) %s}",
                transactionID, arg.byteLimit(), arg.toString());
        }
    };
    struct AbortMessage : public HasRead, public HasWrite, public HasToString {
        uint16_t transactionID;
        uint16_t errorValue;
        ByteBuffer arg = ByteBuffer::Net::getInstance();

        ByteBuffer& read(ByteBuffer& bb) override {
            bb.read(transactionID, errorValue);
            arg = bb.rangeRemains();
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) override {
            bb.write(transactionID, errorValue);
            bb.write(arg.toSpan());
            return bb;
        }
        std::string toString() const override {
            return std_sprintf("{%04X  %d  (%d) %s}",
                transactionID, errorValue, arg.byteLimit(), arg.toString());
        }
    };

    Type type;
    std::variant<CallMessage, RejectMessage, ReturnMessage, AbortMessage> variant;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(type);
        switch(type) {
            case Type::CALL:
            {
                CallMessage body;
                bb.read(body);
                variant = body;
            }
                break;
            case Type::REJECT:
            {
                RejectMessage body;
                bb.read(body);
                variant = body;
            }
                break;
            case Type::RETURN:
            {
                ReturnMessage body;
                bb.read(body);
                variant = body;
            }
            break;
            case Type::ABORT:
            {
                AbortMessage body;
                bb.read(body);
                variant = body;
            }
            break;
        }
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(type);
        switch(type) {
        case Type::CALL:
        {
            auto body = std::get<CallMessage>(variant);
            bb.write(body);
        }
            break;
        case Type::REJECT:
        {
            auto body = std::get<RejectMessage>(variant);
            bb.write(body);
        }
            break;
        case Type::RETURN:
        {
            auto body = std::get<ReturnMessage>(variant);
            bb.write(body);
        }
        break;
        case Type::ABORT:
        {
            auto body = std::get<AbortMessage>(variant);
            bb.write(body);
        }
            break;
        default:
            ERROR()
        }
        return bb;
    }
};

}

//
// Protocol
//
enum class Protocol : uint16_t {
    ENUM_NAME_VALUE(Protocol, PROTOCOL_2,    2)
    ENUM_NAME_VALUE(Protocol, PROTOCOL_3,    3)
};
std::string toString(Protocol value);

//
// ProtocolRange
//
struct ProtocolRange : public HasRead, public HasWrite, public HasToString {
    Protocol low;
    Protocol high;

    ProtocolRange() : low(Protocol::PROTOCOL_3), high(Protocol::PROTOCOL_3) {}

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(low, high);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(low, high);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %s}", courier::toString(low), courier::toString(high));
    }
};

//
// VersionRange
//
struct VersionRange : public HasRead, public HasWrite, public HasToString {
    uint16_t low;
    uint16_t high;

    VersionRange() : low(0), high() {}

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(low, high);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(low, high);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%d  %d}", low, high);
    }
};

//
// ExpeditedMessage
//
namespace expedited {
//
struct CallMessage : public HasRead, public HasWrite, public HasToString {
    ProtocolRange          range;
    protocol3::CallMessage message;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(range, message);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(range, message);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %s}", range.toString(), message.toString());
    }
};
struct ReturnMessage : public HasRead, public HasWrite, public HasToString {
    ProtocolRange            range;
    protocol3::ReturnMessage message;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(range, message);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) override {
        bb.write(range, message);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s  %s}", range.toString(), message.toString());
    }
};

}

}
