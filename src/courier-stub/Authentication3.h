#ifndef STUB_Authentication3_H__
#define STUB_Authentication3_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"
#include "../courier/Service.h"

#include "../stub/Time2.h"

namespace Courier {
    namespace Stub {
        namespace Authentication3 {

            constexpr const char*   PROGRAM_NAME = "Authentication";
            constexpr const quint32 PROGRAM_CODE = 14;
            constexpr const quint32 VERSION_CODE = 3;

            // TYPE  Organization  STRING
            using Organization = STRING;

            // TYPE  Domain  STRING
            using Domain = STRING;

            // TYPE  Object  STRING
            using Object = STRING;

            // TYPE  ThreePartName  RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            struct ThreePartName {
                Organization organization;
                Domain       domain;
                Object       object;
            };

            // TYPE  Clearinghouse_Name  [REF Authentication3::ThreePartName]
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

            // CONST  simpleCredentials  [Const REF simple]  [REF Authentication3::CredentialsType]
            //   ENUM [UNSPECIFIED [[simple  0], [strong  1]]]
            const CredentialsType simpleCredentials = CredentialsType::simple;

            // TYPE  Credentials  RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]]
            //   RECORD [type: ENUM [UNSPECIFIED [[simple  0], [strong  1]]], value: [SEQUENCE (65535)UNSPECIFIED]]]
            struct Credentials {
                CredentialsType         type;
                SEQUENCE_N<UNSPECIFIED> value;
            };

            // TYPE  CredentialsPackage  RECORD [credentials: [REF Authentication3::Credentials], nonce: LONG_CARDINAL, recipient: [REF Authentication3::Clearinghouse_Name], conversationKey: [REF Authentication3::Key]]
            //   RECORD [credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], nonce: LONG_CARDINAL, recipient: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]], conversationKey: [ARRAY (4)UNSPECIFIED]]]
            struct CredentialsPackage {
                Credentials        credentials;
                LONG_CARDINAL      nonce;
                Clearinghouse_Name recipient;
                Key                conversationKey;
            };

            // TYPE  StrongCredentials  RECORD [conversationKey: [REF Authentication3::Key], expirationTime: [REF Time2::Time], initiator: [REF Authentication3::Clearinghouse_Name]]
            //   RECORD [conversationKey: [ARRAY (4)UNSPECIFIED]], expirationTime: LONG_CARDINAL, initiator: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]]]
            struct StrongCredentials {
                Key                conversationKey;
                Time2::Time        expirationTime;
                Clearinghouse_Name initiator;
            };

            // TYPE  SimpleCredentials  [REF Authentication3::Clearinghouse_Name]
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

            // TYPE  SimpleVerifier  [REF Authentication3::HashedPassword]
            //   CARDINAL
            using SimpleVerifier = HashedPassword;

            // TYPE  Proxy  [SEQUENCE (65535)UNSPECIFIED]]
            using Proxy = SEQUENCE_N<UNSPECIFIED>;

            // TYPE  StrongProxy  RECORD [randomBits: [REF Authentication3::Block], expirationTime: [REF Time2::Time], agent: [REF Authentication3::Clearinghouse_Name]]
            //   RECORD [randomBits: [ARRAY (4)UNSPECIFIED]], expirationTime: LONG_CARDINAL, agent: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]]]
            struct StrongProxy {
                Block              randomBits;
                Time2::Time        expirationTime;
                Clearinghouse_Name agent;
            };

            // TYPE  SimpleProxy  BOOLEAN
            using SimpleProxy = BOOLEAN;

            // TYPE  Problem  ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5], [proxyInvalid  6], [proxyExpired  7], [otherProblem  8]]]
            enum class Problem : quint16 {
                credentialsInvalid       = 0,
                verifierInvalid          = 1,
                verifierExpired          = 2,
                verifierReused           = 3,
                credentialsExpired       = 4,
                inappropriateCredentials = 5,
                proxyInvalid             = 6,
                proxyExpired             = 7,
                otherProblem             = 8,
            };

            // CONST  AuthenticationError  2  [ERROR problem: [REF Authentication3::Problem]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5], [proxyInvalid  6], [proxyExpired  7], [otherProblem  8]]]]
            struct AuthenticationError : public Service::Abort {
                AuthenticationError() : Service::Abort(programName, programCode, versionCode, "AuthenticationError", 2), problem() {}

                Problem problem;
            };

            // TYPE  CallProblem  ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [otherCallProblem  12]]]
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
                otherCallProblem           = 12,
            };

            // TYPE  Which  ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [agent  3]]]
            enum class Which : quint16 {
                notApplicable = 0,
                initiator     = 1,
                recipient     = 2,
                agent         = 3,
            };

            // CONST  CallError  1  [ERROR problem: [REF Authentication3::CallProblem], whichArg: [REF Authentication3::Which]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[tooBusy  0], [accessRightsInsufficient  1], [keysUnavailable  2], [strongKeyDoesNotExist  3], [simpleKeyDoesNotExist  4], [strongKeyAlreadyRegistered  5], [simpleKeyAlreadyRegistered  6], [domainForNewKeyUnavailable  7], [domainForNewKeyUnknown  8], [badKey  9], [badName  10], [databaseFull  11], [otherCallProblem  12]]], whichArg: ENUM [UNSPECIFIED [[notApplicable  0], [initiator  1], [recipient  2], [agent  3]]]]
            struct CallError : public Service::Abort {
                CallError() : Service::Abort(programName, programCode, versionCode, "CallError", 1), problem(), whichArg() {}

                CallProblem problem;
                Which       whichArg;
            };

            // CONST  GetStrongCredentials  1  [PROCEDURE arg:[initiator: [REF Authentication3::Clearinghouse_Name], recipient: [REF Authentication3::Clearinghouse_Name], nonce: LONG_CARDINAL] result:[credentialsPackage: [SEQUENCE (65535)UNSPECIFIED]]] error:[CallError]]
            //   [PROCEDURE arg:[initiator: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]], recipient: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]], nonce: LONG_CARDINAL] result:[credentialsPackage: [SEQUENCE (65535)UNSPECIFIED]]] error:[]]
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

            // CONST  TradeProxyForCredentials  9  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier], initiator: [REF Authentication3::Clearinghouse_Name], proxy: [REF Authentication3::Proxy], recipient: [REF Authentication3::Clearinghouse_Name], nonce: LONG_CARDINAL] result:[credentialsPackage: [SEQUENCE (65535)UNSPECIFIED]], proxyForRecipient: [REF Authentication3::Proxy]] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], initiator: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]], proxy: [SEQUENCE (65535)UNSPECIFIED]], recipient: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]], nonce: LONG_CARDINAL] result:[credentialsPackage: [SEQUENCE (65535)UNSPECIFIED]], proxyForRecipient: [SEQUENCE (65535)UNSPECIFIED]]] error:[]]
            struct TradeProxyForCredentials {
                static constexpr const char*   NAME = "TradeProxyForCredentials";
                static constexpr const quint16 CODE = 9;

                struct Param {
                    Credentials        credentials;
                    Verifier           verifier;
                    Clearinghouse_Name initiator;
                    Proxy              proxy;
                    Clearinghouse_Name recipient;
                    LONG_CARDINAL      nonce;
                };
                struct Result {
                    SEQUENCE_N<UNSPECIFIED> credentialsPackage;
                    Proxy                   proxyForRecipient;
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  CreateStrongKey  3  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier], name: [REF Authentication3::Clearinghouse_Name], encryptedKey: [REF Authentication3::Block]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]], encryptedKey: [ARRAY (4)UNSPECIFIED]]] result:[] error:[]]
            struct CreateStrongKey {
                static constexpr const char*   NAME = "CreateStrongKey";
                static constexpr const quint16 CODE = 3;

                struct Param {
                    Credentials        credentials;
                    Verifier           verifier;
                    Clearinghouse_Name name;
                    Block              encryptedKey;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  ChangeStrongKey  4  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier], encryptedNewKey: [REF Authentication3::Block]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], encryptedNewKey: [ARRAY (4)UNSPECIFIED]]] result:[] error:[]]
            struct ChangeStrongKey {
                static constexpr const char*   NAME = "ChangeStrongKey";
                static constexpr const quint16 CODE = 4;

                struct Param {
                    Credentials credentials;
                    Verifier    verifier;
                    Block       encryptedNewKey;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  DeleteStrongKey  5  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier], name: [REF Authentication3::Clearinghouse_Name]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]]] result:[] error:[]]
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

            // CONST  CheckSimpleCredentials  2  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier]] result:[ok: BOOLEAN, initiator: [REF Authentication3::Clearinghouse_Name]] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]]] result:[ok: BOOLEAN, initiator: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]]] error:[]]
            struct CheckSimpleCredentials {
                static constexpr const char*   NAME = "CheckSimpleCredentials";
                static constexpr const quint16 CODE = 2;

                struct Param {
                    Credentials credentials;
                    Verifier    verifier;
                };
                struct Result {
                    BOOLEAN            ok;
                    Clearinghouse_Name initiator;
                };

                using call = void (*)(Param& param, Result& result);
                // throw AuthenticationError, CallError
            };

            // CONST  CreateSimpleKey  6  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier], name: [REF Authentication3::Clearinghouse_Name], key: [REF Authentication3::HashedPassword]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]], key: CARDINAL] result:[] error:[]]
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

            // CONST  ChangeSimpleKey  7  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier], newKey: [REF Authentication3::HashedPassword]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], newKey: CARDINAL] result:[] error:[]]
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

            // CONST  DeleteSimpleKey  8  [PROCEDURE arg:[credentials: [REF Authentication3::Credentials], verifier: [REF Authentication3::Verifier], name: [REF Authentication3::Clearinghouse_Name]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[credentials: RECORD [type: [REF Authentication3::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]], name: RECORD [organization: [REF Authentication3::Organization], domain: [REF Authentication3::Domain], object: [REF Authentication3::Object]]] result:[] error:[]]
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
    QString toString(const Courier::Stub::Authentication3::CredentialsType value);
    QString toString(const Courier::Stub::Authentication3::Problem         value);
    QString toString(const Courier::Stub::Authentication3::CallProblem     value);
    QString toString(const Courier::Stub::Authentication3::Which           value);

    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CredentialsType value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::Problem         value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CallProblem     value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::Which           value);

    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CredentialsType& value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::Problem&         value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CallProblem&     value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::Which&           value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Authentication3::ThreePartName&                    value);
    QString toString(const Courier::Stub::Authentication3::Credentials&                      value);
    QString toString(const Courier::Stub::Authentication3::CredentialsPackage&               value);
    QString toString(const Courier::Stub::Authentication3::StrongCredentials&                value);
    QString toString(const Courier::Stub::Authentication3::StrongVerifier&                   value);
    QString toString(const Courier::Stub::Authentication3::StrongProxy&                      value);
    QString toString(const Courier::Stub::Authentication3::AuthenticationError&              value);
    QString toString(const Courier::Stub::Authentication3::CallError&                        value);
    QString toString(const Courier::Stub::Authentication3::GetStrongCredentials::Param&      value);
    QString toString(const Courier::Stub::Authentication3::GetStrongCredentials::Result&     value);
    QString toString(const Courier::Stub::Authentication3::TradeProxyForCredentials::Param&  value);
    QString toString(const Courier::Stub::Authentication3::TradeProxyForCredentials::Result& value);
    QString toString(const Courier::Stub::Authentication3::CreateStrongKey::Param&           value);
    QString toString(const Courier::Stub::Authentication3::CreateStrongKey::Result&          value);
    QString toString(const Courier::Stub::Authentication3::ChangeStrongKey::Param&           value);
    QString toString(const Courier::Stub::Authentication3::ChangeStrongKey::Result&          value);
    QString toString(const Courier::Stub::Authentication3::DeleteStrongKey::Param&           value);
    QString toString(const Courier::Stub::Authentication3::DeleteStrongKey::Result&          value);
    QString toString(const Courier::Stub::Authentication3::CheckSimpleCredentials::Param&    value);
    QString toString(const Courier::Stub::Authentication3::CheckSimpleCredentials::Result&   value);
    QString toString(const Courier::Stub::Authentication3::CreateSimpleKey::Param&           value);
    QString toString(const Courier::Stub::Authentication3::CreateSimpleKey::Result&          value);
    QString toString(const Courier::Stub::Authentication3::ChangeSimpleKey::Param&           value);
    QString toString(const Courier::Stub::Authentication3::ChangeSimpleKey::Result&          value);
    QString toString(const Courier::Stub::Authentication3::DeleteSimpleKey::Param&           value);
    QString toString(const Courier::Stub::Authentication3::DeleteSimpleKey::Result&          value);

    void serialize(BLOCK& block, const Courier::Stub::Authentication3::ThreePartName&                    value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::Credentials&                      value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CredentialsPackage&               value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::StrongCredentials&                value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::StrongVerifier&                   value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::StrongProxy&                      value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::AuthenticationError&              value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CallError&                        value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::GetStrongCredentials::Param&      value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::GetStrongCredentials::Result&     value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::TradeProxyForCredentials::Param&  value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::TradeProxyForCredentials::Result& value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CreateStrongKey::Param&           value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CreateStrongKey::Result&          value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::ChangeStrongKey::Param&           value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::ChangeStrongKey::Result&          value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::DeleteStrongKey::Param&           value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::DeleteStrongKey::Result&          value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CheckSimpleCredentials::Param&    value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CheckSimpleCredentials::Result&   value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CreateSimpleKey::Param&           value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::CreateSimpleKey::Result&          value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::ChangeSimpleKey::Param&           value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::ChangeSimpleKey::Result&          value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::DeleteSimpleKey::Param&           value);
    void serialize(BLOCK& block, const Courier::Stub::Authentication3::DeleteSimpleKey::Result&          value);

    void deserialize(BLOCK& block, Courier::Stub::Authentication3::ThreePartName&                    value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::Credentials&                      value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CredentialsPackage&               value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::StrongCredentials&                value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::StrongVerifier&                   value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::StrongProxy&                      value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::AuthenticationError&              value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CallError&                        value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::GetStrongCredentials::Param&      value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::GetStrongCredentials::Result&     value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::TradeProxyForCredentials::Param&  value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::TradeProxyForCredentials::Result& value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CreateStrongKey::Param&           value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CreateStrongKey::Result&          value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::ChangeStrongKey::Param&           value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::ChangeStrongKey::Result&          value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::DeleteStrongKey::Param&           value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::DeleteStrongKey::Result&          value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CheckSimpleCredentials::Param&    value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CheckSimpleCredentials::Result&   value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CreateSimpleKey::Param&           value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::CreateSimpleKey::Result&          value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::ChangeSimpleKey::Param&           value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::ChangeSimpleKey::Result&          value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::DeleteSimpleKey::Param&           value);
    void deserialize(BLOCK& block, Courier::Stub::Authentication3::DeleteSimpleKey::Result&          value);
}
#endif
