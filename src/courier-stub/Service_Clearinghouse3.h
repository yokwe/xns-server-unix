#ifndef STUB_Service_Clearinghouse3_H__
#define STUB_Service_Clearinghouse3_H__

#include "../courier/Service.h"
#include "../stub/Clearinghouse3.h"

namespace Courier {
    namespace Stub {
        class Service_Clearinghouse3 : public Service::ServiceBase {
        public:
            Service_Clearinghouse3() : Service::ServiceBase("Clearinghouse", 2, 3) {}
            virtual ~Service_Clearinghouse3() {}

            using CallMessage =       Protocol::Protocol3::Protocol3_CALL;
            using RetrieveAddresses = Clearinghouse3::RetrieveAddresses;
            using ListDomainServed =  Clearinghouse3::ListDomainServed;
            using CreateObject =      Clearinghouse3::CreateObject;
            using DeleteObject =      Clearinghouse3::DeleteObject;
            using LookupObject =      Clearinghouse3::LookupObject;
            using ListOrganizations = Clearinghouse3::ListOrganizations;
            using ListDomain =        Clearinghouse3::ListDomain;
            using ListObjects =       Clearinghouse3::ListObjects;
            using ListAliases =       Clearinghouse3::ListAliases;
            using ListAliasesOf =     Clearinghouse3::ListAliasesOf;
            using CreateAlias =       Clearinghouse3::CreateAlias;
            using DeleteAlias =       Clearinghouse3::DeleteAlias;
            using AddGroupProperty =  Clearinghouse3::AddGroupProperty;
            using AddItemProperty =   Clearinghouse3::AddItemProperty;
            using DeleteProperty =    Clearinghouse3::DeleteProperty;
            using ListProperties =    Clearinghouse3::ListProperties;
            using RetrieveItem =      Clearinghouse3::RetrieveItem;
            using ChangeItem =        Clearinghouse3::ChangeItem;
            using RetrieveMembers =   Clearinghouse3::RetrieveMembers;
            using AddMember =         Clearinghouse3::AddMember;
            using AddSelf =           Clearinghouse3::AddSelf;
            using DeleteMember =      Clearinghouse3::DeleteMember;
            using DeleteSelf =        Clearinghouse3::DeleteSelf;
            using IsMember =          Clearinghouse3::IsMember;

            virtual void init()    = 0;
            virtual void destroy() = 0;

            virtual void retrieveAddresses (quint16 transaction, const RetrieveAddresses::Param& param, RetrieveAddresses::Result& result) = 0;
            virtual void listDomainServed  (quint16 transaction, const ListDomainServed::Param&  param, ListDomainServed::Result&  result) = 0;
            virtual void createObject      (quint16 transaction, const CreateObject::Param&      param, CreateObject::Result&      result) = 0;
            virtual void deleteObject      (quint16 transaction, const DeleteObject::Param&      param, DeleteObject::Result&      result) = 0;
            virtual void lookupObject      (quint16 transaction, const LookupObject::Param&      param, LookupObject::Result&      result) = 0;
            virtual void listOrganizations (quint16 transaction, const ListOrganizations::Param& param, ListOrganizations::Result& result) = 0;
            virtual void listDomain        (quint16 transaction, const ListDomain::Param&        param, ListDomain::Result&        result) = 0;
            virtual void listObjects       (quint16 transaction, const ListObjects::Param&       param, ListObjects::Result&       result) = 0;
            virtual void listAliases       (quint16 transaction, const ListAliases::Param&       param, ListAliases::Result&       result) = 0;
            virtual void listAliasesOf     (quint16 transaction, const ListAliasesOf::Param&     param, ListAliasesOf::Result&     result) = 0;
            virtual void createAlias       (quint16 transaction, const CreateAlias::Param&       param, CreateAlias::Result&       result) = 0;
            virtual void deleteAlias       (quint16 transaction, const DeleteAlias::Param&       param, DeleteAlias::Result&       result) = 0;
            virtual void addGroupProperty  (quint16 transaction, const AddGroupProperty::Param&  param, AddGroupProperty::Result&  result) = 0;
            virtual void addItemProperty   (quint16 transaction, const AddItemProperty::Param&   param, AddItemProperty::Result&   result) = 0;
            virtual void deleteProperty    (quint16 transaction, const DeleteProperty::Param&    param, DeleteProperty::Result&    result) = 0;
            virtual void listProperties    (quint16 transaction, const ListProperties::Param&    param, ListProperties::Result&    result) = 0;
            virtual void retrieveItem      (quint16 transaction, const RetrieveItem::Param&      param, RetrieveItem::Result&      result) = 0;
            virtual void changeItem        (quint16 transaction, const ChangeItem::Param&        param, ChangeItem::Result&        result) = 0;
            virtual void retrieveMembers   (quint16 transaction, const RetrieveMembers::Param&   param, RetrieveMembers::Result&   result) = 0;
            virtual void addMember         (quint16 transaction, const AddMember::Param&         param, AddMember::Result&         result) = 0;
            virtual void addSelf           (quint16 transaction, const AddSelf::Param&           param, AddSelf::Result&           result) = 0;
            virtual void deleteMember      (quint16 transaction, const DeleteMember::Param&      param, DeleteMember::Result&      result) = 0;
            virtual void deleteSelf        (quint16 transaction, const DeleteSelf::Param&        param, DeleteSelf::Result&        result) = 0;
            virtual void isMember          (quint16 transaction, const IsMember::Param&          param, IsMember::Result&          result) = 0;

            bool        isProcedureValid    (int code);
            const char* getProcedureName    (int code);
            void        service             (const CallMessage& callMessage, Block& request, Block& response);

        private:
            void callRetrieveAddresses (const CallMessage& callMessage, Block& request, Block& response);
            void callListDomainServed  (const CallMessage& callMessage, Block& request, Block& response);
            void callCreateObject      (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteObject      (const CallMessage& callMessage, Block& request, Block& response);
            void callLookupObject      (const CallMessage& callMessage, Block& request, Block& response);
            void callListOrganizations (const CallMessage& callMessage, Block& request, Block& response);
            void callListDomain        (const CallMessage& callMessage, Block& request, Block& response);
            void callListObjects       (const CallMessage& callMessage, Block& request, Block& response);
            void callListAliases       (const CallMessage& callMessage, Block& request, Block& response);
            void callListAliasesOf     (const CallMessage& callMessage, Block& request, Block& response);
            void callCreateAlias       (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteAlias       (const CallMessage& callMessage, Block& request, Block& response);
            void callAddGroupProperty  (const CallMessage& callMessage, Block& request, Block& response);
            void callAddItemProperty   (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteProperty    (const CallMessage& callMessage, Block& request, Block& response);
            void callListProperties    (const CallMessage& callMessage, Block& request, Block& response);
            void callRetrieveItem      (const CallMessage& callMessage, Block& request, Block& response);
            void callChangeItem        (const CallMessage& callMessage, Block& request, Block& response);
            void callRetrieveMembers   (const CallMessage& callMessage, Block& request, Block& response);
            void callAddMember         (const CallMessage& callMessage, Block& request, Block& response);
            void callAddSelf           (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteMember      (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteSelf        (const CallMessage& callMessage, Block& request, Block& response);
            void callIsMember          (const CallMessage& callMessage, Block& request, Block& response);
        };
    }
}
#endif
