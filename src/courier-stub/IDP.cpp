#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/IDP");

#include "../stub/IDP.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::IDP::Network value) {
    static QMap<Courier::Stub::IDP::Network, QString> map = {
        {Courier::Stub::IDP::Network::UNKNOWN, "UNKNOWN"},
        {Courier::Stub::IDP::Network::ALL,     "ALL"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::IDP::Socket value) {
    static QMap<Courier::Stub::IDP::Socket, QString> map = {
        {Courier::Stub::IDP::Socket::RIP,       "RIP"},
        {Courier::Stub::IDP::Socket::ECHO,      "ECHO"},
        {Courier::Stub::IDP::Socket::ERR,       "ERR"},
        {Courier::Stub::IDP::Socket::ENVOY,     "ENVOY"},
        {Courier::Stub::IDP::Socket::COURIER,   "COURIER"},
        {Courier::Stub::IDP::Socket::CHS_OLD,   "CHS_OLD"},
        {Courier::Stub::IDP::Socket::TIME,      "TIME"},
        {Courier::Stub::IDP::Socket::BOOT,      "BOOT"},
        {Courier::Stub::IDP::Socket::DIAG,      "DIAG"},
        {Courier::Stub::IDP::Socket::CHS,       "CHS"},
        {Courier::Stub::IDP::Socket::AUTH,      "AUTH"},
        {Courier::Stub::IDP::Socket::MAIL,      "MAIL"},
        {Courier::Stub::IDP::Socket::NET_EXEC,  "NET_EXEC"},
        {Courier::Stub::IDP::Socket::WS_INFO,   "WS_INFO"},
        {Courier::Stub::IDP::Socket::BINDING,   "BINDING"},
        {Courier::Stub::IDP::Socket::GERM,      "GERM"},
        {Courier::Stub::IDP::Socket::TELEDEBUG, "TELEDEBUG"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::IDP::Checksum value) {
    static QMap<Courier::Stub::IDP::Checksum, QString> map = {
        {Courier::Stub::IDP::Checksum::NONE, "NONE"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::IDP::Type value) {
    static QMap<Courier::Stub::IDP::Type, QString> map = {
        {Courier::Stub::IDP::Type::RIP,  "RIP"},
        {Courier::Stub::IDP::Type::ECHO, "ECHO"},
        {Courier::Stub::IDP::Type::ERR,  "ERR"},
        {Courier::Stub::IDP::Type::PEP,  "PEP"},
        {Courier::Stub::IDP::Type::SPP,  "SPP"},
        {Courier::Stub::IDP::Type::BOOT, "BOOT"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::IDP::Network value) {
    Courier::serialize(block, (quint32)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::IDP::Socket value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::IDP::Checksum value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::IDP::Type value) {
    Courier::serialize(block, (quint8)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::IDP::Network& value) {
    quint32 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::IDP::Network)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::IDP::Socket& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::IDP::Socket)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::IDP::Checksum& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::IDP::Checksum)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::IDP::Type& value) {
    quint8 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::IDP::Type)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::IDP::NetworkAddress& value) {
    QStringList list;
    // network  [REF IDP::Network]
    //   ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]]
    list << QString("[%1 %2]").arg("network").arg(Courier::toString(value.network));
    // host  [REF IDP::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    list << QString("[%1 %2]").arg("host").arg(Courier::toString(value.host));
    // socket  [REF IDP::Socket]
    //   ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]
    list << QString("[%1 %2]").arg("socket").arg(Courier::toString(value.socket));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::IDP::Frame& value) {
    QStringList list;
    // checksum  [REF IDP::Checksum]
    //   ENUM [UNSPECIFIED [[NONE  65535]]]
    list << QString("[%1 %2]").arg("checksum").arg(Courier::toString(value.checksum));
    // length  CARDINAL
    list << QString("[%1 %2]").arg("length").arg(Courier::toString(value.length));
    // control  [REF IDP::Control]
    //   MACHINE BYTE [trace: (0..0) BOOLEAN, filler: (1..3) CARDINAL, hop: (4..7) CARDINAL]
    list << QString("[%1 %2]").arg("control").arg(Courier::toString(value.control));
    // type  [REF IDP::Type]
    //   ENUM [BYTE [[RIP  1], [ECHO  2], [ERR  3], [PEP  4], [SPP  5], [BOOT  9]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // dst  [REF IDP::NetworkAddress]
    //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], host: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], socket: ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]]
    list << QString("[%1 %2]").arg("dst").arg(Courier::toString(value.dst));
    // src  [REF IDP::NetworkAddress]
    //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], host: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], socket: ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]]
    list << QString("[%1 %2]").arg("src").arg(Courier::toString(value.src));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::IDP::NetworkAddress& value) {
    // network  [REF IDP::Network]
    //   ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]]
    Courier::serialize(block, value.network);
    // host  [REF IDP::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::serialize(block, value.host);
    // socket  [REF IDP::Socket]
    //   ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]
    Courier::serialize(block, value.socket);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::IDP::Frame& value) {
    // checksum  [REF IDP::Checksum]
    //   ENUM [UNSPECIFIED [[NONE  65535]]]
    Courier::serialize(block, value.checksum);
    // length  CARDINAL
    Courier::serialize(block, value.length);
    // control  [REF IDP::Control]
    //   MACHINE BYTE [trace: (0..0) BOOLEAN, filler: (1..3) CARDINAL, hop: (4..7) CARDINAL]
    Courier::serialize(block, value.control);
    // type  [REF IDP::Type]
    //   ENUM [BYTE [[RIP  1], [ECHO  2], [ERR  3], [PEP  4], [SPP  5], [BOOT  9]]]
    Courier::serialize(block, value.type);
    // dst  [REF IDP::NetworkAddress]
    //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], host: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], socket: ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]]
    Courier::serialize(block, value.dst);
    // src  [REF IDP::NetworkAddress]
    //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], host: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], socket: ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]]
    Courier::serialize(block, value.src);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::IDP::NetworkAddress& value) {
    // network  [REF IDP::Network]
    //   ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]]
    Courier::deserialize(block, value.network);
    // host  [REF IDP::Host]
    //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
    Courier::deserialize(block, value.host);
    // socket  [REF IDP::Socket]
    //   ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]
    Courier::deserialize(block, value.socket);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::IDP::Frame& value) {
    // checksum  [REF IDP::Checksum]
    //   ENUM [UNSPECIFIED [[NONE  65535]]]
    Courier::deserialize(block, value.checksum);
    // length  CARDINAL
    Courier::deserialize(block, value.length);
    // control  [REF IDP::Control]
    //   MACHINE BYTE [trace: (0..0) BOOLEAN, filler: (1..3) CARDINAL, hop: (4..7) CARDINAL]
    Courier::deserialize(block, value.control);
    // type  [REF IDP::Type]
    //   ENUM [BYTE [[RIP  1], [ECHO  2], [ERR  3], [PEP  4], [SPP  5], [BOOT  9]]]
    Courier::deserialize(block, value.type);
    // dst  [REF IDP::NetworkAddress]
    //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], host: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], socket: ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]]
    Courier::deserialize(block, value.dst);
    // src  [REF IDP::NetworkAddress]
    //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], host: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], socket: ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]]
    Courier::deserialize(block, value.src);
    // data  BLOCK
    value.data = block.remainder();
}

//
// Machine Function Definition
//
QString Courier::toString(const Courier::Stub::IDP::Control& value) {
    QStringList list;
    // trace  BOOLEAN
    list << QString("[%1 %2]").arg("trace").arg(Courier::toString(value.trace));
    // filler  CARDINAL
    list << QString("[%1 %2]").arg("filler").arg(Courier::toString(value.filler));
    // hop  CARDINAL
    list << QString("[%1 %2]").arg("hop").arg(Courier::toString(value.hop));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::IDP::Control& value) {
    BYTE v = 0;
    v = setBits(v, 0, 0, (BYTE)value.trace);
    v = setBits(v, 1, 3, (BYTE)value.filler);
    v = setBits(v, 4, 7, (BYTE)value.hop);
    Courier::serialize(block, v);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::IDP::Control& value) {
    BYTE v;
    Courier::deserialize(block, v);
    value.trace = (BOOLEAN)getBits(v, 0, 0);
    value.filler = (CARDINAL)getBits(v, 1, 3);
    value.hop = (CARDINAL)getBits(v, 4, 7);
}
