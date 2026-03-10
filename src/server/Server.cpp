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


#include <mutex>
#include <string>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../service/Services.h"

#include "Server.h"

namespace server {
//

static Context* context = 0;

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

uint16_t Context::allocateSocket() {
    std::lock_guard<std::mutex> lock{mutex};

    uint16_t newSocket = std::chrono::system_clock::now().time_since_epoch().count() >> 10;

    for(;;) {
        if (newSocket < xns::MAX_WELLKNOWN_SOCKET) {
            newSocket += xns::MAX_WELLKNOWN_SOCKET;
        }
        if (!activeSocketSet.contains(newSocket)) break;
        newSocket++;
    }
    activeSocketSet.emplace(newSocket);

    return newSocket;
}
void Context::freeSocket(uint16_t value) {
    std::lock_guard<std::mutex> lock{mutex};

    auto count = activeSocketSet.erase(value);
    if (count == 0) {
        logger.error("Unexpected value");
        logger.error("  value  %d", value);
        ERROR()
    }
}


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
        xns::RIP::toString(value.delay));
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

ByteBuffer callExpeditedMessage(Session& session, ByteBuffer& rx) {
    auto tx = service::services.callExpeditedMessage(session, rx);
    return tx;
}
ByteBuffer callCourierMessage(Session& session, ByteBuffer& rx) {
    auto tx = service::services.callCourierMessage(session, rx);
    return tx;
}

//
// Session
//

void Session::sendEther(const ByteBuffer& bb) {
    // make reference
    xns::Ethernet txEthernet;

    txEthernet.dest   = rxEthernet.source;
    txEthernet.source = context.me;
    txEthernet.type   = rxEthernet.type;

    auto tx = getByteBuffer();
    // write ethernet header
    tx.write(txEthernet);
    tx.write(bb);

    // add padding for mininum packet size
    auto length = tx.byteLimit();
    for(uint32_t i = length; i < MIN_PACKET_SIZE; i++) tx.put8(0);

    if constexpr (SHOW_RESPONSE_DURATION) {
        logger.info("Duration  %d", durationMilli());
    }
    if constexpr (SHOW_PACKET_ETHERNET) {
        logger.info("ETH  <<  %s  (%d) %s", toString(txEthernet), bb.byteLimit(), bb.toString());
    }

    TransmitData transmitData(tx);
    threadTransmit.push(transmitData);
}

void Session::sendIDP(const ByteBuffer& txbb) {
    xns::IDP txHeader;

    txHeader.checksum    = xns::IDP::Checksum::NOCHECK;
    txHeader.length      = xns::IDP::HEADER_LENGTH_IN_BYTE + txbb.byteLimit();
    txHeader.control     = 0;
    txHeader.packetType  = rxIDP.packetType;
    txHeader.dst.network = rxIDP.src.network;
    txHeader.dst.host    = rxIDP.src.host;
    txHeader.dst.socket  = rxIDP.src.socket;
    txHeader.src.network = context.net;
    txHeader.src.host    = context.me;
    txHeader.src.socket  = rxIDP.dst.socket;

    auto tx = getByteBuffer();
    tx.write(txHeader);
    tx.write(txbb);
    // to make even length data, add Garbage Byte if length is odd.
    if (tx.byteLimit() & 1) tx.put8(0);

    // update checksum
    // Garbage Byte, which is included in the Checksum, but not in the Length
    auto checksum = xns::IDP::computeChecksum(tx.data(), 2, tx.byteLimit());
    tx.rewind();
    tx.write(checksum);

    txHeader.checksum = checksum;
    if constexpr (SHOW_PACKET_IDP) logger.info("IDP  <<  %s  (%d) %s", toString(txHeader), txbb.byteLimit(), txbb.toString());

    sendEther(tx);
}

void Session::sendError(xns::Error::ErrorNumber errorNumber, uint16_t errorParameter) {
    xns::Error txHeader{errorNumber, errorParameter};

    auto tx = getByteBuffer();
    tx.write(txHeader, rxIDP);

    if constexpr (SHOW_PACKET_ERROR) logger.info("Error<<  %s  IDP  %s", txHeader.toString(), rxIDP.toString());

    sendIDP(tx);
}

}