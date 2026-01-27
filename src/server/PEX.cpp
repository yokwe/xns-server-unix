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
 // PEX.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/PEX.h"

#include "Server.h"

namespace xns::server::PEX {
//
using T = xns::PEX;
struct MyProcess : public Process<T> {
    void process(ByteBuffer& rx, ByteBuffer& tx, Context& context) override;
    void process(Param<T>& receive, Param<T>& transmit, Context& context) override;
};

void MyProcess::process(ByteBuffer& rx, ByteBuffer& tx, Context& context) {
    auto receive  = Param<T>::receive(rx);
    auto transmit = Param<T>::transmit();

    // prepare transmit.header
    transmit.header.id         = receive.header.id;
    transmit.header.clientType = receive.header.clientType;

    process(receive, transmit, context);

    transmit.body.flip();

    // output to rx
    tx.write(transmit.header);
    tx.write(transmit.body.toSpan());
}
void MyProcess::process(Param<T>& receive, Param<T>& transmit, Context& context) {
    (void)receive; (void)transmit; (void)context;
    logger.info("PEX  >>  %s  (%d) %s", receive.header.toString(), receive.body.byteLimit(), receive.body.toString());
}

static MyProcess myProcess;
void process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context) {
    myProcess.process(rx, tx, context);
}

}