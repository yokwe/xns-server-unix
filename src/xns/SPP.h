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
#include <compare>

namespace xns {
//

class SPP {
public:
    enum class SST : uint8_t {
        ENUM_NAME_VALUE(SST, DATA,          0) // for all Courier messages
        ENUM_NAME_VALUE(SST, BULK,          1) // for bulk data
        ENUM_NAME_VALUE(SST, CLOSE,       254) // for closing connection
        ENUM_NAME_VALUE(SST, CLOSE_REPLY, 255) // for reply of closing connection (handshake)
    };
    static std::string toString(SST value);

    // function for seq comparison
    // return true when a is before b
    static inline constexpr bool isBefore(uint16_t a, uint16_t b) {
        if (a < b) {
            // a = 10  b =    20 => diff =    10 => true
            // a = 10  b = 65530 => diff = 65520 => false
            auto diff = b - a;
            return diff < 30000;
        } else if (a > b) {
            // a =    20  b = 10  => diff =    20 => false
            // a = 65530  b = 10  => diff = 65520 => true
            auto diff = a - b;
            return 30000 < diff;
        } else {
            return false;
        }
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
        return std_sprintf("{%s%s%s%s  %s  %04X  %04X  %d  %d  %d}",
            system()       ? "S" : "_",
            sendAck()      ? "S" : "_",
            attention()    ? "A" : "_",
            endOfMessage() ? "E" : "_",
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

private:
    // format of control
    //   bit 0  system packet
    //   bit 1  sent acknowledgement
    //   bit 2  attention
    //   bit 3  end of message
    static const constexpr uint8_t BIT_SYSTEM         = 0x80;
    static const constexpr uint8_t BIT_SEND_ACK       = 0x40;
    static const constexpr uint8_t BIT_ATTENTION      = 0x20;
    static const constexpr uint8_t BIT_END_OF_MESSAGE = 0x10;
};

}
