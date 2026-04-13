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
 // SocketManager.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "Server.h"
#include "SocketError.h"
#include "SocketManager.h"

namespace server {
//

void SocketManager::add(Socket socket, Listener* listener) {
    std::lock_guard<std::mutex> locck(mutex);
    if (map.contains(socket)) {
        ERROR()
    } else {
        listener->set(this);
        map[socket] = listener;
        logger.info("add  %-8s  %s", toString(socket), listener->name());
    }
}
void SocketManager::remove(Socket socket) {
    std::lock_guard<std::mutex> locck(mutex);
    if (map.contains(socket)) {
        auto* listener = map[socket];
        logger.info("remove   %s  %s", toString(socket), listener->name());
        delete listener;
        map.erase(socket); // remove from map
    } else {
        ERROR()
    }
}

bool SocketManager::contains(Socket socket) {
    std::lock_guard<std::mutex> locck(mutex);
    return map.contains(socket);
}

void SocketManager::process(Session& session, ByteBuffer& rx) {
    // special for Error packet
    auto packetType = session.rxIDP.packetType;
    if (packetType == xns::IDP::PacketType::ERROR_) {
        static SocketError socketError;
        bool stopped = false;
        socketError.process(session, rx, stopped);
        return;
    }

    auto socket = session.rxIDP.dst.socket;
    Listener* listener;
    {
        std::lock_guard<std::mutex> locck(mutex);
        listener = map.contains(socket) ? map[socket] : 0;
    }
    if (listener) {
        bool stopped = false;
        listener->process(session, rx, stopped);
        if (stopped) {
            logger.info("stopped      %s  %s", toString(socket), listener->name());
            delete listener;
            map.erase(socket);
        }
    } else {
        logger.warn("no listener  %s  %s", toString(socket), xns::IDP::toString(packetType));
        if (packetType == xns::IDP::PacketType::PEX) {
            xns::PEX   pexHeader;
            ByteBuffer pexBody = getByteBuffer();
            rx.read(pexHeader, pexBody);
            logger.info("    PEX  >>  %s  (%d) %s", pexHeader.toString(), pexBody.byteLimit(), pexBody.toString());
        } else if (packetType == xns::IDP::PacketType::SPP) {
            xns::SPP   sppHeader;
            ByteBuffer sppBody = getByteBuffer();
            rx.read(sppHeader, sppBody);
            logger.info("    SPP  >>  %s  (%d) %s", sppHeader.toString(), sppBody.byteLimit(), sppBody.toString());
        } else {
            logger.info("    IDP  >>  %s  (%d) %s", toString(session.rxIDP), rx.byteLimit(), rx.toString());
        }
    }
}

Socket SocketManager::newSocket() {
    auto ret = static_cast<Socket>(std::chrono::system_clock::now().time_since_epoch().count() >> 10);
    for(;;) {
        if (ret <= xns::MAX_WELLKNOWN_SOCKET) {
            ret = ret + static_cast<uint16_t>(xns::MAX_WELLKNOWN_SOCKET);
            continue;
        }
        if (!map.contains(ret)) return ret;
        ret = ret + 13;
    }
}

}
