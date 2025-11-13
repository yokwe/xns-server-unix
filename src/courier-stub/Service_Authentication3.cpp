#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub-svc/Authentication3");

#include "../stub/Authentication3.h"
#include "../stub/Service_Authentication3.h"

#include "../courier/Last.h"

bool        Courier::Stub::Service_Authentication3::isProcedureValid(int code) {
    switch(code) {
    case GetStrongCredentials::CODE:
        return true;
    case CheckSimpleCredentials::CODE:
        return true;
    case CreateStrongKey::CODE:
        return true;
    case ChangeStrongKey::CODE:
        return true;
    case DeleteStrongKey::CODE:
        return true;
    case CreateSimpleKey::CODE:
        return true;
    case ChangeSimpleKey::CODE:
        return true;
    case DeleteSimpleKey::CODE:
        return true;
    case TradeProxyForCredentials::CODE:
        return true;
    default:
        return false;
    }
}
const char* Courier::Stub::Service_Authentication3::getProcedureName(int code) {
    switch(code) {
    case GetStrongCredentials::CODE:
        return GetStrongCredentials::NAME;
    case CheckSimpleCredentials::CODE:
        return CheckSimpleCredentials::NAME;
    case CreateStrongKey::CODE:
        return CreateStrongKey::NAME;
    case ChangeStrongKey::CODE:
        return ChangeStrongKey::NAME;
    case DeleteStrongKey::CODE:
        return DeleteStrongKey::NAME;
    case CreateSimpleKey::CODE:
        return CreateSimpleKey::NAME;
    case ChangeSimpleKey::CODE:
        return ChangeSimpleKey::NAME;
    case DeleteSimpleKey::CODE:
        return DeleteSimpleKey::NAME;
    case TradeProxyForCredentials::CODE:
        return TradeProxyForCredentials::NAME;
    default:
        logger.error("Unexpected code = %d", code);
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_Authentication3::service(const CallMessage& callMessage, Block& request, Block& response) {
    switch(callMessage.procedure) {
    case GetStrongCredentials::CODE:
        callGetStrongCredentials(callMessage, request, response);
        break;
    case CheckSimpleCredentials::CODE:
        callCheckSimpleCredentials(callMessage, request, response);
        break;
    case CreateStrongKey::CODE:
        callCreateStrongKey(callMessage, request, response);
        break;
    case ChangeStrongKey::CODE:
        callChangeStrongKey(callMessage, request, response);
        break;
    case DeleteStrongKey::CODE:
        callDeleteStrongKey(callMessage, request, response);
        break;
    case CreateSimpleKey::CODE:
        callCreateSimpleKey(callMessage, request, response);
        break;
    case ChangeSimpleKey::CODE:
        callChangeSimpleKey(callMessage, request, response);
        break;
    case DeleteSimpleKey::CODE:
        callDeleteSimpleKey(callMessage, request, response);
        break;
    case TradeProxyForCredentials::CODE:
        callTradeProxyForCredentials(callMessage, request, response);
        break;
    default:
        logger.error("Unexpected callMessage.procedure = %d", callMessage.procedure);
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_Authentication3::callGetStrongCredentials(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        GetStrongCredentials::Param  param;
        GetStrongCredentials::Result result;
        Courier::deserialize(request, param);
        getStrongCredentials(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callCheckSimpleCredentials(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        CheckSimpleCredentials::Param  param;
        CheckSimpleCredentials::Result result;
        Courier::deserialize(request, param);
        checkSimpleCredentials(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callCreateStrongKey(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        CreateStrongKey::Param  param;
        CreateStrongKey::Result result;
        Courier::deserialize(request, param);
        createStrongKey(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callChangeStrongKey(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ChangeStrongKey::Param  param;
        ChangeStrongKey::Result result;
        Courier::deserialize(request, param);
        changeStrongKey(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callDeleteStrongKey(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        DeleteStrongKey::Param  param;
        DeleteStrongKey::Result result;
        Courier::deserialize(request, param);
        deleteStrongKey(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callCreateSimpleKey(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        CreateSimpleKey::Param  param;
        CreateSimpleKey::Result result;
        Courier::deserialize(request, param);
        createSimpleKey(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callChangeSimpleKey(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ChangeSimpleKey::Param  param;
        ChangeSimpleKey::Result result;
        Courier::deserialize(request, param);
        changeSimpleKey(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callDeleteSimpleKey(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        DeleteSimpleKey::Param  param;
        DeleteSimpleKey::Result result;
        Courier::deserialize(request, param);
        deleteSimpleKey(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
void Courier::Stub::Service_Authentication3::callTradeProxyForCredentials(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        TradeProxyForCredentials::Param  param;
        TradeProxyForCredentials::Result result;
        Courier::deserialize(request, param);
        tradeProxyForCredentials(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Authentication3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Authentication3::CallError& e) {
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
