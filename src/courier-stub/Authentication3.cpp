#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Authentication3");

#include "../stub/Authentication3.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Authentication3::CredentialsType value) {
    static QMap<Courier::Stub::Authentication3::CredentialsType, QString> map = {
        {Courier::Stub::Authentication3::CredentialsType::simple, "simple"},
        {Courier::Stub::Authentication3::CredentialsType::strong, "strong"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Authentication3::Problem value) {
    static QMap<Courier::Stub::Authentication3::Problem, QString> map = {
        {Courier::Stub::Authentication3::Problem::credentialsInvalid,       "credentialsInvalid"},
        {Courier::Stub::Authentication3::Problem::verifierInvalid,          "verifierInvalid"},
        {Courier::Stub::Authentication3::Problem::verifierExpired,          "verifierExpired"},
        {Courier::Stub::Authentication3::Problem::verifierReused,           "verifierReused"},
        {Courier::Stub::Authentication3::Problem::credentialsExpired,       "credentialsExpired"},
        {Courier::Stub::Authentication3::Problem::inappropriateCredentials, "inappropriateCredentials"},
        {Courier::Stub::Authentication3::Problem::proxyInvalid,             "proxyInvalid"},
        {Courier::Stub::Authentication3::Problem::proxyExpired,             "proxyExpired"},
        {Courier::Stub::Authentication3::Problem::otherProblem,             "otherProblem"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Authentication3::CallProblem value) {
    static QMap<Courier::Stub::Authentication3::CallProblem, QString> map = {
        {Courier::Stub::Authentication3::CallProblem::tooBusy,                    "tooBusy"},
        {Courier::Stub::Authentication3::CallProblem::accessRightsInsufficient,   "accessRightsInsufficient"},
        {Courier::Stub::Authentication3::CallProblem::keysUnavailable,            "keysUnavailable"},
        {Courier::Stub::Authentication3::CallProblem::strongKeyDoesNotExist,      "strongKeyDoesNotExist"},
        {Courier::Stub::Authentication3::CallProblem::simpleKeyDoesNotExist,      "simpleKeyDoesNotExist"},
        {Courier::Stub::Authentication3::CallProblem::strongKeyAlreadyRegistered, "strongKeyAlreadyRegistered"},
        {Courier::Stub::Authentication3::CallProblem::simpleKeyAlreadyRegistered, "simpleKeyAlreadyRegistered"},
        {Courier::Stub::Authentication3::CallProblem::domainForNewKeyUnavailable, "domainForNewKeyUnavailable"},
        {Courier::Stub::Authentication3::CallProblem::domainForNewKeyUnknown,     "domainForNewKeyUnknown"},
        {Courier::Stub::Authentication3::CallProblem::badKey,                     "badKey"},
        {Courier::Stub::Authentication3::CallProblem::badName,                    "badName"},
        {Courier::Stub::Authentication3::CallProblem::databaseFull,               "databaseFull"},
        {Courier::Stub::Authentication3::CallProblem::otherCallProblem,           "otherCallProblem"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Authentication3::Which value) {
    static QMap<Courier::Stub::Authentication3::Which, QString> map = {
        {Courier::Stub::Authentication3::Which::notApplicable, "notApplicable"},
        {Courier::Stub::Authentication3::Which::initiator,     "initiator"},
        {Courier::Stub::Authentication3::Which::recipient,     "recipient"},
        {Courier::Stub::Authentication3::Which::agent,         "agent"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CredentialsType value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::Problem value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CallProblem value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::Which value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CredentialsType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication3::CredentialsType)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::Problem& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication3::Problem)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CallProblem& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication3::CallProblem)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::Which& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication3::Which)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Authentication3::ThreePartName& value) {
    QStringList list;
    // organization  [REF Authentication3::Organization]
    //   STRING
    list << QString("[%1 %2]").arg("organization").arg(Courier::toString(value.organization));
    // domain  [REF Authentication3::Domain]
    //   STRING
    list << QString("[%1 %2]").arg("domain").arg(Courier::toString(value.domain));
    // object  [REF Authentication3::Object]
    //   STRING
    list << QString("[%1 %2]").arg("object").arg(Courier::toString(value.object));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::Credentials& value) {
    QStringList list;
    // type  [REF Authentication3::CredentialsType]
    //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("value").arg(Courier::toString(value.value));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::CredentialsPackage& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // nonce  LONG_CARDINAL
    list << QString("[%1 %2]").arg("nonce").arg(Courier::toString(value.nonce));
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("recipient").arg(Courier::toString(value.recipient));
    // conversationKey  [REF Authentication3::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("conversationKey").arg(Courier::toString(value.conversationKey));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::StrongCredentials& value) {
    QStringList list;
    // conversationKey  [REF Authentication3::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("conversationKey").arg(Courier::toString(value.conversationKey));
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    list << QString("[%1 %2]").arg("expirationTime").arg(Courier::toString(value.expirationTime));
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("initiator").arg(Courier::toString(value.initiator));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::StrongVerifier& value) {
    QStringList list;
    // timeStamp  [REF Time2::Time]
    //   LONG_CARDINAL
    list << QString("[%1 %2]").arg("timeStamp").arg(Courier::toString(value.timeStamp));
    // ticks  LONG_CARDINAL
    list << QString("[%1 %2]").arg("ticks").arg(Courier::toString(value.ticks));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::StrongProxy& value) {
    QStringList list;
    // randomBits  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("randomBits").arg(Courier::toString(value.randomBits));
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    list << QString("[%1 %2]").arg("expirationTime").arg(Courier::toString(value.expirationTime));
    // agent  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("agent").arg(Courier::toString(value.agent));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::AuthenticationError& value) {
    QStringList list;
    // problem  [REF Authentication3::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5], [proxyInvalid  6], [proxyExpired  7], [otherProblem  8]]]
    list << QString("[%1 %2]").arg("problem").arg(Courier::toString(value.problem));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::CallError& value) {
    QStringList list;
    // problem  [REF Authentication3::CallProblem]
    //   ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [otherCallProblem  12]]]
    list << QString("[%1 %2]").arg("problem").arg(Courier::toString(value.problem));
    // whichArg  [REF Authentication3::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [agent  3]]]
    list << QString("[%1 %2]").arg("whichArg").arg(Courier::toString(value.whichArg));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::GetStrongCredentials::Param& value) {
    QStringList list;
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("initiator").arg(Courier::toString(value.initiator));
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("recipient").arg(Courier::toString(value.recipient));
    // nonce  LONG_CARDINAL
    list << QString("[%1 %2]").arg("nonce").arg(Courier::toString(value.nonce));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::GetStrongCredentials::Result& value) {
    QStringList list;
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("credentialsPackage").arg(Courier::toString(value.credentialsPackage));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::TradeProxyForCredentials::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("initiator").arg(Courier::toString(value.initiator));
    // proxy  [REF Authentication3::Proxy]
    //   [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("proxy").arg(Courier::toString(value.proxy));
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("recipient").arg(Courier::toString(value.recipient));
    // nonce  LONG_CARDINAL
    list << QString("[%1 %2]").arg("nonce").arg(Courier::toString(value.nonce));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::TradeProxyForCredentials::Result& value) {
    QStringList list;
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("credentialsPackage").arg(Courier::toString(value.credentialsPackage));
    // proxyForRecipient  [REF Authentication3::Proxy]
    //   [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("proxyForRecipient").arg(Courier::toString(value.proxyForRecipient));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::CreateStrongKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    // encryptedKey  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("encryptedKey").arg(Courier::toString(value.encryptedKey));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::CreateStrongKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication3::ChangeStrongKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // encryptedNewKey  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("encryptedNewKey").arg(Courier::toString(value.encryptedNewKey));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::ChangeStrongKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication3::DeleteStrongKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::DeleteStrongKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication3::CheckSimpleCredentials::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::CheckSimpleCredentials::Result& value) {
    QStringList list;
    // ok  BOOLEAN
    list << QString("[%1 %2]").arg("ok").arg(Courier::toString(value.ok));
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("initiator").arg(Courier::toString(value.initiator));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::CreateSimpleKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    // key  [REF Authentication3::HashedPassword]
    //   CARDINAL
    list << QString("[%1 %2]").arg("key").arg(Courier::toString(value.key));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::CreateSimpleKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication3::ChangeSimpleKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // newKey  [REF Authentication3::HashedPassword]
    //   CARDINAL
    list << QString("[%1 %2]").arg("newKey").arg(Courier::toString(value.newKey));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::ChangeSimpleKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication3::DeleteSimpleKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication3::DeleteSimpleKey::Result&) {
    return "[]";
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::ThreePartName& value) {
    // organization  [REF Authentication3::Organization]
    //   STRING
    Courier::serialize(block, value.organization);
    // domain  [REF Authentication3::Domain]
    //   STRING
    Courier::serialize(block, value.domain);
    // object  [REF Authentication3::Object]
    //   STRING
    Courier::serialize(block, value.object);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::Credentials& value) {
    // type  [REF Authentication3::CredentialsType]
    //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
    Courier::serialize(block, value.type);
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.value);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CredentialsPackage& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // nonce  LONG_CARDINAL
    Courier::serialize(block, value.nonce);
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.recipient);
    // conversationKey  [REF Authentication3::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.conversationKey);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::StrongCredentials& value) {
    // conversationKey  [REF Authentication3::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.conversationKey);
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::serialize(block, value.expirationTime);
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.initiator);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::StrongVerifier& value) {
    // timeStamp  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::serialize(block, value.timeStamp);
    // ticks  LONG_CARDINAL
    Courier::serialize(block, value.ticks);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::StrongProxy& value) {
    // randomBits  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.randomBits);
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::serialize(block, value.expirationTime);
    // agent  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.agent);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::AuthenticationError& value) {
    // problem  [REF Authentication3::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5], [proxyInvalid  6], [proxyExpired  7], [otherProblem  8]]]
    Courier::serialize(block, value.problem);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CallError& value) {
    // problem  [REF Authentication3::CallProblem]
    //   ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [otherCallProblem  12]]]
    Courier::serialize(block, value.problem);
    // whichArg  [REF Authentication3::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [agent  3]]]
    Courier::serialize(block, value.whichArg);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::GetStrongCredentials::Param& value) {
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.initiator);
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.recipient);
    // nonce  LONG_CARDINAL
    Courier::serialize(block, value.nonce);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::GetStrongCredentials::Result& value) {
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.credentialsPackage);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::TradeProxyForCredentials::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.initiator);
    // proxy  [REF Authentication3::Proxy]
    //   [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.proxy);
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.recipient);
    // nonce  LONG_CARDINAL
    Courier::serialize(block, value.nonce);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::TradeProxyForCredentials::Result& value) {
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.credentialsPackage);
    // proxyForRecipient  [REF Authentication3::Proxy]
    //   [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.proxyForRecipient);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CreateStrongKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
    // encryptedKey  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.encryptedKey);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication3::CreateStrongKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::ChangeStrongKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // encryptedNewKey  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.encryptedNewKey);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication3::ChangeStrongKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::DeleteStrongKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication3::DeleteStrongKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CheckSimpleCredentials::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CheckSimpleCredentials::Result& value) {
    // ok  BOOLEAN
    Courier::serialize(block, value.ok);
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.initiator);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::CreateSimpleKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
    // key  [REF Authentication3::HashedPassword]
    //   CARDINAL
    Courier::serialize(block, value.key);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication3::CreateSimpleKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::ChangeSimpleKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // newKey  [REF Authentication3::HashedPassword]
    //   CARDINAL
    Courier::serialize(block, value.newKey);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication3::ChangeSimpleKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication3::DeleteSimpleKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication3::DeleteSimpleKey::Result&) {
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::ThreePartName& value) {
    // organization  [REF Authentication3::Organization]
    //   STRING
    Courier::deserialize(block, value.organization);
    // domain  [REF Authentication3::Domain]
    //   STRING
    Courier::deserialize(block, value.domain);
    // object  [REF Authentication3::Object]
    //   STRING
    Courier::deserialize(block, value.object);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::Credentials& value) {
    // type  [REF Authentication3::CredentialsType]
    //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
    Courier::deserialize(block, value.type);
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.value);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CredentialsPackage& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // nonce  LONG_CARDINAL
    Courier::deserialize(block, value.nonce);
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.recipient);
    // conversationKey  [REF Authentication3::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.conversationKey);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::StrongCredentials& value) {
    // conversationKey  [REF Authentication3::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.conversationKey);
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::deserialize(block, value.expirationTime);
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.initiator);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::StrongVerifier& value) {
    // timeStamp  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::deserialize(block, value.timeStamp);
    // ticks  LONG_CARDINAL
    Courier::deserialize(block, value.ticks);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::StrongProxy& value) {
    // randomBits  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.randomBits);
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::deserialize(block, value.expirationTime);
    // agent  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.agent);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::AuthenticationError& value) {
    // problem  [REF Authentication3::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5], [proxyInvalid  6], [proxyExpired  7], [otherProblem  8]]]
    Courier::deserialize(block, value.problem);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CallError& value) {
    // problem  [REF Authentication3::CallProblem]
    //   ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [otherCallProblem  12]]]
    Courier::deserialize(block, value.problem);
    // whichArg  [REF Authentication3::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [agent  3]]]
    Courier::deserialize(block, value.whichArg);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::GetStrongCredentials::Param& value) {
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.initiator);
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.recipient);
    // nonce  LONG_CARDINAL
    Courier::deserialize(block, value.nonce);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::GetStrongCredentials::Result& value) {
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.credentialsPackage);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::TradeProxyForCredentials::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.initiator);
    // proxy  [REF Authentication3::Proxy]
    //   [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.proxy);
    // recipient  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.recipient);
    // nonce  LONG_CARDINAL
    Courier::deserialize(block, value.nonce);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::TradeProxyForCredentials::Result& value) {
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.credentialsPackage);
    // proxyForRecipient  [REF Authentication3::Proxy]
    //   [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.proxyForRecipient);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CreateStrongKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
    // encryptedKey  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.encryptedKey);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication3::CreateStrongKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::ChangeStrongKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // encryptedNewKey  [REF Authentication3::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.encryptedNewKey);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication3::ChangeStrongKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::DeleteStrongKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication3::DeleteStrongKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CheckSimpleCredentials::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CheckSimpleCredentials::Result& value) {
    // ok  BOOLEAN
    Courier::deserialize(block, value.ok);
    // initiator  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.initiator);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::CreateSimpleKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
    // key  [REF Authentication3::HashedPassword]
    //   CARDINAL
    Courier::deserialize(block, value.key);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication3::CreateSimpleKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::ChangeSimpleKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // newKey  [REF Authentication3::HashedPassword]
    //   CARDINAL
    Courier::deserialize(block, value.newKey);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication3::ChangeSimpleKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication3::DeleteSimpleKey::Param& value) {
    // credentials  [REF Authentication3::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication3::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication3::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication3::DeleteSimpleKey::Result&) {
}
