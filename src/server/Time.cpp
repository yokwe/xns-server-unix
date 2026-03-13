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
 // Time.cpp
 //

#include "../util/Debug.h"
#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../courier/Time.h"

#include "../xns/PEX.h"

#include "Server.h"
#include "Session.h"

namespace server {
//
static courier::Time::Response call(Session& session, courier::Time::Request request) {
    // make reference
    auto& context = session.context;

    // sanity check
    if (request.version != courier::Time::Version::CURRENT) ERROR()
    if (request.type    != courier::Time::Type::REQUEST)    ERROR()

    courier::Time::Response response;

    response.version         = courier::Time::Version::CURRENT;
    response.type            = courier::Time::Type::RESPONSE;
    response.time            = Util::getMesaTime();
    response.offsetDirection = static_cast<courier::Time::Response::Direction>(context.config.time.offsetDirection);
    response.offsetHours     = context.config.time.offsetHours;
    response.offsetMinutes   = context.config.time.offsetMinutes;
    response.dstStart        = static_cast<courier::Time::Response::DST>(context.config.time.dstStart);
    response.dstEnd          = static_cast<courier::Time::Response::DST>(context.config.time.dstEnd);
    response.tolerance       = courier::Time::Response::Tolerance::KNOWN;
    response.toleranceValue  = 10;

    return response;
}

void listenerTIME(Session& session, const ByteBuffer& rx) {
    if (session.rxIDP.packetType != xns::IDP::PacketType::PEX) ERROR()

    xns::PEX&   pexHeader(session.rxPEX);
    ByteBuffer pexBody;

    rx.read(pexHeader, pexBody);
    if constexpr (SHOW_PACKET_PEX)  logger.info("PEX  >>  %s  (%d) %s", pexHeader.toString(), pexBody.byteLimit(), pexBody.toString());

    courier::Time::Request rxHeader;
    ByteBuffer rxbb;
    pexBody.read(rxHeader, rxbb);

    if constexpr (SHOW_PACKET_TIME) logger.info("TIME >>  %s  (%d) %s", rxHeader.toString(), rxbb.byteLimit(), rxbb.toString());

    if (rx.remains()) ERROR()

    auto txHeader = call(session, rxHeader);
    if constexpr (SHOW_PACKET_TIME) logger.info("TIME <<  %s", txHeader.toString());

    auto tx = getByteBuffer();
    tx.write(txHeader);
    
    session.sendPEX(tx);
}

}