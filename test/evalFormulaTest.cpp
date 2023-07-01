#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(evalFormulaTest, failsOnEmptyString) {
    std::string formula;
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
}

TEST(evalFormulaTest, failsOnInvalidCharacter) {
    std::string formula = "X";
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
    formula = "X";
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
    formula = "10K";
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
    formula = "5101";
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
    formula = "01!&|^>=.";
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
}

TEST(evalFormulaTest, doesNotFailOnValidCharacters) {
    std::string formula = "1!0&0|0^0>0=";
    EXPECT_NO_THROW(eval_formula(formula));
}

TEST(evalFormulaTest, failsOnTooManyOperators) {
    std::string formula = "10!=&";
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
}

TEST(evalFormulaTest, failsOnTooFewOperators) {
    std::string formula = ("111!!!");
    EXPECT_THROW(eval_formula(formula), std::runtime_error);
}

TEST(evalFormulaTest, handlesSimpleNegation) {
    std::string formula = ("1!");
    EXPECT_FALSE(eval_formula(formula));
    formula = ("0!");
    EXPECT_TRUE(eval_formula(formula));
}

TEST(evalFormulaTest, handlesChainedNegation) {
    std::string formula = ("1!!");
    EXPECT_TRUE(eval_formula(formula));
    formula = "0!!!!!";
    EXPECT_TRUE(eval_formula(formula));
    formula = "1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    EXPECT_FALSE(eval_formula(formula));
}

TEST(evalFormulaTest, handlesSimpleConjunction) {
    std::string formula = ("00&");
    EXPECT_FALSE(eval_formula(formula));
    formula = ("01&");
    EXPECT_FALSE(eval_formula(formula));
    formula = ("10&");
    EXPECT_FALSE(eval_formula(formula));
    formula = ("11&");
    EXPECT_TRUE(eval_formula(formula));
}

TEST(evalFormulaTest, testsFromsubject) {
    std::string formula;
    formula = "10&";
    EXPECT_FALSE(eval_formula(formula));
    formula = "10|";
    EXPECT_TRUE(eval_formula(formula));
    formula = "11>";
    EXPECT_TRUE(eval_formula(formula));
    formula = "10=";
    EXPECT_FALSE(eval_formula(formula));
    formula = "1011||=";
    EXPECT_TRUE(eval_formula(formula));
}