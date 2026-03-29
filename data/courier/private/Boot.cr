Boot: PROGRAM 0 VERSION 0 =
BEGIN

EtherBootPacketType: TYPE = {simpleRequest(1), simpleData(2), sppRequest(3)};

EthernetBootFileNumber: TYPE = courier::Host;
ConnectionID: TYPE = UNSPECIFIED;


BootFileRequest: TYPE = CHOICE EtherBootPacketType OF {
	simpleRequest => RECORD [bootFileNumber: EthernetBootFileNumber],
	simpleData => RECORD [
		bootFileNumber: EthernetBootFileNumber,
		packetNumber: CARDINAL],  -- starts with 1
		-- data: ARRAY [0..0) OF WORD
		-- one page of data normally, no data means end of file.
	sppRequest => RECORD [
		bootFileNumber: EthernetBootFileNumber,
		connectionID: ConnectionID]
};

END.