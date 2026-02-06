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
#include <type_traits>
#include <variant>
#include <vector>

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


//
// SEQUENCE
//
// use std::vector for SEQUENCE

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
struct CallMessage {
    Type       type;
    uint16_t   transactionID;
    uint32_t   programNumber;
    uint16_t   versionNumber;
    uint16_t   procedureValue;
    ByteBuffer arg;

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(type, transactionID, programNumber, versionNumber, procedureValue, arg);
        if (type != Type::CALL) ERROR()
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(type, transactionID, programNumber, versionNumber, procedureValue, arg);
        return bb;
    }
    std::string toString() const {
        return std_sprintf("{%s  %04X  %d  %d  %d  (%d) %s}",
            courier::toString(type), transactionID, programNumber, versionNumber, procedureValue, arg.byteLimit(), arg.toString());
    }
};
struct ReturnMessage {
    Type       type;
    uint16_t   transactionID;
    ByteBuffer arg;

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(type, transactionID, arg);
        if (type != Type::RETURN) ERROR()
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(type, transactionID, arg);
        return bb;
    }
    std::string toString() const {
        return std_sprintf("{%s  %04X  (%d) %s}",
            courier::toString(type), transactionID, arg.byteLimit(), arg.toString());
    }
};
struct AbortMessage {
    Type       type;
    uint16_t   transactionID;
    uint16_t   errorValue;
    ByteBuffer arg;

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(type, transactionID, errorValue, arg);
        if (type != Type::ABORT) ERROR()
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(type, transactionID, errorValue, arg);
        return bb;
    }
    std::string toString() const {
        return std_sprintf("{%s  %04X  (%d) %s}",
            courier::toString(type), transactionID, arg.byteLimit(), arg.toString());
    }
};

struct MessageType {
    enum class Type : uint16_t {
        ENUM_NAME_VALUE(Type, CALL,    0)
        ENUM_NAME_VALUE(Type, REJECT,  1)
        ENUM_NAME_VALUE(Type, RETURN,  2)
        ENUM_NAME_VALUE(Type, ABORT,   3)
    };
    static std::string toString(Type value);

    struct CallMessage {
        uint16_t transactionID;
        uint32_t programNumber;
        uint16_t versionNumber;
        uint16_t procedureValue;
        ByteBuffer arg;

        ByteBuffer& read(ByteBuffer& bb) {
            bb.read(transactionID, programNumber, versionNumber, procedureValue);
            arg = bb.rangeRemains();
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) {
            bb.write(transactionID, programNumber, versionNumber, procedureValue);
            bb.write(arg.toSpan());
            return bb;
        }
        std::string toString() const {
            return std_sprintf("{%04X  %d  %d  %d  (%d) %s}",
                transactionID, programNumber, versionNumber, procedureValue, arg.byteLimit(), arg.toString());
        }
    };
    struct RejectMessage {
        enum class Type : uint16_t {
            ENUM_NAME_VALUE(Type, NO_SUCH_PROGRAM_NUMBER,  0)
            ENUM_NAME_VALUE(Type, NO_SUCH_VERSION_NUMBER,  1)
            ENUM_NAME_VALUE(Type, NO_SUCH_PROCEDURE_VALUE, 2)
            ENUM_NAME_VALUE(Type, INALID_ARGUMENT,         3)
            ENUM_NAME_VALUE(Type, UNSPECIFIED_ERROR,  0xFFFF)
        };
        static std::string toString(Type value);

        struct ImplementedVersionNumbers{
            uint16_t lowest;
            uint16_t highest;

            ByteBuffer& read(ByteBuffer& bb) {
                bb.read(lowest, highest);
                return bb;
            }
            ByteBuffer& write(ByteBuffer& bb) {
                bb.write(lowest, highest);
                return bb;
            }
            std::string toString() const {
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

        ByteBuffer& read(ByteBuffer& bb) {
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
        ByteBuffer& write(ByteBuffer& bb) {
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
        std::string toString() const {
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
    struct ReturnMessage {
        uint16_t transactionID;
        ByteBuffer arg;

        ByteBuffer& read(ByteBuffer& bb) {
            bb.read(transactionID);
            arg = bb.rangeRemains();
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) {
            bb.write(transactionID);
            bb.write(arg.toSpan());
            return bb;
        }
        std::string toString() const {
            return std_sprintf("{%04X  (%d) %s}",
                transactionID, arg.byteLimit(), arg.toString());
        }
    };
    struct AbortMessage {
        uint16_t transactionID;
        uint16_t errorValue;
        ByteBuffer arg;

        ByteBuffer& read(ByteBuffer& bb) {
            bb.read(transactionID, errorValue);
            arg = bb.rangeRemains();
            return bb;
        }
        ByteBuffer& write(ByteBuffer& bb) {
            bb.write(transactionID, errorValue);
            bb.write(arg.toSpan());
            return bb;
        }
        std::string toString() const {
            return std_sprintf("{%04X  %d  (%d) %s}",
                transactionID, errorValue, arg.byteLimit(), arg.toString());
        }
    };

    Type type;
    std::variant<CallMessage, RejectMessage, ReturnMessage, AbortMessage> variant;

    ByteBuffer& read(ByteBuffer& bb) {
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
    ByteBuffer& write(ByteBuffer& bb) {
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
struct ProtocolRange {
    Protocol low;
    Protocol high;

    ProtocolRange() : low(Protocol::PROTOCOL_3), high(Protocol::PROTOCOL_3) {}

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(low, high);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(low, high);
        return bb;
    }
    std::string toString() const {
        return std_sprintf("{%s  %s}", courier::toString(low), courier::toString(high));
    }
};

//
// VersionRange
//
struct VersionRange {
    uint16_t low;
    uint16_t high;

    VersionRange() : low(0), high() {}

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(low, high);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(low, high);
        return bb;
    }
    std::string toString() const {
        return std_sprintf("{%d  %d}", low, high);
    }
};

//
// ExpeditedMessage
//
namespace expedited {
//
struct CallMessage {
    ProtocolRange          range;
    protocol3::CallMessage message;

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(range, message);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(range, message);
        return bb;
    }
    std::string toString() const {
        return std_sprintf("{%s  %s}", range.toString(), message.toString());
    }
};
struct ReturnMessage {
    ProtocolRange            range;
    protocol3::ReturnMessage message;

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(range, message);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(range, message);
        return bb;
    }
    std::string toString() const {
        return std_sprintf("{%s  %s}", range.toString(), message.toString());
    }
};

}

}
