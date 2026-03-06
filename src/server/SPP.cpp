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
 // SPP.cpp
 //

#include <mutex>
#include <vector>

#include "../util/Debug.h"
#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

#include "Server.h"
#include "SPP.h"

namespace server::SPP {
//
static uint16_t nextSrcID = 1;

//
// Sessions
//
static Sessions   sessions;
static std::mutex mutex;


void Sessions::maintain() {
    std::lock_guard<std::mutex>lock (mutex);

    auto now = Util::getSecondsSinceEpoch();
    auto pred = [&](Session& o) { return o.endingTime < now; };
    
   std::erase_if(sessionList, pred);
}
Session Sessions::allocate(Context& context, uint16_t dstID) {
    maintain();
    std::lock_guard<std::mutex>lock (mutex);

    uint16_t socket = context.allocateSocket();
    uint16_t srcID = nextSrcID++;
    Session session{socket, srcID, dstID};

    sessionList.push_back(session);
    return session;
}
void Sessions::free(uint16_t srcID) {
    std::lock_guard<std::mutex>lock (mutex);

    std::erase_if(sessionList, [&](Session& o){return o.srcID == srcID;});
}
bool Sessions::contains(uint16_t srcID) {
    maintain();
    for(const auto& e: sessionList) {
        if (e.srcID == srcID) return true;
    }
    return false;
}
Session Sessions::get(uint16_t srcID) {
    maintain();
    for(const auto& e: sessionList) {
        if (e.srcID == srcID) return e;
    }
    logger.error("Unexpected srcID");
    logger.error("  srcID  %d", srcID);
    ERROR()
}

void Sessions::update(const xns::SPP& spp) {
    uint16_t srcID = spp.srcID;

    for(auto& e: sessionList) {
        if (e.srcID == srcID) {
            e.state      = Session::State::ESTABLISHED;
            e.endingTime = Util::getSecondsSinceEpoch() + GRACE_PERIOD_EXPIRATION;
            e.seq        = spp.seq;
            e.ack        = spp.ack;
            e.alloc      = spp.alloc;
            return;
        }
    }
    logger.error("Unexpected value");
    logger.error("  spp  %d", spp.toString());
    ERROR()
}

using SPP   = xns::SPP;

void processCourierSocket(ByteBuffer& rx, Context& context, Response& response) {
    SPP rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto tx = getByteBuffer();

    if (!rxHeader.systemPacket()) {
        logger.info("Unexpected NOT system packet");
        return;
    }

    if (sessions.contains(rxHeader.dstID)) {
        logger.info("Unexpected srcID in sessions");
        return;
    }

    auto session = sessions.allocate(context, rxHeader.srcID);
    logger.info("NEW SESSION  %d  %04X  %d", session.socket, session.srcID, sessions.sessionList.size());
    // update IDP dst.socket for new session
    response.rxIDP.dst.socket = static_cast<xns::Socket>(session.socket);
    
    SPP txHeader;
    txHeader.systemPacket(true);
    txHeader.sendAck(true);
    txHeader.srcID = session.srcID;
    txHeader.dstID = session.dstID;
    txHeader.seq = 0;
    txHeader.ack = 0;
    txHeader.alloc = 1;

    tx.write(txHeader);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  <<  %s", txHeader.toString());

    response.transmitAsIDP(tx, context);
}

void processClientSocket(ByteBuffer& rx, Context& context, Response& response) {
    SPP rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto tx = getByteBuffer();

    if (!sessions.contains(rxHeader.dstID)) {
        logger.info("Unexpected dstID not in sessions  %04X  %", rxHeader.dstID, sessions.sessionList.size());
        return;
    }

    auto session = sessions.get(rxHeader.dstID);

    SPP txHeader;
    txHeader.srcID = session.srcID;
    txHeader.dstID = session.dstID;
    txHeader.seq   = session.seq;
    txHeader.ack   = session.ack;
    txHeader.alloc = session.alloc;

    if (rxHeader.systemPacket()) {
        if (rxHeader.sendAck()) {
            // FIXME
            txHeader.systemPacket(true);
            tx.write(txHeader);
        } else {
            logger.info("Unexpected system packet");
            // FIXME
        }
    } else {
        // FIXME
        auto txbb = callExpeditedMessage(rxbb, context, response);
        tx.write(txHeader);
        tx.write(txbb);
    }
    response.transmitAsIDP(tx, context);
}

void process  (ByteBuffer& rx, Context& context, Response& response) {
    if (response.rxIDP.dst.socket == xns::Socket::COURIER) {
        processCourierSocket(rx, context, response);
    } else {
        processClientSocket(rx, context, response);
    }
}

}