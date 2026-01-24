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

 #include <cstdint>


#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "Server.h"

namespace xns::server {
//
enum class Socket : uint16_t {
    RIP       =  1,
    ECHO      =  2,
    ERR       =  3,
    ENVOY     =  4,
    COURIER   =  5,
    CHS_OLD   =  7,
    TIME      =  8,
    BOOT      = 10,
    DIAG      = 19,
    CHS       = 20,
    AUTH      = 21,
    MAIL      = 22,
    NET_EXEC  = 23,
    WS_INFO   = 24,
    BINDING   = 28,
    GERM      = 35,
    TELEDEBUG = 48,
};
static std::string toString(Socket socket) {
    return std_sprintf("%d", socket);
}



class NetworkAddress : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
public:
    Net    net;
    Host   host;
    Socket socket;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(net, host, socket);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        bb.write(net, host, socket);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%s %s %s}", net.toString(), host.toString(), xns::server::toString(socket));
    }
};



class IDP : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
public:
    static constexpr int HEADER_LENGTH = 30;

    uint16_t checksum;  // Checksum
    uint16_t length;
    uint8_t  control;
    uint8_t  type;      // Type


    uint32_t dstNet;    // Net
    uint64_t dstHost;   // Host
    uint16_t dstSocket; // Soeckt

    uint32_t srcNet;    // Net
    uint64_t srcHost;   // Host
    uint16_t srcSocket; // Socket

};

void processIDP      (ByteBuffer& rx, ByteBuffer& tx, Context& context) {
    (void)rx; (void)tx, (void)context;
    logger.info("%s", __func__);
}

}