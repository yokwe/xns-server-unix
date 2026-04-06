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
bool PacketQueue::contains(uint16_t seq) {
    if (empty()) return false;

    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: list) {
        if (e.seq == seq) return true;
    }
    return false;
}
void PacketQueue::add(const Packet& packet) {
    if (packet.system()) ERROR();

    std::lock_guard<std::mutex> lock(mutex);
    // sanity check
    for(auto& e: list) {
        if (e.seq == packet.seq) {
            logger.info("Duplicate seq");
            logger.info("  packet %s", packet.toString());
            logger.info("  e      %s", e.toString());
            ERROR()
        }
    }

    list.push_back(packet);
    count++;
}
void PacketQueue::remove(uint16_t seq) {
    std::lock_guard<std::mutex> lock(mutex);

    for(auto i = list.begin(); i != list.end();) {
        if (i->seq == seq) {
            list.erase(i);
            count--;
            return;
        } else {
            i++;
        }
    }
    ERROR()
}

Packet& PacketQueue::get(uint16_t seq) {
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: list) {
        if (e.seq == seq) return e;
    }
    ERROR()
}

void PacketQueue::clear() {
    std::lock_guard<std::mutex> lock(mutex);
    list.clear();
    count = 0;
}

uint32_t PacketQueue::size() {
    return count;
}
bool PacketQueue::empty() {
    return count == 0;
}

void PacketQueue::map(MapFunction function) {
    if (empty()) return;
    std::lock_guard<std::mutex> lock(mutex);
    for(auto& e: list) {
        function(e);
    }
}

void PacketQueue::mapDelete(MapDeleteFunction function) {
    if (empty()) return;
    std::lock_guard<std::mutex> lock(mutex);
    list.remove_if(function);
    count = list.size();
}

}
