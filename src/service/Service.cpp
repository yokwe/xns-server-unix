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

    // FIXME
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

    if (message.key != Message::Key::call) {
        logger.warn("Unpexpected message key  %d  %d", message.toString());
        return getByteBuffer();
    }

    auto callMessage = message.toCall();
    auto program = callMessage.programNumber;
    auto version = callMessage.versionNumber;
    auto procedure = callMessage.procedureValue;

    auto service = services.getService(program, version);
    if (service == 0) {
        auto serviceList = services.getService(program);
        if (serviceList.empty()) {
            RejectMessage rejectMessage;
            rejectMessage.transactionID = callMessage.transactionID;
            rejectMessage.rejectDetails = RejectMessage::RejectDetails::getNoSuchProgramNumber();

            auto replyMessage = Message::getReject(rejectMessage);

            auto tx = getByteBuffer();
            tx.write(replyMessage);
            return tx;
        } else {
            uint16_t high = 0;
            uint16_t low = 0;
            for(auto& e: serviceList) {
                auto version = e->version;
                if (high == 0) high = version;
                if (low == 0) low   = version;
                if (high < version) high = version;
                if (version < low) low = version;
            }

            VersionRange versionRange{low, high};
            
            RejectMessage rejectMessage;
            rejectMessage.transactionID = callMessage.transactionID;
            rejectMessage.rejectDetails = RejectMessage::RejectDetails::getNoSuchVersionNumber(versionRange);

            auto replyMessage = Message::getReject(rejectMessage);

            auto tx = getByteBuffer();
            tx.write(replyMessage);
            return tx;
        }
    }
    auto proc = service->getProcedure(procedure);
    if (proc == 0) {
        RejectMessage rejectMessage{callMessage.transactionID, RejectMessage::RejectDetails::getNoSuchProcedureValue()};

        auto replyMessage = Message::getReject(rejectMessage);

        auto tx = getByteBuffer();
        tx.write(replyMessage);
        return tx;
    }

    logger.info("call  %s  %s", service->name, proc->name);
    if (proc->hasFunction()) {
        logger.info("no fuunction installed  %s  %s", service->name, proc->name);
        auto tx = getByteBuffer();
        return tx;
    }

    try {
        auto tx = proc->call(rx);
        return tx;
    } catch (const ErrorBase& errorBase) {
        // return Error
        auto tx = getByteBuffer();
        // FIXME
        return tx;
    } catch (const RejectBase& rejectBase) {
        // return reject
        auto tx = getByteBuffer();
        // FIXME
        return tx;
    }
}

ByteBuffer returnReject(const RejectBase reject) {
    var a = reject.toRejectDetail();

    auto rejectMessage = RejectMessage::RejectDetails::getNoSuchProgramNumber();

    auto message = Message::getReject(rejectMessage);

}

}
