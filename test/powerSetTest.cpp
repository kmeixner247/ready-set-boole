#include <gtest/gtest.h>
#include "../rsb.hpp"
#include <vector>

TEST(powerSetTest, exists) {
    std::vector<int> v;
    EXPECT_NO_THROW(powerset(v));
}