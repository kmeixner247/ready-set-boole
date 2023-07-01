#include <gtest/gtest.h>
#include "../rsb.hpp"

TEST(assertFormulaTest, throwsOnEmptyFormula) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid(""));
}

TEST(assertFormulaTest, throwsOnInvalidNegation) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid("!"));
}

TEST(assertFormulaTest, throwsOnInvalidConjunction) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid("&"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("A&"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("AB&&"));
}

TEST(assertFormulaTest, throwsOnInvalidDisjunction) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid("|"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("A|"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("AB||"));
}

TEST(assertFormulaTest, throwsOnInvalidExclusiveDisjunction) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid("^"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("A^"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("AB^^"));
}

TEST(assertFormulaTest, throwsOnInvalidMaterialCondition) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid(">"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("A>"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("AB>>"));
}

TEST(assertFormulaTest, throwsOnInvalidEquivalence) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid("="));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("A="));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("AB=="));
}

TEST(assertFormulaTest, throwsOnInvalidSymbols) {
    String formula;
    for (char c = 1; c > 0; c++) {
        if (c < 'A' || c > 'Z') {
            formula = "A";
            formula.append(1, c);
            formula.append(1, '&');
            EXPECT_ANY_THROW(assertThatFormulaIsValid(formula));
            EXPECT_ANY_THROW(assertThatFormulaIsValid(formula.substr(1, 1)));
        }
    }
}

TEST(assertFormulaTest, throwsOnNotEnoughOperators) {
    EXPECT_ANY_THROW(assertThatFormulaIsValid("AA"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("AB"));
    EXPECT_ANY_THROW(assertThatFormulaIsValid("ABCD&|^D>E=FF&"));
}

TEST(assertFormulaTest, doesNotThrowOnValidNegation) {
    EXPECT_NO_THROW(assertThatFormulaIsValid("A!"));
}

TEST(assertFormulaTest, doesNotThrowOnValidConjunction) {
    EXPECT_NO_THROW(assertThatFormulaIsValid("AB&"));
}

TEST(assertFormulaTest, doesNotThrowOnValidDisjunction) {
    EXPECT_NO_THROW(assertThatFormulaIsValid("AB|"));
}

TEST(assertFormulaTest, doesNotThrowOnValidExclusiveDisjunction) {
    EXPECT_NO_THROW(assertThatFormulaIsValid("AB^"));
}

TEST(assertFormulaTest, doesNotThrowOnValidMaterialCondition) {
    EXPECT_NO_THROW(assertThatFormulaIsValid("AB>"));
}

TEST(assertFormulaTest, doesNotThrowOnValidEquivalence) {
    EXPECT_NO_THROW(assertThatFormulaIsValid("AB="));
}

TEST(assertFormulaTest, doesNotThrowOnValidSingleCharacter) {
    String formula = "A";
    while (formula[0] <= 'Z') {
        EXPECT_NO_THROW(assertThatFormulaIsValid(formula));
        formula[0]++;
    }
}

TEST(assertFormulaTest, doesNotThrowOnValidComplexFormulas) {
    EXPECT_NO_THROW(assertThatFormulaIsValid("AB&C|DA|>"));
    EXPECT_NO_THROW(assertThatFormulaIsValid("AAAA&|>A=A=A=AA==AA>>"));
}