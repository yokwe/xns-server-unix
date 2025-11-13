#ifndef STUB_Time2_H__
#define STUB_Time2_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace Time2 {

            constexpr const char*   PROGRAM_NAME = "Time";
            constexpr const quint32 PROGRAM_CODE = 15;
            constexpr const quint32 VERSION_CODE = 2;

            // TYPE  Time  LONG_CARDINAL
            using Time = LONG_CARDINAL;

            // CONST  earliestTime  2114294400  [REF Time2::Time]
            //   LONG_CARDINAL
            const Time earliestTime = 2114294400U;
        }
    }
}
#endif
