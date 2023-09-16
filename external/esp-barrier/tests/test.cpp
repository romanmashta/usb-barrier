#include "gtest/gtest.h"
#include "library.h"
#include "ArduinoFake.h"

#include "barrier/ProtocolUtil.h"
#include "barrier/protocol_types.h"
#include "io/IStream.h"
#include "base/Log.h"

#include <iostream>

TEST(BarrierLibraryTest, TestAddition) {
    using namespace fakeit;

    int (*println)(const char *) = [](const char *str) {
        std::cout << str << std::endl;
        return 0;
    };

    int (*print)(const char *) = [](const char *str) {
        std::cout << str;
        return 0;
    };

    int (*prints)(const String &s) = [](const String &s) {
        std::cout << s.c_str();
        return 0;
    };

    When(Method(ArduinoFake(), millis)).AlwaysReturn(100);
    When(Method(ArduinoFake(), delay)).AlwaysReturn();
    When(OverloadedMethod(ArduinoFake(Serial), print, size_t(const char *))).AlwaysDo(print);
    When(OverloadedMethod(ArduinoFake(Serial), print, size_t(const String&))).AlwaysDo(prints);
    When(OverloadedMethod(ArduinoFake(Serial), println, size_t(const char *))).AlwaysDo(println);

    //hello();
}

fakeit::Mock<barrier::IStream> createIStreamMock(const std::string& predefinedData, size_t& readOffset){
    fakeit::Mock<barrier::IStream> mockStream;

    fakeit::When(Method(mockStream, read)).AlwaysDo([&](void* buffer, UInt32 n) -> UInt32 {
        if (readOffset >= predefinedData.size()) {
            return 0;
        }
        size_t bytesToRead = std::min(n, static_cast<UInt32>(predefinedData.size() - readOffset));
        std::memcpy(buffer, predefinedData.data() + readOffset, bytesToRead);
        readOffset += bytesToRead;
        return bytesToRead;
    });

    fakeit::When(Method(mockStream, write)).AlwaysDo([](const void* buffer, UInt32 n) {});
    fakeit::When(Method(mockStream, isReady)).AlwaysReturn(true);

    return mockStream;
}

TEST(BarrierLibraryTest, TestProtocolUtil) {
    std::string predefinedData = "Barrier\x01\x10\x02\x20";
    size_t readOffset = 0;
    fakeit::Mock<barrier::IStream> mockStream = createIStreamMock(predefinedData, readOffset);

    barrier::IStream* stream = &mockStream.get();

    Log log;
    log.setFilter(kDEBUG5);

    UInt16 v1, v2;

    bool result = ProtocolUtil::readf(stream, kMsgHello, &v1, &v2);

    ASSERT_TRUE(result);
    ASSERT_EQ(v1, 0x0110);
    ASSERT_EQ(v2, 0x0220);
}