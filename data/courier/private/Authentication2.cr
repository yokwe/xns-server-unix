Authentication: PROGRAM 14 VERSION 2 =

BEGIN


NetworkAddress: TYPE = courier::NetworkAddress;

NetworkAddressList: TYPE = SEQUENCE 40 OF NetworkAddress;

Organization: TYPE = STRING;
Domain: TYPE = STRING;
Object: TYPE = STRING;

ThreePartName: TYPE = RECORD [
    organization: Organization,
    domain: Domain,
    object: Object
    ];

Clearinghouse_Name:  TYPE = ThreePartName;


-- ERRORS --

Problem: TYPE = {
    credentialsInvalid(0),
    verifierInvalid(1),
    verifierExpired(2),
    verifierReused(3),
    credentialsExpired(4),
    inappropriateCredentials(5) };
AuthenticationError: ERROR[problem: Problem] = 2;

CallProblem: TYPE = {
    tooBusy(0),
    accessRightsInsufficient(1),
    keysUnavailable(2),
    strongKeyDoesNotExist(3),
    simpleKeyDoesNotExist(4),
    strongKeyAlreadyRegistered(5),
    simpleKeyAlreadyRegistered(6),
    domainForNewKeyUnavailable(7),
    domainForNewKeyUnknown(8),
    badKey(9),
    badName(10),
    databaseFull(11),
    other(12) };
Which: TYPE = {notApplicable(0), initiator(1), recipient(2), client(3) };
CallError: ERROR [problem: CallProblem, whichArg: Which] = 1;


-- PROCEDURES --

RetrieveAddresses: PROCEDURE
RETURNS [address: NetworkAddressList]
REPORTS [CallError] = 0;


-- Strong Authentication --

GetStrongCredentials: PROCEDURE [
		initiator, recipient: Clearinghouse_Name,
		nonce: LONG CARDINAL ]
	RETURNS [ credentialsPackage: SEQUENCE OF UNSPECIFIED ]
	REPORTS [ CallError ] = 1;

END.
