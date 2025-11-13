#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/CHEntries");

#include "../stub/CHEntries.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::CHEntries::PortClientType value) {
    static QMap<Courier::Stub::CHEntries::PortClientType, QString> map = {
        {Courier::Stub::CHEntries::PortClientType::unassigned,      "unassigned"},
        {Courier::Stub::CHEntries::PortClientType::outOfService,    "outOfService"},
        {Courier::Stub::CHEntries::PortClientType::its,             "its"},
        {Courier::Stub::CHEntries::PortClientType::irs,             "irs"},
        {Courier::Stub::CHEntries::PortClientType::gws,             "gws"},
        {Courier::Stub::CHEntries::PortClientType::ibm3270Host,     "ibm3270Host"},
        {Courier::Stub::CHEntries::PortClientType::ttyEmulation,    "ttyEmulation"},
        {Courier::Stub::CHEntries::PortClientType::rbs,             "rbs"},
        {Courier::Stub::CHEntries::PortClientType::fax,             "fax"},
        {Courier::Stub::CHEntries::PortClientType::mailGateway,     "mailGateway"},
        {Courier::Stub::CHEntries::PortClientType::phototypesetter, "phototypesetter"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::CHEntries::PortDialerType value) {
    static QMap<Courier::Stub::CHEntries::PortDialerType, QString> map = {
        {Courier::Stub::CHEntries::PortDialerType::dialerNone, "dialerNone"},
        {Courier::Stub::CHEntries::PortDialerType::vadic,      "vadic"},
        {Courier::Stub::CHEntries::PortDialerType::hayes,      "hayes"},
        {Courier::Stub::CHEntries::PortDialerType::ventel,     "ventel"},
        {Courier::Stub::CHEntries::PortDialerType::rs366,      "rs366"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::CHEntries::PortSyncType value) {
    static QMap<Courier::Stub::CHEntries::PortSyncType, QString> map = {
        {Courier::Stub::CHEntries::PortSyncType::asynchronous,    "asynchronous"},
        {Courier::Stub::CHEntries::PortSyncType::synchronous,     "synchronous"},
        {Courier::Stub::CHEntries::PortSyncType::bitSynchronous,  "bitSynchronous"},
        {Courier::Stub::CHEntries::PortSyncType::byteSynchronous, "byteSynchronous"},
        {Courier::Stub::CHEntries::PortSyncType::syncAny,         "syncAny"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::CHEntries::PortEchoingLocation value) {
    static QMap<Courier::Stub::CHEntries::PortEchoingLocation, QString> map = {
        {Courier::Stub::CHEntries::PortEchoingLocation::echoLocal,  "echoLocal"},
        {Courier::Stub::CHEntries::PortEchoingLocation::echoRemote, "echoRemote"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::PortClientType value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::PortDialerType value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::PortSyncType value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::PortEchoingLocation value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::PortClientType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::CHEntries::PortClientType)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::PortDialerType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::CHEntries::PortDialerType)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::PortSyncType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::CHEntries::PortSyncType)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::PortEchoingLocation& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::CHEntries::PortEchoingLocation)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::CHEntries::MailboxesValue& value) {
    QStringList list;
    // time  [REF Time2::Time]
    //   LONG_CARDINAL
    list << QString("[%1 %2]").arg("time").arg(Courier::toString(value.time));
    // mailService  [SEQUENCE (65535)[REF Clearinghouse2::Name]]]
    //   [SEQUENCE (65535)RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]]]
    list << QString("[%1 %2]").arg("mailService").arg(Courier::toString(value.mailService));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::CHEntries::AuthenticationLevelValue& value) {
    QStringList list;
    // simpleSupported  BOOLEAN
    list << QString("[%1 %2]").arg("simpleSupported").arg(Courier::toString(value.simpleSupported));
    // strongSupported  BOOLEAN
    list << QString("[%1 %2]").arg("strongSupported").arg(Courier::toString(value.strongSupported));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::CHEntries::UserDataValue& value) {
    QStringList list;
    // lastNameIndex  CARDINAL
    list << QString("[%1 %2]").arg("lastNameIndex").arg(Courier::toString(value.lastNameIndex));
    // fileService  [REF Clearinghouse2::Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("fileService").arg(Courier::toString(value.fileService));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::CHEntries::RS232CData& value) {
    QStringList list;
    // cIUPort  BOOLEAN
    list << QString("[%1 %2]").arg("cIUPort").arg(Courier::toString(value.cIUPort));
    // owningClientType  [REF CHEntries::PortClientType]
    //   ENUM [UNSPECIFIED [[unassigned  0], [outOfService  1], [its  2], [irs  3], [gws  4], [ibm3270Host  5], [ttyEmulation  6], [rbs  7], [fax  9], [mailGateway  10], [phototypesetter  11]]]
    list << QString("[%1 %2]").arg("owningClientType").arg(Courier::toString(value.owningClientType));
    // preemptionAllowed  BOOLEAN
    list << QString("[%1 %2]").arg("preemptionAllowed").arg(Courier::toString(value.preemptionAllowed));
    // lineNumber  CARDINAL
    list << QString("[%1 %2]").arg("lineNumber").arg(Courier::toString(value.lineNumber));
    // dialerNumber  CARDINAL
    list << QString("[%1 %2]").arg("dialerNumber").arg(Courier::toString(value.dialerNumber));
    // duplexity  [REF CHEntries::Duplexity]
    //   CARDINAL
    list << QString("[%1 %2]").arg("duplexity").arg(Courier::toString(value.duplexity));
    // dialingHardware  [REF CHEntries::PortDialerType]
    //   ENUM [UNSPECIFIED [[dialerNone  0], [vadic  1], [hayes  2], [ventel  3], [rs366  4]]]
    list << QString("[%1 %2]").arg("dialingHardware").arg(Courier::toString(value.dialingHardware));
    // charLength  [REF CHEntries::CharLength]
    //   CARDINAL
    list << QString("[%1 %2]").arg("charLength").arg(Courier::toString(value.charLength));
    // echoing  [REF CHEntries::PortEchoingLocation]
    //   ENUM [UNSPECIFIED [[echoLocal  0], [echoRemote  1]]]
    list << QString("[%1 %2]").arg("echoing").arg(Courier::toString(value.echoing));
    // xxxxpaddingxxx  LONG_CARDINAL
    list << QString("[%1 %2]").arg("xxxxpaddingxxx").arg(Courier::toString(value.xxxxpaddingxxx));
    // flowControl  [REF CHEntries::FlowControl]
    //   CARDINAL
    list << QString("[%1 %2]").arg("flowControl").arg(Courier::toString(value.flowControl));
    // lineSpeed  [REF CHEntries::LineSpeed]
    //   CARDINAL
    list << QString("[%1 %2]").arg("lineSpeed").arg(Courier::toString(value.lineSpeed));
    // parity  [REF CHEntries::Parity]
    //   CARDINAL
    list << QString("[%1 %2]").arg("parity").arg(Courier::toString(value.parity));
    // stopBits  [REF CHEntries::StopBits]
    //   CARDINAL
    list << QString("[%1 %2]").arg("stopBits").arg(Courier::toString(value.stopBits));
    // portActsAsDCE  BOOLEAN
    list << QString("[%1 %2]").arg("portActsAsDCE").arg(Courier::toString(value.portActsAsDCE));
    // accessControl  [REF Clearinghouse2::Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("accessControl").arg(Courier::toString(value.accessControl));
    // validLineSpeeds  [SEQUENCE (65535)[REF CHEntries::LineSpeed]]]
    //   [SEQUENCE (65535)CARDINAL]]
    list << QString("[%1 %2]").arg("validLineSpeeds").arg(Courier::toString(value.validLineSpeeds));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::MailboxesValue& value) {
    // time  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::serialize(block, value.time);
    // mailService  [SEQUENCE (65535)[REF Clearinghouse2::Name]]]
    //   [SEQUENCE (65535)RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]]]
    Courier::serialize(block, value.mailService);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::AuthenticationLevelValue& value) {
    // simpleSupported  BOOLEAN
    Courier::serialize(block, value.simpleSupported);
    // strongSupported  BOOLEAN
    Courier::serialize(block, value.strongSupported);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::UserDataValue& value) {
    // lastNameIndex  CARDINAL
    Courier::serialize(block, value.lastNameIndex);
    // fileService  [REF Clearinghouse2::Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.fileService);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::CHEntries::RS232CData& value) {
    // cIUPort  BOOLEAN
    Courier::serialize(block, value.cIUPort);
    // owningClientType  [REF CHEntries::PortClientType]
    //   ENUM [UNSPECIFIED [[unassigned  0], [outOfService  1], [its  2], [irs  3], [gws  4], [ibm3270Host  5], [ttyEmulation  6], [rbs  7], [fax  9], [mailGateway  10], [phototypesetter  11]]]
    Courier::serialize(block, value.owningClientType);
    // preemptionAllowed  BOOLEAN
    Courier::serialize(block, value.preemptionAllowed);
    // lineNumber  CARDINAL
    Courier::serialize(block, value.lineNumber);
    // dialerNumber  CARDINAL
    Courier::serialize(block, value.dialerNumber);
    // duplexity  [REF CHEntries::Duplexity]
    //   CARDINAL
    Courier::serialize(block, value.duplexity);
    // dialingHardware  [REF CHEntries::PortDialerType]
    //   ENUM [UNSPECIFIED [[dialerNone  0], [vadic  1], [hayes  2], [ventel  3], [rs366  4]]]
    Courier::serialize(block, value.dialingHardware);
    // charLength  [REF CHEntries::CharLength]
    //   CARDINAL
    Courier::serialize(block, value.charLength);
    // echoing  [REF CHEntries::PortEchoingLocation]
    //   ENUM [UNSPECIFIED [[echoLocal  0], [echoRemote  1]]]
    Courier::serialize(block, value.echoing);
    // xxxxpaddingxxx  LONG_CARDINAL
    Courier::serialize(block, value.xxxxpaddingxxx);
    // flowControl  [REF CHEntries::FlowControl]
    //   CARDINAL
    Courier::serialize(block, value.flowControl);
    // lineSpeed  [REF CHEntries::LineSpeed]
    //   CARDINAL
    Courier::serialize(block, value.lineSpeed);
    // parity  [REF CHEntries::Parity]
    //   CARDINAL
    Courier::serialize(block, value.parity);
    // stopBits  [REF CHEntries::StopBits]
    //   CARDINAL
    Courier::serialize(block, value.stopBits);
    // portActsAsDCE  BOOLEAN
    Courier::serialize(block, value.portActsAsDCE);
    // accessControl  [REF Clearinghouse2::Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.accessControl);
    // validLineSpeeds  [SEQUENCE (65535)[REF CHEntries::LineSpeed]]]
    //   [SEQUENCE (65535)CARDINAL]]
    Courier::serialize(block, value.validLineSpeeds);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::MailboxesValue& value) {
    // time  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::deserialize(block, value.time);
    // mailService  [SEQUENCE (65535)[REF Clearinghouse2::Name]]]
    //   [SEQUENCE (65535)RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]]]
    Courier::deserialize(block, value.mailService);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::AuthenticationLevelValue& value) {
    // simpleSupported  BOOLEAN
    Courier::deserialize(block, value.simpleSupported);
    // strongSupported  BOOLEAN
    Courier::deserialize(block, value.strongSupported);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::UserDataValue& value) {
    // lastNameIndex  CARDINAL
    Courier::deserialize(block, value.lastNameIndex);
    // fileService  [REF Clearinghouse2::Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.fileService);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::CHEntries::RS232CData& value) {
    // cIUPort  BOOLEAN
    Courier::deserialize(block, value.cIUPort);
    // owningClientType  [REF CHEntries::PortClientType]
    //   ENUM [UNSPECIFIED [[unassigned  0], [outOfService  1], [its  2], [irs  3], [gws  4], [ibm3270Host  5], [ttyEmulation  6], [rbs  7], [fax  9], [mailGateway  10], [phototypesetter  11]]]
    Courier::deserialize(block, value.owningClientType);
    // preemptionAllowed  BOOLEAN
    Courier::deserialize(block, value.preemptionAllowed);
    // lineNumber  CARDINAL
    Courier::deserialize(block, value.lineNumber);
    // dialerNumber  CARDINAL
    Courier::deserialize(block, value.dialerNumber);
    // duplexity  [REF CHEntries::Duplexity]
    //   CARDINAL
    Courier::deserialize(block, value.duplexity);
    // dialingHardware  [REF CHEntries::PortDialerType]
    //   ENUM [UNSPECIFIED [[dialerNone  0], [vadic  1], [hayes  2], [ventel  3], [rs366  4]]]
    Courier::deserialize(block, value.dialingHardware);
    // charLength  [REF CHEntries::CharLength]
    //   CARDINAL
    Courier::deserialize(block, value.charLength);
    // echoing  [REF CHEntries::PortEchoingLocation]
    //   ENUM [UNSPECIFIED [[echoLocal  0], [echoRemote  1]]]
    Courier::deserialize(block, value.echoing);
    // xxxxpaddingxxx  LONG_CARDINAL
    Courier::deserialize(block, value.xxxxpaddingxxx);
    // flowControl  [REF CHEntries::FlowControl]
    //   CARDINAL
    Courier::deserialize(block, value.flowControl);
    // lineSpeed  [REF CHEntries::LineSpeed]
    //   CARDINAL
    Courier::deserialize(block, value.lineSpeed);
    // parity  [REF CHEntries::Parity]
    //   CARDINAL
    Courier::deserialize(block, value.parity);
    // stopBits  [REF CHEntries::StopBits]
    //   CARDINAL
    Courier::deserialize(block, value.stopBits);
    // portActsAsDCE  BOOLEAN
    Courier::deserialize(block, value.portActsAsDCE);
    // accessControl  [REF Clearinghouse2::Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.accessControl);
    // validLineSpeeds  [SEQUENCE (65535)[REF CHEntries::LineSpeed]]]
    //   [SEQUENCE (65535)CARDINAL]]
    Courier::deserialize(block, value.validLineSpeeds);
}
