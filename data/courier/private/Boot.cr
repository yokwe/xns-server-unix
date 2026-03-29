Boot: PROGRAM 0 VERSION 0 =
BEGIN

BootFileNumber: TYPE = courier::Host;
ConnectionID: TYPE = UNSPECIFIED;

BootRequestType: TYPE = {simpleRequest(1), simpleData(2), sppRequest(3)};

BootFileRequest: TYPE = CHOICE BootRequestType OF {
	simpleRequest => RECORD [bootFileNumber: BootFileNumber],
	simpleData => RECORD [
		bootFileNumber: BootFileNumber,
		packetNumber: CARDINAL],  -- starts with 1
		-- data: ARRAY [0..0) OF WORD
		-- one page of data normally, no data means end of file.
	sppRequest => RECORD [
		bootFileNumber: BootFileNumber,
		connectionID: ConnectionID]
};

END.