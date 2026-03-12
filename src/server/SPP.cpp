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
#include <utility>
#include <vector>

#include "../util/Debug.h"
#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/SPP.h"

#include "../service/Services.h"

#include "Server.h"
#include "SPP.h"

namespace server::SPP {
//

//
// Connections
//
static Connections connections;
static std::mutex  mutex;


void Connections::maintain() {
    std::lock_guard<std::mutex>lock (mutex);

    auto now = Util::getSecondsSinceEpoch();
    auto pred = [&](auto& o) { return o.second.expired(now); };
    std::erase_if(map, pred);
}
Connection& Connections::allocate(uint16_t srcSocket, const xns::SPP& rxHeader) {
    maintain();
    std::lock_guard<std::mutex>lock (mutex);

    Connection connection{srcSocket, srcSocket, rxHeader};

    auto key = getKey(connection);
    map.emplace(key, connection);
//    logger.info("allocate  %08X  %s", key, connection.toString());

    auto& ret = map[key];
    return ret;
}
void Connections::free(uint32_t key) {
    std::lock_guard<std::mutex>lock (mutex);

    auto pred = [&](auto& o){return o.first == key;};
    std::erase_if(map, pred);
}
bool Connections::contains(uint32_t key) {
    maintain();
    return map.contains(key);
}
Connection& Connections::get(uint32_t key) {
    maintain();
    auto i = map.find(key);
    if (i != map.end()) {
        auto& ret = i->second;
        return ret;
    }

    logger.error("Unexpected spp");
    logger.error("  key       %08X", key);
    logger.error("  existing connections  %d", connections.size());
    for(auto& e: map) {
        logger.error("  %08X  %s", e.first, e.second.toString());
    }
    ERROR()
}

void Connections::update(const xns::SPP& rxHeader) {
    auto key = getKey(rxHeader);
    auto i = map.find(key);
    auto& connection = i->second;
    if (i != map.end()) {
        connection.expirationTime = Connection::nextExpirationTime();
        connection.rxseq          = rxHeader.seq;
        connection.rxack          = rxHeader.ack;
        connection.rxalloc        = rxHeader.alloc;
        return;
    }

    logger.error("Unexpected spp");
    logger.error("  key       %08X", key);
    logger.error("  rxHeader  %s", rxHeader.toString());
    logger.error("  existing connections");
    for(auto& e: map) {
        logger.error("  %08X  %s", e.first, e.second.toString());
    }
    ERROR()
}


//
// Listener
//
static std::unordered_map<uint16_t, Listener> listenerMap;
void listen(uint16_t socket, Listener listener) {
    if (listenerMap.contains(socket)) {
        ERROR()
    } else {
        listenerMap[socket] = listener;
    }
}
void unlisten(uint16_t socket) {
    if (listenerMap.contains(socket)) {
        listenerMap.erase(socket);
    } else {
        ERROR()
    }
}


//
// processXXX
//
void processNew(Session& session, const xns::SPP& rxHeader, ByteBuffer& rxbb, Listener listener) {
    (void)listener;
    // sanity check
    if (!rxHeader.systemPacket()) {
        logger.warn("Unexpected NOT system packet");
        return;
    }
    if (!rxbb.empty()) {
        logger.warn("Unexpected rxbb is not empty");
        return;
    }

    auto srcSocket = allocateSocket();
    auto connection = connections.allocate(srcSocket, rxHeader);
    logger.info("NEW  CONNECTION  %d  %s", connections.map.size(), connection.toString());

    // set socket to txHeader.src.socket to redirect
    session.rxIDP.dst.socket = static_cast<xns::Socket>(srcSocket);

    // add listener
    server::listen(srcSocket, listenerCOURIER);
    server::SPP::listen(srcSocket, server::SPP::listenerSPP);

    xns::SPP txHeader;
    txHeader.systemPacket(true);
    txHeader.sendAck(true);
    txHeader.srcID = connection.srcID;
    txHeader.dstID = connection.dstID;
    txHeader.seq   = connection.txseq;
    txHeader.ack   = connection.txack;
    txHeader.alloc = connection.txalloc;

    session.send(txHeader);
}

void processOldConnectionNew(Connection& connection, Session& session, const xns::SPP& rxHeader, ByteBuffer& rxbb, Listener listener) {
    (void)listener;
    (void)rxbb;

    // process system packet
    if (rxHeader.systemPacket()) {
        connection.state = Connection::State::DATA;

        logger.info("OPEN CONNECTION  %d  %s", connections.map.size(), connection.toString());


        xns::SPP txHeader;
        txHeader.systemPacket(true);
        txHeader.srcID = connection.srcID;
        txHeader.dstID = connection.dstID;
        txHeader.seq   = connection.txseq;
        txHeader.ack   = connection.txack;
        txHeader.alloc = connection.txalloc;

        session.send(txHeader);
        return;
    }
    logger.warn("Unexpected");
}

void processClose(Connection& connection, Session& session, const xns::SPP& rxHeader, ByteBuffer& rxbb, Listener listener) {
    (void)listener;
    (void)connection; (void)session; (void)rxHeader; (void)rxbb;
    logger.info("## Close");

    connection.state = Connection::State::CLOSING;
    xns::SPP txHeader;
    txHeader.sendAck(true);
    txHeader.sst = xns::SPP::SST::CLOSE_REPLY;
    txHeader.srcID = connection.srcID;
    txHeader.dstID = connection.dstID;
    txHeader.seq   = connection.txseq++;
    txHeader.ack   = ++connection.txack;
    txHeader.alloc = ++connection.txalloc;

    session.send(txHeader);
    return;
}
void processCloseReply(Connection& connection, Session& session, const xns::SPP& rxHeader, ByteBuffer& rxbb, Listener listener) {
    (void)listener;
    (void)connection; (void)session; (void)rxHeader; (void)rxbb;
    logger.info("## CloseReply");

    // xns::SPP txHeader;
    // txHeader.sendAck(true);
    // txHeader.sst = xns::SPP::SST::CLOSE_REPLY;
    // txHeader.srcID = connection.srcID;
    // txHeader.dstID = connection.dstID;
    // txHeader.seq   = connection.txseq++;
    // txHeader.ack   = ++connection.txack;
    // txHeader.alloc = ++connection.txalloc;

    // session.send(txHeader);
}
void processData(Connection& connection, Session& session, const xns::SPP& rxHeader, ByteBuffer& rxbb, Listener listener) {
    (void)listener;
    // check duplicate
    if (rxHeader.seq == connection.txack) {
        // process user data
        CallContext callContext{session, connection};
        auto tx = service::services.callExpeditedMessage(callContext, rxbb);
        // increment txack and txalloc
        connection.txack = connection.txalloc = rxHeader.seq + 1;
        // send result
    } else {
        // Igore other packet
        logger.info("## Ignore packet");
    }
}
void processBulk(Connection& connection, Session& session, const xns::SPP& rxHeader, ByteBuffer& rxbb, Listener listener) {
    (void)listener;
    (void)connection; (void)session; (void)rxHeader; (void)rxbb;
    logger.info("## BULK");
}

void listenerSPP  (Session& session, const ByteBuffer& rx) {
    xns::SPP rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto socket = std::to_underlying(session.rxIDP.dst.socket);
    if (!listenerMap.contains(socket)) {
        logger.warn("Unknown socket  %d", socket);
        return;
    }
    auto& listener = listenerMap[socket];

    if (connections.contains(Connections::getKey(rxHeader))) {
        auto& connection = connections.get(Connections::getKey(rxHeader));
        connection.updateExpirationTime();

        if (rxHeader.systemPacket()) {
            if (rxHeader.sendAck()) {
                xns::SPP txHeader;
                txHeader.systemPacket(true);
                txHeader.srcID = connection.srcID;
                txHeader.dstID = connection.dstID;
                txHeader.seq   = connection.txseq;
                txHeader.ack   = connection.txack;
                txHeader.alloc = connection.txalloc;
        
                session.send(txHeader);
            }
            return;
        }
        
        switch(rxHeader.sst) {
        case xns::SPP::SST::CLOSE:
            processClose(connection, session, rxHeader, rxbb, listener);
            break;
        case xns::SPP::SST::CLOSE_REPLY:
            processCloseReply(connection, session, rxHeader, rxbb, listener);
            break;
        case xns::SPP::SST::DATA:
            processData(connection, session, rxHeader, rxbb, listener);
            break;
        case xns::SPP::SST::BULK:
            processBulk(connection, session, rxHeader, rxbb, listener);
            break;
        default:
            ERROR()
        }
    } else {
        processNew(session, rxHeader, rxbb, listener);
    }
}

}