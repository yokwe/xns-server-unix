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
static Connections connections;
static std::mutex  mutex;


void Connections::maintain() {
    std::lock_guard<std::mutex>lock (mutex);

    auto now = Util::getSecondsSinceEpoch();
    auto pred = [&](Connection& o) { return o.expired(now); };
    
   std::erase_if(list, pred);
}
Connection Connections::allocate(Context& context, uint16_t dstID) {
    maintain();
    std::lock_guard<std::mutex>lock (mutex);

    uint16_t socket = context.allocateSocket();
    uint16_t srcID = nextSrcID++;
    Connection connection{socket, srcID, dstID};

    list.push_back(connection);
    return connection;
}
void Connections::free(uint16_t srcID) {
    std::lock_guard<std::mutex>lock (mutex);

    std::erase_if(list, [&](Connection& o){return o.srcID == srcID;});
}
bool Connections::contains(uint16_t srcID) {
    maintain();
    for(const auto& e: list) {
        if (e.srcID == srcID) return true;
    }
    return false;
}
Connection Connections::get(uint16_t srcID) {
    maintain();
    for(const auto& e: list) {
        if (e.srcID == srcID) return e;
    }
    logger.error("Unexpected srcID");
    logger.error("  srcID  %d", srcID);
    ERROR()
}

void Connections::update(const xns::SPP& spp) {
    uint16_t srcID = spp.srcID;

    for(auto& e: list) {
        if (e.srcID == srcID) {
            e.state          = Connection::State::ESTABLISHED;
            e.expirationTime = Connection::nextExpirationTime();
            e.seq            = spp.seq;
            e.ack            = spp.ack;
            e.alloc          = spp.alloc;
            return;
        }
    }
    logger.error("Unexpected value");
    logger.error("  spp  %d", spp.toString());
    ERROR()
}

using SPP   = xns::SPP;

void processCourierSocket(Session& session, ByteBuffer& rx) {
    SPP rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto tx = getByteBuffer();

    if (!rxHeader.systemPacket()) {
        logger.info("Unexpected NOT system packet");
        return;
    }

    if (connections.contains(rxHeader.dstID)) {
        logger.info("Unexpected srcID in sessions");
        return;
    }

    auto connection = connections.allocate(session.context, rxHeader.srcID);
    logger.info("NEW SESSION  %d  %04X  %d", connection.socket, connection.srcID, connections.list.size());
    // update IDP dst.socket for new session
    session.rxIDP.dst.socket = static_cast<xns::Socket>(connection.socket);
    
    SPP txHeader;
    txHeader.systemPacket(true);
    txHeader.sendAck(true);
    txHeader.srcID = connection.srcID;
    txHeader.dstID = connection.dstID;
    txHeader.seq = 0;
    txHeader.ack = 0;
    txHeader.alloc = 1;

    tx.write(txHeader);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  <<  %s", txHeader.toString());

    session.sendIDP(tx);
}

void processClientSocket(Session& session, const ByteBuffer& rx) {
    SPP rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto tx = getByteBuffer();

    if (!connections.contains(rxHeader.dstID)) {
        logger.info("Unexpected dstID not in sessions  %04X  %", rxHeader.dstID, connections.list.size());
        return;
    }

    auto connection = connections.get(rxHeader.dstID);

    SPP txHeader;
    txHeader.srcID = connection.srcID;
    txHeader.dstID = connection.dstID;
    txHeader.seq   = connection.seq;
    txHeader.ack   = connection.ack;
    txHeader.alloc = connection.alloc;

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
        auto txbb = callExpeditedMessage(session, rxbb);
        tx.write(txHeader);
        tx.write(txbb);
    }
    session.sendIDP(tx);
}

void process  (Session& session, ByteBuffer& rx) {
    if (session.rxIDP.dst.socket == xns::Socket::COURIER) {
        processCourierSocket(session, rx);
    } else {
        processClientSocket(session, rx);
    }
}

}