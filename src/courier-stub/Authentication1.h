#ifndef STUB_Authentication1_H__
#define STUB_Authentication1_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"
#include "../courier/Service.h"

namespace Courier {
    namespace Stub {
        namespace Authentication1 {

            constexpr const char*   PROGRAM_NAME = "Authentication";
            constexpr const quint32 PROGRAM_CODE = 14;
            constexpr const quint32 VERSION_CODE = 1;

            // TYPE  ClearinghouseOrganization  STRING
            using ClearinghouseOrganization = STRING;

            // TYPE  ClearinghouseDomain  STRING
            using ClearinghouseDomain = STRING;

            // TYPE  ClearinghouseObject  STRING
            using ClearinghouseObject = STRING;

            // TYPE  ClearinghouseThreePartName  RECORD [organization: [REF Authentication1::ClearinghouseOrganization], domain: [REF Authentication1::ClearinghouseDomain], object: [REF Authentication1::ClearinghouseObject]]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            struct ClearinghouseThreePartName {
                ClearinghouseOrganization organization;
                ClearinghouseDomain       domain;
                ClearinghouseObject       object;
            };

            // TYPE  ClearinghouseName  [REF Authentication1::ClearinghouseThreePartName]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            using ClearinghouseName = ClearinghouseThreePartName;

            // TYPE  CredentialsType  CARDINAL
            using CredentialsType = CARDINAL;

            // TYPE  Credentials  RECORD [type: [REF Authentication1::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]]
            //   RECORD [type: CARDINAL, value: [SEQUENCE (65535)UNSPECIFIED]]]
            struct Credentials {
                CredentialsType         type;
                SEQUENCE_N<UNSPECIFIED> value;
            };

            // CONST  simpleCredentials  0  [REF Authentication1::CredentialsType]
            //   CARDINAL
            const CredentialsType simpleCredentials = 0;

            // TYPE  SimpleCredentials  [REF Authentication1::ClearinghouseName]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            using SimpleCredentials = ClearinghouseName;

            // TYPE  Verifier  [SEQUENCE (12)UNSPECIFIED]]
            using Verifier = SEQUENCE_N<UNSPECIFIED,12>;

            // TYPE  HashedPassword  CARDINAL
            using HashedPassword = CARDINAL;

            // TYPE  SimpleVerifier  [REF Authentication1::HashedPassword]
            //   CARDINAL
            using SimpleVerifier = HashedPassword;

            // TYPE  Which  ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
            enum class Which : quint16 {
                notApplicable = 0,
                initiator     = 1,
                recipient     = 2,
                client        = 3,
            };

            // TYPE  CallProblem  CARDINAL
            using CallProblem = CARDINAL;

            // CONST  CallError  1  [ERROR problem: [REF Authentication1::CallProblem], whichArg: [REF Authentication1::Which]]
            //   [ERROR problem: CARDINAL, whichArg: ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]]
            struct CallError : public Service::Abort {
                CallError() : Service::Abort(programName, programCode, versionCode, "CallError", 1), problem(), whichArg() {}

                CallProblem problem;
                Which       whichArg;
            };

            // TYPE  Problem  ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
            enum class Problem : quint16 {
                credentialsInvalid       = 0,
                verifierInvalid          = 1,
                verifierExpired          = 2,
                verifierReused           = 3,
                credentialsExpired       = 4,
                inappropriateCredentials = 5,
            };

            // CONST  AuthenticationError  2  [ERROR problem: [REF Authentication1::Problem]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]]
            struct AuthenticationError : public Service::Abort {
                AuthenticationError() : Service::Abort(programName, programCode, versionCode, "AuthenticationError", 2), problem() {}

                Problem problem;
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Authentication1::Which   value);
    QString toString(const Courier::Stub::Authentication1::Problem value);

    void serialize(BLOCK& block, const Courier::Stub::Authentication1::Which   value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication1::Problem value);

    void deserialize(BLOCK& block, Courier::Stub::Authentication1::Which&   value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication1::Problem& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Authentication1::ClearinghouseThreePartName& value);
    QString toString(const Courier::Stub::Authentication1::Credentials&                value);
    QString toString(const Courier::Stub::Authentication1::CallError&                  value);
    QString toString(const Courier::Stub::Authentication1::AuthenticationError&        value);

    void serialize(BLOCK& block, const Courier::Stub::Authentication1::ClearinghouseThreePartName& value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication1::Credentials&                value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication1::CallError&                  value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication1::AuthenticationError&        value);

    void deserialize(BLOCK& block, Courier::Stub::Authentication1::ClearinghouseThreePartName& value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication1::Credentials&                value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication1::CallError&                  value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication1::AuthenticationError&        value);
}
#endif
