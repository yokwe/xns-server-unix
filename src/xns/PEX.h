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
 // PEX.h
 //

#pragma once

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

namespace xns {
//
class PEX : public HasToString {
public:
    // APilot/15.0.1/NS/Public/PacketExchange.mesa
    // ExchangeClientType: TYPE = MACHINE DEPENDENT {
    //     unspecified(0), timeService(1), clearinghouseService(2), teledebug(10B),
    //     electronicMailFirstPEType(20B), electronicMailLastPEType(27B),
    //     remoteDebugFirstPEType(30B), remoteDebugLastPEType(37B),
    //     acceptanceTestRegistration(40B), performanceTestData(41B),
    //     protocolCertification(50B), voyeur(51B),
    //     dixieDataPEType(101B), dixieAckPEType(102B),
    //     dixieBusyPEType(103B), dixieErrorPEType(104B),
    //     outsideXeroxFirst(100000B), outsideXeroxLast(LAST[CARDINAL])};

    enum class ClientType : uint16_t {
        ENUM_NAME_VALUE(ClientType, UNSPEC,    0)
        ENUM_NAME_VALUE(ClientType, TIME,      1)
        ENUM_NAME_VALUE(ClientType, CHS,       2)
        ENUM_NAME_VALUE(ClientType, TELEDEBUG, 8)
    };
    static std::string toString(ClientType value);

    uint32_t   id;
    ClientType clientType;

    PEX() : id(0), clientType(ClientType::UNSPEC) {}

    ByteBuffer& read(ByteBuffer& bb) {
        bb.read(id, clientType);
        return bb;
    }
    ByteBuffer& write(ByteBuffer& bb) {
        bb.write(id, clientType);
        return bb;
    }
    std::string toString() const override {
        return std_sprintf("{%08X %-4s}", id, toString(clientType));
    }
};

}