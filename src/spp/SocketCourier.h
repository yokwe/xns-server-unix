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
// SocketCourier.h
//


#pragma once

#include <chrono>
#include <string>

#include "../xns/XNS.h"

#include "../server/SocketManager.h"

#include "ClientCourier.h"
#include "SocketSPP.h"

namespace spp {
//
using SocketManager = server::SocketManager;
using Socket        = xns::Socket;

struct SocketCourierClient: public SocketManager::Listener {
    static const constexpr std::string NAME = "SocketCourierClient";
    static constexpr auto CLOSE_REPLY_TIMEOUT = std::chrono::seconds(5);

    enum class State {
        NEW, OPEN, CLOSE, CLOSE_REPLY,
    };
    std::string toString(State value) {
        static std::unordered_map<State, std::string, ScopedEnumHash> map = {
            {State::NEW,         "NEW"},
            {State::OPEN,        "OPEN"},
            {State::CLOSE,       "CLOSE"},
            {State::CLOSE_REPLY, "CLOSE_REPLY"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%d", std::to_underlying(value));
    }

    const Socket   socket;
    const Host     host;
    const uint16_t srcID;
    const uint16_t dstID;

    State    state;
    uint32_t closeCount;

    SocketCourierClient(Socket socket_, const Host& host_, uint16_t srcID_, uint16_t dstID_) :
        SocketManager::Listener(), socket(socket_), host(host_), srcID(srcID_), dstID(dstID_), state(State::NEW), closeCount(0) {}

    const std::string& name() override {
        return NAME;
    }

    void start() override {}
    void stop()  override;
    void process(Session& session, ByteBuffer&rxß) override;
};


struct SocketCourier: public SocketSPP {
    static const constexpr auto SOCKET = xns::Socket::COURIER;
    static const constexpr std::string NAME = "SocketCourier";
    
    SocketCourier() : SocketSPP() {}

    SocketManager::Listener* getListener(Socket socket, const Host& host, uint16_t srcID, uint16_t dstID) override {
        return new SocketCourierClient(socket, host, srcID, dstID);
    }
    Client* getClient(Connection* connection) override {
        return new ClientCourier(connection);
    }
    const std::string& name() override {
        return NAME;
    }

};

}
