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
 // IDP.h
 //

#pragma once

#include <string>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "../xns/XNS.h"


namespace xns::server {
//

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
        return std_sprintf("{%s %s %s}", net.toString(), host.toString(), xns::toString(socket));
    }
};



class IDP : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
public:
    static constexpr int HEADER_LENGTH = 30;

    uint16_t checksum;  // Checksum
    uint16_t length;
    uint8_t  control;
    uint8_t  type;      // Type

    NetworkAddress dst;
    NetworkAddress src;

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(checksum, length, control, type, dst, src);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        bb.write(checksum, length, control, type, dst, src);
        return bb;
    }
    std::string toString() const override;

};

}