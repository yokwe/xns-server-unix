#ifndef STUB_Ethernet_H__
#define STUB_Ethernet_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace Ethernet {

            // TYPE  Host  ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
            enum class Host : quint64 {
                ALL = 0xFFFFFFFFFFFFU,
            };

            // TYPE  Type  ENUM [UNSPECIFIED [[PUP  512], [IDP  1536], [IP4  2048]]]
            enum class Type : quint16 {
                PUP = 0x200,
                IDP = 0x600,
                IP4 = 0x800,
            };

            // TYPE  Frame  RECORD [dst: [REF Ethernet::Host], src: [REF Ethernet::Host], type: [REF Ethernet::Type], data: BLOCK]
            //   RECORD [dst: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], src: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], type: ENUM [UNSPECIFIED [[PUP  512], [IDP  1536], [IP4  2048]]], data: BLOCK]
            struct Frame {
                Host  dst;
                Host  src;
                Type  type;
                BLOCK data{nullptr, 0};
            };

            // CONST  HEADER_LENGTH  14  CARDINAL
            const CARDINAL HEADER_LENGTH = 14;

            // CONST  DATA_LENGTH_MIN  46  CARDINAL
            const CARDINAL DATA_LENGTH_MIN = 46;

            // CONST  DATA_LENGTH_MAX  1500  CARDINAL
            const CARDINAL DATA_LENGTH_MAX = 1500;

            // CONST  FRAME_LENGTH_MIN  60  CARDINAL
            const CARDINAL FRAME_LENGTH_MIN = 60;

            // CONST  FRAME_LENGTH_MAX  1514  CARDINAL
            const CARDINAL FRAME_LENGTH_MAX = 1514;
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Ethernet::Host value);
    QString toString(const Courier::Stub::Ethernet::Type value);

    void serialize(BLOCK& block, const Courier::Stub::Ethernet::Host value);
    void serialize(BLOCK& block, const Courier::Stub::Ethernet::Type value);

    void deserialize(BLOCK& block, Courier::Stub::Ethernet::Host& value);
    void deserialize(BLOCK& block, Courier::Stub::Ethernet::Type& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Ethernet::Frame& value);

    void serialize(BLOCK& block, const Courier::Stub::Ethernet::Frame& value);

    void deserialize(BLOCK& block, Courier::Stub::Ethernet::Frame& value);
}
#endif
