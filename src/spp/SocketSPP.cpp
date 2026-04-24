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
 // SocketSPP.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../server/SocketManager.h"

#include "Connection.h"

#include "SocketSPP.h"

namespace spp {
//

//
// SocketSPPClient
//
void SocketSPPClient::process(Session& session, ByteBuffer&rx) {
    // sanity check
    if (session.rxIDP.packetType != xns::IDP::PacketType::SPP) ERROR()

    xns::SPP   rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto sst = rxHeader.sst;
    logger.info("SPP  %s  %04X  %s  %s", xns::toString(connection.socket), rxHeader.seq, toString(connection.state), xns::SPP::toString(sst));

    // create alias of connection->state;
    auto& state = connection.state;

    if (state == State::OPENING) {
        if (rxHeader.seq == 0 && rxHeader.dstID != 0) {
            // connection is esablished
            state = State::OPEN;
            stopAt(STOP_AT_NEVER());
        } else {
            ERROR()
        }
    }

    if (sst == SST::CLOSE) {
        if (state == State::OPEN) {
            state = State::CLOSING;
            connection.receiveQueue.clear();
            connection.retransmitQueue.clear();
            // increment ack and alloc
            connection.txRange++;
        } else if (state == State::CLOSING) {
            // OK
        } else {
            ERROR();
        }
        // send close
        connection.transmitClose();
    } else if (sst == SST::CLOSE_REPLY) {
        if (state == State::CLOSING) {
            state = State::CLOSE;
            connection.retransmitQueue.clear();
            connection.receiveQueue.clear();
            // increment seq
            connection.seq++;
            // increment ack and alloc
            connection.txRange++;
            // stop after CLOSING_TIMEOUT from now
            stopAt(CLOSING_TIMEOUT);
        } else if (state == State::CLOSE) {
            // OK
        } else {
            ERROR();
        }

        // send close reply
        connection.transmitCloseReply();
    } else {
        if ((state == State::CLOSE || state == State::CLOSING) && !rxHeader.system()) {
            // Unexpected situation
            logger.info("SSP  %s  %s  UNEXPECTED state", xns::toString(connection.socket), xns::SPP::toString(sst));
            stopAt(STOP_AT_NOW());
        } else {
            connection.receive(rxHeader, rxbb);
        }
    }
}

void SocketSPPClient::stop() {
    connection.receiveQueue.clear();
    connection.retransmitQueue.clear();
    // stop client
    connection.client->stop();
    // remove connection from connections
    connections.remove(&connection);
}


static uint16_t newConnectionID() {
    static uint16_t lastResult = 0;

    // Overflow period in second  is  65536 / (1000 / N)
    // Overflow period in minutes is  65536 / ((1000 / N) * 60)
    // When N = 30  Overflow time is 32.768 minutes
    constexpr uint64_t N = 30;
    auto milliseconds = std::chrono::milliseconds(std::chrono::steady_clock::now().time_since_epoch().count()).count();
    uint16_t result = milliseconds / N;
    // sanity check
    if (result == lastResult) {
        // if same result, wait N milliseconds to incremetn result
        std::this_thread::sleep_for(std::chrono::milliseconds(N));
        result++;
    }
    return lastResult = result;
}


void SocketSPP::process(Session& session, ByteBuffer&rx) {
    if (session.rxIDP.packetType != xns::IDP::PacketType::SPP)    ERROR()

    xns::SPP   rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    // sanity check
    if (!rxHeader.system()) {
        logger.error("Unexpected NOT system packet");
        ERROR()
    }
    if (!rxbb.empty()) {
        logger.error("Unexpected rxbb is not empty");
        ERROR()
    }
    if (rxHeader.ack == 0 && rxHeader.dstID == 0) {
        // Expected
    } else {
        // Unexpected
        // Ignore this packet
        logger.error("Unexpected packet  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());
        return;
    }

    const Host     host  = session.srcHost();
    const uint16_t dstID = rxHeader.srcID;

    {
        const uint16_t srcID = rxHeader.dstID;
        auto* oldConnection = connections.get(host, srcID, dstID);
        if (oldConnection) {
            auto& connection = *oldConnection;
            logger.info("SPP REOPEN %s  %s", name(), connection.toString());
            // set dst.socket to redirect response
            session.dstSocket(connection.socket);
            // send packet
            connection.transmitSystemAck();
            return;
        }
    }

    // add new connection
    const uint16_t srcID = newConnectionID();

    // get new socket for srcSocket
    auto socket = server::socketManager.newSocket();

    // set dst.socket to redirect socket
    session.dstSocket(socket);

    Connection& connection = *new Connection(session, srcID, dstID);
    connections.add(&connection);

    // set client to connection
    connection.set(getClient(&connection));

    // start client thread
    connection.client->start();

    // start listening new socket
    auto* listener = new SocketSPPClient(connection);
    server::socketManager.add(socket, listener);

    logger.info("SPP OPENING  %s  %s", name(), connection.toString());
    
    // send packet
//    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    connection.transmitSystemAck();
}

}