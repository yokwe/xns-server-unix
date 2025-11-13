#ifndef STUB_Routing_H__
#define STUB_Routing_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

#include "../stub/IDP.h"

namespace Courier {
    namespace Stub {
        namespace Routing {

            // TYPE  Type  ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
            enum class Type : quint16 {
                REQUEST  = 1,
                RESPONSE = 2,
            };

            // TYPE  Hop  ENUM [UNSPECIFIED [[MAX  16]]]
            enum class Hop : quint16 {
                MAX = 16,
            };

            // TYPE  Tuple  RECORD [network: [REF IDP::Network], hop: [REF Routing::Hop]]
            //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], hop: ENUM [UNSPECIFIED [[MAX  16]]]]
            struct Tuple {
                IDP::Network network;
                Hop          hop;
            };

            // TYPE  Frame  RECORD [type: [REF Routing::Type], data: BLOCK]
            //   RECORD [type: ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]], data: BLOCK]
            struct Frame {
                Type  type;
                BLOCK data{nullptr, 0};
            };

            // CONST  tupleLength  6  CARDINAL
            const CARDINAL tupleLength = 6;
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Routing::Type value);
    QString toString(const Courier::Stub::Routing::Hop  value);

    void serialize(BLOCK& block, const Courier::Stub::Routing::Type value);
    void serialize(BLOCK& block, const Courier::Stub::Routing::Hop  value);

    void deserialize(BLOCK& block, Courier::Stub::Routing::Type& value);
    void deserialize(BLOCK& block, Courier::Stub::Routing::Hop&  value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Routing::Tuple& value);
    QString toString(const Courier::Stub::Routing::Frame& value);

    void serialize(BLOCK& block, const Courier::Stub::Routing::Tuple& value);
    void serialize(BLOCK& block, const Courier::Stub::Routing::Frame& value);

    void deserialize(BLOCK& block, Courier::Stub::Routing::Tuple& value);
    void deserialize(BLOCK& block, Courier::Stub::Routing::Frame& value);
}
#endif
