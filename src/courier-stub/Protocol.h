#ifndef STUB_Protocol_H__
#define STUB_Protocol_H__

#include "../courier/Courier.h"
#include "../courier/StreamOf.h"

namespace Courier {
    namespace Stub {
        namespace Protocol {

            // TYPE  ProtocolType  ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
            enum class ProtocolType : quint16 {
                PROTOCOL2 = 2,
                PROTOCOL3 = 3,
            };

            // TYPE  MessageType  ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]]
            enum class MessageType : quint16 {
                CALL   = 0,
                REJECT = 1,
                RETURN = 2,
                ABORT  = 3,
            };

            // TYPE  RejectCode  ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]]
            enum class RejectCode : quint16 {
                NO_SUCH_PROGRAM_NUMBER   = 0,
                NO_SUCH_VERSION_NUMBER   = 1,
                NO_SUCH_PROCEDURE_NUMBER = 2,
                INALID_ARGUMENTS         = 3,
            };

            // TYPE  Protocol2  [CHOICE [REF Protocol::MessageType] [[[CALL] => RECORD [transaction: CARDINAL, program: CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, rejectCode: [REF Protocol::RejectCode]]]]]
            //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, rejectCode: [REF Protocol::RejectCode]]]]]
            struct Protocol2 {
                struct Protocol2_CHOICE_01 {
                    CARDINAL transaction;
                    CARDINAL program;
                    CARDINAL version;
                    CARDINAL procedure;
                    BLOCK    data{nullptr, 0};
                };
                struct Protocol2_CHOICE_02 {
                    CARDINAL transaction;
                    BLOCK    data{nullptr, 0};
                };
                struct Protocol2_CHOICE_03 {
                    CARDINAL transaction;
                    CARDINAL abortCode;
                    BLOCK    data{nullptr, 0};
                };
                struct Protocol2_CHOICE_04 {
                    CARDINAL   transaction;
                    RejectCode rejectCode;
                };
                // Provide alias for code readability
                using Protocol2_CALL   = Protocol2_CHOICE_01;
                using Protocol2_RETURN = Protocol2_CHOICE_02;
                using Protocol2_ABORT  = Protocol2_CHOICE_03;
                using Protocol2_REJECT = Protocol2_CHOICE_04;

                using CHOICE_TAG = MessageType;
                CHOICE_TAG choiceTag;

                Protocol2_CALL&   CALL()   const;
                Protocol2_RETURN& RETURN() const;
                Protocol2_ABORT&  ABORT()  const;
                Protocol2_REJECT& REJECT() const;
            private:
                mutable Protocol2_CALL   choice_CALL;
                mutable Protocol2_RETURN choice_RETURN;
                mutable Protocol2_ABORT  choice_ABORT;
                mutable Protocol2_REJECT choice_REJECT;
            };

            // TYPE  ProtocolRange  RECORD [low: [REF Protocol::ProtocolType], high: [REF Protocol::ProtocolType]]
            //   RECORD [low: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]], high: ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]]
            struct ProtocolRange {
                ProtocolType low;
                ProtocolType high;
            };

            // TYPE  VersionRange  RECORD [low: CARDINAL, high: CARDINAL]
            struct VersionRange {
                CARDINAL low;
                CARDINAL high;
            };

            // CONST  pvLow  [Const REF PROTOCOL2]  [REF Protocol::ProtocolType]
            //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
            const ProtocolType pvLow = ProtocolType::PROTOCOL2;

            // CONST  pvHigh  [Const REF PROTOCOL3]  [REF Protocol::ProtocolType]
            //   ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]]
            const ProtocolType pvHigh = ProtocolType::PROTOCOL3;

            // TYPE  Reject  [CHOICE [REF Protocol::RejectCode] [[[NO_SUCH_PROGRAM_NUMBER, NO_SUCH_PROCEDURE_NUMBER, INALID_ARGUMENTS] => RECORD []], [[NO_SUCH_VERSION_NUMBER] => RECORD [range: [REF Protocol::VersionRange]]]]]
            //   [CHOICE ENUM [UNSPECIFIED [[NO_SUCH_PROGRAM_NUMBER  0], [NO_SUCH_VERSION_NUMBER  1], [NO_SUCH_PROCEDURE_NUMBER  2], [INALID_ARGUMENTS  3]]] [[[NO_SUCH_PROGRAM_NUMBER, NO_SUCH_PROCEDURE_NUMBER, INALID_ARGUMENTS] => RECORD []], [[NO_SUCH_VERSION_NUMBER] => RECORD [range: [REF Protocol::VersionRange]]]]]
            struct Reject {
                struct Reject_CHOICE_01 {
                };
                struct Reject_CHOICE_02 {
                    VersionRange range;
                };
                // Provide alias for code readability
                using Reject_NO_SUCH_PROGRAM_NUMBER   = Reject_CHOICE_01;
                using Reject_NO_SUCH_PROCEDURE_NUMBER = Reject_CHOICE_01;
                using Reject_INALID_ARGUMENTS         = Reject_CHOICE_01;
                using Reject_NO_SUCH_VERSION_NUMBER   = Reject_CHOICE_02;

                using CHOICE_TAG = RejectCode;
                CHOICE_TAG choiceTag;

                Reject_NO_SUCH_PROGRAM_NUMBER&   NO_SUCH_PROGRAM_NUMBER()   const;
                Reject_NO_SUCH_PROCEDURE_NUMBER& NO_SUCH_PROCEDURE_NUMBER() const;
                Reject_INALID_ARGUMENTS&         INALID_ARGUMENTS()         const;
                Reject_NO_SUCH_VERSION_NUMBER&   NO_SUCH_VERSION_NUMBER()   const;
            private:
                mutable Reject_NO_SUCH_PROGRAM_NUMBER   choice_NO_SUCH_PROGRAM_NUMBER;
                mutable Reject_NO_SUCH_PROCEDURE_NUMBER choice_NO_SUCH_PROCEDURE_NUMBER;
                mutable Reject_INALID_ARGUMENTS         choice_INALID_ARGUMENTS;
                mutable Reject_NO_SUCH_VERSION_NUMBER   choice_NO_SUCH_VERSION_NUMBER;
            };

            // TYPE  Protocol3  [CHOICE [REF Protocol::MessageType] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
            //   [CHOICE ENUM [UNSPECIFIED [[CALL  0], [REJECT  1], [RETURN  2], [ABORT  3]]] [[[CALL] => RECORD [transaction: CARDINAL, program: LONG_CARDINAL, version: CARDINAL, procedure: CARDINAL, data: BLOCK]], [[RETURN] => RECORD [transaction: CARDINAL, data: BLOCK]], [[ABORT] => RECORD [transaction: CARDINAL, abortCode: CARDINAL, data: BLOCK]], [[REJECT] => RECORD [transaction: CARDINAL, reject: [REF Protocol::Reject]]]]]
            struct Protocol3 {
                struct Protocol3_CHOICE_01 {
                    CARDINAL      transaction;
                    LONG_CARDINAL program;
                    CARDINAL      version;
                    CARDINAL      procedure;
                    BLOCK         data{nullptr, 0};
                };
                struct Protocol3_CHOICE_02 {
                    CARDINAL transaction;
                    BLOCK    data{nullptr, 0};
                };
                struct Protocol3_CHOICE_03 {
                    CARDINAL transaction;
                    CARDINAL abortCode;
                    BLOCK    data{nullptr, 0};
                };
                struct Protocol3_CHOICE_04 {
                    CARDINAL transaction;
                    Reject   reject;
                };
                // Provide alias for code readability
                using Protocol3_CALL   = Protocol3_CHOICE_01;
                using Protocol3_RETURN = Protocol3_CHOICE_02;
                using Protocol3_ABORT  = Protocol3_CHOICE_03;
                using Protocol3_REJECT = Protocol3_CHOICE_04;

                using CHOICE_TAG = MessageType;
                CHOICE_TAG choiceTag;

                Protocol3_CALL&   CALL()   const;
                Protocol3_RETURN& RETURN() const;
                Protocol3_ABORT&  ABORT()  const;
                Protocol3_REJECT& REJECT() const;
            private:
                mutable Protocol3_CALL   choice_CALL;
                mutable Protocol3_RETURN choice_RETURN;
                mutable Protocol3_ABORT  choice_ABORT;
                mutable Protocol3_REJECT choice_REJECT;
            };

            // TYPE  Message  [CHOICE [REF Protocol::ProtocolType] [[[PROTOCOL2] => RECORD [protocol2: [REF Protocol::Protocol2]]], [[PROTOCOL3] => RECORD [protocol3: [REF Protocol::Protocol3]]]]]
            //   [CHOICE ENUM [UNSPECIFIED [[PROTOCOL2  2], [PROTOCOL3  3]]] [[[PROTOCOL2] => RECORD [protocol2: [REF Protocol::Protocol2]]], [[PROTOCOL3] => RECORD [protocol3: [REF Protocol::Protocol3]]]]]
            struct Message {
                struct Message_CHOICE_01 {
                    Protocol2 protocol2;
                };
                struct Message_CHOICE_02 {
                    Protocol3 protocol3;
                };
                // Provide alias for code readability
                using Message_PROTOCOL2 = Message_CHOICE_01;
                using Message_PROTOCOL3 = Message_CHOICE_02;

                using CHOICE_TAG = ProtocolType;
                CHOICE_TAG choiceTag;

                Message_PROTOCOL2& PROTOCOL2() const;
                Message_PROTOCOL3& PROTOCOL3() const;
            private:
                mutable Message_PROTOCOL2 choice_PROTOCOL2;
                mutable Message_PROTOCOL3 choice_PROTOCOL3;
            };
        }
    }

    //
    // Enum Function Declaration
    //
    QString toString(const Courier::Stub::Protocol::ProtocolType value);
    QString toString(const Courier::Stub::Protocol::MessageType  value);
    QString toString(const Courier::Stub::Protocol::RejectCode   value);

    void serialize(BLOCK& block, const Courier::Stub::Protocol::ProtocolType value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::MessageType  value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::RejectCode   value);

    void deserialize(BLOCK& block, Courier::Stub::Protocol::ProtocolType& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::MessageType&  value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::RejectCode&   value);

    //
    // Record Function Declaration
    //
    QString toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_01& value);
    QString toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_02& value);
    QString toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_03& value);
    QString toString(const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_04& value);
    QString toString(const Courier::Stub::Protocol::ProtocolRange&                  value);
    QString toString(const Courier::Stub::Protocol::VersionRange&                   value);
    QString toString(const Courier::Stub::Protocol::Reject::Reject_CHOICE_01&       value);
    QString toString(const Courier::Stub::Protocol::Reject::Reject_CHOICE_02&       value);
    QString toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_01& value);
    QString toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_02& value);
    QString toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_03& value);
    QString toString(const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_04& value);
    QString toString(const Courier::Stub::Protocol::Message::Message_CHOICE_01&     value);
    QString toString(const Courier::Stub::Protocol::Message::Message_CHOICE_02&     value);

    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_01& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_02& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_03& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_04& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::ProtocolRange&                  value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::VersionRange&                   value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Reject::Reject_CHOICE_01&       value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Reject::Reject_CHOICE_02&       value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_01& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_02& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_03& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_04& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Message::Message_CHOICE_01&     value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Message::Message_CHOICE_02&     value);

    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_01& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_02& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_03& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2::Protocol2_CHOICE_04& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::ProtocolRange&                  value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::VersionRange&                   value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Reject::Reject_CHOICE_01&       value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Reject::Reject_CHOICE_02&       value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_01& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_02& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_03& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3::Protocol3_CHOICE_04& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Message::Message_CHOICE_01&     value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Message::Message_CHOICE_02&     value);

    //
    // Choice Function Declaration
    //
    QString toString(const Courier::Stub::Protocol::Protocol2& value);
    QString toString(const Courier::Stub::Protocol::Reject&    value);
    QString toString(const Courier::Stub::Protocol::Protocol3& value);
    QString toString(const Courier::Stub::Protocol::Message&   value);

    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol2& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Reject&    value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Protocol3& value);
    void serialize(BLOCK& block, const Courier::Stub::Protocol::Message&   value);

    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol2& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Reject&    value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Protocol3& value);
    void deserialize(BLOCK& block, Courier::Stub::Protocol::Message&   value);
}
#endif
