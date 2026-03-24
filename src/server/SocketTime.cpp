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
 // SocketTime.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../courier/Time.h"

#include "Server.h"
#include "Session.h"
#include "Context.h"

#include "SocketTime.h"

namespace server {
//

static courier::Time::Response call(Session& session, courier::Time::Request request) {
    using namespace courier::Time;

    // make reference
    auto& context = *session.context;

    // sanity check
    if (request.version != Version::CURRENT) ERROR()
    if (request.type    != courier::Time::Type::REQUEST)    ERROR()

    courier::Time::Response response;

    response.version         = Version::CURRENT;
    response.type            = Type::RESPONSE;
    response.time            = Util::getMesaTime();
    response.offsetDirection = static_cast<Response::Direction>(context.config.time.offsetDirection);
    response.offsetHours     = context.config.time.offsetHours;
    response.offsetMinutes   = context.config.time.offsetMinutes;
    response.dstStart        = static_cast<Response::DST>(context.config.time.dstStart);
    response.dstEnd          = static_cast<Response::DST>(context.config.time.dstEnd);
    response.tolerance       = Response::Tolerance::KNOWN;
    response.toleranceValue  = 10;

    return response;
}

void SocketTime::process(Session& session, ByteBuffer&rx, bool& stopped) {
    stopped = false;
    if (session.rxIDP.packetType != xns::IDP::PacketType::PEX)    ERROR()

    ByteBuffer pexBody;
    rx.read(session.rxPEX, pexBody);
    if constexpr (SHOW_PACKET_PEX)  logger.info("PEX  >>  %s  (%d) %s", session.rxPEX.toString(), pexBody.byteLimit(), pexBody.toString());

    courier::Time::Request rxTime;
    ByteBuffer timeBody;
    pexBody.read(rxTime, timeBody);

    if constexpr (SHOW_PACKET_TIME) logger.info("TIME >>  %s  (%d) %s", rxTime.toString(), timeBody.byteLimit(), timeBody.toString());
    if (timeBody.remains()) ERROR()

    auto txTime = call(session, rxTime);
    if constexpr (SHOW_PACKET_TIME) logger.info("TIME <<  %s", txTime.toString());

    auto tx = getByteBuffer();
    tx.write(txTime);
    
    session.sendPEX(tx);
}

}