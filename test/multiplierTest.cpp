    #include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(multiplierTest, worksWithZeros) {
    EXPECT_EQ(multiplier(0, 0), 0 * 0);
    EXPECT_EQ(multiplier(0, 1), 0 * 1);
    EXPECT_EQ(multiplier(1, 0), 1 * 0);
    EXPECT_EQ(multiplier(15, 0), 15 * 0);
    EXPECT_EQ(multiplier(0, 12341223), 0 * 12341223);
    EXPECT_EQ(multiplier(0, 4294967295), 0 * 4294967295);
    EXPECT_EQ(multiplier(4294967295, 0), 4294967295 * 0);
}

TEST(multiplierTest, worksWithOnes) {
    EXPECT_EQ(multiplier(1, 1), 1 * 1);
    EXPECT_EQ(multiplier(1, 2), 1 * 2);
    EXPECT_EQ(multiplier(2, 1), 2 * 1);
}

TEST(multiplierTest, worksWithBasicNumbers) {
    EXPECT_EQ(multiplier(2, 2), 2 * 2);
    EXPECT_EQ(multiplier(2, 6), 2 * 6);
    EXPECT_EQ(multiplier(12, 12), 12 * 12);
    EXPECT_EQ(multiplier(1000, 10000), 100 * 100000);
    EXPECT_EQ(multiplier(69, 69), 69 * 69);
}

TEST(multiplierTest, isCommutative) {
    EXPECT_EQ(multiplier(123, 321), multiplier(321, 123));
    EXPECT_EQ(multiplier(921, 55555), multiplier(55555, 921));
}


    TEST(multiplierTest, hasConstantTimeComplexity) {
        auto startTime = std::chrono::high_resolution_clock::now();
        uint32_t a = 4294967295;
        uint32_t b = 4294967295;
        for (size_t i = 0; i < 100000; i++) {
            multiplier(a, b);
        }
        auto sampleTime = std::chrono::high_resolution_clock::now() - startTime;
        for (size_t i = 1; i < 1000000000; i *= 10) {
            startTime = std::chrono::high_resolution_clock::now();
            for (size_t j = 0; j < 100000; j++) {
                multiplier(i, i);
            }
            auto endTime = std::chrono::high_resolution_clock::now() - startTime;
            EXPECT_LE(endTime.count(), sampleTime.count() * 2) << "Execution time for " << i << " exceeds twice that of MAX_UINT";
        }
    }