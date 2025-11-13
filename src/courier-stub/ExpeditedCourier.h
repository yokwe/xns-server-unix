#ifndef STUB_ExpeditedCourier_H__
#define STUB_ExpeditedCourier_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

#include "../stub/Protocol.h"

namespace Courier {
    namespace Stub {
        namespace ExpeditedCourier {

            // TYPE  Frame  RECORD [protocolRange: [REF Protocol::ProtocolRange], message: [REF Protocol::Protocol3], data: BLOCK]
            //   RECORD [protocolRange: RECORD [low: [REF Protocol::ProtocolType], high: [REF Protocol::ProtocolType]], message: [CHOICE [REF Protocol::MessageType] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]], data: BLOCK]
            struct Frame {
                Protocol::ProtocolRange protocolRange;
                Protocol::Protocol3     message;
                BLOCK                   data{nullptr, 0};
            };
        }
    }

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::ExpeditedCourier::Frame& value);

    void serialize(BLOCK& block, const Courier::Stub::ExpeditedCourier::Frame& value);

    void deserialize(BLOCK& block, Courier::Stub::ExpeditedCourier::Frame& value);
}
#endif
