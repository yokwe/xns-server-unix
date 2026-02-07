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
 // Echo.cpp
 //

 #include "../util/Debug.h"
 #include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/Echo.h"

#include "Server.h"

namespace server::Echo {
//
using Echo   = xns::Echo;
using Type   = xns::Echo::Type;
using Result = HeaderBody<Echo>;

Result request(Echo& rxHeader, ByteBuffer& rxbb, Context& context) {
    logger.info("## %s", __PRETTY_FUNCTION__);
    (void)rxHeader; (void)context;
    Echo txHeader{Type::RESPONSE};
    ByteBuffer txbb = rxbb;
    return Result{txHeader, txbb};
}
Result response(Echo& rxHeader, ByteBuffer& rxbb, Context& context) {
    logger.info("## %s", __PRETTY_FUNCTION__);
    (void)rxHeader; (void)rxbb; (void)context;
    Echo txHeader;
    ByteBuffer txbb;
    return Result{txHeader, txbb};
}

static std::unordered_map<Type, Result (*)(Echo&, ByteBuffer&, Context&)> map {
    {Type::REQUEST,  request},
    {Type::RESPONSE, response},
};

ByteBuffer process  (ByteBuffer& rx, Context& context) {
    Echo rxHeader;
    ByteBuffer rxbb;
    rx.read(rxHeader, rxbb);
    if (SHOW_PACKET_ECHO) logger.info("Echo >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto [txHeader, txbb] = map.at(rxHeader.type)(rxHeader, rxbb, context);
    auto tx = getByteBuffer();
    
    if (rxHeader.type == Type::REQUEST) {
        tx.write(txHeader);
        tx.write(txbb);
        if (SHOW_PACKET_ECHO) logger.info("Echo <<  %s  (%d) %s", txHeader.toString(), txbb.byteLimit(), txbb.toString());
    }

    return tx;
}

}