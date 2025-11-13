#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Boot");

#include "../stub/Boot.h"

#include "../courier/Last.h"


Courier::Stub::Boot::BootFileRequest::BootFileRequest_simpleRequest& Courier::Stub::Boot::BootFileRequest::simpleRequest() const {
    if (choiceTag == CHOICE_TAG::simpleRequest) {
        return choice_simpleRequest;
    } else {
        logger.error("choiceTag  expect simpleRequest  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Boot::BootFileRequest::BootFileRequest_simpleData& Courier::Stub::Boot::BootFileRequest::simpleData() const {
    if (choiceTag == CHOICE_TAG::simpleData) {
        return choice_simpleData;
    } else {
        logger.error("choiceTag  expect simpleData  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Boot::BootFileRequest::BootFileRequest_sppRequest& Courier::Stub::Boot::BootFileRequest::sppRequest() const {
    if (choiceTag == CHOICE_TAG::sppRequest) {
        return choice_sppRequest;
    } else {
        logger.error("choiceTag  expect sppRequest  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Boot::EtherBootPacketType value) {
    static QMap<Courier::Stub::Boot::EtherBootPacketType, QString> map = {
        {Courier::Stub::Boot::EtherBootPacketType::simpleRequest, "simpleRequest"},
        {Courier::Stub::Boot::EtherBootPacketType::simpleData,    "simpleData"},
        {Courier::Stub::Boot::EtherBootPacketType::sppRequest,    "sppRequest"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Boot::EtherBootPacketType value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Boot::EtherBootPacketType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Boot::EtherBootPacketType)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_01& value) {
    QStringList list;
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    list << QString("[%1 %2]").arg("bootFileNumber").arg(Courier::toString(value.bootFileNumber));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_02& value) {
    QStringList list;
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    list << QString("[%1 %2]").arg("bootFileNumber").arg(Courier::toString(value.bootFileNumber));
    // packetNumber  CARDINAL
    list << QString("[%1 %2]").arg("packetNumber").arg(Courier::toString(value.packetNumber));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_03& value) {
    QStringList list;
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    list << QString("[%1 %2]").arg("bootFileNumber").arg(Courier::toString(value.bootFileNumber));
    // connectionID  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    list << QString("[%1 %2]").arg("connectionID").arg(Courier::toString(value.connectionID));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_01& value) {
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::serialize(block, value.bootFileNumber);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_02& value) {
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::serialize(block, value.bootFileNumber);
    // packetNumber  CARDINAL
    Courier::serialize(block, value.packetNumber);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_03& value) {
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::serialize(block, value.bootFileNumber);
    // connectionID  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    Courier::serialize(block, value.connectionID);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_01& value) {
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::deserialize(block, value.bootFileNumber);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_02& value) {
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::deserialize(block, value.bootFileNumber);
    // packetNumber  CARDINAL
    Courier::deserialize(block, value.packetNumber);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest::BootFileRequest_CHOICE_03& value) {
    // bootFileNumber  [REF Boot::EthernetBootFileNumber]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::deserialize(block, value.bootFileNumber);
    // connectionID  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    Courier::deserialize(block, value.connectionID);
}

//
// Choice Function Definition
//
QString Courier::toString(const Courier::Stub::Boot::BootFileRequest& value) {
    switch(value.choiceTag) {
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::simpleRequest:
        return QString("[%1 %2]").arg("simpleRequest").arg(Courier::toString(value.simpleRequest()));
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::simpleData:
        return QString("[%1 %2]").arg("simpleData").arg(Courier::toString(value.simpleData()));
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::sppRequest:
        return QString("[%1 %2]").arg("sppRequest").arg(Courier::toString(value.sppRequest()));
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Boot::BootFileRequest& value) {
    block.serialize16((quint16)value.choiceTag);
    switch(value.choiceTag) {
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::simpleRequest:
        Courier::serialize(block, value.simpleRequest());
        break;
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::simpleData:
        Courier::serialize(block, value.simpleData());
        break;
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::sppRequest:
        Courier::serialize(block, value.sppRequest());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Boot::BootFileRequest& value) {
    quint16 choiceTag_;
    block.deserialize16(choiceTag_);
    value.choiceTag = (Courier::Stub::Boot::BootFileRequest::CHOICE_TAG)choiceTag_;
    switch(value.choiceTag) {
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::simpleRequest:
        Courier::deserialize(block, value.simpleRequest());
        break;
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::simpleData:
        Courier::deserialize(block, value.simpleData());
        break;
    case Courier::Stub::Boot::BootFileRequest::CHOICE_TAG::sppRequest:
        Courier::deserialize(block, value.sppRequest());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
