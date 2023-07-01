#include <gtest/gtest.h>
#include "../rsb.hpp"

void testCNF(std::string formula) {
    std::string s1 = get_truth_table(formula);
    std::string s2 = get_truth_table(conjunctive_normal_form(formula));
    EXPECT_EQ(s1, s2);
}
TEST(conjunctiveNormalFormTest, exists) {
    EXPECT_NO_THROW(conjunctive_normal_form(""));
}

TEST(conjunctiveNormalFormTest, handlesBasicInput) {
    testCNF("");
    testCNF("A");
    testCNF("AB&");
    testCNF("AB|");
}

TEST(conjunctiveNormalFormTest, appliesNegationNormalForm) {
    testCNF("AB|!");
}

TEST(conjunctiveNormalFormTest, applesAssociativity) {
    testCNF("AB&C&");
    testCNF("AB&C&D&");
    testCNF("AB&C&D&E&");
    testCNF("AB&C&D&E&F&");
    testCNF("AB|C|");
    testCNF("AB|C|D|");
    testCNF("AB|C|D|E|");
    testCNF("AB|C|D|E|F|");
}

TEST(conjunctiveNormalFormTest, appliesDistributivity) {
    testCNF("ABC&|");
}

TEST(conjunctiveNormalFormTest, handlesComplexFormula) {
    testCNF("AB|!C&!D!!E|!!!=F>AA==F=K>");
}