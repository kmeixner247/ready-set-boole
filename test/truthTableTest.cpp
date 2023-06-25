#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(truthTableTest, exists) {
    std::string formula;
    EXPECT_NO_THROW(print_truth_table(formula));
}

TEST(truthTableTest, lolTest) {
    std::string formula("AB&C|");
    EXPECT_NO_THROW(print_truth_table(formula));
}
