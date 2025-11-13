#ifndef STUB_Boot_H__
#define STUB_Boot_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

#include "../stub/IDP.h"
#include "../stub/SequencedPacket.h"

namespace Courier {
    namespace Stub {
        namespace Boot {

            // TYPE  EtherBootPacketType  ENUM [UNSPECIFIED [[simpleRequest  1], [simpleData  2], [sppRequest  3]]]
            enum class EtherBootPacketType : quint16 {
                simpleRequest = 1,
                simpleData    = 2,
                sppRequest    = 3,
            };

            // TYPE  EthernetBootFileNumber  [REF IDP::Host]
            //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
            using EthernetBootFileNumber = IDP::Host;

            // TYPE  BootFileRequest  [CHOICE [REF Boot::EtherBootPacketType] [[[simpleRequest] => RECORD [bootFileNumber: [REF Boot::EthernetBootFileNumber]]], [[simpleData] => RECORD [bootFileNumber: [REF Boot::EthernetBootFileNumber], packetNumber: CARDINAL]], [[sppRequest] => RECORD [bootFileNumber: [REF Boot::EthernetBootFileNumber], connectionID: [REF SequencedPacket::ConnectionID]]]]]
            //   [CHOICE ENUM [UNSPECIFIED [[simpleRequest  1], [simpleData  2], [sppRequest  3]]] [[[simpleRequest] => RECORD [bootFileNumber: [REF Boot::EthernetBootFileNumber]]], [[simpleData] => RECORD [bootFileNumber: [REF Boot::EthernetBootFileNumber], packetNumber: CARDINAL]], [[sppRequest] => RECORD [bootFileNumber: [REF Boot::EthernetBootFileNumber], connectionID: [REF SequencedPacket::ConnectionID]]]]]
            struct BootFileRequest {
                struct BootFileRequest_CHOICE_01 {
                    EthernetBootFileNumber bootFileNumber;
                };
                struct BootFileRequest_CHOICE_02 {
                    EthernetBootFileNumber bootFileNumber;
                    CARDINAL               packetNumber;
                };
                struct BootFileRequest_CHOICE_03 {
                    EthernetBootFileNumber        bootFileNumber;
                    SequencedPacket::ConnectionID connectionID;
                };
                // Provide alias for code readability
                using BootFileRequest_simpleRequest = BootFileRequest_CHOICE_01;
                using BootFileRequest_simpleData    = BootFileRequest_CHOICE_02;
                using BootFileRequest_sppRequest    = BootFileRequest_CHOICE_03;

                using CHOICE_TAG = EtherBootPacketType;
                CHOICE_TAG choiceTag;

                BootFileRequest_simpleRequest& simpleRequest() const;
                BootFileRequest_simpleData&    simpleData()    const;
                BootFileRequest_sppRequest&    sppRequest()    const;
            private:
                mutable BootFileRequest_simpleRequest choice_simpleRequest;
                mutable BootFileRequest_simpleData    choice_simpleData;
                mutable BootFileRequest_sppRequest    choice_sppRequest;
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Boot::EtherBootPacketType value);

    void serialize(BLOCK& block, const Courier::Stub::Boot::EtherBootPacketType value);

    void deserialize(BLOCK& block, Courier::Stub::Boot::EtherBootPacketType& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_01& value);
    QString toString(const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_02& value);
    QString toString(const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_03& value);

    void serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_01& value);
    void serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_02& value);
    void serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_03& value);

    void deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_01& value);
    void deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_02& value);
    void deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_03& value);

    //
    // Choice Function Declaration
    //
    QString toString(const Courier::Stub::Boot::BootFileRequest& value);

    void serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest& value);

    void deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest& value);
}
#endif
