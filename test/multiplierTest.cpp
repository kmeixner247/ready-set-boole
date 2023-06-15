#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(multiplierTest, worksWithZeros) {
    EXPECT_EQ(multiplier(0, 0), 0);
    EXPECT_EQ(multiplier(0, 1), 0);
    EXPECT_EQ(multiplier(1, 0), 0);
    EXPECT_EQ(multiplier(15, 0), 0);
    EXPECT_EQ(multiplier(0, 12341223), 0);
    EXPECT_EQ(multiplier(0, 4294967295), 0);
    EXPECT_EQ(multiplier(4294967295, 0), 0);
}

TEST(multiplierTest, worksWithOnes) {
    EXPECT_EQ(multiplier(1, 1), 1);
    EXPECT_EQ(multiplier(1, 2), 2);
    EXPECT_EQ(multiplier(2, 1), 2);

    EXPECT_EQ(multiplier(2, 2), 4);
    EXPECT_EQ(multiplier(2, 6), 12);
    EXPECT_EQ(multiplier(12, 12), 144);
    EXPECT_EQ(multiplier(1000, 10000), 10000000);
    EXPECT_EQ(multiplier(69, 69), 69*69);
}