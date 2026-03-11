RIP: PROGRAM 0 VERSION 0 =
BEGIN

Network: TYPE = courier::Network;

Operation: TYPE = {REQUEST(1), RESPONSE(2)};

Delay: TYPE = {ZERO(0), INFINITY(16)};

Entry: TYPE = RECORD [
    network: Network,
    delay:   Delay];

RIP: TYPE = RECORD [
    operation: Operation];
--  list: List<Entry>

END.