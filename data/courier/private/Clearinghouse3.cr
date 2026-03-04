Clearinghouse: PROGRAM 2 VERSION 3 =
BEGIN
	DEPENDS UPON
		BulkData(0) VERSION 1,
		Authentication (14) VERSION 3;

NetworkAddress: TYPE = courier::NetworkAddress;

NetworkAddressList: TYPE = SEQUENCE 40 OF NetworkAddress;

Authenticator: TYPE = RECORD [
	credentials: Authentication.Credentials,
	verifier: Authentication.Verifier];


Organization: TYPE = STRING;
Domain: TYPE = STRING;
Object: TYPE = STRING;

maxOrganizationsLength: CARDINAL = 20; -- in bytes --
maxDomainLength: CARDINAL = 20; -- in bytes --
maxObjectLength: CARDINAL = 40; -- in bytes --

-- There can be no wildcard characters in any of the following types. --
OrganizationName: TYPE = Organization;

TwoPartName: TYPE = RECORD [
	organization: Organization,
	domain: Domain];

DomainName: TYPE = TwoPartName;

StreamOfDomainName: TYPE = CHOICE OF {
	nextSegment (0) => RECORD [
		segment: SEQUENCE OF DomainName],
--		restOfStream: StreamOfDomainName],
	lastSegment (1) => SEQUENCE OF DomainName};



RetrieveAddresses: PROCEDURE
RETURNS [address: NetworkAddressList]
REPORTS [CallError] = 0;

-- ListDomainServed returns StreamOfDomainName in BulkData
-- See bfsgetdoms.c and bdt.c of XNSOnUX
ListDomainServed: PROCEDURE [domains: BulkData.Sink, agent: Authenticator]
REPORTS [AuthenticationError, CallError] = 1;

END.