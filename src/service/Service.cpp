/*******************************************************************************
 * Copyright (c) 2026, Yasuhiro Hasegawa
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

//
// Service.cpp
//

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../courier/Courier3.h"

#include "Services.h"
#include "Service.h"


namespace service {
//
using namespace courier::Courier3;

ByteBuffer ServicesBase::callExpedited(const ByteBuffer& rx) {
    ProtocolRange protocolRange;
    rx.read(protocolRange);

    if (SupportingProtol < protocolRange.lowest || protocolRange.highest < SupportingProtol) {
        logger.warn("Unpexpected protolRange  %d  %d", protocolRange.lowest, protocolRange.highest);
        return getByteBuffer();
    }

    return call(rx);
}

ByteBuffer ServicesBase::call(const ByteBuffer& rx) {
    Message message;
    rx.read(message);

    const auto callMessage    = message.toCall();
    const auto transasionID   = callMessage.transactionID;
    const auto programNumber  = callMessage.programNumber;
    const auto versionNumber  = callMessage.versionNumber;
    const auto procedureValue = callMessage.procedureValue;

    try {
        logger.info("COURIER %04X  %d  %d  %d", transactionID, programNumber, versionNumber, procedureValue);
    
        if (message.key != Message::Key::call) {
            logger.warn("Unpexpected message key  %d  %d", message.toString());
            throw UnspecifiedReject{};
        }
    
        // sanity check
        auto service = services.getService(program, version);
        if (service == 0) {
            auto serviceList = services.getService(program);
            if (serviceList.empty()) {
                throw NoSuchProgramNumberReject{};
            } else {
                VersionRange versionRange{serviceList[0]->version, serviceList[0]->version};
                auto& high = versionRange.highest;
                auto& low  = versionRange.lowest;
                for(auto& e: serviceList) {
                    auto version = e->version;
                    if (high < version) high = version;
                    if (version < low)  low  = version;
                }
                throw NoSuchVersionNumber{versionRange};
            }
        }
        auto proc = service->getProcedure(procedure);
        if (proc == 0) {
            throw NoSuchProcedureValue{};
        }
    
        logger.info("CALL    %04X  %s  %s", transactionID, service->name, proc->name);
        if (proc->hasFunction()) {
            logger.info("no fuunction installed  %s  %s", service->name, proc->name);
            auto tx = getByteBuffer();
            // DO NOTHING
            return tx;
        }
        
        // Return
        ReturnMessage returnMessage{transacionID};
        auto replyMessage = Message::fromReturn(returnMessage);
        auto result = proc->call(rx);

        logger.info("RETURN  %04X  %s  %s", transactionID, service->name, proc->name);

        auto tx = getByteBuffer();
        tx.write(returnMessage)
        tx.write(result);
        return tx;
    } catch (const ErrorBase& errorBase) {
        // Abort
        logger.info("ABORT   %04X  %d  %s", transactionID, errorBase.value, errorBase.name);
        AbortMessage abortMssage{transactionID, errorBase.number};
        auto replyMessage = Message::fromAbort(abortMessage)

        auto tx = getByteBuffer();
        tx.write(replyMessage);
        tx.write(errorBase);
        return tx;
    } catch (const RejectBase& rejectBase) {
        // Reject
        logger.info("REJECT  %04X  %d  %s", transactionID, rejectBase.value, rejectBase.name);
        RejectMessage rejectMessage{transactionID, rejectBase.toRejectDetail()};
        auto replyMessage = Message::fromReject(rejectMessage);

        auto tx = getByteBuffer();
        tx.write(replyMessage);
        return tx;
    }
}

ByteBuffer returnReject(const RejectBase reject) {
    var a = reject.toRejectDetail();

    auto rejectMessage = RejectMessage::RejectDetails::getNoSuchProgramNumber();

    auto message = Message::getReject(rejectMessage);

}

}
