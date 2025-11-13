#ifndef STUB_CHEntries_H__
#define STUB_CHEntries_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

#include "../stub/Clearinghouse2.h"
#include "../stub/Time2.h"

namespace Courier {
    namespace Stub {
        namespace CHEntries {

            // CONST  members  3  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property members = 3;

            // CONST  addressList  4  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property addressList = 4;

            // CONST  mailboxes  31  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property mailboxes = 31;

            // CONST  authenticationLevel  8  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property authenticationLevel = 8;

            // CONST  fileService  10000  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property fileService = 10000;

            // CONST  printService  10001  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property printService = 10001;

            // CONST  user  10003  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property user = 10003;

            // CONST  mailService  10004  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property mailService = 10004;

            // CONST  clearinghouseService  10021  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property clearinghouseService = 10021;

            // CONST  userGroup  10022  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property userGroup = 10022;

            // CONST  userData  20000  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property userData = 20000;

            // TYPE  Description  STRING
            using Description = STRING;

            // TYPE  AddressListValue  [REF Clearinghouse2::NetworkAddressList]
            //   [SEQUENCE (40)RECORD [network: [ARRAY (2)UNSPECIFIED]], host: [ARRAY (3)UNSPECIFIED]], socket: UNSPECIFIED]]]
            using AddressListValue = Clearinghouse2::NetworkAddressList;

            // TYPE  MailboxesValue  RECORD [time: [REF Time2::Time], mailService: [SEQUENCE (65535)[REF Clearinghouse2::Name]]]]
            //   RECORD [time: LONG_CARDINAL, mailService: [SEQUENCE (65535)[REF Clearinghouse2::Name]]]]
            struct MailboxesValue {
                Time2::Time                      time;
                SEQUENCE_N<Clearinghouse2::Name> mailService;
            };

            // TYPE  AuthenticationLevelValue  RECORD [simpleSupported: BOOLEAN, strongSupported: BOOLEAN]
            struct AuthenticationLevelValue {
                BOOLEAN simpleSupported;
                BOOLEAN strongSupported;
            };

            // TYPE  UserDataValue  RECORD [lastNameIndex: CARDINAL, fileService: [REF Clearinghouse2::Name]]
            //   RECORD [lastNameIndex: CARDINAL, fileService: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]]]
            struct UserDataValue {
                CARDINAL             lastNameIndex;
                Clearinghouse2::Name fileService;
            };

            // CONST  authKeys  6  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property authKeys = 6;

            // CONST  services  51  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property services = 51;

            // CONST  internetworkRoutingService  10002  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property internetworkRoutingService = 10002;

            // CONST  workstation  10005  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property workstation = 10005;

            // CONST  externalCommunicationsService  10006  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property externalCommunicationsService = 10006;

            // CONST  rs232CPort  10007  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property rs232CPort = 10007;

            // CONST  interactiveTerminalService  10008  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property interactiveTerminalService = 10008;

            // CONST  gatewayService  10009  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property gatewayService = 10009;

            // CONST  ibm3270Host  10010  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property ibm3270Host = 10010;

            // CONST  mailGateway  10011  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property mailGateway = 10011;

            // CONST  siemens9750Host  10012  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property siemens9750Host = 10012;

            // CONST  adobeService  10013  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property adobeService = 10013;

            // CONST  librarianService  10014  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property librarianService = 10014;

            // CONST  ttxGateway  10015  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property ttxGateway = 10015;

            // CONST  authenticationService  10016  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property authenticationService = 10016;

            // CONST  remoteBatchService  10017  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property remoteBatchService = 10017;

            // CONST  network  10018  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property network = 10018;

            // CONST  networkServers  10019  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property networkServers = 10019;

            // CONST  communicationsInterfaceUnit  10020  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property communicationsInterfaceUnit = 10020;

            // CONST  fetchService  10023  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property fetchService = 10023;

            // CONST  rs232CData  20001  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property rs232CData = 20001;

            // CONST  ibm3270HostData  20002  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property ibm3270HostData = 20002;

            // CONST  siemens9750HostData  20003  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property siemens9750HostData = 20003;

            // CONST  canMailTo  20005  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property canMailTo = 20005;

            // CONST  mailGatewayRouteData  20006  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property mailGatewayRouteData = 20006;

            // CONST  foreignMailSystemName  20007  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property foreignMailSystemName = 20007;

            // CONST  userPassword  20101  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property userPassword = 20101;

            // CONST  rs232CBack  20102  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property rs232CBack = 20102;

            // CONST  ibm3270HostBack  20103  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property ibm3270HostBack = 20103;

            // CONST  associatedWorkstation  30005  [REF Clearinghouse2::Property]
            //   LONG_CARDINAL
            const Clearinghouse2::Property associatedWorkstation = 30005;

            // TYPE  Duplexity  CARDINAL
            using Duplexity = CARDINAL;

            // TYPE  CharLength  CARDINAL
            using CharLength = CARDINAL;

            // TYPE  FlowControl  CARDINAL
            using FlowControl = CARDINAL;

            // TYPE  LineSpeed  CARDINAL
            using LineSpeed = CARDINAL;

            // TYPE  Parity  CARDINAL
            using Parity = CARDINAL;

            // TYPE  StopBits  CARDINAL
            using StopBits = CARDINAL;

            // TYPE  PortClientType  ENUM [UNSPECIFIED [[unassigned  0], [outOfService  1], [its  2], [irs  3], [gws  4], [ibm3270Host  5], [ttyEmulation  6], [rbs  7], [fax  9], [mailGateway  10], [phototypesetter  11]]]
            enum class PortClientType : quint16 {
                unassigned      =  0,
                outOfService    =  1,
                its             =  2,
                irs             =  3,
                gws             =  4,
                ibm3270Host     =  5,
                ttyEmulation    =  6,
                rbs             =  7,
                fax             =  9,
                mailGateway     = 10,
                phototypesetter = 11,
            };

            // TYPE  PortDialerType  ENUM [UNSPECIFIED [[dialerNone  0], [vadic  1], [hayes  2], [ventel  3], [rs366  4]]]
            enum class PortDialerType : quint16 {
                dialerNone = 0,
                vadic      = 1,
                hayes      = 2,
                ventel     = 3,
                rs366      = 4,
            };

            // TYPE  PortSyncType  ENUM [UNSPECIFIED [[asynchronous  0], [synchronous  1], [bitSynchronous  2], [byteSynchronous  3], [syncAny  4]]]
            enum class PortSyncType : quint16 {
                asynchronous    = 0,
                synchronous     = 1,
                bitSynchronous  = 2,
                byteSynchronous = 3,
                syncAny         = 4,
            };

            // TYPE  PortEchoingLocation  ENUM [UNSPECIFIED [[echoLocal  0], [echoRemote  1]]]
            enum class PortEchoingLocation : quint16 {
                echoLocal  = 0,
                echoRemote = 1,
            };

            // TYPE  RS232CData  RECORD [cIUPort: BOOLEAN, owningClientType: [REF CHEntries::PortClientType], preemptionAllowed: BOOLEAN, lineNumber: CARDINAL, dialerNumber: CARDINAL, duplexity: [REF CHEntries::Duplexity], dialingHardware: [REF CHEntries::PortDialerType], charLength: [REF CHEntries::CharLength], echoing: [REF CHEntries::PortEchoingLocation], xxxxpaddingxxx: LONG_CARDINAL, flowControl: [REF CHEntries::FlowControl], lineSpeed: [REF CHEntries::LineSpeed], parity: [REF CHEntries::Parity], stopBits: [REF CHEntries::StopBits], portActsAsDCE: BOOLEAN, accessControl: [REF Clearinghouse2::Name], validLineSpeeds: [SEQUENCE (65535)[REF CHEntries::LineSpeed]]]]
            //   RECORD [cIUPort: BOOLEAN, owningClientType: ENUM [UNSPECIFIED [[unassigned  0], [outOfService  1], [its  2], [irs  3], [gws  4], [ibm3270Host  5], [ttyEmulation  6], [rbs  7], [fax  9], [mailGateway  10], [phototypesetter  11]]], preemptionAllowed: BOOLEAN, lineNumber: CARDINAL, dialerNumber: CARDINAL, duplexity: CARDINAL, dialingHardware: ENUM [UNSPECIFIED [[dialerNone  0], [vadic  1], [hayes  2], [ventel  3], [rs366  4]]], charLength: CARDINAL, echoing: ENUM [UNSPECIFIED [[echoLocal  0], [echoRemote  1]]], xxxxpaddingxxx: LONG_CARDINAL, flowControl: CARDINAL, lineSpeed: CARDINAL, parity: CARDINAL, stopBits: CARDINAL, portActsAsDCE: BOOLEAN, accessControl: RECORD [organization: [REF Clearinghouse2::Organization], domain: [REF Clearinghouse2::Domain], object: [REF Clearinghouse2::Object]], validLineSpeeds: [SEQUENCE (65535)[REF CHEntries::LineSpeed]]]]
            struct RS232CData {
                BOOLEAN               cIUPort;
                PortClientType        owningClientType;
                BOOLEAN               preemptionAllowed;
                CARDINAL              lineNumber;
                CARDINAL              dialerNumber;
                Duplexity             duplexity;
                PortDialerType        dialingHardware;
                CharLength            charLength;
                PortEchoingLocation   echoing;
                LONG_CARDINAL         xxxxpaddingxxx;
                FlowControl           flowControl;
                LineSpeed             lineSpeed;
                Parity                parity;
                StopBits              stopBits;
                BOOLEAN               portActsAsDCE;
                Clearinghouse2::Name  accessControl;
                SEQUENCE_N<LineSpeed> validLineSpeeds;
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::CHEntries::PortClientType      value);
    QString toString(const Courier::Stub::CHEntries::PortDialerType      value);
    QString toString(const Courier::Stub::CHEntries::PortSyncType        value);
    QString toString(const Courier::Stub::CHEntries::PortEchoingLocation value);

    void serialize(BLOCK& block, const Courier::Stub::CHEntries::PortClientType      value);
    void serialize(BLOCK& block, const Courier::Stub::CHEntries::PortDialerType      value);
    void serialize(BLOCK& block, const Courier::Stub::CHEntries::PortSyncType        value);
    void serialize(BLOCK& block, const Courier::Stub::CHEntries::PortEchoingLocation value);

    void deserialize(BLOCK& block, Courier::Stub::CHEntries::PortClientType&      value);
    void deserialize(BLOCK& block, Courier::Stub::CHEntries::PortDialerType&      value);
    void deserialize(BLOCK& block, Courier::Stub::CHEntries::PortSyncType&        value);
    void deserialize(BLOCK& block, Courier::Stub::CHEntries::PortEchoingLocation& value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::CHEntries::MailboxesValue&           value);
    QString toString(const Courier::Stub::CHEntries::AuthenticationLevelValue& value);
    QString toString(const Courier::Stub::CHEntries::UserDataValue&            value);
    QString toString(const Courier::Stub::CHEntries::RS232CData&               value);

    void serialize(BLOCK& block, const Courier::Stub::CHEntries::MailboxesValue&           value);
    void serialize(BLOCK& block, const Courier::Stub::CHEntries::AuthenticationLevelValue& value);
    void serialize(BLOCK& block, const Courier::Stub::CHEntries::UserDataValue&            value);
    void serialize(BLOCK& block, const Courier::Stub::CHEntries::RS232CData&               value);

    void deserialize(BLOCK& block, Courier::Stub::CHEntries::MailboxesValue&           value);
    void deserialize(BLOCK& block, Courier::Stub::CHEntries::AuthenticationLevelValue& value);
    void deserialize(BLOCK& block, Courier::Stub::CHEntries::UserDataValue&            value);
    void deserialize(BLOCK& block, Courier::Stub::CHEntries::RS232CData&               value);
}
#endif
