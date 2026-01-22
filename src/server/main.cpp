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

#include <span>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"
#include "../util/net.h"
#include "../util/ThreadControl.h"
#include "../util/ThreadQueue.h"

#include "../xns/Type.h"
#include "../xns/Ethernet.h"
#include "../xns/Config.h"

#include "Server.h"

struct TransmitData {
    ByteBuffer tx;
    TransmitData() : tx(ByteBuffer::Net::getInstance(xns::PACKET_SIZE)) {}
};
struct ThreadTransmit : public thread_queue::ThreadQueueProcessor<TransmitData> {
    net::Driver& driver;

    ThreadTransmit(net::Driver& driver_) : thread_queue::ThreadQueueProcessor<TransmitData>("ThreadTransmit"), driver(driver_) {}

    void process(const TransmitData& data) override {
        auto span = data.tx.toSpanLimit();
        driver.transmit(span);
    }
};

struct ReceiveData {
    ByteBuffer rx;
    ReceiveData() : rx(ByteBuffer::Net::getInstance(xns::PACKET_SIZE)) {}
};
struct ThreadReceive : public thread_queue::ThreadQueueProducer<ReceiveData> {
    net::Driver& driver;

    ThreadReceive(net::Driver& driver_) : thread_queue::ThreadQueueProducer<ReceiveData>("ThreadReceive"), driver(driver_) {}

    // produce return true when data has value
    bool produce(ReceiveData& data, std::chrono::milliseconds timeout) override{
        net::Driver::data_type span;
        int ret = driver.receive(span, timeout);
        data.rx.clear();
        // copy data from span to bb
        if (ret) data.rx.put(span);
        data.rx.flip();
        return ret;
    }
};


Context context;

int main(int, char **) {
	logger.info("START");

    setSignalHandler(SIGINT);
	setSignalHandler(SIGTERM);
	setSignalHandler(SIGHUP);
	setSignalHandler(SIGSEGV);

    auto config = xns::config::Config::getInstance();
    logger.info("config network interface  %s", config.server.interface);
    // register constant of host and net from config
    xns::initialize(config);

    context = Context(config);
	logger.info("device  %s  %s", context.driver->device.name, net::toHexaDecimalString(context.driver->device.address));
	logger.info("ME      %s", net::toHexaDecimalString(context.ME));
	logger.info("NET     %d", context.NET);

    auto& driver = *context.driver;
	driver.open();

    ThreadReceive  threadReceive(driver);
    ThreadTransmit threadTransmit(driver);

    std::function<void()> f1 = std::bind(&ThreadReceive::run, &threadReceive);
    std::function<void()> f2 = std::bind(&ThreadTransmit::run, &threadTransmit);

	ThreadControl t1("threadReceive",  f1);
	ThreadControl t2("threadTransmit", f2);

    driver.clear();
    t1.start();
    t2.start();

    for(;;) {
        ReceiveData receiveData;

        threadReceive.pop(receiveData);
        if (receiveData.rx.empty()) continue;

        // build receiveFrame
        xns::ethernet::Frame receiveFrame;
        receiveData.rx.read(receiveFrame);

        logger.info("ETH  >>  %s  %d", receiveFrame.toString(), receiveData.rx.remains());

        if (receiveFrame.dest() != context.ME && receiveFrame.dest() != xns::BROADCAST) {
            // not my address or not broadcast
            // logger.info("frame  %s  %d", receive.toString(), rx.remaining());
            continue;
        }
        if (receiveFrame.type == xns::XNS) {
            // not XNS packet
            continue;
        }

        xns::ethernet::Frame transmitFrame;
        // build transmitFrame
        transmitFrame.dest(receiveFrame.source());
        transmitFrame.source(context.ME);
        transmitFrame.type = receiveFrame.type;

        ByteBuffer payload = ByteBuffer::Net::getInstance(net::PACKET_SIZE);

        // build payload
//        processIDP(receiveData.rx, payload, context);

        // if payload is empty, continue with next received data
        payload.flip();
        // logger.info("payload  length  %d", payload.length());
        if (payload.empty()) continue;

        logger.info("ETH  <<  %s  %d", transmitFrame.toString(), payload.remains());

        TransmitData transmitData;
        // build transmitData
        transmitData.tx.write(transmitFrame);
        transmitData.tx.write(payload.toSpanLimit());

        // add padding if it is smaller than MINIMUM_LENGTH
        auto length = transmitData.tx.byteLimit();
        if (length < xns::MINIMUM_LENGTH) {
            for(uint32_t i = length; i < xns::MINIMUM_LENGTH; i++) transmitData.tx.put8(0);
        }

        threadTransmit.push(transmitData);
	}

    threadReceive.stop();
    threadTransmit.stop();
    t1.join();
    t2.join();

	logger.info("STOP");
}
