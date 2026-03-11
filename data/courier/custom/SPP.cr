SPP: PROGRAM 0 VERSION 0 =
BEGIN

SST: TYPE = {
    DATA         (0),  -- courier message
    BULKD        (1),  -- bulk data
    CLOSE      (254),  -- closing connection
    CLOSE_REPLY(255)}; -- reply of closing connection (handshake)

SPP: TYPE = RECORD [
    word0: UNSPECIFIED,
    srcID: UNSPECIFIED,  -- id of self
    dstID: UNSPECIFIED,  -- id of other end
    seq:   CARDINAL,     -- sequence of this packet
    ack:   CARDINAL,     -- sequence of next expecting packet or sequence before this was acknowledged
    alloc: CARDINAL];    -- sequence of ??


END.