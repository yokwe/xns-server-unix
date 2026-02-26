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
// Service.h
//

#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include "../util/ByteBuffer.h"

namespace service {
//
struct ProcedureBase {
    virtual uint16_t           getValue() = 0;
    virtual const std::string& getName()  = 0;

    virtual bool hasFunction() const = 0;
    virtual void call(const ByteBuffer& in, ByteBuffer& out) const = 0; // called from network input

    ProcedureBase() {}
    virtual ~ProcedureBase() {}
};

template<typename T>
struct Procedure : public ProcedureBase {
    using A        = T::Argument;
    using R        = T::Result;
    using Function = T::Function;

    uint16_t getValue() override {
        return value;
    }
    const std::string& getName() override {
        return name;
    }

    Procedure(uint16_t value_, const char* name_) : ProcedureBase(), value(value_), name(name_), function(0) {}

    void set(Function newValue) {
        function = newValue;
    }
    bool hasFunction() const override {
        return function != 0;
    }

    void call(const ByteBuffer& in, ByteBuffer& out) const override {
        if constexpr (std::is_void_v<A>) {
            if constexpr (std::is_void_v<R>) {
                function();
            } else {
                R result = function();
                out.write(result);
            }
        } else {
            A argument = in.get<A>();
            if constexpr (std::is_void_v<R>) {
                function(argument);
            } else {
                R result = function(argument);
                out.write(result);
            }
        }
        if (in.byteRemains() != 0) {
            // input data is still remaining
            // something goes wrong
            // FIXME
        }
    }

private:
    const uint16_t    value;
    const std::string name;

    Function          function;
};

struct ErrorBase {
    const uint16_t       value;
    const std::string    name;

    ErrorBase(uint16_t value_, const std::string name_) : value(value_), name(name_) {}
};

struct Service {
    uint32_t getNumber() const {
        return number;
    }
    uint16_t getVersion() const {
        return version;
    }
    const std::string& getName() const {
        return name;
    }

    Service (uint32_t number_, uint16_t version_, const std::string& name_) : number(number_), version(version_), name(name_) {}

    ProcedureBase* getProcedure(uint16_t value) {
        for(auto e: procedureList) {
            if (e->getValue() == value) return e;
        }
        return 0;
    }

protected:
    const uint32_t    number;
    const uint16_t    version;
    const std::string name;

    std::vector<ProcedureBase*> procedureList;
};

struct ServicesBase {
    std::vector<Service*> getService(uint32_t number) {
        std::vector<Service*> ret;
        for(auto e: serviceList) {
            if (e->getNumber() == number) ret.push_back(e);
        }
        return ret;
    }
    Service* getService(uint32_t number, uint16_t version) {
        for(auto e: serviceList) {
            if (e->getNumber() == number && e->getVersion() == version) return e;
        }
        return 0;
    }

protected:
    std::vector<Service*> serviceList;
};

void call(const ByteBuffer& in, ByteBuffer& out);

}
