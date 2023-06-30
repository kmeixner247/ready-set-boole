#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(isSatisfiableTest, exists) {
    std::string formula;
    EXPECT_NO_THROW(sat(formula));
}

TEST(isSatisfiableTest, asdf) {
    EXPECT_TRUE(sat("AB|"));
    EXPECT_TRUE(sat("AB&"));
    EXPECT_FALSE(sat("AA!&"));
    EXPECT_FALSE(sat("AA^"));
}