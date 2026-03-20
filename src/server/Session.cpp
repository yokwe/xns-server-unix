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
 // Session.cpp
 //

 #include "../util/Util.h"
 static const Logger logger(__FILE__);

 #include "Server.h"
 #include "Session.h"
 #include "Context.h"

 namespace server {
//
void Session::sendEther(const ByteBuffer& bb) {
    // make reference
    xns::Ethernet txEthernet;

    txEthernet.dest   = rxEthernet.source;
    txEthernet.source = context->me;
    txEthernet.type   = rxEthernet.type;

    auto tx = getByteBuffer();
    // write ethernet header
    tx.write(txEthernet);
    tx.write(bb);

    // add padding for mininum packet size
    auto length = tx.byteLimit();
    for(uint32_t i = length; i < MIN_PACKET_SIZE; i++) tx.put8(0);

    if constexpr (SHOW_RESPONSE_DURATION) {
        logger.info("Duration  %d", milliTime());
    }
    if constexpr (SHOW_PACKET_ETHERNET) {
        logger.info("ETH  <<  %s  (%d) %s", server::toString(txEthernet), bb.byteLimit(), bb.toString());
    }

    TransmitData transmitData(tx);
    threadTransmit->push(transmitData);
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
    txHeader.src.network = context->net;
    txHeader.src.host    = context->me;
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
    if constexpr (SHOW_PACKET_IDP) logger.info("IDP  <<  %s  (%d) %s", server::toString(txHeader), txbb.byteLimit(), txbb.toString());

    sendEther(tx);
}

void Session::sendError(xns::Error::ErrorNumber errorNumber, uint16_t errorParameter) {
    xns::Error txHeader{errorNumber, errorParameter};

    auto tx = getByteBuffer();
    tx.write(txHeader, rxIDP);

    if constexpr (SHOW_PACKET_ERROR) logger.info("Error<<  %s  IDP  %s", txHeader.toString(), rxIDP.toString());

    sendIDP(tx);
}

void Session::sendPEX(const ByteBuffer& txbb) {
    auto& txHeader = rxPEX;

    auto tx = getByteBuffer();
    tx.write(txHeader);
    tx.write(txbb);

    if constexpr (SHOW_PACKET_PEX) logger.info("PEX  <<  %s  (%d) %s", txHeader.toString(), txbb.byteLimit(), txbb.toString());

    sendIDP(tx);
}

void Session::send(const xns::SPP& header, const ByteBuffer& body) {
    auto tx = getByteBuffer();
    tx.write(header, body);

    if constexpr (SHOW_PACKET_SPP) logger.info("SPP  <<  %s  (%d) %s", header.toString(), body.byteLimit(), body.toString());
    sendIDP(tx);
}

}