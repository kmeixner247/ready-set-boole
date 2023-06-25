#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(negationNormalFormTest, exists) {
    EXPECT_NO_THROW(negation_normal_form(""));
}

TEST(negationNormalFormTest, simplifiesDoubleNegation) {
    EXPECT_EQ(negation_normal_form("A!!"), "A");
    EXPECT_EQ(negation_normal_form("A!!!"), "A!");
    EXPECT_EQ(negation_normal_form("A!!!!"), "A");
    EXPECT_EQ(negation_normal_form("A!!!!!"), "A!");
    EXPECT_EQ(negation_normal_form("A!!!!!!!!!!!!!!!!!"), "A!");
    EXPECT_EQ(negation_normal_form("A!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"), "A");
    EXPECT_EQ(negation_normal_form("A!!B!!|"), "AB|");
    EXPECT_EQ(negation_normal_form("A!!!B!!!|C!!|"), "A!B!|C|");
}

TEST(negationNormalFormTest, appliesDeMorganLaws) {
    EXPECT_EQ(negation_normal_form("AB|!"), "A!B!&");
    EXPECT_EQ(negation_normal_form("AB&!"), "A!B!|");
    EXPECT_EQ(negation_normal_form("ABC||!"), "A!B!C!&&");
    EXPECT_EQ(negation_normal_form("ABC&&!"), "A!B!C!||");
    EXPECT_EQ(negation_normal_form("ABCD|||!"), "A!B!C!D!&&&");
    EXPECT_EQ(negation_normal_form("ABCD&&&!"), "A!B!C!D!|||");
    EXPECT_EQ(negation_normal_form("AB|C&!"), "A!B!&C!|");
    EXPECT_EQ(negation_normal_form("AB&C|!"), "A!B!|C!&");
}

TEST(negationNormalFormTest, transformsMaterialCondition) {
    EXPECT_EQ(negation_normal_form("AB>"), "A!B|");
}

TEST(negationNormalFormTest, transformsEquivalence) {
    EXPECT_EQ(negation_normal_form("AB="), "AB&A!B!&|");
}

TEST(negationNormalFormTest, complexFormula) {
    EXPECT_EQ(negation_normal_form("AB|!C&!D!!E|!!!=F>"), "A!B!&C&DE||AB|C!|D!E!&|&F|")
}