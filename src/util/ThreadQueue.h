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
// ThreadQueue.h
//

#pragma once

#include <chrono>
#include <list>
#include <functional>
#include <mutex>

#include "../util/Util.h"


namespace thread_queue {

template<typename T>
class ThreadQueueProcessor {
    std::string             name;
    std::mutex              mutex;
    std::condition_variable cv;
    std::list<T>            list;
    static inline bool      stopThread;
public:
    ThreadQueueProcessor(const std::string& name_) : name(name_) {}
    virtual ~ThreadQueueProcessor() = default;

    virtual void process(const T& data) = 0;

    static void stop() {
        stopThread = true;
    }
    void push(const T& data) {
        std::unique_lock<std::mutex> lock(mutex);
        list.push_front(data);
        cv.notify_one();
    }
    void clear() {
        std::unique_lock<std::mutex> lock(mutex);
        list.clear();
    }
    using Predicate = std::function<bool(const T&)>;
    void erase_if(Predicate pred) {
        std::unique_lock<std::mutex> lock(mutex);
        std::erase_if(list, pred);
    }

    void run() {
        logger.info("ThreadQueue start %s", name);
        stopThread = false;
        list.clear();

        {
            std::unique_lock<std::mutex> lock(mutex);
            for(;;) {
                if (stopThread) goto exit;
                while(list.empty()) {
                    cv.wait_for(lock, Util::ONE_SECOND);
                    if (stopThread) goto exit;
                }
                while(!list.empty()) {
                    if (stopThread) goto exit;
                    T data = list.back();
                    process(data);
                    list.pop_back();
                }
            }
        }
    exit:
        logger.info("ThreadQueue stop  %s", name);
    }
};

template<typename T>
class ThreadQueueProducer {
    std::string               name;
    std::mutex                mutex;
    std::condition_variable   cv;
    std::list<T>              list;
    static inline bool        stopThread;
public:
    ThreadQueueProducer(const std::string& name_) : name(name_) {}

    virtual ~ThreadQueueProducer() = default;

    // produce return true when data has value
    virtual bool produce(T& data, std::chrono::milliseconds timeout) = 0;

    static void stop() {
        stopThread = true;
    }
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
    using Predicate = std::function<bool(const T&)>;
    void erase_if(Predicate pred) {
        std::unique_lock<std::mutex> lock(mutex);
        std::erase_if(list, pred);
    }

    void run() {
        logger.info("ThreadQueue start %s", name);
        stopThread = false;
        list.clear();

        for(;;) {
            if (stopThread) goto exit;
            T data;
            if (produce(data, Util::ONE_SECOND)) {
                list.push_front(data);
                cv.notify_one();
            }
        }
    exit:
        logger.info("ThreadQueue stop  %s", name);
        //
    }

};

}