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

#include "../util/Util.h"
#include "../util/ByteBuffer.h"

#include "Courier.h"

namespace courier::service {
//
struct ProcedureBase {
    virtual uint16_t           getValue() const = 0;
    virtual const std::string& getName()  const = 0;

    virtual void call(const ByteBuffer& bbIn, ByteBuffer& bbOut) const = 0; // called from network input

    ProcedureBase() {}
    virtual ~ProcedureBase() {}
};

template<typename T>
struct Procedure : public ProcedureBase {
    using A = T::Argument;
    using R = T::Result;
    Procedure(uint16_t value_, const char* name_) : ProcedureBase(), value(value_), name(name_), function(0) {}

    uint16_t getValue() const override {
        return value;
    }
    const std::string& getName() const override {
        return name;
    }

    using Function = T::Function;

    void set(Function newValue) {
        function = newValue;
    }
    bool hasFunction() {
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
    uint16_t    value;
    std::string name;
    Function    function;
};

struct Program {
    uint32_t getNumber() const {
        return number;
    }
    uint16_t getVersion() const {
        return version;
    }
    const std::string& getName() const {
        return name;
    }

    Program (uint32_t number_, uint16_t version_, const std::string& name_) : number(number_), version(version_), name(name_) {}

protected:
    const uint32_t    number;
    const uint16_t    version;
    const std::string name;

    std::vector<ProcedureBase*> procedureList;
};

void call(const ByteBuffer& in, ByteBuffer& out);

}
