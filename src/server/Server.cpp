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
 // Server.cpp
 //


#include <cstdint>
#include <mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../xns/Error.h"

#include "../service/Services.h"

#include "Server.h"
#include "Session.h"

namespace server {
//

// context is used in toString()
static Context* context = 0;

//
// Context
//
Context::Context() {
    courier = courier::Config::getInstance();
    config = Config::getInstance();
    auto device = net::getDevice(config.server.interface);
    driver = net::getDriver(device);
    // delieved values
    me     = config.server.address;
    net    = static_cast<Network>(config.server.net);
    // build routingMap
    for(const auto& e: config.net) {
        auto net = static_cast<Network>(e.net);
        auto delay = static_cast<Delay>(e.delay);

        if (delay == Delay::INFINITY) continue;
        Routing routing(net, delay, e.name);
        routingMap[net] = routing;
    }
    // build networdkNameMap
    for(const auto& e: config.net) {
        networkNameMap[e.net] = e.name;
    }
    // build hostNameMap
    for(const auto& e: config.host) {
        hostNameMap[e.address] = e.name;
    }
    // set static uglobal variable context
    context = this;
}


//
// Listener
//
static std::unordered_map<uint16_t, Listener> listenerMap;
void listen(uint16_t socket, Listener listener) {
    if (listenerMap.contains(socket)) {
        logger.error("Unexpected socket");
        logger.error("  socket  %d", socket);
        ERROR()
    }
    listenerMap[socket] = listener;
}
void unlisten(uint16_t value) {
    auto count = listenerMap.erase(value);
    if (count == 0) {
        logger.error("Unexpected value");
        logger.error("  value  %d", value);
        ERROR()
    }
}


void processEthernet(Session& session, ByteBuffer& rx) {
    // makre reference
    auto& context(session.context);
    auto& ethernetHeader(session.rxEthernet);
    auto& idpHeader(session.rxIDP);

    ByteBuffer ethenetBody;
    rx.read(ethernetHeader, ethenetBody);

    bool myPacket = false;
    if (ethernetHeader.type == xns::Ethernet::Type::XNS) {
        if (ethernetHeader.source == context.me) {
            // NOT myPacket
        } else {
            if (ethernetHeader.dest.isBroadcas() || ethernetHeader.dest == context.me) {
                myPacket = true;
            }
        }
    }
    if (!myPacket) return;

    if constexpr (SHOW_PACKET_ETHERNET) logger.info("ETH  >>  %s  (%d) %s", toString(ethernetHeader), ethenetBody.byteLimit(), ethenetBody.toString());

    ethenetBody.read(idpHeader);
    auto idpBody = ethenetBody.byteRange(xns::IDP::HEADER_LENGTH_IN_BYTE, idpHeader.length - xns::IDP::HEADER_LENGTH_IN_BYTE);
    if constexpr (SHOW_PACKET_IDP) logger.info("IDP  >>  %s  (%d) %s", toString(idpHeader), idpBody.byteLimit(), idpBody.toString());

    // sanity check
    if (idpHeader.checksum != xns::IDP::Checksum::NOCHECK) {
        auto checksum = xns::IDP::computeChecksum(ethenetBody.data(), 2, idpHeader.length);
        if (idpHeader.checksum != checksum) {
            logger.warn("checksum error  %s  %s", xns::IDP::toString(idpHeader.checksum), xns::IDP::toString(checksum));
            // FIXME send Error packet
            session.sendError(xns::Error::ErrorNumber::BAD_CHECKSUM);
            return;
        }
    }

    auto socket = std::to_underlying(idpHeader.dst.socket);
    if (listenerMap.contains(socket)) {
        listenerMap[socket](session, idpBody);
    } else {
        logger.warn("Unknown socket  %d", socket);
    }
}


//
// Socket
//
static std::mutex socketSetMutex;
static std::unordered_set<uint16_t> socketSet;
uint16_t allocateSocket() {
    std::lock_guard<std::mutex> lock{socketSetMutex};

    uint16_t newSocket = std::chrono::system_clock::now().time_since_epoch().count() >> 10;
    for(;;) {
        if (newSocket < xns::MAX_WELLKNOWN_SOCKET) {
            newSocket += xns::MAX_WELLKNOWN_SOCKET;
        }
        if (!socketSet.contains(newSocket)) break;
        newSocket++;
    }
    socketSet.emplace(newSocket);

    return newSocket;
}
void freeSocket(uint16_t value) {
    std::lock_guard<std::mutex> lock{socketSetMutex};

    auto count = socketSet.erase(value);
    if (count == 0) {
        logger.error("Unexpected value");
        logger.error("  value  %d", value);
        ERROR()
    }
}


ByteBuffer callExpeditedMessage(CallContext& callContext, ByteBuffer& rx) {
    auto tx = service::services.callExpeditedMessage(callContext, rx);
    return tx;
}
ByteBuffer callCourierMessage(CallContext& callContext, ByteBuffer& rx) {
    auto tx = service::services.callCourierMessage(callContext, rx);
    return tx;
}


//
// toString()
//
std::string toStringNetwork(uint32_t value) {
    if (context == 0) ERROR()
    auto& map = context->networkNameMap;
    return map.contains(value) ? map[value] : std_sprintf("%08X", value);
}
std::string toStringHost(uint64_t value) {
    if (context == 0) ERROR()
    auto& map = context->hostNameMap;
    return map.contains(value) ? map[value] : net::toHexaDecimalString(value);
}

std::string toString(const xns::Ethernet& value) {
    return std_sprintf("{%s  %s  %s}",
        toStringHost(value.dest),
        toStringHost(value.source),
        xns::Ethernet::toString(value.type));
}

static std::string toString(const xns::RIP::Entry& value) {
    return std_sprintf("{%s  %s}",
        toStringNetwork(value.network),
        ::toString(value.delay));
}
std::string toString(const xns::RIP& value) {
    std::string string;
    for(const auto& e: value.entryList) {
        string += std_sprintf(" %s", toString(e));
    }
    return std_sprintf("{%-8s  (%d) %s}",
        xns::toString(value.operation),
        value.entryList.size(),
        string.empty() ? "" : string.substr(1));
}

static std::string toString(const xns::NetworkAddress& value) {
    return std_sprintf("%s-%s-%s",
        toStringNetwork(value.network),
        toStringHost(value.host),
        xns::toString(value.socket));
}
std::string toString(const xns::IDP& value) {
    return std_sprintf("{%s  %d  %d  %s  %s  %s}",
        xns::IDP::toString(value.checksum),
        value.length,
        value.control,
        xns::IDP::toString(value.packetType),
        toString(value.dst), toString(value.src));    
}

}