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
// SimpleQueue.h
//

#pragma once

#include <list>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <algorithm>

#include "../util/Util.h"

template<typename T>
class SimpleQueue {
    std::list<T>              list;
    std::mutex                mutex;
    std::condition_variable   cv;
public:
    SimpleQueue() {}

    SimpleQueue(const SimpleQueue<T>& that)  : list(that.list), mutex(), cv() {}
    SimpleQueue(SimpleQueue<T>&& that)       : list(that.list), mutex(), cv() {}

    // push data
    void push(T& data) {
        std::unique_lock<std::mutex> lock(mutex);
        list.push_front(data);
        cv.notify_one();
    }

    // pop returns data if available
    // pop return true when data has value
    bool pop(T& data, std::chrono::milliseconds duration = Util::ONE_SECOND) {
        std::unique_lock<std::mutex> lock(mutex);
        if (list.empty()) {
            cv.wait_for(lock, duration);
        }
        bool hasData = false;
        if (!list.empty()) {
            data = list.back();
            list.pop_back();
            hasData = true;
        }
        return hasData;
    }
    void clear() {
        std::unique_lock<std::mutex> lock(mutex);
        list.clear();
    }
    uint32_t size() {
        std::unique_lock<std::mutex> lock(mutex);
        return list.size();
    }
    bool empty() {
        std::unique_lock<std::mutex> lock(mutex);
        return list.empty();
    }

    using Predicate = std::function<bool(const T&)>;
    void erase_if(Predicate pred) {
        std::unique_lock<std::mutex> lock(mutex);
        std::erase_if(list.begin(), list.end(), pred);
    }
    uint32_t count_if(Predicate pred) {
        std::unique_lock<std::mutex> lock(mutex);
        return std::count_if(list.cbegin(), list.cend(), pred);
    }
};
