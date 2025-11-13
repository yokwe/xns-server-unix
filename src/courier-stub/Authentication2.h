#ifndef STUB_Authentication2_H__
#define STUB_Authentication2_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"
#include "../courier/Service.h"

#include "../stub/Time2.h"

namespace Courier {
    namespace Stub {
        namespace Authentication2 {

            constexpr const char*   PROGRAM_NAME = "Authentication";
            constexpr const quint32 PROGRAM_CODE = 14;
            constexpr const quint32 VERSION_CODE = 2;

            // TYPE  Organization  STRING
            using Organization = STRING;

            // TYPE  Domain  STRING
            using Domain = STRING;

            // TYPE  Object  STRING
            using Object = STRING;

            // TYPE  ThreePartName  RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            struct ThreePartName {
                Organization organization;
                Domain       domain;
                Object       object;
            };

            // TYPE  Clearinghouse_Name  [REF Authentication2::ThreePartName]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            using Clearinghouse_Name = ThreePartName;

            // TYPE  Key  [ARRAY (4)UNSPECIFIED]]
            using Key = ARRAY_N<UNSPECIFIED,4>;

            // TYPE  Block  [ARRAY (4)UNSPECIFIED]]
            using Block = ARRAY_N<UNSPECIFIED,4>;

            // TYPE  HashedPassword  CARDINAL
            using HashedPassword = CARDINAL;

            // TYPE  CredentialsType  ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
            enum class CredentialsType : quint16 {
                simple = 0,
                strong = 1,
            };

            // CONST  simpleCredentials  [Const REF simple]  [REF Authentication2::CredentialsType]
            //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
            const CredentialsType simpleCredentials = CredentialsType::simple;

            // TYPE  Credentials  RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]]
            //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
            struct Credentials {
                CredentialsType         type;
                SEQUENCE_N<UNSPECIFIED> value;
            };

            // TYPE  CredentialsPackage  RECORD [credentials: [REF Authentication2::Credentials], nonce: LONG_CARDINAL, recipient: [REF Authentication2::Clearinghouse_Name], conversationKey: [REF Authentication2::Key]]
            //   RECORD [credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], nonce: LONG_CARDINAL, recipient: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]], conversationKey: [ARRAY (4)UNSPECIFIED]]]
            struct CredentialsPackage {
                Credentials        credentials;
                LONG_CARDINAL      nonce;
                Clearinghouse_Name recipient;
                Key                conversationKey;
            };

            // TYPE  StrongCredentials  RECORD [conversationKey: [REF Authentication2::Key], expirationTime: [REF Time2::Time], initiator: [REF Authentication2::Clearinghouse_Name]]
            //   RECORD [conversationKey: [ARRAY (4)UNSPECIFIED]], expirationTime: LONG_CARDINAL, initiator: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]]]
            struct StrongCredentials {
                Key                conversationKey;
                Time2::Time        expirationTime;
                Clearinghouse_Name initiator;
            };

            // TYPE  SimpleCredentials  [REF Authentication2::Clearinghouse_Name]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            using SimpleCredentials = Clearinghouse_Name;

            // TYPE  Verifier  [SEQUENCE (12)UNSPECIFIED]]
            using Verifier = SEQUENCE_N<UNSPECIFIED,12>;

            // TYPE  StrongVerifier  RECORD [timeStamp: [REF Time2::Time], ticks: LONG_CARDINAL]
            //   RECORD [timeStamp: LONG_CARDINAL, ticks: LONG_CARDINAL]
            struct StrongVerifier {
                Time2::Time   timeStamp;
                LONG_CARDINAL ticks;
            };

            // TYPE  SimpleVerifier  [REF Authentication2::HashedPassword]
            //   CARDINAL
            using SimpleVerifier = HashedPassword;

            // TYPE  Problem  ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]
            enum class Problem : quint16 {
                credentialsInvalid       = 0,
                verifierInvalid          = 1,
                verifierExpired          = 2,
                verifierReused           = 3,
                credentialsExpired       = 4,
                inappropriateCredentials = 5,
            };

            // CONST  AuthenticationError  2  [ERROR problem: [REF Authentication2::Problem]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]]
            struct AuthenticationError : public Service::Abort {
                AuthenticationError() : Service::Abort(programName, programCode, versionCode, "AuthenticationError", 2), problem() {}

                Problem problem;
            };

            // TYPE  CallProblem  ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [other  12]]]
            enum class CallProblem : quint16 {
                tooBusy                    =  0,
                accessRightsInsufficient   =  1,
                keysUnavailable            =  2,
                strongKeyDoesNotExist      =  3,
                simpleKeyDoesNotExist      =  4,
                strongKeyAlreadyRegistered =  5,
                simpleKeyAlreadyRegistered =  6,
                domainForNewKeyUnavailable =  7,
                domainForNewKeyUnknown     =  8,
                badKey                     =  9,
                badName                    = 10,
                databaseFull               = 11,
                other                      = 12,
            };

            // TYPE  Which  ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]
            enum class Which : quint16 {
                notApplicable = 0,
                initiator     = 1,
                recipient     = 2,
                client        = 3,
            };

            // CONST  CallError  1  [ERROR problem: [REF Authentication2::CallProblem], whichArg: [REF Authentication2::Which]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [other  12]]], whichArg: ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [client  3]]]]
            struct CallError : public Service::Abort {
                CallError() : Service::Abort(programName, programCode, versionCode, "CallError", 1), problem(), whichArg() {}

                CallProblem problem;
                Which       whichArg;
            };

            // CONST  GetStrongCredentials  1  [PROCEDURE arg:[initiator: [REF Authentication2::Clearinghouse_Name], recipient: [REF Authentication2::Clearinghouse_Name], nonce: LONG_CARDINAL] result:[credentialsPackage: [SEQUENCE (65535)UNSPECIFIED]]] error:[CallError]]
            //   [PROCEDURE arg:[initiator: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]], recipient: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]], nonce: LONG_CARDINAL] result:[credentialsPackage: [SEQUENCE (65535)UNSPECIFIED]]] error:[]]
            struct GetStrongCredentials {
                static constexpr const char*   NAME = "GetStrongCredentials";
                static constexpr const quint16 CODE = 1;

                struct Param {
                    Clearinghouse_Name initiator;
                    Clearinghouse_Name recipient;
                    LONG_CARDINAL      nonce;
                };
                struct Result {
                    SEQUENCE_N<UNSPECIFIED> credentialsPackage;
                };

                using call = void (*)(Param& param, Result& result);
                // throw CallError
            };

            // CONST  CreateStrongKey  3  [PROCEDURE arg:[credentials: [REF Authentication2::Credentials], verifier: [REF Authentication2::Verifier], name: [REF Authentication2::Clearinghouse_Name], key: [REF Authentication2::Key]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]], key: [ARRAY (4)UNSPECIFIED]]] result:[] error:[]]
            struct CreateStrongKey {
                static constexpr const char*   NAME = "CreateStrongKey";
                static constexpr const quint16 CODE = 3;

                struct Param {
                    Credentials        credentials;
                    Verifier           verifier;
                    Clearinghouse_Name name;
                    Key                key;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  ChangeStrongKey  4  [PROCEDURE arg:[credentials: [REF Authentication2::Credentials], verifier: [REF Authentication2::Verifier], newKey: [REF Authentication2::Block]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], newKey: [ARRAY (4)UNSPECIFIED]]] result:[] error:[]]
            struct ChangeStrongKey {
                static constexpr const char*   NAME = "ChangeStrongKey";
                static constexpr const quint16 CODE = 4;

                struct Param {
                    Credentials credentials;
                    Verifier    verifier;
                    Block       newKey;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  DeleteStrongKey  5  [PROCEDURE arg:[credentials: [REF Authentication2::Credentials], verifier: [REF Authentication2::Verifier], name: [REF Authentication2::Clearinghouse_Name]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]]] result:[] error:[]]
            struct DeleteStrongKey {
                static constexpr const char*   NAME = "DeleteStrongKey";
                static constexpr const quint16 CODE = 5;

                struct Param {
                    Credentials        credentials;
                    Verifier           verifier;
                    Clearinghouse_Name name;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  CheckSimpleCredentials  2  [PROCEDURE arg:[credentials: [REF Authentication2::Credentials], verifier: [REF Authentication2::Verifier]] result:[ok: BOOLEAN] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]]] result:[ok: BOOLEAN] error:[]]
            struct CheckSimpleCredentials {
                static constexpr const char*   NAME = "CheckSimpleCredentials";
                static constexpr const quint16 CODE = 2;

                struct Param {
                    Credentials credentials;
                    Verifier    verifier;
                };
                struct Result {
                    BOOLEAN ok;
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  CreateSimpleKey  6  [PROCEDURE arg:[credentials: [REF Authentication2::Credentials], verifier: [REF Authentication2::Verifier], name: [REF Authentication2::Clearinghouse_Name], key: [REF Authentication2::HashedPassword]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]], key: CARDINAL] result:[] error:[]]
            struct CreateSimpleKey {
                static constexpr const char*   NAME = "CreateSimpleKey";
                static constexpr const quint16 CODE = 6;

                struct Param {
                    Credentials        credentials;
                    Verifier           verifier;
                    Clearinghouse_Name name;
                    HashedPassword     key;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  ChangeSimpleKey  7  [PROCEDURE arg:[credentials: [REF Authentication2::Credentials], verifier: [REF Authentication2::Verifier], newKey: [REF Authentication2::HashedPassword]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], newKey: CARDINAL] result:[] error:[]]
            struct ChangeSimpleKey {
                static constexpr const char*   NAME = "ChangeSimpleKey";
                static constexpr const quint16 CODE = 7;

                struct Param {
                    Credentials    credentials;
                    Verifier       verifier;
                    HashedPassword newKey;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  DeleteSimpleKey  8  [PROCEDURE arg:[credentials: [REF Authentication2::Credentials], verifier: [REF Authentication2::Verifier], name: [REF Authentication2::Clearinghouse_Name]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication2::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication2::Organization], domain: [REF Authentication2::Domain], object: [REF Authentication2::Object]]] result:[] error:[]]
            struct DeleteSimpleKey {
                static constexpr const char*   NAME = "DeleteSimpleKey";
                static constexpr const quint16 CODE = 8;

                struct Param {
                    Credentials        credentials;
                    Verifier           verifier;
                    Clearinghouse_Name name;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Authentication2::CredentialsType value);
    QString toString(const Courier::Stub::Authentication2::Problem         value);
    QString toString(const Courier::Stub::Authentication2::CallProblem     value);
    QString toString(const Courier::Stub::Authentication2::Which           value);

    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CredentialsType value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::Problem         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CallProblem     value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::Which           value);

    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CredentialsType& value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::Problem&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CallProblem&     value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::Which&           value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Authentication2::ThreePartName&                  value);
    QString toString(const Courier::Stub::Authentication2::Credentials&                    value);
    QString toString(const Courier::Stub::Authentication2::CredentialsPackage&             value);
    QString toString(const Courier::Stub::Authentication2::StrongCredentials&              value);
    QString toString(const Courier::Stub::Authentication2::StrongVerifier&                 value);
    QString toString(const Courier::Stub::Authentication2::AuthenticationError&            value);
    QString toString(const Courier::Stub::Authentication2::CallError&                      value);
    QString toString(const Courier::Stub::Authentication2::GetStrongCredentials::Param&    value);
    QString toString(const Courier::Stub::Authentication2::GetStrongCredentials::Result&   value);
    QString toString(const Courier::Stub::Authentication2::CreateStrongKey::Param&         value);
    QString toString(const Courier::Stub::Authentication2::CreateStrongKey::Result&        value);
    QString toString(const Courier::Stub::Authentication2::ChangeStrongKey::Param&         value);
    QString toString(const Courier::Stub::Authentication2::ChangeStrongKey::Result&        value);
    QString toString(const Courier::Stub::Authentication2::DeleteStrongKey::Param&         value);
    QString toString(const Courier::Stub::Authentication2::DeleteStrongKey::Result&        value);
    QString toString(const Courier::Stub::Authentication2::CheckSimpleCredentials::Param&  value);
    QString toString(const Courier::Stub::Authentication2::CheckSimpleCredentials::Result& value);
    QString toString(const Courier::Stub::Authentication2::CreateSimpleKey::Param&         value);
    QString toString(const Courier::Stub::Authentication2::CreateSimpleKey::Result&        value);
    QString toString(const Courier::Stub::Authentication2::ChangeSimpleKey::Param&         value);
    QString toString(const Courier::Stub::Authentication2::ChangeSimpleKey::Result&        value);
    QString toString(const Courier::Stub::Authentication2::DeleteSimpleKey::Param&         value);
    QString toString(const Courier::Stub::Authentication2::DeleteSimpleKey::Result&        value);

    void serialize(BLOCK& block, const Courier::Stub::Authentication2::ThreePartName&                  value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::Credentials&                    value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CredentialsPackage&             value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::StrongCredentials&              value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::StrongVerifier&                 value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::AuthenticationError&            value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CallError&                      value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::GetStrongCredentials::Param&    value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::GetStrongCredentials::Result&   value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CreateStrongKey::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CreateStrongKey::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::ChangeStrongKey::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::ChangeStrongKey::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::DeleteStrongKey::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::DeleteStrongKey::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CheckSimpleCredentials::Param&  value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CheckSimpleCredentials::Result& value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CreateSimpleKey::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::CreateSimpleKey::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::ChangeSimpleKey::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::ChangeSimpleKey::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::DeleteSimpleKey::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication2::DeleteSimpleKey::Result&        value);

    void deserialize(BLOCK& block, Courier::Stub::Authentication2::ThreePartName&                  value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::Credentials&                    value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CredentialsPackage&             value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::StrongCredentials&              value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::StrongVerifier&                 value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::AuthenticationError&            value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CallError&                      value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::GetStrongCredentials::Param&    value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::GetStrongCredentials::Result&   value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CreateStrongKey::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CreateStrongKey::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::ChangeStrongKey::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::ChangeStrongKey::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::DeleteStrongKey::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::DeleteStrongKey::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CheckSimpleCredentials::Param&  value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CheckSimpleCredentials::Result& value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CreateSimpleKey::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::CreateSimpleKey::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::ChangeSimpleKey::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::ChangeSimpleKey::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::DeleteSimpleKey::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication2::DeleteSimpleKey::Result&        value);
}
#endif
