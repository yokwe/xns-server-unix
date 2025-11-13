#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/ExpeditedCourier");

#include "../stub/ExpeditedCourier.h"

#include "../courier/Last.h"


//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::ExpeditedCourier::Frame& value) {
    QStringList list;
    // protocolRange  [REF Protocol::ProtocolRange]
    //   RECORD [low: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]], high: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]]
    list << QString("[%1 %2]").arg("protocolRange").arg(Courier::toString(value.protocolRange));
    // message  [REF Protocol::Protocol3]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
    list << QString("[%1 %2]").arg("message").arg(Courier::toString(value.message));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::ExpeditedCourier::Frame& value) {
    // protocolRange  [REF Protocol::ProtocolRange]
    //   RECORD [low: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]], high: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]]
    Courier::serialize(block, value.protocolRange);
    // message  [REF Protocol::Protocol3]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
    Courier::serialize(block, value.message);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::ExpeditedCourier::Frame& value) {
    // protocolRange  [REF Protocol::ProtocolRange]
    //   RECORD [low: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]], high: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]]
    Courier::deserialize(block, value.protocolRange);
    // message  [REF Protocol::Protocol3]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
    Courier::deserialize(block, value.message);
    // data  BLOCK
    value.data = block.remainder();
}
