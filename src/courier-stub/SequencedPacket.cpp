#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/SequencedPacket");

#include "../stub/SequencedPacket.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::SequencedPacket::Type value) {
    static QMap<Courier::Stub::SequencedPacket::Type, QString> map = {
        {Courier::Stub::SequencedPacket::Type::DATA,        "DATA"},
        {Courier::Stub::SequencedPacket::Type::BULK,        "BULK"},
        {Courier::Stub::SequencedPacket::Type::CLOSE,       "CLOSE"},
        {Courier::Stub::SequencedPacket::Type::CLOSE_REPLY, "CLOSE_REPLY"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::SequencedPacket::Type value) {
    Courier::serialize(block, (quint8)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::SequencedPacket::Type& value) {
    quint8 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::SequencedPacket::Type)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::SequencedPacket::Frame& value) {
    QStringList list;
    // control  [REF SequencedPacket::Control]
    //   MACHINE BYTE [system: (0..0) BOOLEAN, sendAck: (1..1) BOOLEAN, attention: (2..2) BOOLEAN, endMessage: (3..3) BOOLEAN, reserve: (4..7) UNSPECIFIED]
    list << QString("[%1 %2]").arg("control").arg(Courier::toString(value.control));
    // type  [REF SequencedPacket::Type]
    //   ENUM [BYTE [[DATA  0], [BULK  1], [CLOSE  254], [CLOSE_REPLY  255]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // src  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    list << QString("[%1 %2]").arg("src").arg(Courier::toString(value.src));
    // dst  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    list << QString("[%1 %2]").arg("dst").arg(Courier::toString(value.dst));
    // seq  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    list << QString("[%1 %2]").arg("seq").arg(Courier::toString(value.seq));
    // ack  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    list << QString("[%1 %2]").arg("ack").arg(Courier::toString(value.ack));
    // alloc  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    list << QString("[%1 %2]").arg("alloc").arg(Courier::toString(value.alloc));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::SequencedPacket::Frame& value) {
    // control  [REF SequencedPacket::Control]
    //   MACHINE BYTE [system: (0..0) BOOLEAN, sendAck: (1..1) BOOLEAN, attention: (2..2) BOOLEAN, endMessage: (3..3) BOOLEAN, reserve: (4..7) UNSPECIFIED]
    Courier::serialize(block, value.control);
    // type  [REF SequencedPacket::Type]
    //   ENUM [BYTE [[DATA  0], [BULK  1], [CLOSE  254], [CLOSE_REPLY  255]]]
    Courier::serialize(block, value.type);
    // src  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    Courier::serialize(block, value.src);
    // dst  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    Courier::serialize(block, value.dst);
    // seq  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    Courier::serialize(block, value.seq);
    // ack  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    Courier::serialize(block, value.ack);
    // alloc  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    Courier::serialize(block, value.alloc);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::SequencedPacket::Frame& value) {
    // control  [REF SequencedPacket::Control]
    //   MACHINE BYTE [system: (0..0) BOOLEAN, sendAck: (1..1) BOOLEAN, attention: (2..2) BOOLEAN, endMessage: (3..3) BOOLEAN, reserve: (4..7) UNSPECIFIED]
    Courier::deserialize(block, value.control);
    // type  [REF SequencedPacket::Type]
    //   ENUM [BYTE [[DATA  0], [BULK  1], [CLOSE  254], [CLOSE_REPLY  255]]]
    Courier::deserialize(block, value.type);
    // src  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    Courier::deserialize(block, value.src);
    // dst  [REF SequencedPacket::ConnectionID]
    //   UNSPECIFIED
    Courier::deserialize(block, value.dst);
    // seq  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    Courier::deserialize(block, value.seq);
    // ack  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    Courier::deserialize(block, value.ack);
    // alloc  [REF SequencedPacket::SequenceNumber]
    //   UNSPECIFIED
    Courier::deserialize(block, value.alloc);
    // data  BLOCK
    value.data = block.remainder();
}

//
// Machine Function Definition
//
QString Courier::toString(const Courier::Stub::SequencedPacket::Control& value) {
    QStringList list;
    // system  BOOLEAN
    list << QString("[%1 %2]").arg("system").arg(Courier::toString(value.system));
    // sendAck  BOOLEAN
    list << QString("[%1 %2]").arg("sendAck").arg(Courier::toString(value.sendAck));
    // attention  BOOLEAN
    list << QString("[%1 %2]").arg("attention").arg(Courier::toString(value.attention));
    // endMessage  BOOLEAN
    list << QString("[%1 %2]").arg("endMessage").arg(Courier::toString(value.endMessage));
    // reserve  UNSPECIFIED
    list << QString("[%1 %2]").arg("reserve").arg(Courier::toString(value.reserve));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::SequencedPacket::Control& value) {
    BYTE v = 0;
    v = setBits(v, 0, 0, (BYTE)value.system);
    v = setBits(v, 1, 1, (BYTE)value.sendAck);
    v = setBits(v, 2, 2, (BYTE)value.attention);
    v = setBits(v, 3, 3, (BYTE)value.endMessage);
    v = setBits(v, 4, 7, (BYTE)value.reserve);
    Courier::serialize(block, v);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::SequencedPacket::Control& value) {
    BYTE v;
    Courier::deserialize(block, v);
    value.system = (BOOLEAN)getBits(v, 0, 0);
    value.sendAck = (BOOLEAN)getBits(v, 1, 1);
    value.attention = (BOOLEAN)getBits(v, 2, 2);
    value.endMessage = (BOOLEAN)getBits(v, 3, 3);
    value.reserve = (UNSPECIFIED)getBits(v, 4, 7);
}
