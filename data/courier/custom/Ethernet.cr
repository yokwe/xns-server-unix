Ethernet: PROGRAM 0 VERSION 0 =
BEGIN

Type: TYPE = {
    XNS(600H),
    IP4(800H),
    PUP(A00H)};

Host: TYPE = courier::Host;

Ethernet: TYPE = RECORD [
    dst:  Host,
    src:  Host,
    type: Type];

END.
