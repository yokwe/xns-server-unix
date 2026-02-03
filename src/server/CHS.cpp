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

#include "../util/Debug.h"
#include "../util/Util.h"
static const Logger logger(__FILE__);

#include "../util/ByteBuffer.h"

#include "../courier/Courier.h"

#include "Server.h"

namespace server::CHS {
//

// RetrieveAddresses: PROCEDURE
// RETURNS [address: NetworkAddressList]
// REPORTS [CallError] = 0;

// NetworkAddress: TYPE = RECORD [
// 	network: ARRAY 2 OF UNSPECIFIED,
// 	host: ARRAY 3 OF UNSPECIFIED,
// 	socket: UNSPECIFIED ];
// NetworkAddressList: TYPE = SEQUENCE 40 OF NetworkAddress;

using namespace courier::expedited;

ByteBuffer process(ByteBuffer& rx, Context& context) {
    (void)context;
    CallMessage rxHeader;

    rx.read(rxHeader);
    if (SHOW_PACKET_TIME) logger.info("CHS  >>  %s", rxHeader.toString());
    if (rx.remains()) ERROR()

    auto program = rxHeader.message.programNumber;
    auto version = rxHeader.message.versionNumber;
    auto procedure = rxHeader.message.procedureValue;

    courier::Config::Key key{program, version};
    auto prog = context.courier.programMap.at(key);
    auto proc = prog.procedureMap.at(procedure);
    logger.info("%s  %s", prog.name, proc.name);

    // auto txHeader = call(rxHeader, context);
    // if (SHOW_PACKET_TIME) logger.info("TIME <<  %s", txHeader.toString());

    auto tx = getByteBuffer();
    // tx.write(txHeader);
    return tx;
}


}
