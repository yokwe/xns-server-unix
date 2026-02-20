Courier: PROGRAM 0 VERSION 3 =
BEGIN
  -- 4.3.1 Call
  CallMessageBody: TYPE = RECORD [
    transactionID: UNSPECIFIED,
    programNumber: LONG CARDINAL,
    versionNumber, procedureValue: CARDINAL];
--  procedureArguments: RECORD [procedure-dependant]];
    
  -- 4.3.2 Reject
  ImplimentedVersionNumbers: TYPE = RECORD [
    lowest, heighest: CARDINAL];

  RejectMessageBody: TYPE = RECORD [
    transactionID: UNSPECIFIED,
    rejectDetails: CHOICE OF {
      noSuchProgramNuber(0)  => RECORD [],
      noSuchVersionNumber(1) => ImplimentedVersionNumbers,
      noSUchProcedureValue(2),
      invalidArgument(3),
      unspecified(FFFFH)     => RECORD []}];
  
  -- 4.3.3 Return
  ReturnMessageBody: TYPE = RECORD [
    transacionID: UNSPECIFIED];
--  procedureResults: RECORD [procedure-depent]];

  -- 4.3.4 Abort
  AbortMessageBody: TYPE = RECORD [
    transactionID: UNSPECIFIED,
    errorValue: CARDINAL];
--  errorArguments: RECORD [error-dependen]];

  -- 4.3 Message Type
  MessageType: TYPE = CHOICE OF {
    call(0)   => CallMessageBody,
    reject(1) => RejectMessageBody,
    return(2) => ReturnMessageBody,
    abort(3)  => AbortMessageBody};

END.