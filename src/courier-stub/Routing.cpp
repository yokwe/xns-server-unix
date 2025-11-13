#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Routing");

#include "../stub/Routing.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Routing::Type value) {
    static QMap<Courier::Stub::Routing::Type, QString> map = {
        {Courier::Stub::Routing::Type::REQUEST,  "REQUEST"},
        {Courier::Stub::Routing::Type::RESPONSE, "RESPONSE"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Routing::Hop value) {
    static QMap<Courier::Stub::Routing::Hop, QString> map = {
        {Courier::Stub::Routing::Hop::MAX, "MAX"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Routing::Type value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Routing::Hop value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Routing::Type& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Routing::Type)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Routing::Hop& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Routing::Hop)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Routing::Tuple& value) {
    QStringList list;
    // network  [REF IDP::Network]
    //   ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]]
    list << QString("[%1 %2]").arg("network").arg(Courier::toString(value.network));
    // hop  [REF Routing::Hop]
    //   ENUM [UNSPECIFIED [[MAX  16]]]
    list << QString("[%1 %2]").arg("hop").arg(Courier::toString(value.hop));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Routing::Frame& value) {
    QStringList list;
    // type  [REF Routing::Type]
    //   ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Routing::Tuple& value) {
    // network  [REF IDP::Network]
    //   ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]]
    Courier::serialize(block, value.network);
    // hop  [REF Routing::Hop]
    //   ENUM [UNSPECIFIED [[MAX  16]]]
    Courier::serialize(block, value.hop);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Routing::Frame& value) {
    // type  [REF Routing::Type]
    //   ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
    Courier::serialize(block, value.type);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Routing::Tuple& value) {
    // network  [REF IDP::Network]
    //   ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]]
    Courier::deserialize(block, value.network);
    // hop  [REF Routing::Hop]
    //   ENUM [UNSPECIFIED [[MAX  16]]]
    Courier::deserialize(block, value.hop);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Routing::Frame& value) {
    // type  [REF Routing::Type]
    //   ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
    Courier::deserialize(block, value.type);
    // data  BLOCK
    value.data = block.remainder();
}
