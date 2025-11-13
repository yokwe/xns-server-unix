#ifndef STUB_Clearinghouse2_H__
#define STUB_Clearinghouse2_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"
#include "../courier/Service.h"

#include "../stub/BulkData1.h"
#include "../stub/Authentication1.h"

namespace Courier {
    namespace Stub {
        namespace Clearinghouse2 {

            constexpr const char*   PROGRAM_NAME = "Clearinghouse";
            constexpr const quint32 PROGRAM_CODE = 2;
            constexpr const quint32 VERSION_CODE = 2;

            // TYPE  Organization  STRING
            using Organization = STRING;

            // TYPE  Domain  STRING
            using Domain = STRING;

            // TYPE  Object  STRING
            using Object = STRING;

            // CONST  maxOrganizationsLength  20  CARDINAL
            const CARDINAL maxOrganizationsLength = 20;

            // CONST  maxDomainLength  20  CARDINAL
            const CARDINAL maxDomainLength = 20;

            // CONST  maxObjectLength  40  CARDINAL
            const CARDINAL maxObjectLength = 40;

            // TYPE  OrganizationName  [REF Clearinghouse2::Organization]
            //   STRING
            using OrganizationName = Organization;

            // TYPE  TwoPartName  RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain]]
            //   RECORD [organization: STRING, domain: STRING]
            struct TwoPartName {
                Organization organization;
                Domain       domain;
            };

            // TYPE  DomainName  [REF Clearinghouse2::TwoPartName]
            //   RECORD [organization: STRING, domain: STRING]
            using DomainName = TwoPartName;

            // TYPE  ThreePartName  RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            struct ThreePartName {
                Organization organization;
                Domain       domain;
                Object       object;
            };

            // TYPE  ObjectName  [REF Clearinghouse2::ThreePartName]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            using ObjectName = ThreePartName;

            // TYPE  Name  [REF Clearinghouse2::ThreePartName]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            using Name = ThreePartName;

            // TYPE  OrganizationNamePattern  [REF Clearinghouse2::Organization]
            //   STRING
            using OrganizationNamePattern = Organization;

            // TYPE  DomainNamePattern  [REF Clearinghouse2::TwoPartName]
            //   RECORD [organization: STRING, domain: STRING]
            using DomainNamePattern = TwoPartName;

            // TYPE  ObjectNamePattern  [REF Clearinghouse2::ThreePartName]
            //   RECORD [organization: STRING, domain: STRING, object: STRING]
            using ObjectNamePattern = ThreePartName;

            // TYPE  StreamOfDomain  [CHOICE [[[[nextSegment  0]] => RECORD [segment: [SEQUENCE (65535)[REF Clearinghouse2::Domain]]], restOfStream: [REF Clearinghouse2::StreamOfDomain]]], [[[lastSegment  1]] => [SEQUENCE (65535)[REF Clearinghouse2::Domain]]]]]]
            // FIXME
            using StreamOfDomain = Courier::StreamOf<Domain>;

            // TYPE  StreamOfDomainName  [CHOICE [[[[nextSegment  0]] => RECORD [segment: [SEQUENCE (65535)[REF Clearinghouse2::DomainName]]], restOfStream: [REF Clearinghouse2::StreamOfDomainName]]], [[[lastSegment  1]] => [SEQUENCE (65535)[REF Clearinghouse2::DomainName]]]]]]
            // FIXME
            using StreamOfDomainName = Courier::StreamOf<DomainName>;

            // TYPE  StreamOfObject  [CHOICE [[[[nextSegment  0]] => RECORD [segment: [SEQUENCE (65535)[REF Clearinghouse2::Object]]], restOfStream: [REF Clearinghouse2::StreamOfObject]]], [[[lastSegment  1]] => [SEQUENCE (65535)[REF Clearinghouse2::Object]]]]]]
            // FIXME
            using StreamOfObject = Courier::StreamOf<Object>;

            // TYPE  StreamOfObjectName  [CHOICE [[[[nextSegment  0]] => RECORD [segment: [SEQUENCE (65535)[REF Clearinghouse2::ObjectName]]], restOfStream: [REF Clearinghouse2::StreamOfObjectName]]], [[[lastSegment  1]] => [SEQUENCE (65535)[REF Clearinghouse2::ObjectName]]]]]]
            // FIXME
            using StreamOfObjectName = Courier::StreamOf<ObjectName>;

            // TYPE  StreamOfOrganization  [CHOICE [[[[nextSegment  0]] => RECORD [segment: [SEQUENCE (65535)[REF Clearinghouse2::Organization]]], restOfStream: [REF Clearinghouse2::StreamOfOrganization]]], [[[lastSegment  1]] => [SEQUENCE (65535)[REF Clearinghouse2::Organization]]]]]]
            // FIXME
            using StreamOfOrganization = Courier::StreamOf<Organization>;

            // TYPE  StreamOfThreePartName  [CHOICE [[[[nextSegment  0]] => RECORD [segment: [SEQUENCE (65535)[REF Clearinghouse2::ThreePartName]]], restOfStream: [REF Clearinghouse2::StreamOfThreePartName]]], [[[lastSegment  1]] => [SEQUENCE (65535)[REF Clearinghouse2::ThreePartName]]]]]]
            // FIXME
            using StreamOfThreePartName = Courier::StreamOf<ThreePartName>;

            // TYPE  Property  LONG_CARDINAL
            using Property = LONG_CARDINAL;

            // TYPE  Properties  [SEQUENCE (250)[REF Clearinghouse2::Property]]]
            //   [SEQUENCE (250)LONG_CARDINAL]]
            using Properties = SEQUENCE_N<Property,250>;

            // CONST  all  0  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Property all = 0;

            // CONST  nullProperty  4294967295  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Property nullProperty = 0xFFFFFFFFU;

            // TYPE  Item  [SEQUENCE (500)UNSPECIFIED]]
            using Item = SEQUENCE_N<UNSPECIFIED,500>;

            // TYPE  NetworkAddress  RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], socket: UNSPECIFIED]
            struct NetworkAddress {
                ARRAY_N<UNSPECIFIED,2> network;
                ARRAY_N<UNSPECIFIED,3> host;
                UNSPECIFIED            socket;
            };

            // TYPE  NetworkAddressList  [SEQUENCE (40)[REF Clearinghouse2::NetworkAddress]]]
            //   [SEQUENCE (40)RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], socket: UNSPECIFIED]]]
            using NetworkAddressList = SEQUENCE_N<NetworkAddress,40>;

            // TYPE  Authenticator  RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]
            //   RECORD [credentials: RECORD [type: [REF Authentication1::CredentialsType], value: [SEQUENCE (65535)UNSPECIFIED]]], verifier: [SEQUENCE (12)UNSPECIFIED]]]
            struct Authenticator {
                Authentication1::Credentials credentials;
                Authentication1::Verifier    verifier;
            };

            // CONST  wildcard  ""*""  STRING
            const STRING wildcard = "*";

            // TYPE  WhichArgument  ENUM [UNSPECIFIED [[first  1], [second  2]]]
            enum class WhichArgument : quint16 {
                first  = 1,
                second = 2,
            };

            // TYPE  ArgumentProblem  ENUM [UNSPECIFIED [[illegalProperty  10], [illegalOrganizationName  11], [illegalDomainName  12], [illegalObjectName  13], [noSuchOrganization  14], [noSuchDomain  15], [noSuchObject  16]]]
            enum class ArgumentProblem : quint16 {
                illegalProperty         = 10,
                illegalOrganizationName = 11,
                illegalDomainName       = 12,
                illegalObjectName       = 13,
                noSuchOrganization      = 14,
                noSuchDomain            = 15,
                noSuchObject            = 16,
            };

            // CONST  ArgumentError  2  [ERROR problem: [REF Clearinghouse2::ArgumentProblem], which: [REF Clearinghouse2::WhichArgument]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[illegalProperty  10], [illegalOrganizationName  11], [illegalDomainName  12], [illegalObjectName  13], [noSuchOrganization  14], [noSuchDomain  15], [noSuchObject  16]]], which: ENUM [UNSPECIFIED [[first  1], [second  2]]]]
            struct ArgumentError : public Service::Abort {
                ArgumentError() : Service::Abort(programName, programCode, versionCode, "ArgumentError", 2), problem(), which() {}

                ArgumentProblem problem;
                WhichArgument   which;
            };

            // CONST  AuthenticationError  6  [ERROR problem: [REF Authentication1::Problem]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[credentialsInvalid  0], [verifierInvalid  1], [verifierExpired  2], [verifierReused  3], [credentialsExpired  4], [inappropriateCredentials  5]]]]
            struct AuthenticationError : public Service::Abort {
                AuthenticationError() : Service::Abort(programName, programCode, versionCode, "AuthenticationError", 6), problem() {}

                Authentication1::Problem problem;
            };

            // TYPE  CallProblem  ENUM [UNSPECIFIED [[accessRightsInsufficient  1], [tooBusy  2], [serverDown  3], [useCourier  4], [other  5]]]
            enum class CallProblem : quint16 {
                accessRightsInsufficient = 1,
                tooBusy                  = 2,
                serverDown               = 3,
                useCourier               = 4,
                other                    = 5,
            };

            // CONST  CallError  1  [ERROR problem: [REF Clearinghouse2::CallProblem]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[accessRightsInsufficient  1], [tooBusy  2], [serverDown  3], [useCourier  4], [other  5]]]]
            struct CallError : public Service::Abort {
                CallError() : Service::Abort(programName, programCode, versionCode, "CallError", 1), problem() {}

                CallProblem problem;
            };

            // TYPE  PropertyProblem  ENUM [UNSPECIFIED [[missing  20], [wrongType  21]]]
            enum class PropertyProblem : quint16 {
                missing   = 20,
                wrongType = 21,
            };

            // CONST  PropertyError  3  [ERROR problem: [REF Clearinghouse2::PropertyProblem], distinguishedObject: [REF Clearinghouse2::ObjectName]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[missing  20], [wrongType  21]]], distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]]
            struct PropertyError : public Service::Abort {
                PropertyError() : Service::Abort(programName, programCode, versionCode, "PropertyError", 3), problem(), distinguishedObject() {}

                PropertyProblem problem;
                ObjectName      distinguishedObject;
            };

            // TYPE  UpdateProblem  ENUM [UNSPECIFIED [[noChange  30], [outOfDate  31], [objectOverflow  32], [databaseOverflow  33]]]
            enum class UpdateProblem : quint16 {
                noChange         = 30,
                outOfDate        = 31,
                objectOverflow   = 32,
                databaseOverflow = 33,
            };

            // CONST  UpdateError  4  [ERROR problem: [REF Clearinghouse2::UpdateProblem], found: BOOLEAN, which: [REF Clearinghouse2::WhichArgument], distinguishedObject: [REF Clearinghouse2::ObjectName]]
            //   [ERROR problem: ENUM [UNSPECIFIED [[noChange  30], [outOfDate  31], [objectOverflow  32], [databaseOverflow  33]]], found: BOOLEAN, which: ENUM [UNSPECIFIED [[first  1], [second  2]]], distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]]
            struct UpdateError : public Service::Abort {
                UpdateError() : Service::Abort(programName, programCode, versionCode, "UpdateError", 4), problem(), found(), which(), distinguishedObject() {}

                UpdateProblem problem;
                BOOLEAN       found;
                WhichArgument which;
                ObjectName    distinguishedObject;
            };

            // CONST  WrongServer  5  [ERROR hint: [REF Clearinghouse2::ObjectName]]
            //   [ERROR hint: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]]
            struct WrongServer : public Service::Abort {
                WrongServer() : Service::Abort(programName, programCode, versionCode, "WrongServer", 5), hint() {}

                ObjectName hint;
            };

            // CONST  CreateObject  2  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], agent: [REF Clearinghouse2::Authenticator]] result:[] error:[ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[] error:[]]
            struct CreateObject {
                static constexpr const char*   NAME = "CreateObject";
                static constexpr const quint16 CODE = 2;

                struct Param {
                    ObjectName    name;
                    Authenticator agent;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer
            };

            // CONST  DeleteObject  3  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], agent: [REF Clearinghouse2::Authenticator]] result:[] error:[ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[] error:[]]
            struct DeleteObject {
                static constexpr const char*   NAME = "DeleteObject";
                static constexpr const quint16 CODE = 3;

                struct Param {
                    ObjectName    name;
                    Authenticator agent;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer
            };

            // CONST  LookupObject  4  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectNamePattern], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct LookupObject {
                static constexpr const char*   NAME = "LookupObject";
                static constexpr const quint16 CODE = 4;

                struct Param {
                    ObjectNamePattern name;
                    Authenticator     agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, WrongServer
            };

            // CONST  ListOrganizations  5  [PROCEDURE arg:[pattern: [REF Clearinghouse2::OrganizationNamePattern], list: [REF BulkData1::Sink], agent: [REF Clearinghouse2::Authenticator]] result:[] error:[ArgumentError, AuthenticationError, CallError, WrongServer]]
            //   [PROCEDURE arg:[pattern: STRING, list: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[] error:[]]
            struct ListOrganizations {
                static constexpr const char*   NAME = "ListOrganizations";
                static constexpr const quint16 CODE = 5;

                struct Param {
                    OrganizationNamePattern pattern;
                    BulkData1::Sink         list;
                    Authenticator           agent;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, WrongServer
            };

            // CONST  ListDomain  6  [PROCEDURE arg:[pattern: [REF Clearinghouse2::DomainNamePattern], list: [REF BulkData1::Sink], agent: [REF Clearinghouse2::Authenticator]] result:[] error:[ArgumentError, AuthenticationError, CallError, WrongServer]]
            //   [PROCEDURE arg:[pattern: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain]], list: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[] error:[]]
            struct ListDomain {
                static constexpr const char*   NAME = "ListDomain";
                static constexpr const quint16 CODE = 6;

                struct Param {
                    DomainNamePattern pattern;
                    BulkData1::Sink   list;
                    Authenticator     agent;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, WrongServer
            };

            // CONST  ListObjects  7  [PROCEDURE arg:[pattern: [REF Clearinghouse2::ObjectNamePattern], property: [REF Clearinghouse2::Property], list: [REF BulkData1::Sink], agent: [REF Clearinghouse2::Authenticator]] result:[] error:[ArgumentError, AuthenticationError, CallError, WrongServer]]
            //   [PROCEDURE arg:[pattern: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, list: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[] error:[]]
            struct ListObjects {
                static constexpr const char*   NAME = "ListObjects";
                static constexpr const quint16 CODE = 7;

                struct Param {
                    ObjectNamePattern pattern;
                    Property          property;
                    BulkData1::Sink   list;
                    Authenticator     agent;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, WrongServer
            };

            // CONST  ListAliasesOf  9  [PROCEDURE arg:[pattern: [REF Clearinghouse2::ObjectNamePattern], list: [REF BulkData1::Sink], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, WrongServer]]
            //   [PROCEDURE arg:[pattern: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], list: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct ListAliasesOf {
                static constexpr const char*   NAME = "ListAliasesOf";
                static constexpr const quint16 CODE = 9;

                struct Param {
                    ObjectNamePattern pattern;
                    BulkData1::Sink   list;
                    Authenticator     agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, WrongServer
            };

            // CONST  CreateAlias  10  [PROCEDURE arg:[alias: [REF Clearinghouse2::ObjectName], sameAs: [REF Clearinghouse2::ObjectName], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[alias: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], sameAs: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct CreateAlias {
                static constexpr const char*   NAME = "CreateAlias";
                static constexpr const quint16 CODE = 10;

                struct Param {
                    ObjectName    alias;
                    ObjectName    sameAs;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer
            };

            // CONST  DeleteAlias  11  [PROCEDURE arg:[alias: [REF Clearinghouse2::ObjectName], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[alias: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct DeleteAlias {
                static constexpr const char*   NAME = "DeleteAlias";
                static constexpr const quint16 CODE = 11;

                struct Param {
                    ObjectName    alias;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, UpdateError, WrongServer
            };

            // CONST  ListAliases  8  [PROCEDURE arg:[pattern: [REF Clearinghouse2::ObjectNamePattern], list: [REF BulkData1::Sink], agent: [REF Clearinghouse2::Authenticator]] result:[] error:[ArgumentError, AuthenticationError, CallError, WrongServer]]
            //   [PROCEDURE arg:[pattern: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], list: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[] error:[]]
            struct ListAliases {
                static constexpr const char*   NAME = "ListAliases";
                static constexpr const quint16 CODE = 8;

                struct Param {
                    ObjectNamePattern pattern;
                    BulkData1::Sink   list;
                    Authenticator     agent;
                };
                struct Result {
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, WrongServer
            };

            // CONST  DeleteProperty  14  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], property: [REF Clearinghouse2::Property], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct DeleteProperty {
                static constexpr const char*   NAME = "DeleteProperty";
                static constexpr const quint16 CODE = 14;

                struct Param {
                    ObjectName    name;
                    Property      property;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  ListProperties  15  [PROCEDURE arg:[pattern: [REF Clearinghouse2::ObjectNamePattern], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName], properties: [REF Clearinghouse2::Properties]] error:[ArgumentError, AuthenticationError, CallError, WrongServer]]
            //   [PROCEDURE arg:[pattern: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], properties: [SEQUENCE (250)[REF Clearinghouse2::Property]]]] error:[]]
            struct ListProperties {
                static constexpr const char*   NAME = "ListProperties";
                static constexpr const quint16 CODE = 15;

                struct Param {
                    ObjectNamePattern pattern;
                    Authenticator     agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                    Properties properties;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, WrongServer
            };

            // CONST  AddItemProperty  13  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], newProperty: [REF Clearinghouse2::Property], value: [REF Clearinghouse2::Item], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], newProperty: LONG_CARDINAL, value: [SEQUENCE (500)UNSPECIFIED]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct AddItemProperty {
                static constexpr const char*   NAME = "AddItemProperty";
                static constexpr const quint16 CODE = 13;

                struct Param {
                    ObjectName    name;
                    Property      newProperty;
                    Item          value;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  RetrieveItem  16  [PROCEDURE arg:[pattern: [REF Clearinghouse2::ObjectNamePattern], property: [REF Clearinghouse2::Property], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName], value: [REF Clearinghouse2::Item]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, WrongServer]]
            //   [PROCEDURE arg:[pattern: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], value: [SEQUENCE (500)UNSPECIFIED]]] error:[]]
            struct RetrieveItem {
                static constexpr const char*   NAME = "RetrieveItem";
                static constexpr const quint16 CODE = 16;

                struct Param {
                    ObjectNamePattern pattern;
                    Property          property;
                    Authenticator     agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                    Item       value;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, WrongServer
            };

            // CONST  ChangeItem  17  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], property: [REF Clearinghouse2::Property], newValue: [REF Clearinghouse2::Item], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, newValue: [SEQUENCE (500)UNSPECIFIED]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct ChangeItem {
                static constexpr const char*   NAME = "ChangeItem";
                static constexpr const quint16 CODE = 17;

                struct Param {
                    ObjectName    name;
                    Property      property;
                    Item          newValue;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  AddGroupProperty  12  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], newProperty: [REF Clearinghouse2::Property], membership: [REF BulkData1::Source], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], newProperty: LONG_CARDINAL, membership: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct AddGroupProperty {
                static constexpr const char*   NAME = "AddGroupProperty";
                static constexpr const quint16 CODE = 12;

                struct Param {
                    ObjectName        name;
                    Property          newProperty;
                    BulkData1::Source membership;
                    Authenticator     agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  RetrieveMembers  18  [PROCEDURE arg:[pattern: [REF Clearinghouse2::ObjectNamePattern], property: [REF Clearinghouse2::Property], membership: [REF BulkData1::Sink], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, WrongServer]]
            //   [PROCEDURE arg:[pattern: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, membership: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct RetrieveMembers {
                static constexpr const char*   NAME = "RetrieveMembers";
                static constexpr const quint16 CODE = 18;

                struct Param {
                    ObjectNamePattern pattern;
                    Property          property;
                    BulkData1::Sink   membership;
                    Authenticator     agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, WrongServer
            };

            // CONST  AddMember  19  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], property: [REF Clearinghouse2::Property], newMember: [REF Clearinghouse2::ThreePartName], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, newMember: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct AddMember {
                static constexpr const char*   NAME = "AddMember";
                static constexpr const quint16 CODE = 19;

                struct Param {
                    ObjectName    name;
                    Property      property;
                    ThreePartName newMember;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  AddSelf  20  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], property: [REF Clearinghouse2::Property], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct AddSelf {
                static constexpr const char*   NAME = "AddSelf";
                static constexpr const quint16 CODE = 20;

                struct Param {
                    ObjectName    name;
                    Property      property;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  DeleteMember  21  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], property: [REF Clearinghouse2::Property], member: [REF Clearinghouse2::ThreePartName], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, member: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct DeleteMember {
                static constexpr const char*   NAME = "DeleteMember";
                static constexpr const quint16 CODE = 21;

                struct Param {
                    ObjectName    name;
                    Property      property;
                    ThreePartName member;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  DeleteSelf  22  [PROCEDURE arg:[name: [REF Clearinghouse2::ObjectName], property: [REF Clearinghouse2::Property], agent: [REF Clearinghouse2::Authenticator]] result:[distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer]]
            //   [PROCEDURE arg:[name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct DeleteSelf {
                static constexpr const char*   NAME = "DeleteSelf";
                static constexpr const quint16 CODE = 22;

                struct Param {
                    ObjectName    name;
                    Property      property;
                    Authenticator agent;
                };
                struct Result {
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, UpdateError, WrongServer
            };

            // CONST  IsMember  23  [PROCEDURE arg:[memberOf: [REF Clearinghouse2::ObjectNamePattern], property: [REF Clearinghouse2::Property], secondaryProperty: [REF Clearinghouse2::Property], name: [REF Clearinghouse2::ThreePartName], agent: [REF Clearinghouse2::Authenticator]] result:[isMember: BOOLEAN, distinguishedObject: [REF Clearinghouse2::ObjectName]] error:[ArgumentError, AuthenticationError, CallError, PropertyError, WrongServer]]
            //   [PROCEDURE arg:[memberOf: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], property: LONG_CARDINAL, secondaryProperty: LONG_CARDINAL, name: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[isMember: BOOLEAN, distinguishedObject: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]] error:[]]
            struct IsMember {
                static constexpr const char*   NAME = "IsMember";
                static constexpr const quint16 CODE = 23;

                struct Param {
                    ObjectNamePattern memberOf;
                    Property          property;
                    Property          secondaryProperty;
                    ThreePartName     name;
                    Authenticator     agent;
                };
                struct Result {
                    BOOLEAN    isMember;
                    ObjectName distinguishedObject;
                };

                using call = void (*)(Param& param, Result& result);
                // throw ArgumentError, AuthenticationError, CallError, PropertyError, WrongServer
            };

            // CONST  RetrieveAddresses  0  [PROCEDURE arg:[] result:[address: [REF Clearinghouse2::NetworkAddressList]] error:[CallError]]
            //   [PROCEDURE arg:[] result:[address: [SEQUENCE (40)[REF Clearinghouse2::NetworkAddress]]]] error:[]]
            struct RetrieveAddresses {
                static constexpr const char*   NAME = "RetrieveAddresses";
                static constexpr const quint16 CODE = 0;

                struct Param {
                };
                struct Result {
                    NetworkAddressList address;
                };

                using call = void (*)(Param& param, Result& result);
                // throw CallError
            };

            // CONST  ListDomainServed  1  [PROCEDURE arg:[domains: [REF BulkData1::Sink], agent: [REF Clearinghouse2::Authenticator]] result:[] error:[AuthenticationError, CallError]]
            //   [PROCEDURE arg:[domains: [CHOICE [[[[null  0], [immediate  1]] => RECORD []], [[[passive  2], [active  3]] => RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], identifier: [REF BulkData1::Identifier]]]]], agent: RECORD [credentials: [REF Authentication1::Credentials], verifier: [REF Authentication1::Verifier]]] result:[] error:[]]
            struct ListDomainServed {
                static constexpr const char*   NAME = "ListDomainServed";
                static constexpr const quint16 CODE = 1;

                struct Param {
                    BulkData1::Sink domains;
                    Authenticator   agent;
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
    QString toString(const Courier::Stub::Clearinghouse2::WhichArgument   value);
    QString toString(const Courier::Stub::Clearinghouse2::ArgumentProblem value);
    QString toString(const Courier::Stub::Clearinghouse2::CallProblem     value);
    QString toString(const Courier::Stub::Clearinghouse2::PropertyProblem value);
    QString toString(const Courier::Stub::Clearinghouse2::UpdateProblem   value);

    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::WhichArgument   value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ArgumentProblem value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::CallProblem     value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::PropertyProblem value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::UpdateProblem   value);

    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::WhichArgument&   value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ArgumentProblem& value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::CallProblem&     value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::PropertyProblem& value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::UpdateProblem&   value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Clearinghouse2::TwoPartName&               value);
    QString toString(const Courier::Stub::Clearinghouse2::ThreePartName&             value);
    QString toString(const Courier::Stub::Clearinghouse2::NetworkAddress&            value);
    QString toString(const Courier::Stub::Clearinghouse2::Authenticator&             value);
    QString toString(const Courier::Stub::Clearinghouse2::ArgumentError&             value);
    QString toString(const Courier::Stub::Clearinghouse2::AuthenticationError&       value);
    QString toString(const Courier::Stub::Clearinghouse2::CallError&                 value);
    QString toString(const Courier::Stub::Clearinghouse2::PropertyError&             value);
    QString toString(const Courier::Stub::Clearinghouse2::UpdateError&               value);
    QString toString(const Courier::Stub::Clearinghouse2::WrongServer&               value);
    QString toString(const Courier::Stub::Clearinghouse2::CreateObject::Param&       value);
    QString toString(const Courier::Stub::Clearinghouse2::CreateObject::Result&      value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteObject::Param&       value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteObject::Result&      value);
    QString toString(const Courier::Stub::Clearinghouse2::LookupObject::Param&       value);
    QString toString(const Courier::Stub::Clearinghouse2::LookupObject::Result&      value);
    QString toString(const Courier::Stub::Clearinghouse2::ListOrganizations::Param&  value);
    QString toString(const Courier::Stub::Clearinghouse2::ListOrganizations::Result& value);
    QString toString(const Courier::Stub::Clearinghouse2::ListDomain::Param&         value);
    QString toString(const Courier::Stub::Clearinghouse2::ListDomain::Result&        value);
    QString toString(const Courier::Stub::Clearinghouse2::ListObjects::Param&        value);
    QString toString(const Courier::Stub::Clearinghouse2::ListObjects::Result&       value);
    QString toString(const Courier::Stub::Clearinghouse2::ListAliasesOf::Param&      value);
    QString toString(const Courier::Stub::Clearinghouse2::ListAliasesOf::Result&     value);
    QString toString(const Courier::Stub::Clearinghouse2::CreateAlias::Param&        value);
    QString toString(const Courier::Stub::Clearinghouse2::CreateAlias::Result&       value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteAlias::Param&        value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteAlias::Result&       value);
    QString toString(const Courier::Stub::Clearinghouse2::ListAliases::Param&        value);
    QString toString(const Courier::Stub::Clearinghouse2::ListAliases::Result&       value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteProperty::Param&     value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteProperty::Result&    value);
    QString toString(const Courier::Stub::Clearinghouse2::ListProperties::Param&     value);
    QString toString(const Courier::Stub::Clearinghouse2::ListProperties::Result&    value);
    QString toString(const Courier::Stub::Clearinghouse2::AddItemProperty::Param&    value);
    QString toString(const Courier::Stub::Clearinghouse2::AddItemProperty::Result&   value);
    QString toString(const Courier::Stub::Clearinghouse2::RetrieveItem::Param&       value);
    QString toString(const Courier::Stub::Clearinghouse2::RetrieveItem::Result&      value);
    QString toString(const Courier::Stub::Clearinghouse2::ChangeItem::Param&         value);
    QString toString(const Courier::Stub::Clearinghouse2::ChangeItem::Result&        value);
    QString toString(const Courier::Stub::Clearinghouse2::AddGroupProperty::Param&   value);
    QString toString(const Courier::Stub::Clearinghouse2::AddGroupProperty::Result&  value);
    QString toString(const Courier::Stub::Clearinghouse2::RetrieveMembers::Param&    value);
    QString toString(const Courier::Stub::Clearinghouse2::RetrieveMembers::Result&   value);
    QString toString(const Courier::Stub::Clearinghouse2::AddMember::Param&          value);
    QString toString(const Courier::Stub::Clearinghouse2::AddMember::Result&         value);
    QString toString(const Courier::Stub::Clearinghouse2::AddSelf::Param&            value);
    QString toString(const Courier::Stub::Clearinghouse2::AddSelf::Result&           value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteMember::Param&       value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteMember::Result&      value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteSelf::Param&         value);
    QString toString(const Courier::Stub::Clearinghouse2::DeleteSelf::Result&        value);
    QString toString(const Courier::Stub::Clearinghouse2::IsMember::Param&           value);
    QString toString(const Courier::Stub::Clearinghouse2::IsMember::Result&          value);
    QString toString(const Courier::Stub::Clearinghouse2::RetrieveAddresses::Param&  value);
    QString toString(const Courier::Stub::Clearinghouse2::RetrieveAddresses::Result& value);
    QString toString(const Courier::Stub::Clearinghouse2::ListDomainServed::Param&   value);
    QString toString(const Courier::Stub::Clearinghouse2::ListDomainServed::Result&  value);

    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::TwoPartName&               value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ThreePartName&             value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::NetworkAddress&            value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::Authenticator&             value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ArgumentError&             value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AuthenticationError&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::CallError&                 value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::PropertyError&             value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::UpdateError&               value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::WrongServer&               value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::CreateObject::Param&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::CreateObject::Result&      value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteObject::Param&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteObject::Result&      value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::LookupObject::Param&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::LookupObject::Result&      value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListOrganizations::Param&  value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListOrganizations::Result& value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListDomain::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListDomain::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListObjects::Param&        value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListObjects::Result&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListAliasesOf::Param&      value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListAliasesOf::Result&     value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::CreateAlias::Param&        value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::CreateAlias::Result&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteAlias::Param&        value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteAlias::Result&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListAliases::Param&        value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListAliases::Result&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteProperty::Param&     value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteProperty::Result&    value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListProperties::Param&     value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListProperties::Result&    value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddItemProperty::Param&    value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddItemProperty::Result&   value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::RetrieveItem::Param&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::RetrieveItem::Result&      value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ChangeItem::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ChangeItem::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddGroupProperty::Param&   value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddGroupProperty::Result&  value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::RetrieveMembers::Param&    value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::RetrieveMembers::Result&   value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddMember::Param&          value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddMember::Result&         value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddSelf::Param&            value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::AddSelf::Result&           value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteMember::Param&       value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteMember::Result&      value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteSelf::Param&         value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::DeleteSelf::Result&        value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::IsMember::Param&           value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::IsMember::Result&          value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::RetrieveAddresses::Param&  value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::RetrieveAddresses::Result& value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListDomainServed::Param&   value);
    void serialize(BLOCK& block, const Courier::Stub::Clearinghouse2::ListDomainServed::Result&  value);

    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::TwoPartName&               value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ThreePartName&             value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::NetworkAddress&            value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::Authenticator&             value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ArgumentError&             value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AuthenticationError&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::CallError&                 value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::PropertyError&             value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::UpdateError&               value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::WrongServer&               value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::CreateObject::Param&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::CreateObject::Result&      value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteObject::Param&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteObject::Result&      value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::LookupObject::Param&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::LookupObject::Result&      value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListOrganizations::Param&  value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListOrganizations::Result& value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListDomain::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListDomain::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListObjects::Param&        value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListObjects::Result&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListAliasesOf::Param&      value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListAliasesOf::Result&     value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::CreateAlias::Param&        value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::CreateAlias::Result&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteAlias::Param&        value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteAlias::Result&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListAliases::Param&        value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListAliases::Result&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteProperty::Param&     value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteProperty::Result&    value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListProperties::Param&     value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListProperties::Result&    value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddItemProperty::Param&    value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddItemProperty::Result&   value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::RetrieveItem::Param&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::RetrieveItem::Result&      value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ChangeItem::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ChangeItem::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddGroupProperty::Param&   value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddGroupProperty::Result&  value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::RetrieveMembers::Param&    value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::RetrieveMembers::Result&   value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddMember::Param&          value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddMember::Result&         value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddSelf::Param&            value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::AddSelf::Result&           value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteMember::Param&       value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteMember::Result&      value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteSelf::Param&         value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::DeleteSelf::Result&        value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::IsMember::Param&           value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::IsMember::Result&          value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::RetrieveAddresses::Param&  value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::RetrieveAddresses::Result& value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListDomainServed::Param&   value);
    void deserialize(BLOCK& block, Courier::Stub::Clearinghouse2::ListDomainServed::Result&  value);
}
#endif
