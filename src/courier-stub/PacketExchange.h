#ifndef STUB_PacketExchange_H__
#define STUB_PacketExchange_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace PacketExchange {

            // TYPE  Type  ENUM [UNSPECIFIED [[UNSPEC  0], [TIME  1], [CHS  2], [TELE_DEBUG  3]]]
            enum class Type : quint16 {
                UNSPEC     = 0,
                TIME       = 1,
                CHS        = 2,
                TELE_DEBUG = 3,
            };

            // TYPE  Frame  RECORD [id: UNSPECIFIED2, type: [REF PacketExchange::Type], data: BLOCK]
            //   RECORD [id: UNSPECIFIED2, type: ENUM [UNSPECIFIED [[UNSPEC  0], [TIME  1], [CHS  2], [TELE_DEBUG  3]]], data: BLOCK]
            struct Frame {
                UNSPECIFIED2 id;
                Type         type;
                BLOCK        data{nullptr, 0};
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::PacketExchange::Type value);

    void serialize(BLOCK& block, const Courier::Stub::PacketExchange::Type value);

    void deserialize(BLOCK& block, Courier::Stub::PacketExchange::Type& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::PacketExchange::Frame& value);

    void serialize(BLOCK& block, const Courier::Stub::PacketExchange::Frame& value);

    void deserialize(BLOCK& block, Courier::Stub::PacketExchange::Frame& value);
}
#endif
