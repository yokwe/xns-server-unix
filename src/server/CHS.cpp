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
 // CHS.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "SPP.h"

#include "../xns/XNS.h"
#include "../service/Clearinghouse3.h"
#include "../service/Services.h"

#include "Server.h"

namespace server {
//
static void listenerCHS_PEX(Session& session, ByteBuffer& rx);
static void listenerCHS_SPP(Session& session, ByteBuffer& rx);

void listenerCHS  (Session& session, ByteBuffer& rx) {
    switch(session.rxIDP.packetType) {
    case xns::IDP::PacketType::PEX:
        listenerCHS_PEX(session, rx);
        break;
    case xns::IDP::PacketType::SPP:
        listenerCHS_SPP(session, rx);
        break;
    default:
        ERROR()
    }
}

static void listenerCHS_PEX(Session& session, ByteBuffer& rx) {
    xns::PEX&  pexHeader(session.rxPEX);
    ByteBuffer pexBody;

    rx.read(pexHeader, pexBody);
    if constexpr (SHOW_PACKET_PEX)  logger.info("PEX  >>  %s  (%d) %s", pexHeader.toString(), pexBody.byteLimit(), pexBody.toString());

    SPP::Connection connection;
    CallContext callContext{session, connection};
    auto tx = service::services.callExpeditedMessage(callContext, pexBody);
    if (tx.empty()) return;

    session.sendPEX(tx);
}
static void listenerCHS_SPP(Session& session, ByteBuffer& rx) {
    xns::SPP&  sppHeader(session.rxSPP);
    ByteBuffer sppBody;

    rx.read(sppHeader, sppBody);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", sppHeader.toString(), sppBody.byteLimit(), sppBody.toString());

    // FIXME
}





server::Context* context;

using namespace courier::Clearinghouse3;

RetrieveAddresses::Result RetrieveAddres(CallContext&) {
    logger.info("%s", __func__);

    auto host = xns::Host(context->me);
    NetworkAddress networkAddress = {context->net, host, xns::Socket::CHS};
    NetworkAddressList list{networkAddress};
    RetrieveAddresses::Result result = {list};

    logger.info("%s  %s", __func__, list.toString());

    return result;
}

void ListDomainServed(CallContext& callContext, courier::Clearinghouse3::ListDomainServed::Argument argument) {
    logger.info("%s  argument %s", __func__, argument.toString());
    if (argument.domains.key == courier::BulkData1::Descriptor::Key::immediate) {
        // return data as bulk data
        DomainName myDomain{"FXIS", "Fuji Xerox"};
        courier::SEQUENCE<DomainName, 65535> segment = {
            {myDomain},
        };
        auto ret = StreamOfDomainName::fromLastSegment(segment);


        auto txbb = getByteBuffer();
        txbb.write(ret);

        auto& session = callContext.session;
        auto& connection = callContext.connection;

        {
            xns::SPP txHeader;
            txHeader.sendAck(true);
            txHeader.endOfMessage(true);
            txHeader.sst   = xns::SPP::SST::BULK;
            txHeader.srcID = connection.srcID;
            txHeader.dstID = connection.dstID;
            txHeader.seq   = connection.txseq++;
            txHeader.ack   = ++connection.txack;
            txHeader.alloc = ++connection.txalloc;
    
            session.send(txHeader, txbb);
        }

    } else {
        logger.error("Not expected");
        ERROR()
    }
}

service::Clearinghouse3::FunctionTable functionTable {
    RetrieveAddres,
    ListDomainServed,
};


void init(server::Context& context_) {
    context = &context_;

    service::services.clearinghouse3.set(functionTable);
}

}
