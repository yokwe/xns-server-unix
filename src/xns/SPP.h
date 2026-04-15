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

#include <compare>

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "IDP.h"

namespace xns {
//

class SPP {
public:
    static const constexpr uint32_t HEADER_SIZE_IN_BYTE = 12;

    //  -- from APilot/15.0.1/NS/Friends/NSTypes.mesa
    // maxDataBytesPerSpp: CARDINAL = maxIDPBytesPerPacket - bytesPerSppHeader - bytesPerIDPHeader;
    static const constexpr uint32_t MAX_BODY_SIZE_IN_BYTE = IDP::MAX_BODY_SIZE_IN_BYTE - HEADER_SIZE_IN_BYTE;

    enum class SST : uint8_t {
        DATA        =   0,
        BULK        =   1,
        CLOSE       = 254, // for closing connection
        CLOSE_REPLY = 255, // for reply of closing connection (handshake)
    };
    static std::string toString(SST value) {
        static std::unordered_map<SST, std::string, ScopedEnumHash> map = {
            {SST::DATA,        "DATA"},
            {SST::BULK,        "BULK"},
            {SST::CLOSE,       "CLOSE"},
            {SST::CLOSE_REPLY, "CLOSE_REPLY"},
        };
        return map.contains(value) ? map[value] : std_sprintf("%04X", std::to_underlying(value));
    }

    // function for seq comparison  consider the case when seq is overflowed
    // return true when a is before b
    inline static constexpr bool isBefore(uint16_t a, uint16_t b) {
        // a     10  b     20  c     -10  d     10  true
        // a     10  b  65530  c  -65520  d  65530  false
        // a     20  b     10  c      10  d     10  false
        // a  65530  b     10  c   65520  d  65520  true

        auto c = a - b;
        auto d = abs(c);
        return c < 0 ? d < 32000 : 32000 < d;
    }

    inline static constexpr std::strong_ordering strong_order_seq(uint16_t a, uint16_t b) {
        if (a == b) {
            return std::strong_ordering::equal;
        } else {
            return isBefore(a, b) ? std::strong_ordering::less : std::strong_ordering::greater;
        }
    }

    uint8_t  control; // Control Bit
    SST      sst;     // Sub System Type
    uint16_t srcID;   // connection id of source
    uint16_t dstID;   // connection id of destination
    uint16_t seq;     // sequence of this packet
    uint16_t ack;     // sequence number of the next expected packet  OR  sequence number before this number was acknowledged
    uint16_t alloc;   // sequence number

    SPP() : control(0), sst(SST::DATA), srcID(0), dstID(0), seq(0), ack(0), alloc(0) {}
    SPP(uint8_t control_, SST sst_, uint16_t srcID_, uint16_t dstID_, uint16_t seq_, uint16_t ack_, uint16_t alloc_) :
        control(control_), sst(sst_), srcID(srcID_), dstID(dstID_), seq(seq_), ack(ack_), alloc(alloc_) {}

    void read(const ByteBuffer& bb) {
        bb.read(control, sst, srcID, dstID, seq, ack, alloc);
    }
    void write(ByteBuffer& bb) const {
        bb.write(control, sst, srcID, dstID, seq, ack, alloc);
    }
    std::string toString() const {
        return std_sprintf("{%s%s%s%s%s%s  %s  %04X  %04X  %d  %d  %d}",
            system()       ? "S" : "_",
            sendAck()      ? "S" : "_",
            attention()    ? "A" : "_",
            endOfMessage() ? "E" : "_",
            negotiation()  ? "N" : "_",
            parameter()    ? "P" : "_",
            toString(sst), srcID, dstID, seq, ack, alloc);
    }

    
    bool system() const {
        return control & BIT_SYSTEM;
    }
    bool sendAck() const {
        return control & BIT_SEND_ACK;
    }
    bool attention() const {
        return control & BIT_ATTENTION;
    }
    bool endOfMessage() const {
        return control & BIT_END_OF_MESSAGE;
    }
    bool negotiation() const {
        return control & BIT_NEGOTIATION;
    }
    bool parameter() const {
        return control & BIT_PARAMETER;
    }

    void system(bool newValue) {
        control = (control & ~BIT_SYSTEM)         | (newValue ? BIT_SYSTEM : 0);
    }
    void sendAck(bool newValue) {
        control = (control & ~BIT_SEND_ACK)       | (newValue ? BIT_SEND_ACK : 0);
    }
    void attention(bool newValue) {
        control = (control & ~BIT_ATTENTION)      | (newValue ? BIT_ATTENTION : 0);
    }
    void endOfMessage(bool newValue) {
        control = (control & ~BIT_END_OF_MESSAGE) | (newValue ? BIT_END_OF_MESSAGE : 0);
    }
    void negotiation(bool newValue) {
        control = (control & ~BIT_NEGOTIATION) | (newValue ? BIT_NEGOTIATION : 0);
    }
    void parameter(bool newValue) {
        control = (control & ~BIT_PARAMETER) | (newValue ? BIT_PARAMETER : 0);
    }
    

private:
    // format of control
    //   bit 0  system packet
    //   bit 1  sent acknowledgement
    //   bit 2  attention
    //   bit 3  end of message
    //   bit 4  negotiation
    //   bit 5  parameter

    // See APilot/15.0.1/NS/Private/NewNetworkStreamImpl.mesa for negitiation and parameter
  
    static const constexpr uint8_t BIT_SYSTEM         = 0x80;
    static const constexpr uint8_t BIT_SEND_ACK       = 0x40;
    static const constexpr uint8_t BIT_ATTENTION      = 0x20;
    static const constexpr uint8_t BIT_END_OF_MESSAGE = 0x10;
    static const constexpr uint8_t BIT_NEGOTIATION    = 0x08;
    static const constexpr uint8_t BIT_PARAMETER      = 0x04;
};

}
