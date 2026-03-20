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

#include <functional>
#include <mutex>
#include <string>
#include <chrono>
#include <unordered_map>


#include "../util/ByteBuffer.h"
#include "../util/SimpleQueue.h"
#include "../util/ThreadControl.h"

#include "../xns/XNS.h"

#include "Server.h"
#include "Session.h"

namespace server {
//
struct SocketData {
    Session   session;
    ByteBuffer rx;

    SocketData() {}
    SocketData(const Session& session_, const ByteBuffer& rx_) : session(session_), rx(rx_) {}

    // SocketData(const SocketData&) = default;
    // SocketData& operator =(const SocketData&) = default;
};

class SocketListener {
    using Function     = std::function<void(ByteBuffer&)>;
    using milliseconds = std::chrono::milliseconds;
    using Queue        = SimpleQueue<SocketData>;

    static const constexpr auto WAIT_INTERVAL = std::chrono::milliseconds(500);
    static const constexpr auto IDLE_INTERVAL = std::chrono::milliseconds(5'000);

    std::string   name;
    Queue         queue;
    bool          stopThread;

    milliseconds  waitInterval;
    milliseconds  idleInterval;

    ThreadControl threadControl;

public:
    SocketListener(const std::string& name_, milliseconds waitInterval_ = WAIT_INTERVAL, milliseconds idleInterval_ = IDLE_INTERVAL) :
        name(name_), queue(), stopThread(false),
        waitInterval(waitInterval_), idleInterval(idleInterval_) {
        auto function = std::bind(&SocketListener::run, this);
        threadControl.set(name, function);
    }

    SocketListener(SocketListener&& that) :
        name(that.name), queue(std::move(that.queue)), stopThread(that.stopThread),
        waitInterval(that.waitInterval), idleInterval(that.idleInterval),
        threadControl(std::move(that.threadControl)) {}
    
    virtual ~SocketListener() = default;

    virtual void process(Session&, ByteBuffer& rx) = 0; // rx is idp body
    virtual void idle()                            = 0;

    void accept(Session& session, ByteBuffer& rx) { // rx is idp body
        SocketData data;
        data.session = session;
        // copy rx to data.rx
        data.rx = ByteBuffer(rx.byteLimit());
        data.rx.write(rx);
        data.rx.flip();
        queue.push(data);
    }

    void start() {
        threadControl.start();
    }
    void stop() {
        stopThread = true;
        threadControl.join();
    }

    void run();
};


class SocketManager {
    using Socket       = xns::Socket;
    using LISTENER_MAP = std::unordered_map<Socket, SocketListener*>;

    LISTENER_MAP map;
    std::mutex   mutex;

public:
    void            put     (Socket socket, SocketListener* socketListener);
    SocketListener& get     (Socket socket);
    void            remove  (Socket socket);
    bool            contains(Socket socket);

    Socket          newSocket();

    template<typename T>
    void put() {
        put(T::SOCKET, new T);
    }

    void put(uint16_t socket, SocketListener* socketListener) {
        put(static_cast<Socket>(socket), socketListener);
    }
    SocketListener& get(uint16_t socket) {
        return get(static_cast<Socket>(socket));
    }
    void remove(uint16_t socket) {
        remove(static_cast<Socket>(socket));
    }
    bool contains(uint16_t socket) {
        return contains(static_cast<Socket>(socket));
    }

    void process(Session&, ByteBuffer& rx); // rx is idp body
};

}
