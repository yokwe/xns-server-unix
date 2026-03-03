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
 // CHS.cpp
 //

#include "../util/Util.h"
static const Logger logger(__FILE__);


#include "../xns/XNS.h"
#include "../service/Clearinghouse3.h"
#include "../service/Services.h"

#include "Server.h"

namespace server::CHS {
//
server::Context* context;

using namespace courier::Clearinghouse3;

RetrieveAddresses::Result RetrieveAddres() {
    logger.info("%s", __func__);

    auto host = xns::Host(context->me);
    NetworkAddress networkAddress = {context->net, host, xns::Socket::CHS};
    NetworkAddressList list{networkAddress};
    RetrieveAddresses::Result result = {list};

    logger.info("%s  %s", __func__, list.toString());

    return result;
}

void ListDomainServed(courier::Clearinghouse3::ListDomainServed::Argument argument) {
    //
    logger.info("%s  argument %s", __func__, argument.toString());
}

service::Clearinghouse3::FunctionTable functionTable {
    RetrieveAddres,
    ListDomainServed,
};


void init(server::Context& context_) {
    context = &context_;

    service::services.clearinghouse3.set(functionTable);
}

}
