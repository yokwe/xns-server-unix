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
// ThreadConrol.cpp
//

#include <map>
#include <thread>

#include "Util.h"
static const Logger logger(__FILE__);

#include "ThreadControl.h"

std::map<std::thread::id, std::string> ThreadControl::map;

void ThreadControl::set(const std::string& name_, Function function_) {
    if (joinable()) ERROR()
    name     = name_;
    function = function_;
}
void ThreadControl::set(Function function_) {
    if (joinable()) ERROR()
    function = function_;
}

// COPY
ThreadControl::ThreadControl(const ThreadControl& that) {
    if (that.joinable())  ERROR()
    name     = that.name;
    function = that.function;
}
ThreadControl& ThreadControl::operator =(const ThreadControl& that) {
    if (that.joinable())  ERROR()
    name     = that.name;
    function = that.function;
    return *this;
}

// MOVE
ThreadControl::ThreadControl(ThreadControl&& that) {
    name     = that.name;
    function = that.function;
    thread   = std::move(that.thread);
}
ThreadControl& ThreadControl::operator =(ThreadControl&& that) {
    name     = that.name;
    function = that.function;
    thread   = std::move(that.thread);
    return *this;
}

void ThreadControl::start() {
    logger.info("thread start   %s", name);
    thread = std::thread(function);
    map[thread.get_id()] = this->name;
}

void ThreadControl::join() {
    // sanity check
    if (!joinable()) ERROR()
    logger.info("thread joining %s", name);
    thread.join();
    logger.info("thread joined  %s", name);
}

bool ThreadControl::joinable() const {
    return thread.joinable();
}
