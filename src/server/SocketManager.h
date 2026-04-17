/*******************************************************************************
 * Copyright (c) 2025, Yasuhiro Hasegawa
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
 // SockeManager.h
 //

#pragma once

#include <mutex>
#include <string>
#include <unordered_map>


#include "../util/ByteBuffer.h"

#include "../xns/XNS.h"

#include "Server.h"
#include "Session.h"

namespace server {
//
using Socket = xns::Socket;

class SocketManager {
public:
    class Listener {
    public:
        virtual ~Listener() = default;
        virtual const std::string& name() = 0;

        virtual void start() = 0; // called once from SocketMangaer::add
        virtual void stop()  = 0; // called once from SocketManager::remove

        virtual void process(Session& session, ByteBuffer& rx, bool& stopped) = 0;
        
    };

    template<typename T>
    void add() {
        add(T::SOCKET, new T);
    }

    void add     (Socket socket, Listener* listener);
    void remove  (Socket socket);
    bool contains(Socket socket);

    void process(Session& session, ByteBuffer& rx); // rx is idp body

    Socket newSocket();

private:
    using LISTENER_MAP = std::unordered_map<Socket, Listener*>;

    LISTENER_MAP map;
    std::mutex   mutex;
};

inline SocketManager socketManager;

}
