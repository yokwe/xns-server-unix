#ifndef STUB_Service_Authentication3_H__
#define STUB_Service_Authentication3_H__

#include "../courier/Service.h"
#include "../stub/Authentication3.h"

namespace Courier {
    namespace Stub {
        class Service_Authentication3 : public Service::ServiceBase {
        public:
            Service_Authentication3() : Service::ServiceBase("Authentication", 14, 3) {}
            virtual ~Service_Authentication3() {}

            using CallMessage =              Protocol::Protocol3::Protocol3_CALL;
            using GetStrongCredentials =     Authentication3::GetStrongCredentials;
            using CheckSimpleCredentials =   Authentication3::CheckSimpleCredentials;
            using CreateStrongKey =          Authentication3::CreateStrongKey;
            using ChangeStrongKey =          Authentication3::ChangeStrongKey;
            using DeleteStrongKey =          Authentication3::DeleteStrongKey;
            using CreateSimpleKey =          Authentication3::CreateSimpleKey;
            using ChangeSimpleKey =          Authentication3::ChangeSimpleKey;
            using DeleteSimpleKey =          Authentication3::DeleteSimpleKey;
            using TradeProxyForCredentials = Authentication3::TradeProxyForCredentials;

            virtual void init()    = 0;
            virtual void destroy() = 0;

            virtual void getStrongCredentials     (quint16 transaction, const GetStrongCredentials::Param&     param, GetStrongCredentials::Result&     result) = 0;
            virtual void checkSimpleCredentials   (quint16 transaction, const CheckSimpleCredentials::Param&   param, CheckSimpleCredentials::Result&   result) = 0;
            virtual void createStrongKey          (quint16 transaction, const CreateStrongKey::Param&          param, CreateStrongKey::Result&          result) = 0;
            virtual void changeStrongKey          (quint16 transaction, const ChangeStrongKey::Param&          param, ChangeStrongKey::Result&          result) = 0;
            virtual void deleteStrongKey          (quint16 transaction, const DeleteStrongKey::Param&          param, DeleteStrongKey::Result&          result) = 0;
            virtual void createSimpleKey          (quint16 transaction, const CreateSimpleKey::Param&          param, CreateSimpleKey::Result&          result) = 0;
            virtual void changeSimpleKey          (quint16 transaction, const ChangeSimpleKey::Param&          param, ChangeSimpleKey::Result&          result) = 0;
            virtual void deleteSimpleKey          (quint16 transaction, const DeleteSimpleKey::Param&          param, DeleteSimpleKey::Result&          result) = 0;
            virtual void tradeProxyForCredentials (quint16 transaction, const TradeProxyForCredentials::Param& param, TradeProxyForCredentials::Result& result) = 0;

            bool        isProcedureValid    (int code);
            const char* getProcedureName    (int code);
            void        service             (const CallMessage& callMessage, Block& request, Block& response);

        private:
            void callGetStrongCredentials     (const CallMessage& callMessage, Block& request, Block& response);
            void callCheckSimpleCredentials   (const CallMessage& callMessage, Block& request, Block& response);
            void callCreateStrongKey          (const CallMessage& callMessage, Block& request, Block& response);
            void callChangeStrongKey          (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteStrongKey          (const CallMessage& callMessage, Block& request, Block& response);
            void callCreateSimpleKey          (const CallMessage& callMessage, Block& request, Block& response);
            void callChangeSimpleKey          (const CallMessage& callMessage, Block& request, Block& response);
            void callDeleteSimpleKey          (const CallMessage& callMessage, Block& request, Block& response);
            void callTradeProxyForCredentials (const CallMessage& callMessage, Block& request, Block& response);
        };
    }
}
#endif
