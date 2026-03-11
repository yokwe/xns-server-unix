PEX: PROGRAM 0 VERSION 0 =
BEGIN

ClientType: TYPE = {UNSPEC(0), TIME(1), CHS(2), TELEDEBUG(8)};

PEX: TYPE = RECORD [
    id:         LONG CARDINAL,
    clientType: ClientType];

END.