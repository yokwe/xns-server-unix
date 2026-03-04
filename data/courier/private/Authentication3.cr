Authentication: PROGRAM 14 VERSION 3 =

BEGIN

CredentialsType: TYPE = {simple(0), strong(1)};

Credentials: TYPE = RECORD [
    type:  CredentialsType,
    value: SEQUENCE OF UNSPECIFIED];

Verifier: TYPE = SEQUENCE 12 OF UNSPECIFIED;

END.