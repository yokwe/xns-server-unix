#ifndef STUB_Service_Authentication2_H__
#define STUB_Service_Authentication2_H__

#include "../courier/Service.h"
#include "../stub/Authentication2.h"

namespace Courier {
    namespace Stub {
        class Service_Authentication2 : public Service::ServiceBase {
        public:
            Service_Authentication2() : Service::ServiceBase("Authentication", 14, 2) {}
            virtual ~Service_Authentication2() {}

            using CallMessage =            Protocol::Protocol3::Protocol3_CALL;
            using GetStrongCredentials =   Authentication2::GetStrongCredentials;
            using CheckSimpleCredentials = Authentication2::CheckSimpleCredentials;
            using CreateStrongKey =        Authentication2::CreateStrongKey;
            using ChangeStrongKey =        Authentication2::ChangeStrongKey;
            using DeleteStrongKey =        Authentication2::DeleteStrongKey;
            using CreateSimpleKey =        Authentication2::CreateSimpleKey;
            using ChangeSimpleKey =        Authentication2::ChangeSimpleKey;
            using DeleteSimpleKey =        Authentication2::DeleteSimpleKey;

            virtual void init()    = 0;
            virtual void destroy() = 0;

            virtual void getStrongCredentials   (quint16 transaction, const GetStrongCredentials::Param&   param, GetStrongCredentials::Result&   result) = 0;
            virtual void checkSimpleCredentials (quint16 transaction, const CheckSimpleCredentials::Param& param, CheckSimpleCredentials::Result& result) = 0;
            virtual void createStrongKey        (quint16 transaction, const CreateStrongKey::Param&        param, CreateStrongKey::Result&        result) = 0;
            virtual void changeStrongKey        (quint16 transaction, const ChangeStrongKey::Param&        param, ChangeStrongKey::Result&        result) = 0;
            virtual void deleteStrongKey        (quint16 transaction, const DeleteStrongKey::Param&        param, DeleteStrongKey::Result&        result) = 0;
            virtual void createSimpleKey        (quint16 transaction, const CreateSimpleKey::Param&        param, CreateSimpleKey::Result&        result) = 0;
            virtual void changeSimpleKey        (quint16 transaction, const ChangeSimpleKey::Param&        param, ChangeSimpleKey::Result&        result) = 0;
            virtual void deleteSimpleKey        (quint16 transaction, const DeleteSimpleKey::Param&        param, DeleteSimpleKey::Result&        result) = 0;

            bool        isProcedureValid    (int code);
            const char* getProcedureName    (int code);
            void        service             (const CallMessage& callMessage, Block& request, Block& response);

        private:
            void callGetStrongCredentials   (const CallMessage& callMessage, Block& request, Block& response);
            void callCheckSimpleCredentials (const CallMessage& callMessage, Block& request, Block& response);
            void callCreateStrongKey        (const CallMessage& callMessage, Block& request, Block& response);
            void callChangeStrongKey        (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteStrongKey        (const CallMessage& callMessage, Block& request, Block& response);
            void callCreateSimpleKey        (const CallMessage& callMessage, Block& request, Block& response);
            void callChangeSimpleKey        (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteSimpleKey        (const CallMessage& callMessage, Block& request, Block& response);
        };
    }
}
#endif
