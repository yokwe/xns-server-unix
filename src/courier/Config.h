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
 // Config.h
 //

#pragma once

#include <compare>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <unordered_map>

#include "../util/ByteBuffer.h"

namespace xns::courier {
//
struct Config {
    using CallProc = std::function<ByteBuffer(ByteBuffer&)>;

    struct Procedure {
        std::string name;
        uint16_t    procedure;
        CallProc    callProc;
    };

    struct Program {
        std::string name;
        uint32_t    program;
        uint16_t    version;
    
        std::unordered_map<uint16_t, Procedure> procedureMap;
        //                 procedure
    };

    struct Key : public HasToString {
        struct Hash {
            std::size_t operator()(const Key& value) const {
                return value.program << 16 | value.version;
            }
        };
        
        uint32_t program;
        uint16_t version;
    
        Key(uint32_t program_, uint16_t version_) : program(program_), version(version_) {}
        Key(const Program& program) : program(program.program), version(program.version) {}

        std::string toString() const override {
            return std_sprintf("{%d  %d}", program, version);
        }
    
        bool operator == (const Key& that) const {
            return program == that.program && version == that.version;
        }
    };
    
    std::unordered_map<Key, Program, Key::Hash> programMap;

    static Config getInstance(const std::string& path);
    static Config getInstance() {
        return getInstance("data/courier-config.json");
    }
};


}
