#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/PacketExchange");

#include "../stub/PacketExchange.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::PacketExchange::Type value) {
    static QMap<Courier::Stub::PacketExchange::Type, QString> map = {
        {Courier::Stub::PacketExchange::Type::UNSPEC,     "UNSPEC"},
        {Courier::Stub::PacketExchange::Type::TIME,       "TIME"},
        {Courier::Stub::PacketExchange::Type::CHS,        "CHS"},
        {Courier::Stub::PacketExchange::Type::TELE_DEBUG, "TELE_DEBUG"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::PacketExchange::Type value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::PacketExchange::Type& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::PacketExchange::Type)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::PacketExchange::Frame& value) {
    QStringList list;
    // id  UNSPECIFIED2
    list << QString("[%1 %2]").arg("id").arg(Courier::toString(value.id));
    // type  [REF PacketExchange::Type]
    //   ENUM [UNSPECIFIED [[UNSPEC  0], [TIME  1], [CHS  2], [TELE_DEBUG  3]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::PacketExchange::Frame& value) {
    // id  UNSPECIFIED2
    Courier::serialize(block, value.id);
    // type  [REF PacketExchange::Type]
    //   ENUM [UNSPECIFIED [[UNSPEC  0], [TIME  1], [CHS  2], [TELE_DEBUG  3]]]
    Courier::serialize(block, value.type);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::PacketExchange::Frame& value) {
    // id  UNSPECIFIED2
    Courier::deserialize(block, value.id);
    // type  [REF PacketExchange::Type]
    //   ENUM [UNSPECIFIED [[UNSPEC  0], [TIME  1], [CHS  2], [TELE_DEBUG  3]]]
    Courier::deserialize(block, value.type);
    // data  BLOCK
    value.data = block.remainder();
}
