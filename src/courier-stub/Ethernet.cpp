#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Ethernet");

#include "../stub/Ethernet.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Ethernet::Host value) {
    static QMap<Courier::Stub::Ethernet::Host, QString> map = {
        {Courier::Stub::Ethernet::Host::ALL, "ALL"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Ethernet::Type value) {
    static QMap<Courier::Stub::Ethernet::Type, QString> map = {
        {Courier::Stub::Ethernet::Type::PUP, "PUP"},
        {Courier::Stub::Ethernet::Type::IDP, "IDP"},
        {Courier::Stub::Ethernet::Type::IP4, "IP4"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Ethernet::Host value) {
    Courier::serialize(block, (quint64)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Ethernet::Type value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Ethernet::Host& value) {
    quint64 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Ethernet::Host)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Ethernet::Type& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Ethernet::Type)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Ethernet::Frame& value) {
    QStringList list;
    // dst  [REF Ethernet::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    list << QString("[%1 %2]").arg("dst").arg(Courier::toString(value.dst));
    // src  [REF Ethernet::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    list << QString("[%1 %2]").arg("src").arg(Courier::toString(value.src));
    // type  [REF Ethernet::Type]
    //   ENUM [UNSPECIFIED [[PUP  512], [IDP  1536], [IP4  2048]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Ethernet::Frame& value) {
    // dst  [REF Ethernet::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::serialize(block, value.dst);
    // src  [REF Ethernet::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::serialize(block, value.src);
    // type  [REF Ethernet::Type]
    //   ENUM [UNSPECIFIED [[PUP  512], [IDP  1536], [IP4  2048]]]
    Courier::serialize(block, value.type);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Ethernet::Frame& value) {
    // dst  [REF Ethernet::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::deserialize(block, value.dst);
    // src  [REF Ethernet::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::deserialize(block, value.src);
    // type  [REF Ethernet::Type]
    //   ENUM [UNSPECIFIED [[PUP  512], [IDP  1536], [IP4  2048]]]
    Courier::deserialize(block, value.type);
    // data  BLOCK
    value.data = block.remainder();
}
