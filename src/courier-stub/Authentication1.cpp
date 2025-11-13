#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub/Authentication1");

#include "../stub/Authentication1.h"

#include "../courier/Last.h"


//
// Enum Function Definition
//

QString Courier::toString(const Courier::Stub::Authentication1::Which value) {
    static QMap<Courier::Stub::Authentication1::Which, QString> map = {
        {Courier::Stub::Authentication1::Which::notApplicable, "notApplicable"},
        {Courier::Stub::Authentication1::Which::initiator,     "initiator"},
        {Courier::Stub::Authentication1::Which::recipient,     "recipient"},
        {Courier::Stub::Authentication1::Which::client,        "client"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}

QString Courier::toString(const Courier::Stub::Authentication1::Problem value) {
    static QMap<Courier::Stub::Authentication1::Problem, QString> map = {
        {Courier::Stub::Authentication1::Problem::credentialsInvalid,       "credentialsInvalid"},
        {Courier::Stub::Authentication1::Problem::verifierInvalid,          "verifierInvalid"},
        {Courier::Stub::Authentication1::Problem::verifierExpired,          "verifierExpired"},
        {Courier::Stub::Authentication1::Problem::verifierReused,           "verifierReused"},
        {Courier::Stub::Authentication1::Problem::credentialsExpired,       "credentialsExpired"},
        {Courier::Stub::Authentication1::Problem::inappropriateCredentials, "inappropriateCredentials"},
    };

    if (map.contains(value)) {
        return map[value];
    } else {
        return QString("%1").arg((quint16)value);
    }
}


void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication1::Which value) {
    Courier::serialize(block, (quint16)value);
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication1::Problem value) {
    Courier::serialize(block, (quint16)value);
}


void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication1::Which& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication1::Which)t;
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication1::Problem& value) {
    quint16 t;
    Courier::deserialize(block, t);
    value = (Courier::Stub::Authentication1::Problem)t;
}

//
// Record Function Definition
//
QString Courier::toString(const Courier::Stub::Authentication1::ClearinghouseThreePartName& value) {
    QStringList list;
    // organization  [REF Authentication1::ClearinghouseOrganization]
    //   STRING
    list << QString("[%1 %2]").arg("organization").arg(Courier::toString(value.organization));
    // domain  [REF Authentication1::ClearinghouseDomain]
    //   STRING
    list << QString("[%1 %2]").arg("domain").arg(Courier::toString(value.domain));
    // object  [REF Authentication1::ClearinghouseObject]
    //   STRING
    list << QString("[%1 %2]").arg("object").arg(Courier::toString(value.object));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication1::Credentials& value) {
    QStringList list;
    // type  [REF Authentication1::CredentialsType]
    //   CARDINAL
    list << QString("[%1 %2]").arg("type").arg(Courier::toString(value.type));
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    list << QString("[%1 %2]").arg("value").arg(Courier::toString(value.value));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication1::CallError& value) {
    QStringList list;
    // problem  [REF Authentication1::CallProblem]
    //   CARDINAL
    list << QString("[%1 %2]").arg("problem").arg(Courier::toString(value.problem));
    // whichArg  [REF Authentication1::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
    list << QString("[%1 %2]").arg("whichArg").arg(Courier::toString(value.whichArg));
    return QString("[%1]").arg(list.join(" "));
}
QString Courier::toString(const Courier::Stub::Authentication1::AuthenticationError& value) {
    QStringList list;
    // problem  [REF Authentication1::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
    list << QString("[%1 %2]").arg("problem").arg(Courier::toString(value.problem));
    return QString("[%1]").arg(list.join(" "));
}

void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication1::ClearinghouseThreePartName& value) {
    // organization  [REF Authentication1::ClearinghouseOrganization]
    //   STRING
    Courier::serialize(block, value.organization);
    // domain  [REF Authentication1::ClearinghouseDomain]
    //   STRING
    Courier::serialize(block, value.domain);
    // object  [REF Authentication1::ClearinghouseObject]
    //   STRING
    Courier::serialize(block, value.object);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication1::Credentials& value) {
    // type  [REF Authentication1::CredentialsType]
    //   CARDINAL
    Courier::serialize(block, value.type);
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::serialize(block, value.value);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication1::CallError& value) {
    // problem  [REF Authentication1::CallProblem]
    //   CARDINAL
    Courier::serialize(block, value.problem);
    // whichArg  [REF Authentication1::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
    Courier::serialize(block, value.whichArg);
}
void Courier::serialize(BLOCK& block, const Courier::Stub::Authentication1::AuthenticationError& value) {
    // problem  [REF Authentication1::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
    Courier::serialize(block, value.problem);
}

void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication1::ClearinghouseThreePartName& value) {
    // organization  [REF Authentication1::ClearinghouseOrganization]
    //   STRING
    Courier::deserialize(block, value.organization);
    // domain  [REF Authentication1::ClearinghouseDomain]
    //   STRING
    Courier::deserialize(block, value.domain);
    // object  [REF Authentication1::ClearinghouseObject]
    //   STRING
    Courier::deserialize(block, value.object);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication1::Credentials& value) {
    // type  [REF Authentication1::CredentialsType]
    //   CARDINAL
    Courier::deserialize(block, value.type);
    // value  [SEQUENCE (65535)UNSPECIFIED]]
    Courier::deserialize(block, value.value);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication1::CallError& value) {
    // problem  [REF Authentication1::CallProblem]
    //   CARDINAL
    Courier::deserialize(block, value.problem);
    // whichArg  [REF Authentication1::Which]
    //   ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
    Courier::deserialize(block, value.whichArg);
}
void Courier::deserialize(BLOCK& block, Courier::Stub::Authentication1::AuthenticationError& value) {
    // problem  [REF Authentication1::Problem]
    //   ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
    Courier::deserialize(block, value.problem);
}
