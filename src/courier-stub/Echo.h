#ifndef STUB_Echo_H__
#define STUB_Echo_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace Echo {

            // TYPE  Type  ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
            enum class Type : quint16 {
                REQUEST  = 1,
                RESPONSE = 2,
            };

            // TYPE  Frame  RECORD [type: [REF Echo::Type], data: BLOCK]
            //   RECORD [type: ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]], data: BLOCK]
            struct Frame {
                Type  type;
                BLOCK data{nullptr, 0};
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Echo::Type value);

    void serialize(BLOCK& block, const Courier::Stub::Echo::Type value);

    void deserialize(BLOCK& block, Courier::Stub::Echo::Type& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Echo::Frame& value);

    void serialize(BLOCK& block, const Courier::Stub::Echo::Frame& value);

    void deserialize(BLOCK& block, Courier::Stub::Echo::Frame& value);
}
#endif
