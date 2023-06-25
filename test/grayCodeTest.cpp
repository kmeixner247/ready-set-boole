#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(grayCodeTest, exists) {
    EXPECT_NO_THROW(gray_code(42));
}

TEST(grayCodeTest, worksWithZero) {
    EXPECT_EQ(gray_code(0), 0);
}