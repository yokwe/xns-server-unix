#include "../util/Util.h"
static log4cpp::Category& logger = Logger::getLogger("stub-svc/Clearinghouse3");

#include "../stub/Clearinghouse3.h"
#include "../stub/Service_Clearinghouse3.h"

#include "../courier/Last.h"

bool        Courier::Stub::Service_Clearinghouse3::isProcedureValid(int code) {
    switch(code) {
    case RetrieveAddresses::CODE:
        return true;
    case ListDomainServed::CODE:
        return true;
    case CreateObject::CODE:
        return true;
    case DeleteObject::CODE:
        return true;
    case LookupObject::CODE:
        return true;
    case ListOrganizations::CODE:
        return true;
    case ListDomain::CODE:
        return true;
    case ListObjects::CODE:
        return true;
    case ListAliases::CODE:
        return true;
    case ListAliasesOf::CODE:
        return true;
    case CreateAlias::CODE:
        return true;
    case DeleteAlias::CODE:
        return true;
    case AddGroupProperty::CODE:
        return true;
    case AddItemProperty::CODE:
        return true;
    case DeleteProperty::CODE:
        return true;
    case ListProperties::CODE:
        return true;
    case RetrieveItem::CODE:
        return true;
    case ChangeItem::CODE:
        return true;
    case RetrieveMembers::CODE:
        return true;
    case AddMember::CODE:
        return true;
    case AddSelf::CODE:
        return true;
    case DeleteMember::CODE:
        return true;
    case DeleteSelf::CODE:
        return true;
    case IsMember::CODE:
        return true;
    default:
        return false;
    }
}
const char* Courier::Stub::Service_Clearinghouse3::getProcedureName(int code) {
    switch(code) {
    case RetrieveAddresses::CODE:
        return RetrieveAddresses::NAME;
    case ListDomainServed::CODE:
        return ListDomainServed::NAME;
    case CreateObject::CODE:
        return CreateObject::NAME;
    case DeleteObject::CODE:
        return DeleteObject::NAME;
    case LookupObject::CODE:
        return LookupObject::NAME;
    case ListOrganizations::CODE:
        return ListOrganizations::NAME;
    case ListDomain::CODE:
        return ListDomain::NAME;
    case ListObjects::CODE:
        return ListObjects::NAME;
    case ListAliases::CODE:
        return ListAliases::NAME;
    case ListAliasesOf::CODE:
        return ListAliasesOf::NAME;
    case CreateAlias::CODE:
        return CreateAlias::NAME;
    case DeleteAlias::CODE:
        return DeleteAlias::NAME;
    case AddGroupProperty::CODE:
        return AddGroupProperty::NAME;
    case AddItemProperty::CODE:
        return AddItemProperty::NAME;
    case DeleteProperty::CODE:
        return DeleteProperty::NAME;
    case ListProperties::CODE:
        return ListProperties::NAME;
    case RetrieveItem::CODE:
        return RetrieveItem::NAME;
    case ChangeItem::CODE:
        return ChangeItem::NAME;
    case RetrieveMembers::CODE:
        return RetrieveMembers::NAME;
    case AddMember::CODE:
        return AddMember::NAME;
    case AddSelf::CODE:
        return AddSelf::NAME;
    case DeleteMember::CODE:
        return DeleteMember::NAME;
    case DeleteSelf::CODE:
        return DeleteSelf::NAME;
    case IsMember::CODE:
        return IsMember::NAME;
    default:
        logger.error("Unexpected code = %d", code);
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_Clearinghouse3::service(const CallMessage& callMessage, Block& request, Block& response) {
    switch(callMessage.procedure) {
    case RetrieveAddresses::CODE:
        callRetrieveAddresses(callMessage, request, response);
        break;
    case ListDomainServed::CODE:
        callListDomainServed(callMessage, request, response);
        break;
    case CreateObject::CODE:
        callCreateObject(callMessage, request, response);
        break;
    case DeleteObject::CODE:
        callDeleteObject(callMessage, request, response);
        break;
    case LookupObject::CODE:
        callLookupObject(callMessage, request, response);
        break;
    case ListOrganizations::CODE:
        callListOrganizations(callMessage, request, response);
        break;
    case ListDomain::CODE:
        callListDomain(callMessage, request, response);
        break;
    case ListObjects::CODE:
        callListObjects(callMessage, request, response);
        break;
    case ListAliases::CODE:
        callListAliases(callMessage, request, response);
        break;
    case ListAliasesOf::CODE:
        callListAliasesOf(callMessage, request, response);
        break;
    case CreateAlias::CODE:
        callCreateAlias(callMessage, request, response);
        break;
    case DeleteAlias::CODE:
        callDeleteAlias(callMessage, request, response);
        break;
    case AddGroupProperty::CODE:
        callAddGroupProperty(callMessage, request, response);
        break;
    case AddItemProperty::CODE:
        callAddItemProperty(callMessage, request, response);
        break;
    case DeleteProperty::CODE:
        callDeleteProperty(callMessage, request, response);
        break;
    case ListProperties::CODE:
        callListProperties(callMessage, request, response);
        break;
    case RetrieveItem::CODE:
        callRetrieveItem(callMessage, request, response);
        break;
    case ChangeItem::CODE:
        callChangeItem(callMessage, request, response);
        break;
    case RetrieveMembers::CODE:
        callRetrieveMembers(callMessage, request, response);
        break;
    case AddMember::CODE:
        callAddMember(callMessage, request, response);
        break;
    case AddSelf::CODE:
        callAddSelf(callMessage, request, response);
        break;
    case DeleteMember::CODE:
        callDeleteMember(callMessage, request, response);
        break;
    case DeleteSelf::CODE:
        callDeleteSelf(callMessage, request, response);
        break;
    case IsMember::CODE:
        callIsMember(callMessage, request, response);
        break;
    default:
        logger.error("Unexpected callMessage.procedure = %d", callMessage.procedure);
        COURIER_FATAL_ERROR();
    }
}
void Courier::Stub::Service_Clearinghouse3::callRetrieveAddresses(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        RetrieveAddresses::Param  param;
        RetrieveAddresses::Result result;
        Courier::deserialize(request, param);
        retrieveAddresses(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::CallError& e) {
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
void Courier::Stub::Service_Clearinghouse3::callListDomainServed(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ListDomainServed::Param  param;
        ListDomainServed::Result result;
        Courier::deserialize(request, param);
        listDomainServed(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
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
void Courier::Stub::Service_Clearinghouse3::callCreateObject(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        CreateObject::Param  param;
        CreateObject::Result result;
        Courier::deserialize(request, param);
        createObject(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callDeleteObject(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        DeleteObject::Param  param;
        DeleteObject::Result result;
        Courier::deserialize(request, param);
        deleteObject(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callLookupObject(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        LookupObject::Param  param;
        LookupObject::Result result;
        Courier::deserialize(request, param);
        lookupObject(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callListOrganizations(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ListOrganizations::Param  param;
        ListOrganizations::Result result;
        Courier::deserialize(request, param);
        listOrganizations(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callListDomain(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ListDomain::Param  param;
        ListDomain::Result result;
        Courier::deserialize(request, param);
        listDomain(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callListObjects(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ListObjects::Param  param;
        ListObjects::Result result;
        Courier::deserialize(request, param);
        listObjects(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callListAliases(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ListAliases::Param  param;
        ListAliases::Result result;
        Courier::deserialize(request, param);
        listAliases(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callListAliasesOf(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ListAliasesOf::Param  param;
        ListAliasesOf::Result result;
        Courier::deserialize(request, param);
        listAliasesOf(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callCreateAlias(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        CreateAlias::Param  param;
        CreateAlias::Result result;
        Courier::deserialize(request, param);
        createAlias(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callDeleteAlias(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        DeleteAlias::Param  param;
        DeleteAlias::Result result;
        Courier::deserialize(request, param);
        deleteAlias(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callAddGroupProperty(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        AddGroupProperty::Param  param;
        AddGroupProperty::Result result;
        Courier::deserialize(request, param);
        addGroupProperty(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callAddItemProperty(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        AddItemProperty::Param  param;
        AddItemProperty::Result result;
        Courier::deserialize(request, param);
        addItemProperty(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callDeleteProperty(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        DeleteProperty::Param  param;
        DeleteProperty::Result result;
        Courier::deserialize(request, param);
        deleteProperty(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callListProperties(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ListProperties::Param  param;
        ListProperties::Result result;
        Courier::deserialize(request, param);
        listProperties(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callRetrieveItem(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        RetrieveItem::Param  param;
        RetrieveItem::Result result;
        Courier::deserialize(request, param);
        retrieveItem(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callChangeItem(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        ChangeItem::Param  param;
        ChangeItem::Result result;
        Courier::deserialize(request, param);
        changeItem(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callRetrieveMembers(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        RetrieveMembers::Param  param;
        RetrieveMembers::Result result;
        Courier::deserialize(request, param);
        retrieveMembers(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callAddMember(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        AddMember::Param  param;
        AddMember::Result result;
        Courier::deserialize(request, param);
        addMember(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callAddSelf(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        AddSelf::Param  param;
        AddSelf::Result result;
        Courier::deserialize(request, param);
        addSelf(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callDeleteMember(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        DeleteMember::Param  param;
        DeleteMember::Result result;
        Courier::deserialize(request, param);
        deleteMember(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callDeleteSelf(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        DeleteSelf::Param  param;
        DeleteSelf::Result result;
        Courier::deserialize(request, param);
        deleteSelf(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::UpdateError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
void Courier::Stub::Service_Clearinghouse3::callIsMember(const CallMessage& callMessage, Block& request, Block& response) {
    try {
        IsMember::Param  param;
        IsMember::Result result;
        Courier::deserialize(request, param);
        isMember(callMessage.transaction, param, result);

        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolReturn(callMessage);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, result);
    } catch(const Clearinghouse3::ArgumentError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::AuthenticationError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::CallError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::PropertyError& e) {
        Protocol::Protocol3 protocol3 = Courier::Service::getProtocolAbort(callMessage, e.abortCode);
        Courier::serialize(response, protocol3);
        Courier::serialize(response, e);
    } catch(const Clearinghouse3::WrongServer& e) {
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
