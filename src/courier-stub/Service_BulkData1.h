#ifndef STUB_Service_BulkData1_H__
#define STUB_Service_BulkData1_H__

#include "../courier/Service.h"
#include "../stub/BulkData1.h"

namespace Courier {
    namespace Stub {
        class Service_BulkData1 : public Service::ServiceBase {
        public:
            Service_BulkData1() : Service::ServiceBase("BulkData", 0, 1) {}
            virtual ~Service_BulkData1() {}

            using CallMessage = Protocol::Protocol3::Protocol3_CALL;
            using Send =        BulkData1::Send;
            using Receive =     BulkData1::Receive;
            using Cancel =      BulkData1::Cancel;

            virtual void init()    = 0;
            virtual void destroy() = 0;

            virtual void send    (quint16 transaction, const Send::Param&    param, Send::Result&    result) = 0;
            virtual void receive (quint16 transaction, const Receive::Param& param, Receive::Result& result) = 0;
            virtual void cancel  (quint16 transaction, const Cancel::Param&  param, Cancel::Result&  result) = 0;

            bool        isProcedureValid    (int code);
            const char* getProcedureName    (int code);
            void        service             (const CallMessage& callMessage, Block& request, Block& response);

        private:
            void callSend    (const CallMessage& callMessage, Block& request, Block& response);
            void callReceive (const CallMessage& callMessage, Block& request, Block& response);
            void callCancel  (const CallMessage& callMessage, Block& request, Block& response);
        };
    }
}
#endif
