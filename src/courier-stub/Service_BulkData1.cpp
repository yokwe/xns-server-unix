#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub-svc/BulkData1");

#include "../stub/BulkData1.h"
#include "../stub/Service_BulkData1.h"

#include "../courier/Last.h"

bool        Courier::Stub::Service_BulkData1::isProcedureValid(int code) {
    switch(code) {
    case Send::CODE:
        return true;
    case Receive::CODE:
        return true;
    case Cancel::CODE:
        return true;
    default:
        return false;
    }
}
const char* Courier::Stub::Service_BulkData1::getProcedureName(int code) {
    switch(code) {
    case Send::CODE:
        return Send::NAME;
    case Receive::CODE:
        return Receive::NAME;
    case Cancel::CODE:
        return Cancel::NAME;
    default:
        logger.error("Unexpected code = %d", code);
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_BulkData1::service(const CallMessage& callMessage, Block& request, Block& response) {
    switch(callMessage.procedure) {
    case Send::CODE:
        callSend(callMessage, request, response);
        break;
    case Receive::CODE:
        callReceive(callMessage, request, response);
        break;
    case Cancel::CODE:
        callCancel(callMessage, request, response);
        break;
    default:
        logger.error("Unexpected callMessage.procedure = %d", callMessage.procedure);
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_BulkData1::callSend(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        Send::Param  param;
        Send::Result result;
        Courier::deserialize(request, param);
        send(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const BulkData1::InvalidDescriptor& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::NoSuchIdentifier& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::IdentifierBusy& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::WrongHost& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::WrongDirection& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::TransferAborted& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Courier::Service::Abort& e) {
        logger.error("Uncaught Protocol::Abort  %s%d  %s", e.programName, e.versionCode, e.abortName);
        COURIER_FATAL_ERROR();
    } catch(const std::runtime_error& e) {
        logger.error("std::runtime_error %s", e.what());
        COURIER_FATAL_ERROR();
    } catch(const std::exception& e) {
        logger.error("std::exception %s", e.what());
        COURIER_FATAL_ERROR();
    } catch(...) {
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_BulkData1::callReceive(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        Receive::Param  param;
        Receive::Result result;
        Courier::deserialize(request, param);
        receive(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const BulkData1::InvalidDescriptor& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::NoSuchIdentifier& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::IdentifierBusy& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::WrongHost& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::WrongDirection& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::TransferAborted& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Courier::Service::Abort& e) {
        logger.error("Uncaught Protocol::Abort  %s%d  %s", e.programName, e.versionCode, e.abortName);
        COURIER_FATAL_ERROR();
    } catch(const std::runtime_error& e) {
        logger.error("std::runtime_error %s", e.what());
        COURIER_FATAL_ERROR();
    } catch(const std::exception& e) {
        logger.error("std::exception %s", e.what());
        COURIER_FATAL_ERROR();
    } catch(...) {
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_BulkData1::callCancel(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        Cancel::Param  param;
        Cancel::Result result;
        Courier::deserialize(request, param);
        cancel(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const BulkData1::NoSuchIdentifier& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::IdentifierBusy& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const BulkData1::WrongHost& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Courier::Service::Abort& e) {
        logger.error("Uncaught Protocol::Abort  %s%d  %s", e.programName, e.versionCode, e.abortName);
        COURIER_FATAL_ERROR();
    } catch(const std::runtime_error& e) {
        logger.error("std::runtime_error %s", e.what());
        COURIER_FATAL_ERROR();
    } catch(const std::exception& e) {
        logger.error("std::exception %s", e.what());
        COURIER_FATAL_ERROR();
    } catch(...) {
        COURIER_FATAL_ERROR();
    }
}
