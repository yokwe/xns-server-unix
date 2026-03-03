Clearinghouse: PROGRAM 2 VERSION 3 =
BEGIN
	DEPENDS UPON
		BulkData(0) VERSION 1,
		Authentication (14) VERSION 3;

Network: TYPE = courier::Network;
Host:    TYPE = courier::Host;
Socket:  TYPE = courier::Socket;

NetworkAddress: TYPE = RECORD [
	network: Network,
	host:    Host,
	socket:  Socket];

NetworkAddressList: TYPE = SEQUENCE 40 OF NetworkAddress;

Authenticator: TYPE = RECORD [
	credentials: Authentication.Credentials,
	verifier: Authentication.Verifier];


RetrieveAddresses: PROCEDURE
RETURNS [address: NetworkAddressList]
REPORTS [CallError] = 0;

ListDomainServed: PROCEDURE [domains: BulkData.Sink, agent: Authenticator]
REPORTS [AuthenticationError, CallError] = 1;

END.