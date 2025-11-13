#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Authentication2");

#include "../stub/Authentication2.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Authentication2::CredentialsType value) {
    static QMap<Courier::Stub::Authentication2::CredentialsType, QString> map = {
        {Courier::Stub::Authentication2::CredentialsType::simple, "simple"},
        {Courier::Stub::Authentication2::CredentialsType::strong, "strong"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Authentication2::Problem value) {
    static QMap<Courier::Stub::Authentication2::Problem, QString> map = {
        {Courier::Stub::Authentication2::Problem::credentialsInvalid,       "credentialsInvalid"},
        {Courier::Stub::Authentication2::Problem::verifierInvalid,          "verifierInvalid"},
        {Courier::Stub::Authentication2::Problem::verifierExpired,          "verifierExpired"},
        {Courier::Stub::Authentication2::Problem::verifierReused,           "verifierReused"},
        {Courier::Stub::Authentication2::Problem::credentialsExpired,       "credentialsExpired"},
        {Courier::Stub::Authentication2::Problem::inappropriateCredentials, "inappropriateCredentials"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Authentication2::CallProblem value) {
    static QMap<Courier::Stub::Authentication2::CallProblem, QString> map = {
        {Courier::Stub::Authentication2::CallProblem::tooBusy,                    "tooBusy"},
        {Courier::Stub::Authentication2::CallProblem::accessRightsInsufficient,   "accessRightsInsufficient"},
        {Courier::Stub::Authentication2::CallProblem::keysUnavailable,            "keysUnavailable"},
        {Courier::Stub::Authentication2::CallProblem::strongKeyDoesNotExist,      "strongKeyDoesNotExist"},
        {Courier::Stub::Authentication2::CallProblem::simpleKeyDoesNotExist,      "simpleKeyDoesNotExist"},
        {Courier::Stub::Authentication2::CallProblem::strongKeyAlreadyRegistered, "strongKeyAlreadyRegistered"},
        {Courier::Stub::Authentication2::CallProblem::simpleKeyAlreadyRegistered, "simpleKeyAlreadyRegistered"},
        {Courier::Stub::Authentication2::CallProblem::domainForNewKeyUnavailable, "domainForNewKeyUnavailable"},
        {Courier::Stub::Authentication2::CallProblem::domainForNewKeyUnknown,     "domainForNewKeyUnknown"},
        {Courier::Stub::Authentication2::CallProblem::badKey,                     "badKey"},
        {Courier::Stub::Authentication2::CallProblem::badName,                    "badName"},
        {Courier::Stub::Authentication2::CallProblem::databaseFull,               "databaseFull"},
        {Courier::Stub::Authentication2::CallProblem::other,                      "other"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Authentication2::Which value) {
    static QMap<Courier::Stub::Authentication2::Which, QString> map = {
        {Courier::Stub::Authentication2::Which::notApplicable, "notApplicable"},
        {Courier::Stub::Authentication2::Which::initiator,     "initiator"},
        {Courier::Stub::Authentication2::Which::recipient,     "recipient"},
        {Courier::Stub::Authentication2::Which::client,        "client"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CredentialsType value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::Problem value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CallProblem value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::Which value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CredentialsType& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication2::CredentialsType)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::Problem& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication2::Problem)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CallProblem& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication2::CallProblem)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::Which& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication2::Which)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Authentication2::ThreePartName& value) {
    QStringList list;
    // organization  [REF Authentication2::Organization]
    //   STRING
    list << QString("[%1 %2]").arg("organization").arg(Courier::toString(value.organization));
    // domain  [REF Authentication2::Domain]
    //   STRING
    list << QString("[%1 %2]").arg("domain").arg(Courier::toString(value.domain));
    // object  [REF Authentication2::Object]
    //   STRING
    list << QString("[%1 %2]").arg("object").arg(Courier::toString(value.object));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::Credentials& value) {
    QStringList list;
    // type  [REF Authentication2::CredentialsType]
    //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("value").arg(Courier::toString(value.value));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::CredentialsPackage& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // nonce  LONG_CARDINAL
    list << QString("[%1 %2]").arg("nonce").arg(Courier::toString(value.nonce));
    // recipient  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("recipient").arg(Courier::toString(value.recipient));
    // conversationKey  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("conversationKey").arg(Courier::toString(value.conversationKey));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::StrongCredentials& value) {
    QStringList list;
    // conversationKey  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("conversationKey").arg(Courier::toString(value.conversationKey));
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    list << QString("[%1 %2]").arg("expirationTime").arg(Courier::toString(value.expirationTime));
    // initiator  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("initiator").arg(Courier::toString(value.initiator));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::StrongVerifier& value) {
    QStringList list;
    // timeStamp  [REF Time2::Time]
    //   LONG_CARDINAL
    list << QString("[%1 %2]").arg("timeStamp").arg(Courier::toString(value.timeStamp));
    // ticks  LONG_CARDINAL
    list << QString("[%1 %2]").arg("ticks").arg(Courier::toString(value.ticks));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::AuthenticationError& value) {
    QStringList list;
    // problem  [REF Authentication2::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
    list << QString("[%1 %2]").arg("problem").arg(Courier::toString(value.problem));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::CallError& value) {
    QStringList list;
    // problem  [REF Authentication2::CallProblem]
    //   ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [other  12]]]
    list << QString("[%1 %2]").arg("problem").arg(Courier::toString(value.problem));
    // whichArg  [REF Authentication2::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
    list << QString("[%1 %2]").arg("whichArg").arg(Courier::toString(value.whichArg));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::GetStrongCredentials::Param& value) {
    QStringList list;
    // initiator  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("initiator").arg(Courier::toString(value.initiator));
    // recipient  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("recipient").arg(Courier::toString(value.recipient));
    // nonce  LONG_CARDINAL
    list << QString("[%1 %2]").arg("nonce").arg(Courier::toString(value.nonce));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::GetStrongCredentials::Result& value) {
    QStringList list;
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("credentialsPackage").arg(Courier::toString(value.credentialsPackage));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::CreateStrongKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    // key  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("key").arg(Courier::toString(value.key));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::CreateStrongKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication2::ChangeStrongKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // newKey  [REF Authentication2::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("newKey").arg(Courier::toString(value.newKey));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::ChangeStrongKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication2::DeleteStrongKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::DeleteStrongKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication2::CheckSimpleCredentials::Param& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::CheckSimpleCredentials::Result& value) {
    QStringList list;
    // ok  BOOLEAN
    list << QString("[%1 %2]").arg("ok").arg(Courier::toString(value.ok));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::CreateSimpleKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    // key  [REF Authentication2::HashedPassword]
    //   CARDINAL
    list << QString("[%1 %2]").arg("key").arg(Courier::toString(value.key));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::CreateSimpleKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication2::ChangeSimpleKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // newKey  [REF Authentication2::HashedPassword]
    //   CARDINAL
    list << QString("[%1 %2]").arg("newKey").arg(Courier::toString(value.newKey));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::ChangeSimpleKey::Result&) {
    return "[]";
}
QString Courier::toString(const Courier::Stub::Authentication2::DeleteSimpleKey::Param& value) {
    QStringList list;
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    list << QString("[%1 %2]").arg("credentials").arg(Courier::toString(value.credentials));
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("verifier").arg(Courier::toString(value.verifier));
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    list << QString("[%1 %2]").arg("name").arg(Courier::toString(value.name));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication2::DeleteSimpleKey::Result&) {
    return "[]";
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::ThreePartName& value) {
    // organization  [REF Authentication2::Organization]
    //   STRING
    Courier::serialize(block, value.organization);
    // domain  [REF Authentication2::Domain]
    //   STRING
    Courier::serialize(block, value.domain);
    // object  [REF Authentication2::Object]
    //   STRING
    Courier::serialize(block, value.object);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::Credentials& value) {
    // type  [REF Authentication2::CredentialsType]
    //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
    Courier::serialize(block, value.type);
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.value);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CredentialsPackage& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // nonce  LONG_CARDINAL
    Courier::serialize(block, value.nonce);
    // recipient  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.recipient);
    // conversationKey  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.conversationKey);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::StrongCredentials& value) {
    // conversationKey  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.conversationKey);
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::serialize(block, value.expirationTime);
    // initiator  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.initiator);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::StrongVerifier& value) {
    // timeStamp  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::serialize(block, value.timeStamp);
    // ticks  LONG_CARDINAL
    Courier::serialize(block, value.ticks);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::AuthenticationError& value) {
    // problem  [REF Authentication2::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
    Courier::serialize(block, value.problem);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CallError& value) {
    // problem  [REF Authentication2::CallProblem]
    //   ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [other  12]]]
    Courier::serialize(block, value.problem);
    // whichArg  [REF Authentication2::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
    Courier::serialize(block, value.whichArg);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::GetStrongCredentials::Param& value) {
    // initiator  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.initiator);
    // recipient  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.recipient);
    // nonce  LONG_CARDINAL
    Courier::serialize(block, value.nonce);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::GetStrongCredentials::Result& value) {
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.credentialsPackage);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CreateStrongKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
    // key  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.key);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication2::CreateStrongKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::ChangeStrongKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // newKey  [REF Authentication2::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::serialize(block, value.newKey);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication2::ChangeStrongKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::DeleteStrongKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication2::DeleteStrongKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CheckSimpleCredentials::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CheckSimpleCredentials::Result& value) {
    // ok  BOOLEAN
    Courier::serialize(block, value.ok);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::CreateSimpleKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
    // key  [REF Authentication2::HashedPassword]
    //   CARDINAL
    Courier::serialize(block, value.key);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication2::CreateSimpleKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::ChangeSimpleKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // newKey  [REF Authentication2::HashedPassword]
    //   CARDINAL
    Courier::serialize(block, value.newKey);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication2::ChangeSimpleKey::Result&) {
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication2::DeleteSimpleKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::serialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::serialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::serialize(block, value.name);
}
void Courier::serialize(BLOCK&, const Courier::Stub::Authentication2::DeleteSimpleKey::Result&) {
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::ThreePartName& value) {
    // organization  [REF Authentication2::Organization]
    //   STRING
    Courier::deserialize(block, value.organization);
    // domain  [REF Authentication2::Domain]
    //   STRING
    Courier::deserialize(block, value.domain);
    // object  [REF Authentication2::Object]
    //   STRING
    Courier::deserialize(block, value.object);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::Credentials& value) {
    // type  [REF Authentication2::CredentialsType]
    //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
    Courier::deserialize(block, value.type);
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.value);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CredentialsPackage& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // nonce  LONG_CARDINAL
    Courier::deserialize(block, value.nonce);
    // recipient  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.recipient);
    // conversationKey  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.conversationKey);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::StrongCredentials& value) {
    // conversationKey  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.conversationKey);
    // expirationTime  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::deserialize(block, value.expirationTime);
    // initiator  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.initiator);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::StrongVerifier& value) {
    // timeStamp  [REF Time2::Time]
    //   LONG_CARDINAL
    Courier::deserialize(block, value.timeStamp);
    // ticks  LONG_CARDINAL
    Courier::deserialize(block, value.ticks);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::AuthenticationError& value) {
    // problem  [REF Authentication2::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
    Courier::deserialize(block, value.problem);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CallError& value) {
    // problem  [REF Authentication2::CallProblem]
    //   ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [other  12]]]
    Courier::deserialize(block, value.problem);
    // whichArg  [REF Authentication2::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
    Courier::deserialize(block, value.whichArg);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::GetStrongCredentials::Param& value) {
    // initiator  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.initiator);
    // recipient  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.recipient);
    // nonce  LONG_CARDINAL
    Courier::deserialize(block, value.nonce);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::GetStrongCredentials::Result& value) {
    // credentialsPackage  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.credentialsPackage);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CreateStrongKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
    // key  [REF Authentication2::Key]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.key);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication2::CreateStrongKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::ChangeStrongKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // newKey  [REF Authentication2::Block]
    //   [ARRAY (4)UNSPECIFIED]]
    Courier::deserialize(block, value.newKey);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication2::ChangeStrongKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::DeleteStrongKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication2::DeleteStrongKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CheckSimpleCredentials::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CheckSimpleCredentials::Result& value) {
    // ok  BOOLEAN
    Courier::deserialize(block, value.ok);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::CreateSimpleKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
    // key  [REF Authentication2::HashedPassword]
    //   CARDINAL
    Courier::deserialize(block, value.key);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication2::CreateSimpleKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::ChangeSimpleKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // newKey  [REF Authentication2::HashedPassword]
    //   CARDINAL
    Courier::deserialize(block, value.newKey);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication2::ChangeSimpleKey::Result&) {
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication2::DeleteSimpleKey::Param& value) {
    // credentials  [REF Authentication2::Credentials]
    //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
    Courier::deserialize(block, value.credentials);
    // verifier  [REF Authentication2::Verifier]
    //   [SEQUENCE (12)UNSPECIFIED]]
    Courier::deserialize(block, value.verifier);
    // name  [REF Authentication2::Clearinghouse_Name]
    //   RECORD [organization: STRING, domain: STRING, object: STRING]
    Courier::deserialize(block, value.name);
}
void Courier::deserialize(BLOCK&, Courier::Stub::Authentication2::DeleteSimpleKey::Result&) {
}
