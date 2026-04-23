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
// SocketSPP.h
//


#pragma once

#include <chrono>

#include "../util/ByteBuffer.h"

#include "../server/SocketManager.h"

#include "Connection.h"
#include "Client.h"

namespace spp {
//
using Listener      = server::SocketManager::Listener;
using Session       = server::Session;
using Socket        = xns::Socket;
using milliseconds  = std::chrono::milliseconds;

class SocketSPPClient: public Listener {
    static constexpr auto CLOSING_TIMEOUT = std::chrono::seconds(5);

    const Socket   socket;
    const Host     host;
    const uint16_t srcID;
    const uint16_t dstID;

    Connection* connection;
    
public:
    static const constexpr std::string NAME = "SocketSPPClient";

    SocketSPPClient(Socket socket_, const Host& host_, uint16_t srcID_, uint16_t dstID_):
        Listener(), socket(socket_), host(host_), srcID(srcID_), dstID(dstID_),
        connection(connections.get(host, srcID, dstID)) {}

    const std::string& name() override {
        return NAME;
    }
    
    void start() override {}
    void stop()  override;
    void process(Session& session, ByteBuffer&rx) override;
};

// SocketSPP process request and add client socket to newly allocated socket
class SocketSPP: public Listener {
    static constexpr auto OPENING_TIMEOUT = std::chrono::seconds(10);

public:
    virtual ~SocketSPP() = default;

    void start() override {}
    void stop()  override {}

    void process(Session& session, ByteBuffer&rx) override;

    virtual Client*   getClient(Connection*) = 0;
};

}
