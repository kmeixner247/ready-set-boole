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

TEST(multiplierTest, overflowsCorrectly) {
    uint32_t result = 20000000000 * 20000000000;
    EXPECT_EQ(multiplier(20000000000, 20000000000), result);
    result = 2147483648 * 3;
    EXPECT_EQ(multiplier(2147483648, 3), result);
}