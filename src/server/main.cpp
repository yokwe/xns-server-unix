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

#include "Server.h"

int main(int, char **) {
    using namespace server;

	logger.info("START");

    setSignalHandler(SIGINT);
	setSignalHandler(SIGTERM);
	setSignalHandler(SIGHUP);
	setSignalHandler(SIGSEGV);

    {
        auto bb = getByteBuffer();
        std::string string("ABCD");

        bb.write(string);
        bb.flip();
        logger.info("bb  %d  %s", bb.byteLimit(), bb.toString());

        std::string a;
        bb.read(a);
        logger.info("a  \"%s\"", a);
    }
    {
        auto bb = getByteBuffer();

        std::vector<std::string> vector;
        vector.push_back("A");
        vector.push_back("B");
        vector.push_back("C");
        bb.write(vector);
        bb.flip();
        logger.info("bb  %d  %s", bb.byteLimit(), bb.toString());

        std::vector<std::string>a;
        bb.read(a);
        logger.info("a  %d  %s  %s  %s", a.size(), a[0], a[1], a[2]);
    }

    Context context;

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

    driver.clear();
    t1.start();
    t2.start();

    for(;;) {
        ReceiveData receiveData;
        
        threadReceive.pop(receiveData);
        auto& rx = receiveData.rx;
        if (rx.empty()) continue;

        auto tx = Ethernet::process(rx, context);
        if (tx.empty()) continue;

        TransmitData transmitData(tx);
        threadTransmit.push(transmitData);
	}

    threadReceive.stop();
    threadTransmit.stop();
    t1.join();
    t2.join();

	logger.info("STOP");
}
