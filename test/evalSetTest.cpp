#include <gtest/gtest.h>
#include "../rsb.hpp"
#include "../src/Set.hpp"
#include <vector>

void testEvalSet(const String& formula, const IntVectorVector& sets, const IntVector& expectedSet) {
    EXPECT_EQ(Set(eval_set(formula, sets)), Set(expectedSet));
}

TEST(evalSetTest, failsOnInvalidFormulas) {
    IntVectorVector sets({{1, 2, 3}, {3, 4, 5}});
    EXPECT_ANY_THROW(eval_set("", sets));
    EXPECT_ANY_THROW(eval_set("AA", sets));
    EXPECT_ANY_THROW(eval_set("A&", sets));
    EXPECT_ANY_THROW(eval_set("A|", sets));
    EXPECT_ANY_THROW(eval_set("!", sets));
}
TEST(evalSetTest, handlesNegation) {
    testEvalSet("A!", {{0, 1, 2}}, {});
}

TEST(evalSetTest, handlesConjunction) {
    testEvalSet("AB&", {{0, 1, 2}, {0, 3, 4}}, {0});
}

TEST(evalSetTest, handlesDisjunction) {
    testEvalSet("AB|", {{0, 1, 2}, {3, 4, 5}}, {0, 1, 2, 3, 4, 5});
}

TEST(evalSetTest, handlesExclusiveDisjunction) {
    testEvalSet("AB^", {{0, 1, 2}, {0, 3, 4}, {55}}, {0, 55});
}

TEST(evalSetTest, handlesMaterialCondition) {
    testEvalSet("AB>", {{0, 1, 2}, {2, 4, 5}, {55}}, {4, 5, 55, 2});
}

TEST(evalSetTest, handlesEquivalence) {
    testEvalSet("AB=", {{0, 1, 2}, {2, 4, 5}, {55}}, {55, 2});
}
