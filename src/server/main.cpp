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
 // main.cpp
 //

#include "../util/Util.h"
#include <csignal>
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"
#include "../util/ThreadControl.h"

#include "Server.h"
#include "Session.h"
#include "Context.h"
#include "SocketManager.h"
#include "SocketError.h"
#include "SocketTime.h"
#include "SocketRIP.h"

int main(int, char **) {
    using namespace server;

	logger.info("START");

    setSignalHandler(SIGINT);
	setSignalHandler(SIGTERM);
	setSignalHandler(SIGHUP);
	setSignalHandler(SIGSEGV);
	setSignalHandler(SIGTRAP);
	setSignalHandler(SIGABRT);

    server::Context context{};

	logger.info("device   %s  %s  %s", net::toHexaDecimalString(context.driver->device.address), toStringHost(context.driver->device.address), context.driver->device.name);
	logger.info("me       %s  %s", net::toHexaDecimalString(context.me), toStringHost(context.me));
	logger.info("network  %d  %s", context.net, toStringNetwork(context.net));

    auto& driver = *context.driver;
	driver.open();

    ThreadReceive  threadReceive(driver);
    ThreadTransmit threadTransmit(driver);

    std::function<void()> f1 = std::bind(&ThreadReceive::run, &threadReceive);
    std::function<void()> f2 = std::bind(&ThreadTransmit::run, &threadTransmit);

	ThreadControl t1("threadReceive",  f1);
	ThreadControl t2("threadTransmit", f2);

    // set socket listener
    SocketManager socketManager;
    socketManager.put<server::SocketError>();
    socketManager.put<server::SocketTime>();
    socketManager.put<server::SocketRIP>();

    // enable service implementation
//    server::Clearinghouse3::enable();

//    server::startSPP();

    driver.clear();
    t1.start();
    t2.start();

    for(;;) {
        ReceiveData receiveData;        
        threadReceive.pop(receiveData);
        auto& rx = receiveData.rx;
        if (rx.empty()) continue;

        Session session(&context, &threadTransmit);
        
        auto ethenetBody = getByteBuffer();
        rx.read(session.rxEthernet, ethenetBody);
    
        bool myPacket = false;
        if (session.rxEthernet.type == xns::Ethernet::Type::XNS) {
            if (session.rxEthernet.source == context.me) {
                // NOT myPacket
            } else {
                if (session.rxEthernet.dest.isBroadcas() || session.rxEthernet.dest == context.me) {
                    myPacket = true;
                }
            }
        }
        if (!myPacket) continue;
    
        if constexpr (SHOW_PACKET_ETHERNET) logger.info("ETH  >>  %s  (%d) %s", server::toString(session.rxEthernet), ethenetBody.byteLimit(), ethenetBody.toString());
    
        ethenetBody.read(session.rxIDP);
        auto idpBody = ethenetBody.byteRange(xns::IDP::HEADER_LENGTH_IN_BYTE, session.rxIDP.length - xns::IDP::HEADER_LENGTH_IN_BYTE);
        if constexpr (SHOW_PACKET_IDP) logger.info("IDP  >>  %s  (%d) %s", server::toString(session.rxIDP), idpBody.byteLimit(), idpBody.toString());
    
        // sanity check
        if (session.rxIDP.checksum != xns::IDP::Checksum::NOCHECK) {
            auto checksum = xns::IDP::computeChecksum(ethenetBody.data(), 2, session.rxIDP.length);
            if (session.rxIDP.checksum != checksum) {
                logger.warn("checksum error  %s  %s", xns::IDP::toString(session.rxIDP.checksum), xns::IDP::toString(checksum));
                // FIXME send Error packet
                session.sendError(xns::Error::ErrorNumber::BAD_CHECKSUM);
                continue;
            }
        }
    
        auto socket = session.rxIDP.dst.socket;
        if (socketManager.contains(socket)) {
            socketManager.process(session, idpBody);
        } else {
            logger.warn("Unknown socket  %s", ::toString(socket));
        }
	}

    threadReceive.stop();
    threadTransmit.stop();
    t1.join();
    t2.join();

	logger.info("STOP");
}
