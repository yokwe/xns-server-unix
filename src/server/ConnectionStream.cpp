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
 // ConnectionStream.cpp
 //

 #include "../util/Util.h"
static const Logger logger(__FILE__);

#include "Packet.h"
#include "Connection.h"
#include "ConnectionStream.h"

namespace server {
//
ConnectionStream::ConnectionStream(Connection& connection_) : connection(connection_) {
    // FIXME
}

Result   ConnectionStream::get(Data& data) {
    if (connection.closed()) {
        return Result(Reason::endOfStream, false, 0);
    }

    Packet packet;
    auto timeoutDuration = std::chrono::milliseconds(timeoutValue);
    auto hasData = connection.clientQueue.pop(packet, timeoutDuration);

    Reason reason;
    if (hasData) {
        data = packet.data;
        reason = Reason::normal;
    } else {
        reason = connection.closed() ? Reason::endOfStream : Reason::timeout;
    }

    return Result(reason, packet.endOfMessage(), packet.sst());
}
void     ConnectionStream::put(Data& data, bool endOfMessage, uint8_t sst) {
    connection.transmitUser(sst, false, endOfMessage, data);
}

void     ConnectionStream::attention(uint8_t value) {
    connection.transmitAttention(value);
}
int      ConnectionStream::attention() { // return -1 when no attention
    return connection.attention();
}

uint32_t ConnectionStream::timeout() { // unit is milliseconds
    return timeoutValue;
}               
void     ConnectionStream::timeout(uint32_t value) { // unit is milliseconds
    timeoutValue = value;
}

}
