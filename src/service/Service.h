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
#include "../util/net.h"

#include "../courier/Courier3.h"

namespace service {
//
const uint32_t MAX_PACKET_SIZE = net::maxBytesPerEthernetPacket;
inline ByteBuffer getByteBuffer() {
    return ByteBuffer(MAX_PACKET_SIZE);
}

//
// Procedure
//
struct ProcedureBase {
    const uint16_t    value;
    const std::string name;

    virtual bool hasFunction() const = 0;
    virtual ByteBuffer call(const ByteBuffer& bb) const = 0; // called from network input

    ProcedureBase(uint16_t value_, const char* name_) : value(value_), name(name_) {}

    virtual ~ProcedureBase() {}
};

template<typename T>
struct Procedure : public ProcedureBase {
    using A        = T::Argument;
    using R        = T::Result;
    using Function = T::Function;

    Procedure(uint16_t value_, const char* name_) : ProcedureBase(value_, name_), function(0) {}

    void set(Function newValue) {
        function = newValue;
    }
    bool hasFunction() const override {
        return function != 0;
    }

    ByteBuffer call(const ByteBuffer& rx) const override {
        ByteBuffer tx = getByteBuffer();
        if constexpr (std::is_void_v<A>) {
            if constexpr (std::is_void_v<R>) {
                function();
            } else {
                R result = function();
                tx.write(result);
            }
        } else {
            A argument = rx.get<A>();
            if constexpr (std::is_void_v<R>) {
                function(argument);
            } else {
                R result = function(argument);
                tx.write(result);
            }
        }
        if (rx.byteRemains() != 0) {
            // input data is still remaining
            // something goes wrong
            // FIXME
        }
        return tx;
    }

private:
    Function          function;
};

//
// Reject
//
struct RejectBase {
    const uint16_t       value;
    const std::string    name;

    RejectBase(uint16_t value_, const std::string name_) : value(value_), name(name_) {}
    virtual ~RejectBase() {}

    virtual void read(const ByteBuffer& bb) = 0;
    virtual void write(ByteBuffer& bb) const = 0;
    virtual std::string toString() const = 0;

    using RejectDetails = courier::Courier3::RejectMessage::RejectDetails;
    virtual RejectDetails toRejectDetail() const = 0;
};
struct NoSuchProgramNumberReject : public RejectBase {
    inline static const constexpr uint16_t VALUE = 0;
    inline static const constexpr char*    NAME  = "NoSuchProgramNumberReject";
    
    NoSuchProgramNumberReject() : RejectBase(VALUE, NAME) {}

    inline void read(const ByteBuffer& bb) override {
        bb.read(value);
    }
    inline void write(ByteBuffer& bb) const override {
        bb.write(value);
    }
    inline std::string toString() const override {
        return "{" + ::toString(value) + "}";
    }

    RejectDetails toRejectDetail() const override {
        return RejectDetails::getNoSuchProgramNumber();
    }
};
struct NoSuchVersionNumberReject : public RejectBase {
    inline static const constexpr uint16_t VALUE = 1;
    inline static const constexpr char*    NAME  = "NoSuchVersionNumberReject";
    
    NoSuchVersionNumberReject() : RejectBase(VALUE, NAME) {}
    NoSuchVersionNumberReject(courier::Courier3::VersionRange versionRange_) : RejectBase(VALUE, NAME), versionRange(versionRange_) {}
    
    courier::Courier3::VersionRange versionRange;

    inline void read(const ByteBuffer& bb) override {
        bb.read(value, versionRange);
    }
    inline void write(ByteBuffer& bb) const override{
        bb.write(value, versionRange);
    }
    inline std::string toString() const override {
        return "{" + ::toString(value) + ::toString(versionRange) + "}";
    }

    RejectDetails toRejectDetail() const override {
        return RejectDetails::getNoSuchVersionNumber(versionRange);
    }
};
struct NoSuchProcedureValueReject : public RejectBase {
    inline static const constexpr uint16_t VALUE = 2;
    inline static const constexpr char*    NAME  = "NoSuchProcedureValueReject";

    NoSuchProcedureValueReject() : RejectBase(VALUE, NAME) {}

    inline void read(const ByteBuffer& bb) override {
        bb.read(value);
    }
    inline void write(ByteBuffer& bb) const override{
        bb.write(value);
    }
    inline std::string toString() const override {
        return "{" + ::toString(value) +  "}";
    }

    RejectDetails toRejectDetail() const override {
        return RejectDetails::getNoSuchProcedureValue();
    }
};
struct InvalidArgumentReject : public RejectBase {
    inline static const constexpr uint16_t VALUE = 3;
    inline static const constexpr char*    NAME  = "InvalidArgumentReject";

    InvalidArgumentReject() : RejectBase(VALUE, NAME) {}

    inline void read(const ByteBuffer& bb) override {
        bb.read(value);
    }
    inline void write(ByteBuffer& bb) const override{
        bb.write(value);
    }
    inline std::string toString() const override {
        return "{" + ::toString(value) +  "}";
    }

    RejectDetails toRejectDetail() const override {
        return RejectDetails::getInvalidArgument();
    }
};
struct UnspecifiedReject : public RejectBase {
    inline static const constexpr uint16_t VALUE = 4;
    inline static const constexpr char*    NAME  = "UnspecifiedReject";

    UnspecifiedReject() : RejectBase(VALUE, NAME) {}

    inline void read(const ByteBuffer& bb) override {
        bb.read(value);
    }
    inline void write(ByteBuffer& bb) const override{
        bb.write(value);
    }
    inline std::string toString() const override {
        return "{" + ::toString(value) +  "}";
    }

    RejectDetails toRejectDetail() const override {
        return RejectDetails::getUnspecified();
    }
};

//
// ServiceBase
//
struct ServiceBase {
    const uint32_t    number;
    const uint16_t    version;
    const std::string name;

    ServiceBase(uint32_t number_, uint16_t version_, const std::string& name_) : number(number_), version(version_), name(name_) {}

    ProcedureBase* getProcedure(uint16_t value) {
        for(auto e: procedureList) {
            if (e->value == value) return e;
        }
        return 0;
    }

protected:
    std::vector<ProcedureBase*> procedureList;
};

//
// ServicesBase
//
struct ServicesBase {
    ServicesBase(const std::vector<ServiceBase*>& serviceList_) : serviceList(serviceList_) {}

    std::vector<ServiceBase*> getService(uint32_t number) {
        std::vector<ServiceBase*> ret;
        for(auto e: serviceList) {
            if (e->number == number) ret.push_back(e);
        }
        return ret;
    }
    ServiceBase* getService(uint32_t number, uint16_t version) {
        for(auto e: serviceList) {
            if (e->number == number && e->version == version) return e;
        }
        return 0;
    }

    ByteBuffer call(const ByteBuffer& rx);
    ByteBuffer callExpedited(const ByteBuffer& rx);

protected:
    std::vector<ServiceBase*> serviceList;
};

}
