#include <gtest/gtest.h>
#include "../rsb.hpp"

void testNNF(const std::string& formula) {
    std::string s1 = get_truth_table(formula);
    std::string s2 = get_truth_table(negation_normal_form(formula));
    EXPECT_EQ(s1, s2);
}

TEST(negationNormalFormTest, exists) {
    EXPECT_NO_FATAL_FAILURE(negation_normal_form("A"));
}

TEST(negationNormalFormTest, simplifiesDoubleNegation) {
    testNNF("A!!");
    testNNF("A!!!");
    testNNF("A!!!!");
    testNNF("A!!!!!");
    testNNF("A!!!!!!!!!!!!!!!!!");
    testNNF("A!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    testNNF("A!!B!!|");
    testNNF("A!!!B!!!|C!!|");
}

TEST(negationNormalFormTest, appliesDeMorganLaws) {
    testNNF("AB|!");
    testNNF("AB&!");
    testNNF("ABC||!");
    testNNF("ABC&&!");
    testNNF("ABCD|||!");
    testNNF("ABCD&&&!");
    testNNF("AB|C&!");
    testNNF("AB&C|!");
}

TEST(negationNormalFormTest, transformsMaterialCondition) {
    testNNF("AB>");
}

TEST(negationNormalFormTest, transformsEquivalence) {
    testNNF("AB=");
}

TEST(negationNormalFormTest, complexFormula) {
    testNNF("AB|!C&!D!!E|!!!=F>");
}