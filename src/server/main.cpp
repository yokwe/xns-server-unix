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
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"
#include "../util/ThreadControl.h"

#include "../xns/Config.h"
#include "../xns/XNS.h"
#include "../xns/Ethernet.h"

#include "Server.h"

using namespace xns;

int main(int, char **) {

	logger.info("START");

    setSignalHandler(SIGINT);
	setSignalHandler(SIGTERM);
	setSignalHandler(SIGHUP);
	setSignalHandler(SIGSEGV);

    auto config = xns::Config::getInstance();
    logger.info("config network interface  %s", config.server.interface);

    // register constant of host and net from config
    xns::initialize(&config);

    server::Context context(config);
	logger.info("device  %s  %s", net::toHexaDecimalString(context.driver->device.address), context.driver->device.name);
	logger.info("me      %s  BPF", net::toHexaDecimalString(context.me));
	logger.info("net     %d", context.net);

    auto& driver = *context.driver;
	driver.open();

    server::ThreadReceive  threadReceive(driver);
    server::ThreadTransmit threadTransmit(driver);

    std::function<void()> f1 = std::bind(&server::ThreadReceive::run, &threadReceive);
    std::function<void()> f2 = std::bind(&server::ThreadTransmit::run, &threadTransmit);

	ThreadControl t1("threadReceive",  f1);
	ThreadControl t2("threadTransmit", f2);

    driver.clear();
    t1.start();
    t2.start();

    for(;;) {
        Ethernet transmit;
        auto payload = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);

        // build transmitFrame and payload
        {
            server::ReceiveData receiveData;
            threadReceive.pop(receiveData);
            if (receiveData.rx.empty()) continue;
    
            // build receiveFrame
            Ethernet receive;
            receiveData.rx.read(receive);
    
            bool discardPacket = true;
            if (receive.type == Ethernet::Type::XNS) {
                if (receive.dest == context.me || receive.dest == xns::Host::BROADCAST) {
                    discardPacket = false;
                }
            }
            if (discardPacket) continue;

            logger.info("ETH  >>  %s  %d", receive.toString(), receiveData.rx.remains());
    
            // build transmitFrame
            transmit.dest   = receive.source;
            transmit.source = context.me;
            transmit.type   = receive.type;

            // build payload
            auto rx = receiveData.rx.rangeRemains();
            IDP_process(rx, payload, context);
            payload.flip();
        }

        // logger.info("payload  length  %d", payload.length());
        if (payload.empty()) continue;

        server::TransmitData transmitData;
        {    
            logger.info("ETH  <<  %s  %d", transmit.toString(), payload.remains());

            ByteBuffer& tx = transmitData.tx;
            // build transmitData
            tx.write(transmit);
            tx.write(payload.toSpan());
    
            // add padding if it is smaller than MINIMUM_LENGTH
            auto length = tx.byteLimit();
            if (length < xns::MIN_PACKET_SIZE) {
                for(uint32_t i = length; i < xns::MIN_PACKET_SIZE; i++) tx.put8(0);
            }    
        }
        threadTransmit.push(transmitData);
	}

    threadReceive.stop();
    threadTransmit.stop();
    t1.join();
    t2.join();

	logger.info("STOP");
}
