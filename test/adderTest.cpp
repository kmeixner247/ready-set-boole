#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(adderTest, worksWithZeros) {
    EXPECT_EQ(adder(0, 0), 0);
    EXPECT_EQ(adder(0, 1), 1);
    EXPECT_EQ(adder(1, 0), 1);
    EXPECT_EQ(adder(15, 0), 15);
    EXPECT_EQ(adder(0, 12341223), 12341223);
    EXPECT_EQ(adder(0, 4294967295), 4294967295);
    EXPECT_EQ(adder(4294967295, 0), 4294967295);
}

TEST(adderTest, worksWithBasicNumbers) {
    EXPECT_EQ(adder(1, 1), 2);
    EXPECT_EQ(adder(1, 5), 6);
    EXPECT_EQ(adder(51231, 5), 51236);
    EXPECT_EQ(adder(41, 5161231), 5161272);
    EXPECT_EQ(adder(4444, 5555), 9999);
}

TEST(adderTest, overflowsCorrectly) {
    EXPECT_EQ(adder(4294967295, 1), 0);
    EXPECT_EQ(adder(4294967295, 5), 4);
}

TEST(adderTest, hasConstantTimeComplexity) {
    auto startTime = std::chrono::high_resolution_clock::now();
    uint32_t a = 4294967295;
    uint32_t b = 4294967295;
    for (size_t i = 0; i < 100000; i++) {
        adder(a, b);
    }
    auto sampleTime = std::chrono::high_resolution_clock::now() - startTime;
    for (size_t i = 1; i < 1000000000; i *= 10) {
        startTime = std::chrono::high_resolution_clock::now();
        for (size_t j = 0; j < 100000; j++) {
            adder(i, i);
        }
        auto endTime = std::chrono::high_resolution_clock::now() - startTime;
        EXPECT_LE(endTime.count(), sampleTime.count() * 2) << "Execution time for " << i << " exceeds twice that of MAX_UINT";
    }
}
