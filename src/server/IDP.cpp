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
 // IDP.cpp
 //

#include <unordered_map>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../xns/IDP.h"

#include "Server.h"

namespace xns::server::IDP {
//
using PacketType = xns::IDP::PacketType;
static std::unordered_map<PacketType, ByteBuffer(*)(ByteBuffer&, Context&)> map {
    {PacketType::RIP,    RIP::process},
    {PacketType::ECHO,   Echo::process},
    {PacketType::ERROR_, Error::process},
    {PacketType::PEX,    PEX::process},
    {PacketType::SPP,    SPP::process},
};
ByteBuffer process  (ByteBuffer& rx, Context& context) {
    xns::IDP txHeader;
    ByteBuffer txbb;
    {
        xns::IDP rxHeader;
        rx.read(rxHeader);
        auto rxbb = rx.byteRange(xns::IDP::HEADER_LENGTH_IN_BYTE, rxHeader.length - xns::IDP::HEADER_LENGTH_IN_BYTE);
    
        logger.info("IDP  >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());
    
        // sanity check
        if (rxHeader.checksum != xns::IDP::Checksum::NOCHECK) {
            auto checksum = xns::IDP::computeChecksum(rx.data(), 2, rxHeader.length);
            if (rxHeader.checksum != checksum) {
                logger.warn("checksum error  %s  %s", xns::IDP::toString(rxHeader.checksum), xns::IDP::toString(checksum));
                return ByteBuffer::Net::getInstance(0);
            }
        }

        if (map.contains(rxHeader.packetType)) {
            txbb = map[rxHeader.packetType](rxbb, context);
        } else {
            ERROR()
        }
        
        txbb.flip();
        if (txbb.empty()) return txbb;

        // prepare transmit
        txHeader.checksum    = xns::IDP::Checksum::NOCHECK;
        txHeader.length      = xns::IDP::HEADER_LENGTH_IN_BYTE + txbb.byteLimit();
        txHeader.control     = 0;
        txHeader.packetType  = rxHeader.packetType;
        txHeader.dst.network = rxHeader.src.network;
        txHeader.dst.host    = rxHeader.src.host;
        txHeader.dst.socket  = rxHeader.src.socket;
        txHeader.src.network = static_cast<Network>(context.net);
        txHeader.src.host    = context.me;
        txHeader.src.socket  = rxHeader.dst.socket;    
    }

    // build tx
    auto tx = ByteBuffer::Net::getInstance(xns::MAX_PACKET_SIZE);
    tx.write(txHeader);
    tx.write(txbb.toSpan());
    // to make even length data, add Garbage Byte if length is odd.
    if (tx.byteLimit() & 1) tx.put8(0);

    // update checksum
    // Garbage Byte, which is included in the Checksum, but not in the Length
    auto checksum = xns::IDP::computeChecksum(tx.data(), 2, tx.byteLimit());
    // don't touch tx
    {
        ByteBuffer bb = tx;
        bb.flip();
        bb.write(checksum);
    }

    txHeader.checksum = checksum;
    logger.info("IDP  <<  %s  (%d) %s", txHeader.toString(), txbb.byteLimit(), txbb.toString());

    return tx;
}

}