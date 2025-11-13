#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Echo");

#include "../stub/Echo.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Echo::Type value) {
    static QMap<Courier::Stub::Echo::Type, QString> map = {
        {Courier::Stub::Echo::Type::REQUEST,  "REQUEST"},
        {Courier::Stub::Echo::Type::RESPONSE, "RESPONSE"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Echo::Type value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Echo::Type& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Echo::Type)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Echo::Frame& value) {
    QStringList list;
    // type  [REF Echo::Type]
    //   ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Echo::Frame& value) {
    // type  [REF Echo::Type]
    //   ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
    Courier::serialize(block, value.type);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Echo::Frame& value) {
    // type  [REF Echo::Type]
    //   ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
    Courier::deserialize(block, value.type);
    // data  BLOCK
    value.data = block.remainder();
}
