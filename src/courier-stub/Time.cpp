#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Time");

#include "../stub/Time.h"

#include "../courier/Last.h"


Courier::Stub::Time::PacketData::PacketData_REQUEST& Courier::Stub::Time::PacketData::REQUEST() const {
    if (choiceTag == CHOICE_TAG::REQUEST) {
        return choice_REQUEST;
    } else {
        logger.error("choiceTag  expect REQUEST  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Time::PacketData::PacketData_RESPONSE& Courier::Stub::Time::PacketData::RESPONSE() const {
    if (choiceTag == CHOICE_TAG::RESPONSE) {
        return choice_RESPONSE;
    } else {
        logger.error("choiceTag  expect RESPONSE  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Time::Type value) {
    static QMap<Courier::Stub::Time::Type, QString> map = {
        {Courier::Stub::Time::Type::REQUEST,  "REQUEST"},
        {Courier::Stub::Time::Type::RESPONSE, "RESPONSE"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Time::OffsetDirection value) {
    static QMap<Courier::Stub::Time::OffsetDirection, QString> map = {
        {Courier::Stub::Time::OffsetDirection::WEST, "WEST"},
        {Courier::Stub::Time::OffsetDirection::EAST, "EAST"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Time::ToleranceType value) {
    static QMap<Courier::Stub::Time::ToleranceType, QString> map = {
        {Courier::Stub::Time::ToleranceType::UNKNOWN,          "UNKNOWN"},
        {Courier::Stub::Time::ToleranceType::IN_MILLI_SECONDS, "IN_MILLI_SECONDS"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Time::Type value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Time::OffsetDirection value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Time::ToleranceType value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Time::Type& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Time::Type)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Time::OffsetDirection& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Time::OffsetDirection)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Time::ToleranceType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Time::ToleranceType)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Time::PacketData::PacketData_CHOICE_01&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Time::PacketData::PacketData_CHOICE_02& value) {
    QStringList list;
    // currentTime  LONG_CARDINAL
    list << QString("[%1 %2]").arg("currentTime").arg(Courier::toString(value.currentTime));
    // offsetDirection  [REF Time::OffsetDirection]
    //   ENUM [UNSPECIFIED [[WEST  0], [EAST  1]]]
    list << QString("[%1 %2]").arg("offsetDirection").arg(Courier::toString(value.offsetDirection));
    // offsetHours  CARDINAL
    list << QString("[%1 %2]").arg("offsetHours").arg(Courier::toString(value.offsetHours));
    // offsetMinutes  CARDINAL
    list << QString("[%1 %2]").arg("offsetMinutes").arg(Courier::toString(value.offsetMinutes));
    // startOfDST  CARDINAL
    list << QString("[%1 %2]").arg("startOfDST").arg(Courier::toString(value.startOfDST));
    // endOfDST  CARDINAL
    list << QString("[%1 %2]").arg("endOfDST").arg(Courier::toString(value.endOfDST));
    // toleranceType  [REF Time::ToleranceType]
    //   ENUM [UNSPECIFIED [[UNKNOWN  0], [IN_MILLI_SECONDS  1]]]
    list << QString("[%1 %2]").arg("toleranceType").arg(Courier::toString(value.toleranceType));
    // tolerance  LONG_CARDINAL
    list << QString("[%1 %2]").arg("tolerance").arg(Courier::toString(value.tolerance));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Time::Packet& value) {
    QStringList list;
    // version  [REF Time::Version]
    //   CARDINAL
    list << QString("[%1 %2]").arg("version").arg(Courier::toString(value.version));
    // data  [REF Time::PacketData]
    //   [CHOICE ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]] [[[REQUEST] => RECORD []], [[RESPONSE] => RECORD [currentTime: LONG_CARDINAL, offsetDirection: [REF Time::OffsetDirection], offsetHours: CARDINAL, offsetMinutes: CARDINAL, startOfDST: CARDINAL, endOfDST: CARDINAL, toleranceType: [REF Time::ToleranceType], tolerance: LONG_CARDINAL]]]]
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK&, const Courier::Stub::Time::PacketData::PacketData_CHOICE_01&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Time::PacketData::PacketData_CHOICE_02& value) {
    // currentTime  LONG_CARDINAL
    Courier::serialize(block, value.currentTime);
    // offsetDirection  [REF Time::OffsetDirection]
    //   ENUM [UNSPECIFIED [[WEST  0], [EAST  1]]]
    Courier::serialize(block, value.offsetDirection);
    // offsetHours  CARDINAL
    Courier::serialize(block, value.offsetHours);
    // offsetMinutes  CARDINAL
    Courier::serialize(block, value.offsetMinutes);
    // startOfDST  CARDINAL
    Courier::serialize(block, value.startOfDST);
    // endOfDST  CARDINAL
    Courier::serialize(block, value.endOfDST);
    // toleranceType  [REF Time::ToleranceType]
    //   ENUM [UNSPECIFIED [[UNKNOWN  0], [IN_MILLI_SECONDS  1]]]
    Courier::serialize(block, value.toleranceType);
    // tolerance  LONG_CARDINAL
    Courier::serialize(block, value.tolerance);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Time::Packet& value) {
    // version  [REF Time::Version]
    //   CARDINAL
    Courier::serialize(block, value.version);
    // data  [REF Time::PacketData]
    //   [CHOICE ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]] [[[REQUEST] => RECORD []], [[RESPONSE] => RECORD [currentTime: LONG_CARDINAL, offsetDirection: [REF Time::OffsetDirection], offsetHours: CARDINAL, offsetMinutes: CARDINAL, startOfDST: CARDINAL, endOfDST: CARDINAL, toleranceType: [REF Time::ToleranceType], tolerance: LONG_CARDINAL]]]]
    Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK&, Courier::Stub::Time::PacketData::PacketData_CHOICE_01&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Time::PacketData::PacketData_CHOICE_02& value) {
    // currentTime  LONG_CARDINAL
    Courier::deserialize(block, value.currentTime);
    // offsetDirection  [REF Time::OffsetDirection]
    //   ENUM [UNSPECIFIED [[WEST  0], [EAST  1]]]
    Courier::deserialize(block, value.offsetDirection);
    // offsetHours  CARDINAL
    Courier::deserialize(block, value.offsetHours);
    // offsetMinutes  CARDINAL
    Courier::deserialize(block, value.offsetMinutes);
    // startOfDST  CARDINAL
    Courier::deserialize(block, value.startOfDST);
    // endOfDST  CARDINAL
    Courier::deserialize(block, value.endOfDST);
    // toleranceType  [REF Time::ToleranceType]
    //   ENUM [UNSPECIFIED [[UNKNOWN  0], [IN_MILLI_SECONDS  1]]]
    Courier::deserialize(block, value.toleranceType);
    // tolerance  LONG_CARDINAL
    Courier::deserialize(block, value.tolerance);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Time::Packet& value) {
    // version  [REF Time::Version]
    //   CARDINAL
    Courier::deserialize(block, value.version);
    // data  [REF Time::PacketData]
    //   [CHOICE ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]] [[[REQUEST] => RECORD []], [[RESPONSE] => RECORD [currentTime: LONG_CARDINAL, offsetDirection: [REF Time::OffsetDirection], offsetHours: CARDINAL, offsetMinutes: CARDINAL, startOfDST: CARDINAL, endOfDST: CARDINAL, toleranceType: [REF Time::ToleranceType], tolerance: LONG_CARDINAL]]]]
    Courier::deserialize(block, value.data);
}

//
// Choice Function Definition
//
QString Courier::toString(const Courier::Stub::Time::PacketData& value) {
    switch(value.choiceTag) {
    case Courier::Stub::Time::PacketData::CHOICE_TAG::REQUEST:
        return QString("[%1 %2]").arg("REQUEST").arg(Courier::toString(value.REQUEST()));
    case Courier::Stub::Time::PacketData::CHOICE_TAG::RESPONSE:
        return QString("[%1 %2]").arg("RESPONSE").arg(Courier::toString(value.RESPONSE()));
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Time::PacketData& value) {
    block.serialize16((quint16)value.choiceTag);
    switch(value.choiceTag) {
    case Courier::Stub::Time::PacketData::CHOICE_TAG::REQUEST:
        Courier::serialize(block, value.REQUEST());
        break;
    case Courier::Stub::Time::PacketData::CHOICE_TAG::RESPONSE:
        Courier::serialize(block, value.RESPONSE());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Time::PacketData& value) {
    quint16 choiceTag_;
    block.deserialize16(choiceTag_);
    value.choiceTag = (Courier::Stub::Time::PacketData::CHOICE_TAG)choiceTag_;
    switch(value.choiceTag) {
    case Courier::Stub::Time::PacketData::CHOICE_TAG::REQUEST:
        Courier::deserialize(block, value.REQUEST());
        break;
    case Courier::Stub::Time::PacketData::CHOICE_TAG::RESPONSE:
        Courier::deserialize(block, value.RESPONSE());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
