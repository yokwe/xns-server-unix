Courier: PROGRAM 0 VERSION 3 =
BEGIN
  -- 4.3.1 Call
  CallMessage: TYPE = RECORD [
    transactionID: UNSPECIFIED,
    programNumber: LONG CARDINAL,
    versionNumber, procedureValue: CARDINAL];
--  procedureArguments: RECORD [procedure-dependant]];
    
  -- 4.3.2 Reject
  VersionRange: TYPE = RECORD [
    lowest, highest: CARDINAL];

  RejectMessage: TYPE = RECORD [
    transactionID: UNSPECIFIED,
    rejectDetails: CHOICE OF {
      noSuchProgramNumber(0) => RECORD [],
      noSuchVersionNumber(1) => VersionRange, -- returns supprted version
      noSuchProcedureValue(2),
      invalidArgument(3),
      unspecified(FFFFH)     => RECORD []}];
  
  -- 4.3.3 Return
  ReturnMessage: TYPE = RECORD [
    transacionID: UNSPECIFIED];
--  procedureResults: RECORD [procedure-depent]];

  -- 4.3.4 Abort
  AbortMessage: TYPE = RECORD [
    transactionID: UNSPECIFIED,
    errorValue: CARDINAL];
--  errorArguments: RECORD [error-dependen]];

  -- 4.3 Message Type
  Message: TYPE = CHOICE OF {
    call(0)   => CallMessage,
    reject(1) => RejectMessage,
    return(2) => ReturnMessage,
    abort(3)  => AbortMessage};

  -- Expedited Message
  -- NOTE  Expedited Message support only version 3 of Courier
  ProtocolRange: TYPE = RECORD [
    lowest, highest: CARDINAL];
  SupportingProtol: CARDINAL = 3;

  ExpeditedMessate: TYPE = RECORD [
    protocolRange: ProtocolRange,
    message:       Message];
END.