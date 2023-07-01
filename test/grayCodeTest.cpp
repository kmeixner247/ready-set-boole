#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(grayCodeTest, exists) {
    EXPECT_NO_THROW(gray_code(42));
}

TEST(grayCodeTest, handlesZero) {
    EXPECT_EQ(gray_code(0), 0);
}

TEST(grayCodeTest, handlesBasicInput) {
    EXPECT_EQ(gray_code(0), 0);
    EXPECT_EQ(gray_code(1), 1);
    EXPECT_EQ(gray_code(2), 3);
    EXPECT_EQ(gray_code(3), 2);
    EXPECT_EQ(gray_code(4), 6);
    EXPECT_EQ(gray_code(5), 7);
    EXPECT_EQ(gray_code(6), 5);
    EXPECT_EQ(gray_code(7), 4);
    EXPECT_EQ(gray_code(8), 12);
    EXPECT_EQ(gray_code(9), 13);
    EXPECT_EQ(gray_code(10), 15);
    EXPECT_EQ(gray_code(11), 14);
    EXPECT_EQ(gray_code(12), 10);
    EXPECT_EQ(gray_code(13), 11);
    EXPECT_EQ(gray_code(14), 9);
    EXPECT_EQ(gray_code(15), 8);
    EXPECT_EQ(gray_code(16), 24);
    EXPECT_EQ(gray_code(17), 25);
    EXPECT_EQ(gray_code(18), 27);
    EXPECT_EQ(gray_code(19), 26);
    EXPECT_EQ(gray_code(20), 30);
    EXPECT_EQ(gray_code(21), 31);
    EXPECT_EQ(gray_code(22), 29);
    EXPECT_EQ(gray_code(23), 28);
    EXPECT_EQ(gray_code(24), 20);
    EXPECT_EQ(gray_code(25), 21);
    EXPECT_EQ(gray_code(26), 23);
    EXPECT_EQ(gray_code(27), 22);
    EXPECT_EQ(gray_code(28), 18);
    EXPECT_EQ(gray_code(29), 19);
    EXPECT_EQ(gray_code(30), 17);
    EXPECT_EQ(gray_code(31), 16);
    EXPECT_EQ(gray_code(32), 48);
}