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
 // Packet.cpp
 //

#include <functional>

#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "Packet.h"

namespace spp {
//
void PacketQueue::add(const Packet& packet) {
    std::lock_guard<std::mutex> lock(mutex);
    // sanity check
    for(auto& e: vector) {
        if (!e.vacant && e.packet.seq == packet.seq) ERROR()
    }

    for(auto& e: vector) {
        if (e.vacant) {
            e.vacant = false;
            e.packet = packet;
            count++;
            return;
        }
    }
    ERROR()
}
void PacketQueue::remove(uint16_t seq) {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: vector) {
        if (!e.vacant && e.packet.seq == seq) {
            e.vacant = true;
            count--;
            return;
        }
    }
    ERROR()
}

bool PacketQueue::contains(uint16_t seq) {
    if (empty()) return false;

    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: vector) {
        if (!e.vacant && e.packet.seq == seq) return true;
    }
    return false;
}

Packet& PacketQueue::get(uint16_t seq) {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: vector) {
        if (!e.vacant && e.packet.seq == seq) {
            return e.packet;
        }
    }
    ERROR()
}

void PacketQueue::clear() {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: vector) {
        e.vacant = true;
    }
    count = 0;
}

bool PacketQueue::empty() {
    return count == 0;
}

void PacketQueue::map(MapFunction function) {
    if (empty()) return;
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: vector) {
        if (!e.vacant) function(e.packet);
    }
}

void PacketQueue::mapDelete(MapDeleteFunction function) {
    if (empty()) return;
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: vector) {
        if (!e.vacant) {
            if (function(e.packet)) e.vacant = true;
        }
    }
}

}
