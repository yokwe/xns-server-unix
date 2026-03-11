Error: PROGRAM 0 VERSION 0 =
BEGIN

Type: TYPE = {
    UNSPEC             (0),
    BAD_CHECKSUM       (1),
    NO_SOCKET          (2),
    RESOURCE_LIMIT     (3),
    LISTEN_REJECT      (4),
    INVALID_PACKET_TYPE(5),
    PROTOCOL_VIOLATION (6),
    --
    UNSPECIFIED_IN_ROUTE(1000B),
    INCONSISTENT        (1001B),
    CANT_GET_THERE      (1002B),
    EXCESS_HOPS         (1003B),
    TOO_BIG             (1004B),
    CONGESTION_WARNING  (1005B),
    CONGESTION_DISCARD  (1006B)};

Error: TYPE = RECORD [
    type:      Type,
    parameter: CARDINAL];

END.