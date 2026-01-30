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
 // Ethernet.cpp
 //

 #include "../util/Debug.h"
 #include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/Ethernet.h"

#include "Server.h"

namespace xns::server::Ethernet {
//
ByteBuffer process  (ByteBuffer& rx, Context& context) {
    xns::Ethernet rxHeader;
    rx.read(rxHeader);
    auto rxbb = rx.rangeRemains();

    bool myPacket = false;
    if (rxHeader.type == xns::Ethernet::Type::XNS) {
        if (rxHeader.source != context.me && (rxHeader.dest == context.me || rxHeader.dest == xns::Host::BROADCAST)) {
            myPacket = true;
        }
    }
    if (!myPacket) return ByteBuffer{};

    if (SHOW_PACKET_ETHERNET) logger.info("ETH  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    auto txbb = IDP::process(rxbb, context);        
    txbb.flip();
    if (txbb.empty()) return ByteBuffer{};

    // prepare transmit
    xns::Ethernet txHeader;
    txHeader.dest   = rxHeader.source;
    txHeader.source = context.me;
    txHeader.type   = rxHeader.type;

    // build tx
    auto tx = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);
    tx.write(txHeader);
    tx.write(txbb.toSpan());
    // add padding if it is smaller than MINIMUM_LENGTH
    auto length = tx.byteLimit();
    for(uint32_t i = length; i < xns::MIN_PACKET_SIZE; i++) tx.put8(0);

    if (SHOW_PACKET_ETHERNET) logger.info("ETH  <<  %s  (%d) %s", txHeader.toString(), txbb.byteLimit(), txbb.toString());

    return tx;
}

}
