BulkData: PROGRAM 0 VERSION 1 =

BEGIN

Network: TYPE = courier::Network;
Host:    TYPE = courier::Host;

Identifier: TYPE = RECORD [
	host: Host,  
	hostRelativeIdentifier: ARRAY 2 OF UNSPECIFIED ];

Descriptor: TYPE = CHOICE OF {
	null(0), immediate(1) => RECORD [ ],
	passive(2), active(3) => RECORD [ 
		network:    Network,
		host:       Host,
		identifier: Identifier ]
	};

-- sinks (for external use) --

Sink: TYPE = Descriptor;

END.
