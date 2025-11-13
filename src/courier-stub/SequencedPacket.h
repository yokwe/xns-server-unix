#ifndef STUB_SequencedPacket_H__
#define STUB_SequencedPacket_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace SequencedPacket {

            // TYPE  ConnectionID  UNSPECIFIED
            using ConnectionID = UNSPECIFIED;

            // TYPE  SequenceNumber  UNSPECIFIED
            using SequenceNumber = UNSPECIFIED;

            // TYPE  Control  MACHINE BYTE [system: (0..0) BOOLEAN, sendAck: (1..1) BOOLEAN, attention: (2..2) BOOLEAN, endMessage: (3..3) BOOLEAN, reserve: (4..7) UNSPECIFIED]
            struct Control /* BYTE */ {
                BOOLEAN     system;     // 0 .. 0
                BOOLEAN     sendAck;    // 1 .. 1
                BOOLEAN     attention;  // 2 .. 2
                BOOLEAN     endMessage; // 3 .. 3
                UNSPECIFIED reserve;    // 4 .. 7
            };

            // TYPE  Type  ENUM [BYTE [[DATA  0], [BULK  1], [CLOSE  254], [CLOSE_REPLY  255]]]
            enum class Type : quint8 {
                DATA        =    0,
                BULK        =    1,
                CLOSE       = 0xFE,
                CLOSE_REPLY = 0xFF,
            };

            // TYPE  Frame  RECORD [control: [REF SequencedPacket::Control], type: [REF SequencedPacket::Type], src: [REF SequencedPacket::ConnectionID], dst: [REF SequencedPacket::ConnectionID], seq: [REF SequencedPacket::SequenceNumber], ack: [REF SequencedPacket::SequenceNumber], alloc: [REF SequencedPacket::SequenceNumber], data: BLOCK]
            //   RECORD [control: MACHINE BYTE [system: (0..0) BOOLEAN, sendAck: (1..1) BOOLEAN, attention: (2..2) BOOLEAN, endMessage: (3..3) BOOLEAN, reserve: (4..7) UNSPECIFIED], type: ENUM [BYTE [[DATA  0], [BULK  1], [CLOSE  254], [CLOSE_REPLY  255]]], src: UNSPECIFIED, dst: UNSPECIFIED, seq: UNSPECIFIED, ack: UNSPECIFIED, alloc: UNSPECIFIED, data: BLOCK]
            struct Frame {
                Control        control;
                Type           type;
                ConnectionID   src;
                ConnectionID   dst;
                SequenceNumber seq;
                SequenceNumber ack;
                SequenceNumber alloc;
                BLOCK          data{nullptr, 0};
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::SequencedPacket::Type value);

    void serialize(BLOCK& block, const Courier::Stub::SequencedPacket::Type value);

    void deserialize(BLOCK& block, Courier::Stub::SequencedPacket::Type& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::SequencedPacket::Frame& value);

    void serialize(BLOCK& block, const Courier::Stub::SequencedPacket::Frame& value);

    void deserialize(BLOCK& block, Courier::Stub::SequencedPacket::Frame& value);

    //
    // Machine Function Declaration
    //
    QString toString(const Courier::Stub::SequencedPacket::Control& value);

    void serialize(BLOCK& block, const Courier::Stub::SequencedPacket::Control& value);

    void deserialize(BLOCK& block, Courier::Stub::SequencedPacket::Control& value);
}
#endif
