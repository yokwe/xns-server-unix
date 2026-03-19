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

#include "SocketManager.h"

namespace server {
//

void SocketListener::run() {
    logger.info("SocketListener  START  %s", name);
    auto lastIdle = std::chrono::steady_clock::now();
    ByteBuffer data;
    
    for(;;) {
        if (stopThread) break;
        if (queue.pop(data, waitInterval)) {
            // process data
            process(data);
        } else {
            // do idle task like retransmit
            auto now = std::chrono::steady_clock::now();
            if (now < (lastIdle + idleInterval)) {
                idle();
                lastIdle = now;
            }
        }
    }
    logger.info("SocketListener  STOP  %s", name);
}


//
// SocketManager
//
void SocketManager::put(Socket socket, SocketListener* socketListener) {
    std::lock_guard<std::mutex> locck(mutex);
    if (map.contains(socket)) {
        ERROR()
    } else {
        map[socket] = socketListener;
    }
}
SocketListener& SocketManager::get(Socket socket) {
    std::lock_guard<std::mutex> locck(mutex);
    if (map.contains(socket)) {
        return *map[socket];
    } else {
        ERROR()
    }
}
void SocketManager::remove(Socket socket) {
    std::lock_guard<std::mutex> locck(mutex);
    if (map.contains(socket)) {
        delete map[socket];
        map.erase(socket);
    } else {
        ERROR()
    }
}
bool SocketManager::contains(Socket socket) {
    std::lock_guard<std::mutex> locck(mutex);
    return map.contains(socket);
}

}
