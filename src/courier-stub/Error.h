#ifndef STUB_Error_H__
#define STUB_Error_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace Error {

            // TYPE  Type  ENUM [UNSPECIFIED [[UNSPECIFIED_ERROR  0], [BAD_CHECKSUM  1], [NO_SOCKET  2], [RESOURCE_LIMIT  3], [LISTENER_REJCR  4], [INVALID_PACKET_TYPE  5], [PROTOCOL_VIOLATION  6]]]
            enum class Type : quint16 {
                UNSPECIFIED_ERROR   = 0,
                BAD_CHECKSUM        = 1,
                NO_SOCKET           = 2,
                RESOURCE_LIMIT      = 3,
                LISTENER_REJCR      = 4,
                INVALID_PACKET_TYPE = 5,
                PROTOCOL_VIOLATION  = 6,
            };

            // TYPE  Frame  RECORD [type: [REF Error::Type], parameter: UNSPECIFIED, data: BLOCK]
            //   RECORD [type: ENUM [UNSPECIFIED [[UNSPECIFIED_ERROR  0], [BAD_CHECKSUM  1], [NO_SOCKET  2], [RESOURCE_LIMIT  3], [LISTENER_REJCR  4], [INVALID_PACKET_TYPE  5], [PROTOCOL_VIOLATION  6]]], parameter: UNSPECIFIED, data: BLOCK]
            struct Frame {
                Type        type;
                UNSPECIFIED parameter;
                BLOCK       data{nullptr, 0};
            };

            // CONST  DATA_LENGTH_MIN  42  CARDINAL
            const CARDINAL DATA_LENGTH_MIN = 42;
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Error::Type value);

    void serialize(BLOCK& block, const Courier::Stub::Error::Type value);

    void deserialize(BLOCK& block, Courier::Stub::Error::Type& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Error::Frame& value);

    void serialize(BLOCK& block, const Courier::Stub::Error::Frame& value);

    void deserialize(BLOCK& block, Courier::Stub::Error::Frame& value);
}
#endif
