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
 // SPP.h
 //

#pragma once

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "../server/Server.h"

namespace xns {
//

class SPP : public ByteBuffer::HasRead, public ByteBuffer::HasWrite, public HasToString {
public:
    static void process(ByteBuffer& rx, ByteBuffer& tx, server::Context& context);

    uint8_t  control; // Control Bit
    uint8_t  sst;     // Sub System Type
    uint16_t idSrc;   // connection id of source
    uint16_t idDst;   // connection id of destination
    uint16_t seq;     // sequence
    uint16_t ack;     // acknowledgment
    uint16_t alloc;   // allocation

    SPP() : control(0), sst(0), idSrc(0), idDst(0), seq(0), ack(0), alloc(0) {}

    ByteBuffer& read(ByteBuffer& bb) override {
        bb.read(control, sst, idSrc, idDst, seq, ack, alloc);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) const override {
        bb.write(control, sst, idSrc, idDst, seq, ack, alloc);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%02X  %d  %04X  %04X  %5d  %5d  %5d}", control, sst, idSrc, idDst, seq, ack, alloc);
    }

};

}
