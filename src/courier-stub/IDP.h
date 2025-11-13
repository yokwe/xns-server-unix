#ifndef STUB_IDP_H__
#define STUB_IDP_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

#include "../stub/Ethernet.h"

namespace Courier {
    namespace Stub {
        namespace IDP {

            // TYPE  Network  ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]]
            enum class Network : quint32 {
                UNKNOWN =           0,
                ALL     = 0xFFFFFFFFU,
            };

            // TYPE  Host  [REF Ethernet::Host]
            //   ENUM [UNSPECIFIED3 [[ALL  281474976710655]]]
            using Host = Ethernet::Host;

            // TYPE  Socket  ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]
            enum class Socket : quint16 {
                RIP       =  1,
                ECHO      =  2,
                ERR       =  3,
                ENVOY     =  4,
                COURIER   =  5,
                CHS_OLD   =  7,
                TIME      =  8,
                BOOT      = 10,
                DIAG      = 19,
                CHS       = 20,
                AUTH      = 21,
                MAIL      = 22,
                NET_EXEC  = 23,
                WS_INFO   = 24,
                BINDING   = 28,
                GERM      = 35,
                TELEDEBUG = 48,
            };

            // TYPE  NetworkAddress  RECORD [network: [REF IDP::Network], host: [REF IDP::Host], socket: [REF IDP::Socket]]
            //   RECORD [network: ENUM [UNSPECIFIED2 [[UNKNOWN  0], [ALL  4294967295]]], host: ENUM [UNSPECIFIED3 [[ALL  281474976710655]]], socket: ENUM [UNSPECIFIED [[RIP  1], [ECHO  2], [ERR  3], [ENVOY  4], [COURIER  5], [CHS_OLD  7], [TIME  8], [BOOT  10], [DIAG  19], [CHS  20], [AUTH  21], [MAIL  22], [NET_EXEC  23], [WS_INFO  24], [BINDING  28], [GERM  35], [TELEDEBUG  48]]]]
            struct NetworkAddress {
                Network network;
                Host    host;
                Socket  socket;
            };

            // TYPE  Checksum  ENUM [UNSPECIFIED [[NONE  65535]]]
            enum class Checksum : quint16 {
                NONE = 0xFFFF,
            };

            // TYPE  Control  MACHINE BYTE [trace: (0..0) BOOLEAN, filler: (1..3) CARDINAL, hop: (4..7) CARDINAL]
            struct Control /* BYTE */ {
                BOOLEAN  trace;  // 0 .. 0
                CARDINAL filler; // 1 .. 3
                CARDINAL hop;    // 4 .. 7
            };

            // TYPE  Type  ENUM [BYTE [[RIP  1], [ECHO  2], [ERR  3], [PEP  4], [SPP  5], [BOOT  9]]]
            enum class Type : quint8 {
                RIP  = 1,
                ECHO = 2,
                ERR  = 3,
                PEP  = 4,
                SPP  = 5,
                BOOT = 9,
            };

            // TYPE  Frame  RECORD [checksum: [REF IDP::Checksum], length: CARDINAL, control: [REF IDP::Control], type: [REF IDP::Type], dst: [REF IDP::NetworkAddress], src: [REF IDP::NetworkAddress], data: BLOCK]
            //   RECORD [checksum: ENUM [UNSPECIFIED [[NONE  65535]]], length: CARDINAL, control: MACHINE BYTE [trace: (0..0) BOOLEAN, filler: (1..3) CARDINAL, hop: (4..7) CARDINAL], type: ENUM [BYTE [[RIP  1], [ECHO  2], [ERR  3], [PEP  4], [SPP  5], [BOOT  9]]], dst: RECORD [network: [REF IDP::Network], host: [REF IDP::Host], socket: [REF IDP::Socket]], src: RECORD [network: [REF IDP::Network], host: [REF IDP::Host], socket: [REF IDP::Socket]], data: BLOCK]
            struct Frame {
                Checksum       checksum;
                CARDINAL       length;
                Control        control;
                Type           type;
                NetworkAddress dst;
                NetworkAddress src;
                BLOCK          data{nullptr, 0};
            };

            // CONST  HEADER_LENGTH  30  CARDINAL
            const CARDINAL HEADER_LENGTH = 30;

            // CONST  DATA_LENGTH_MIN  0  CARDINAL
            const CARDINAL DATA_LENGTH_MIN = 0;

            // CONST  DATA_LENGTH_MAX  546  CARDINAL
            const CARDINAL DATA_LENGTH_MAX = 546;

            // CONST  HOP_MAX  16  CARDINAL
            const CARDINAL HOP_MAX = 16;

            // CONST  PACKET_LIFETIME_MAX  60  CARDINAL
            const CARDINAL PACKET_LIFETIME_MAX = 60;
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::IDP::Network  value);
    QString toString(const Courier::Stub::IDP::Socket   value);
    QString toString(const Courier::Stub::IDP::Checksum value);
    QString toString(const Courier::Stub::IDP::Type     value);

    void serialize(BLOCK& block, const Courier::Stub::IDP::Network  value);
    void serialize(BLOCK& block, const Courier::Stub::IDP::Socket   value);
    void serialize(BLOCK& block, const Courier::Stub::IDP::Checksum value);
    void serialize(BLOCK& block, const Courier::Stub::IDP::Type     value);

    void deserialize(BLOCK& block, Courier::Stub::IDP::Network&  value);
    void deserialize(BLOCK& block, Courier::Stub::IDP::Socket&   value);
    void deserialize(BLOCK& block, Courier::Stub::IDP::Checksum& value);
    void deserialize(BLOCK& block, Courier::Stub::IDP::Type&     value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::IDP::NetworkAddress& value);
    QString toString(const Courier::Stub::IDP::Frame&          value);

    void serialize(BLOCK& block, const Courier::Stub::IDP::NetworkAddress& value);
    void serialize(BLOCK& block, const Courier::Stub::IDP::Frame&          value);

    void deserialize(BLOCK& block, Courier::Stub::IDP::NetworkAddress& value);
    void deserialize(BLOCK& block, Courier::Stub::IDP::Frame&          value);

    //
    // Machine Function Declaration
    //
    QString toString(const Courier::Stub::IDP::Control& value);

    void serialize(BLOCK& block, const Courier::Stub::IDP::Control& value);

    void deserialize(BLOCK& block, Courier::Stub::IDP::Control& value);
}
#endif
