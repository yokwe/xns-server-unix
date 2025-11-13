#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Protocol");

#include "../stub/Protocol.h"

#include "../courier/Last.h"


Courier::Stub::Protocol::Protocol2::Protocol2_CALL& Courier::Stub::Protocol::Protocol2::CALL() const {
    if (choiceTag == CHOICE_TAG::CALL) {
        return choice_CALL;
    } else {
        logger.error("choiceTag  expect CALL  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Protocol2::Protocol2_RETURN& Courier::Stub::Protocol::Protocol2::RETURN() const {
    if (choiceTag == CHOICE_TAG::RETURN) {
        return choice_RETURN;
    } else {
        logger.error("choiceTag  expect RETURN  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Protocol2::Protocol2_ABORT& Courier::Stub::Protocol::Protocol2::ABORT() const {
    if (choiceTag == CHOICE_TAG::ABORT) {
        return choice_ABORT;
    } else {
        logger.error("choiceTag  expect ABORT  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Protocol2::Protocol2_REJECT& Courier::Stub::Protocol::Protocol2::REJECT() const {
    if (choiceTag == CHOICE_TAG::REJECT) {
        return choice_REJECT;
    } else {
        logger.error("choiceTag  expect REJECT  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Reject::Reject_NO_SUCH_PROGRAM_NUMBER& Courier::Stub::Protocol::Reject::NO_SUCH_PROGRAM_NUMBER() const {
    if (choiceTag == CHOICE_TAG::NO_SUCH_PROGRAM_NUMBER) {
        return choice_NO_SUCH_PROGRAM_NUMBER;
    } else {
        logger.error("choiceTag  expect NO_SUCH_PROGRAM_NUMBER  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Reject::Reject_NO_SUCH_PROCEDURE_NUMBER& Courier::Stub::Protocol::Reject::NO_SUCH_PROCEDURE_NUMBER() const {
    if (choiceTag == CHOICE_TAG::NO_SUCH_PROCEDURE_NUMBER) {
        return choice_NO_SUCH_PROCEDURE_NUMBER;
    } else {
        logger.error("choiceTag  expect NO_SUCH_PROCEDURE_NUMBER  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Reject::Reject_INALID_ARGUMENTS& Courier::Stub::Protocol::Reject::INALID_ARGUMENTS() const {
    if (choiceTag == CHOICE_TAG::INALID_ARGUMENTS) {
        return choice_INALID_ARGUMENTS;
    } else {
        logger.error("choiceTag  expect INALID_ARGUMENTS  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Reject::Reject_NO_SUCH_VERSION_NUMBER& Courier::Stub::Protocol::Reject::NO_SUCH_VERSION_NUMBER() const {
    if (choiceTag == CHOICE_TAG::NO_SUCH_VERSION_NUMBER) {
        return choice_NO_SUCH_VERSION_NUMBER;
    } else {
        logger.error("choiceTag  expect NO_SUCH_VERSION_NUMBER  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Protocol3::Protocol3_CALL& Courier::Stub::Protocol::Protocol3::CALL() const {
    if (choiceTag == CHOICE_TAG::CALL) {
        return choice_CALL;
    } else {
        logger.error("choiceTag  expect CALL  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Protocol3::Protocol3_RETURN& Courier::Stub::Protocol::Protocol3::RETURN() const {
    if (choiceTag == CHOICE_TAG::RETURN) {
        return choice_RETURN;
    } else {
        logger.error("choiceTag  expect RETURN  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Protocol3::Protocol3_ABORT& Courier::Stub::Protocol::Protocol3::ABORT() const {
    if (choiceTag == CHOICE_TAG::ABORT) {
        return choice_ABORT;
    } else {
        logger.error("choiceTag  expect ABORT  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Protocol3::Protocol3_REJECT& Courier::Stub::Protocol::Protocol3::REJECT() const {
    if (choiceTag == CHOICE_TAG::REJECT) {
        return choice_REJECT;
    } else {
        logger.error("choiceTag  expect REJECT  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Message::Message_PROTOCOL2& Courier::Stub::Protocol::Message::PROTOCOL2() const {
    if (choiceTag == CHOICE_TAG::PROTOCOL2) {
        return choice_PROTOCOL2;
    } else {
        logger.error("choiceTag  expect PROTOCOL2  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

Courier::Stub::Protocol::Message::Message_PROTOCOL3& Courier::Stub::Protocol::Message::PROTOCOL3() const {
    if (choiceTag == CHOICE_TAG::PROTOCOL3) {
        return choice_PROTOCOL3;
    } else {
        logger.error("choiceTag  expect PROTOCOL3  actual %s", Courier::toString(choiceTag));
        COURIER_FATAL_ERROR();
    }
}

//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Protocol::ProtocolType value) {
    static QMap<Courier::Stub::Protocol::ProtocolType, QString> map = {
        {Courier::Stub::Protocol::ProtocolType::PROTOCOL2, "PROTOCOL2"},
        {Courier::Stub::Protocol::ProtocolType::PROTOCOL3, "PROTOCOL3"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Protocol::MessageType value) {
    static QMap<Courier::Stub::Protocol::MessageType, QString> map = {
        {Courier::Stub::Protocol::MessageType::CALL,   "CALL"},
        {Courier::Stub::Protocol::MessageType::REJECT, "REJECT"},
        {Courier::Stub::Protocol::MessageType::RETURN, "RETURN"},
        {Courier::Stub::Protocol::MessageType::ABORT,  "ABORT"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Protocol::RejectCode value) {
    static QMap<Courier::Stub::Protocol::RejectCode, QString> map = {
        {Courier::Stub::Protocol::RejectCode::NO_SUCH_PROGRAM_NUMBER,   "NO_SUCH_PROGRAM_NUMBER"},
        {Courier::Stub::Protocol::RejectCode::NO_SUCH_VERSION_NUMBER,   "NO_SUCH_VERSION_NUMBER"},
        {Courier::Stub::Protocol::RejectCode::NO_SUCH_PROCEDURE_NUMBER, "NO_SUCH_PROCEDURE_NUMBER"},
        {Courier::Stub::Protocol::RejectCode::INALID_ARGUMENTS,         "INALID_ARGUMENTS"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::ProtocolType value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::MessageType value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::RejectCode value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::ProtocolType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Protocol::ProtocolType)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::MessageType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Protocol::MessageType)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::RejectCode& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Protocol::RejectCode)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_01& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // program  CARDINAL
    list << QString("[%1 %2]").arg("program").arg(Courier::toString(value.program));
    // version  CARDINAL
    list << QString("[%1 %2]").arg("version").arg(Courier::toString(value.version));
    // procedure  CARDINAL
    list << QString("[%1 %2]").arg("procedure").arg(Courier::toString(value.procedure));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_02& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_03& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // abortCode  CARDINAL
    list << QString("[%1 %2]").arg("abortCode").arg(Courier::toString(value.abortCode));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_04& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // rejectCode  [REF Protocol::RejectCode]
    //   ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]]
    list << QString("[%1 %2]").arg("rejectCode").arg(Courier::toString(value.rejectCode));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::ProtocolRange& value) {
    QStringList list;
    // low  [REF Protocol::ProtocolType]
    //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
    list << QString("[%1 %2]").arg("low").arg(Courier::toString(value.low));
    // high  [REF Protocol::ProtocolType]
    //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
    list << QString("[%1 %2]").arg("high").arg(Courier::toString(value.high));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::VersionRange& value) {
    QStringList list;
    // low  CARDINAL
    list << QString("[%1 %2]").arg("low").arg(Courier::toString(value.low));
    // high  CARDINAL
    list << QString("[%1 %2]").arg("high").arg(Courier::toString(value.high));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Reject::Reject_CHOICE_01&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Protocol::Reject::Reject_CHOICE_02& value) {
    QStringList list;
    // range  [REF Protocol::VersionRange]
    //   RECORD [low: CARDINAL, high: CARDINAL]
    list << QString("[%1 %2]").arg("range").arg(Courier::toString(value.range));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_01& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // program  LONG_CARDINAL
    list << QString("[%1 %2]").arg("program").arg(Courier::toString(value.program));
    // version  CARDINAL
    list << QString("[%1 %2]").arg("version").arg(Courier::toString(value.version));
    // procedure  CARDINAL
    list << QString("[%1 %2]").arg("procedure").arg(Courier::toString(value.procedure));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_02& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_03& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // abortCode  CARDINAL
    list << QString("[%1 %2]").arg("abortCode").arg(Courier::toString(value.abortCode));
    // data  BLOCK
    list << QString("[%1 %2]").arg("data").arg(Courier::toString(value.data));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_04& value) {
    QStringList list;
    // transaction  CARDINAL
    list << QString("[%1 %2]").arg("transaction").arg(Courier::toString(value.transaction));
    // reject  [REF Protocol::Reject]
    //   [CHOICE ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]] [[[NO_SUCH_PROGRAM_NUMBER, NO_SUCH_PROCEDURE_NUMBER, INALID_ARGUMENTS] => RECORD []], [[NO_SUCH_VERSION_NUMBER] => RECORD [range: [REF Protocol::VersionRange]]]]]
    list << QString("[%1 %2]").arg("reject").arg(Courier::toString(value.reject));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Message::Message_CHOICE_01& value) {
    QStringList list;
    // protocol2  [REF Protocol::Protocol2]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, rejectCode: [REF Protocol::RejectCode]]]]]
    list << QString("[%1 %2]").arg("protocol2").arg(Courier::toString(value.protocol2));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Protocol::Message::Message_CHOICE_02& value) {
    QStringList list;
    // protocol3  [REF Protocol::Protocol3]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
    list << QString("[%1 %2]").arg("protocol3").arg(Courier::toString(value.protocol3));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_01& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // program  CARDINAL
    Courier::serialize(block, value.program);
    // version  CARDINAL
    Courier::serialize(block, value.version);
    // procedure  CARDINAL
    Courier::serialize(block, value.procedure);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_02& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_03& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // abortCode  CARDINAL
    Courier::serialize(block, value.abortCode);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_04& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // rejectCode  [REF Protocol::RejectCode]
    //   ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]]
    Courier::serialize(block, value.rejectCode);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::ProtocolRange& value) {
    // low  [REF Protocol::ProtocolType]
    //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
    Courier::serialize(block, value.low);
    // high  [REF Protocol::ProtocolType]
    //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
    Courier::serialize(block, value.high);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::VersionRange& value) {
    // low  CARDINAL
    Courier::serialize(block, value.low);
    // high  CARDINAL
    Courier::serialize(block, value.high);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Protocol::Reject::Reject_CHOICE_01&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Reject::Reject_CHOICE_02& value) {
    // range  [REF Protocol::VersionRange]
    //   RECORD [low: CARDINAL, high: CARDINAL]
    Courier::serialize(block, value.range);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_01& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // program  LONG_CARDINAL
    Courier::serialize(block, value.program);
    // version  CARDINAL
    Courier::serialize(block, value.version);
    // procedure  CARDINAL
    Courier::serialize(block, value.procedure);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_02& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_03& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // abortCode  CARDINAL
    Courier::serialize(block, value.abortCode);
    // data  BLOCK
    // Courier::serialize(block, value.data);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_04& value) {
    // transaction  CARDINAL
    Courier::serialize(block, value.transaction);
    // reject  [REF Protocol::Reject]
    //   [CHOICE ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]] [[[NO_SUCH_PROGRAM_NUMBER, NO_SUCH_PROCEDURE_NUMBER, INALID_ARGUMENTS] => RECORD []], [[NO_SUCH_VERSION_NUMBER] => RECORD [range: [REF Protocol::VersionRange]]]]]
    Courier::serialize(block, value.reject);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Message::Message_CHOICE_01& value) {
    // protocol2  [REF Protocol::Protocol2]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, rejectCode: [REF Protocol::RejectCode]]]]]
    Courier::serialize(block, value.protocol2);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Message::Message_CHOICE_02& value) {
    // protocol3  [REF Protocol::Protocol3]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
    Courier::serialize(block, value.protocol3);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_01& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // program  CARDINAL
    Courier::deserialize(block, value.program);
    // version  CARDINAL
    Courier::deserialize(block, value.version);
    // procedure  CARDINAL
    Courier::deserialize(block, value.procedure);
    // data  BLOCK
    value.data = block.remainder();
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_02& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // data  BLOCK
    value.data = block.remainder();
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_03& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // abortCode  CARDINAL
    Courier::deserialize(block, value.abortCode);
    // data  BLOCK
    value.data = block.remainder();
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_04& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // rejectCode  [REF Protocol::RejectCode]
    //   ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]]
    Courier::deserialize(block, value.rejectCode);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::ProtocolRange& value) {
    // low  [REF Protocol::ProtocolType]
    //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
    Courier::deserialize(block, value.low);
    // high  [REF Protocol::ProtocolType]
    //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
    Courier::deserialize(block, value.high);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::VersionRange& value) {
    // low  CARDINAL
    Courier::deserialize(block, value.low);
    // high  CARDINAL
    Courier::deserialize(block, value.high);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Protocol::Reject::Reject_CHOICE_01&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Reject::Reject_CHOICE_02& value) {
    // range  [REF Protocol::VersionRange]
    //   RECORD [low: CARDINAL, high: CARDINAL]
    Courier::deserialize(block, value.range);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_01& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // program  LONG_CARDINAL
    Courier::deserialize(block, value.program);
    // version  CARDINAL
    Courier::deserialize(block, value.version);
    // procedure  CARDINAL
    Courier::deserialize(block, value.procedure);
    // data  BLOCK
    value.data = block.remainder();
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_02& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // data  BLOCK
    value.data = block.remainder();
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_03& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // abortCode  CARDINAL
    Courier::deserialize(block, value.abortCode);
    // data  BLOCK
    value.data = block.remainder();
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_04& value) {
    // transaction  CARDINAL
    Courier::deserialize(block, value.transaction);
    // reject  [REF Protocol::Reject]
    //   [CHOICE ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]] [[[NO_SUCH_PROGRAM_NUMBER, NO_SUCH_PROCEDURE_NUMBER, INALID_ARGUMENTS] => RECORD []], [[NO_SUCH_VERSION_NUMBER] => RECORD [range: [REF Protocol::VersionRange]]]]]
    Courier::deserialize(block, value.reject);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Message::Message_CHOICE_01& value) {
    // protocol2  [REF Protocol::Protocol2]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, rejectCode: [REF Protocol::RejectCode]]]]]
    Courier::deserialize(block, value.protocol2);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Message::Message_CHOICE_02& value) {
    // protocol3  [REF Protocol::Protocol3]
    //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
    Courier::deserialize(block, value.protocol3);
}

//
// Choice Function Definition
//
QString Courier::toString(const Courier::Stub::Protocol::Protocol2& value) {
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::CALL:
        return QString("[%1 %2]").arg("CALL").arg(Courier::toString(value.CALL()));
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::RETURN:
        return QString("[%1 %2]").arg("RETURN").arg(Courier::toString(value.RETURN()));
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::ABORT:
        return QString("[%1 %2]").arg("ABORT").arg(Courier::toString(value.ABORT()));
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::REJECT:
        return QString("[%1 %2]").arg("REJECT").arg(Courier::toString(value.REJECT()));
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
QString Courier::toString(const Courier::Stub::Protocol::Reject& value) {
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_PROGRAM_NUMBER:
        return QString("[%1 %2]").arg("NO_SUCH_PROGRAM_NUMBER").arg(Courier::toString(value.NO_SUCH_PROGRAM_NUMBER()));
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_PROCEDURE_NUMBER:
        return QString("[%1 %2]").arg("NO_SUCH_PROCEDURE_NUMBER").arg(Courier::toString(value.NO_SUCH_PROCEDURE_NUMBER()));
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::INALID_ARGUMENTS:
        return QString("[%1 %2]").arg("INALID_ARGUMENTS").arg(Courier::toString(value.INALID_ARGUMENTS()));
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_VERSION_NUMBER:
        return QString("[%1 %2]").arg("NO_SUCH_VERSION_NUMBER").arg(Courier::toString(value.NO_SUCH_VERSION_NUMBER()));
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
QString Courier::toString(const Courier::Stub::Protocol::Protocol3& value) {
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::CALL:
        return QString("[%1 %2]").arg("CALL").arg(Courier::toString(value.CALL()));
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::RETURN:
        return QString("[%1 %2]").arg("RETURN").arg(Courier::toString(value.RETURN()));
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::ABORT:
        return QString("[%1 %2]").arg("ABORT").arg(Courier::toString(value.ABORT()));
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::REJECT:
        return QString("[%1 %2]").arg("REJECT").arg(Courier::toString(value.REJECT()));
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
QString Courier::toString(const Courier::Stub::Protocol::Message& value) {
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Message::CHOICE_TAG::PROTOCOL2:
        return QString("[%1 %2]").arg("PROTOCOL2").arg(Courier::toString(value.PROTOCOL2()));
    case Courier::Stub::Protocol::Message::CHOICE_TAG::PROTOCOL3:
        return QString("[%1 %2]").arg("PROTOCOL3").arg(Courier::toString(value.PROTOCOL3()));
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2& value) {
    block.serialize16((quint16)value.choiceTag);
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::CALL:
        Courier::serialize(block, value.CALL());
        break;
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::RETURN:
        Courier::serialize(block, value.RETURN());
        break;
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::ABORT:
        Courier::serialize(block, value.ABORT());
        break;
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::REJECT:
        Courier::serialize(block, value.REJECT());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Reject& value) {
    block.serialize16((quint16)value.choiceTag);
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_PROGRAM_NUMBER:
        Courier::serialize(block, value.NO_SUCH_PROGRAM_NUMBER());
        break;
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_PROCEDURE_NUMBER:
        Courier::serialize(block, value.NO_SUCH_PROCEDURE_NUMBER());
        break;
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::INALID_ARGUMENTS:
        Courier::serialize(block, value.INALID_ARGUMENTS());
        break;
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_VERSION_NUMBER:
        Courier::serialize(block, value.NO_SUCH_VERSION_NUMBER());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3& value) {
    block.serialize16((quint16)value.choiceTag);
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::CALL:
        Courier::serialize(block, value.CALL());
        break;
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::RETURN:
        Courier::serialize(block, value.RETURN());
        break;
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::ABORT:
        Courier::serialize(block, value.ABORT());
        break;
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::REJECT:
        Courier::serialize(block, value.REJECT());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Protocol::Message& value) {
    block.serialize16((quint16)value.choiceTag);
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Message::CHOICE_TAG::PROTOCOL2:
        Courier::serialize(block, value.PROTOCOL2());
        break;
    case Courier::Stub::Protocol::Message::CHOICE_TAG::PROTOCOL3:
        Courier::serialize(block, value.PROTOCOL3());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2& value) {
    quint16 choiceTag_;
    block.deserialize16(choiceTag_);
    value.choiceTag = (Courier::Stub::Protocol::Protocol2::CHOICE_TAG)choiceTag_;
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::CALL:
        Courier::deserialize(block, value.CALL());
        break;
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::RETURN:
        Courier::deserialize(block, value.RETURN());
        break;
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::ABORT:
        Courier::deserialize(block, value.ABORT());
        break;
    case Courier::Stub::Protocol::Protocol2::CHOICE_TAG::REJECT:
        Courier::deserialize(block, value.REJECT());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Reject& value) {
    quint16 choiceTag_;
    block.deserialize16(choiceTag_);
    value.choiceTag = (Courier::Stub::Protocol::Reject::CHOICE_TAG)choiceTag_;
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_PROGRAM_NUMBER:
        Courier::deserialize(block, value.NO_SUCH_PROGRAM_NUMBER());
        break;
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_PROCEDURE_NUMBER:
        Courier::deserialize(block, value.NO_SUCH_PROCEDURE_NUMBER());
        break;
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::INALID_ARGUMENTS:
        Courier::deserialize(block, value.INALID_ARGUMENTS());
        break;
    case Courier::Stub::Protocol::Reject::CHOICE_TAG::NO_SUCH_VERSION_NUMBER:
        Courier::deserialize(block, value.NO_SUCH_VERSION_NUMBER());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3& value) {
    quint16 choiceTag_;
    block.deserialize16(choiceTag_);
    value.choiceTag = (Courier::Stub::Protocol::Protocol3::CHOICE_TAG)choiceTag_;
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::CALL:
        Courier::deserialize(block, value.CALL());
        break;
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::RETURN:
        Courier::deserialize(block, value.RETURN());
        break;
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::ABORT:
        Courier::deserialize(block, value.ABORT());
        break;
    case Courier::Stub::Protocol::Protocol3::CHOICE_TAG::REJECT:
        Courier::deserialize(block, value.REJECT());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Protocol::Message& value) {
    quint16 choiceTag_;
    block.deserialize16(choiceTag_);
    value.choiceTag = (Courier::Stub::Protocol::Message::CHOICE_TAG)choiceTag_;
    switch(value.choiceTag) {
    case Courier::Stub::Protocol::Message::CHOICE_TAG::PROTOCOL2:
        Courier::deserialize(block, value.PROTOCOL2());
        break;
    case Courier::Stub::Protocol::Message::CHOICE_TAG::PROTOCOL3:
        Courier::deserialize(block, value.PROTOCOL3());
        break;
    default:
        logger.error("Unexpected choiceTag = %d", (quint16)value.choiceTag);
        COURIER_FATAL_ERROR();
        break;
    }
}
