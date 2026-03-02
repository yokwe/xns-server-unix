Clearinghouse: PROGRAM 2 VERSION 3 =
BEGIN

Network: TYPE = courier::Network;
Host:    TYPE = courier::Host;
Socket:  TYPE = courier::Socket;

NetworkAddress: TYPE = RECORD [
	network: Network,
	host:    Host,
	socket:  Socket];

NetworkAddressList: TYPE = SEQUENCE 40 OF NetworkAddress;


RetrieveAddresses: PROCEDURE
RETURNS [address: NetworkAddressList]
REPORTS [CallError] = 0;

END.