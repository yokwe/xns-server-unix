#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Error");

#include "../stub/Error.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Error::Type value) {
    static QMap<Courier::Stub::Error::Type, QString> map = {
        {Courier::Stub::Error::Type::UNSPECIFIED_ERROR,   "UNSPECIFIED_ERROR"},
        {Courier::Stub::Error::Type::BAD_CHECKSUM,        "BAD_CHECKSUM"},
        {Courier::Stub::Error::Type::NO_SOCKET,           "NO_SOCKET"},
        {Courier::Stub::Error::Type::RESOURCE_LIMIT,      "RESOURCE_LIMIT"},
        {Courier::Stub::Error::Type::LISTENER_REJCR,      "LISTENER_REJCR"},
        {Courier::Stub::Error::Type::INVALID_PACKET_TYPE, "INVALID_PACKET_TYPE"},
        {Courier::Stub::Error::Type::PROTOCOL_VIOLATION,  "PROTOCOL_VIOLATION"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Error::Type value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Error::Type& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Error::Type)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Error::Frame& value) {
    QStringList list;
    // type  [REF Error::Type]
    //   ENUM [UNSPECIFIED [[UNSPECIFIED_ERROR  0], [BAD_CHECKSUM  1], [NO_SOCKET  2], [RESOURCE_LIMIT  3], [LISTENER_REJCR  4], [INVALID_PACKET_TYPE  5], [PROTOCOL_VIOLATION  6]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // parameter  UNSPECIFIED
    list << QString("[%1 %2]").arg("parameter").arg(Courier::toString(value.parameter));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Error::Frame& value) {
    // type  [REF Error::Type]
    //   ENUM [UNSPECIFIED [[UNSPECIFIED_ERROR  0], [BAD_CHECKSUM  1], [NO_SOCKET  2], [RESOURCE_LIMIT  3], [LISTENER_REJCR  4], [INVALID_PACKET_TYPE  5], [PROTOCOL_VIOLATION  6]]]
    Courier::serialize(block, value.type);
    // parameter  UNSPECIFIED
    Courier::serialize(block, value.parameter);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Error::Frame& value) {
    // type  [REF Error::Type]
    //   ENUM [UNSPECIFIED [[UNSPECIFIED_ERROR  0], [BAD_CHECKSUM  1], [NO_SOCKET  2], [RESOURCE_LIMIT  3], [LISTENER_REJCR  4], [INVALID_PACKET_TYPE  5], [PROTOCOL_VIOLATION  6]]]
    Courier::deserialize(block, value.type);
    // parameter  UNSPECIFIED
    Courier::deserialize(block, value.parameter);
    // data  BLOCK
    value.data = block.remainder();
}
