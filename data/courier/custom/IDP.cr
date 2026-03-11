IDP: PROGRAM 0 VERSION 0 =
BEGIN

Checksum: TYPE = {ZERO(0), NOCHECK(FFFFH)};

PacketType: TYPE = {
    RIP(1),
    ECHO(2),
    ERROR_(3),
    PEX(4),
    SPP(5),
    BOOT(6)};

NetworkAddress: TYPE = courier::NetworkAddress;

IDP: TYPE = RECORD [
    checksum: Checksum,
    length:   CARDINAL,
    word2:    UNSPECIFIED,
    dst:      NetworkAddress,
    src:      NetworkAddress];

Socket: TYPE = {
    UNKNOWN (0),
    RIP (1),
    ECHO (2),
    ERROR_ (3),
    ENVOY (4),
    COURIER (5),
    CHS_OLD (7),
    TIME (8),
    BOOT (10),
    DIAG (19),
    CHS (20),
    AUTH (21),
    MAIL (22),
    NET_EXEC (23),
    WS_INFO (24),
    BINDING (28),
    GERM (35),
    TELEDEBUG (48),
    MAX_WELLKNOWN_SOCKET(3000),
    ALL (65535)

};

END.