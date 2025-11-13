#ifndef STUB_Time_H__
#define STUB_Time_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace Time {

            // TYPE  Time  LONG_CARDINAL
            using Time = LONG_CARDINAL;

            // CONST  earliestTime  2114294400  [REF Time::Time]
            //   LONG_CARDINAL
            const Time earliestTime = 2114294400U;

            // TYPE  Type  ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]]
            enum class Type : quint16 {
                REQUEST  = 1,
                RESPONSE = 2,
            };

            // TYPE  OffsetDirection  ENUM [UNSPECIFIED [[WEST  0], [EAST  1]]]
            enum class OffsetDirection : quint16 {
                WEST = 0,
                EAST = 1,
            };

            // TYPE  ToleranceType  ENUM [UNSPECIFIED [[UNKNOWN  0], [IN_MILLI_SECONDS  1]]]
            enum class ToleranceType : quint16 {
                UNKNOWN          = 0,
                IN_MILLI_SECONDS = 1,
            };

            // TYPE  Version  CARDINAL
            using Version = CARDINAL;

            // CONST  version  2  [REF Time::Version]
            //   CARDINAL
            const Version version = 2;

            // TYPE  PacketData  [CHOICE [REF Time::Type] [[[REQUEST] => RECORD []], [[RESPONSE] => RECORD [currentTime: LONG_CARDINAL, offsetDirection: [REF Time::OffsetDirection], offsetHours: CARDINAL, offsetMinutes: CARDINAL, startOfDST: CARDINAL, endOfDST: CARDINAL, toleranceType: [REF Time::ToleranceType], tolerance: LONG_CARDINAL]]]]
            //   [CHOICE ENUM [UNSPECIFIED [[REQUEST  1], [RESPONSE  2]]] [[[REQUEST] => RECORD []], [[RESPONSE] => RECORD [currentTime: LONG_CARDINAL, offsetDirection: [REF Time::OffsetDirection], offsetHours: CARDINAL, offsetMinutes: CARDINAL, startOfDST: CARDINAL, endOfDST: CARDINAL, toleranceType: [REF Time::ToleranceType], tolerance: LONG_CARDINAL]]]]
            struct PacketData {
                struct PacketData_CHOICE_01 {
                };
                struct PacketData_CHOICE_02 {
                    LONG_CARDINAL   currentTime;
                    OffsetDirection offsetDirection;
                    CARDINAL        offsetHours;
                    CARDINAL        offsetMinutes;
                    CARDINAL        startOfDST;
                    CARDINAL        endOfDST;
                    ToleranceType   toleranceType;
                    LONG_CARDINAL   tolerance;
                };
                // Provide alias for code readability
                using PacketData_REQUEST  = PacketData_CHOICE_01;
                using PacketData_RESPONSE = PacketData_CHOICE_02;

                using CHOICE_TAG = Type;
                CHOICE_TAG choiceTag;

                PacketData_REQUEST&  REQUEST()  const;
                PacketData_RESPONSE& RESPONSE() const;
            private:
                mutable PacketData_REQUEST  choice_REQUEST;
                mutable PacketData_RESPONSE choice_RESPONSE;
            };

            // TYPE  Packet  RECORD [version: [REF Time::Version], data: [REF Time::PacketData]]
            //   RECORD [version: CARDINAL, data: [CHOICE [REF Time::Type] [[[REQUEST] => RECORD []], [[RESPONSE] => RECORD [currentTime: LONG_CARDINAL, offsetDirection: [REF Time::OffsetDirection], offsetHours: CARDINAL, offsetMinutes: CARDINAL, startOfDST: CARDINAL, endOfDST: CARDINAL, toleranceType: [REF Time::ToleranceType], tolerance: LONG_CARDINAL]]]]]
            struct Packet {
                Version    version;
                PacketData data;
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Time::Type            value);
    QString toString(const Courier::Stub::Time::OffsetDirection value);
    QString toString(const Courier::Stub::Time::ToleranceType   value);

    void serialize(BLOCK& block, const Courier::Stub::Time::Type            value);
    void serialize(BLOCK& block, const Courier::Stub::Time::OffsetDirection value);
    void serialize(BLOCK& block, const Courier::Stub::Time::ToleranceType   value);

    void deserialize(BLOCK& block, Courier::Stub::Time::Type&            value);
    void deserialize(BLOCK& block, Courier::Stub::Time::OffsetDirection& value);
    void deserialize(BLOCK& block, Courier::Stub::Time::ToleranceType&   value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Time::PacketData::PacketData_CHOICE_01& value);
    QString toString(const Courier::Stub::Time::PacketData::PacketData_CHOICE_02& value);
    QString toString(const Courier::Stub::Time::Packet&                           value);

    void serialize(BLOCK& block, const Courier::Stub::Time::PacketData::PacketData_CHOICE_01& value);
    void serialize(BLOCK& block, const Courier::Stub::Time::PacketData::PacketData_CHOICE_02& value);
    void serialize(BLOCK& block, const Courier::Stub::Time::Packet&                           value);

    void deserialize(BLOCK& block, Courier::Stub::Time::PacketData::PacketData_CHOICE_01& value);
    void deserialize(BLOCK& block, Courier::Stub::Time::PacketData::PacketData_CHOICE_02& value);
    void deserialize(BLOCK& block, Courier::Stub::Time::Packet&                           value);

    //
    // Choice Function Declaration
    //
    QString toString(const Courier::Stub::Time::PacketData& value);

    void serialize(BLOCK& block, const Courier::Stub::Time::PacketData& value);

    void deserialize(BLOCK& block, Courier::Stub::Time::PacketData& value);
}
#endif
