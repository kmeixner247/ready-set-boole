#include <iostream>
#include <vector>
#include "../rsb.hpp"

StringVector extractOperands(String const &formula);
String eliminateDoubleNegation(String const &formula);
String transformMaterialCondition(String const &formula);
String transformEquivalence(String const &formula);
String applyDeMorgan(String formula);
String transformExclusiveDisjunction(String const &formula);
String rewriteFormula(String const &formula);

String negation_normal_form(String const &formula) {
    assertThatFormulaIsValid(formula);
    return rewriteFormula(formula);
}

String rewriteFormula(String const &formula) {
    StringVector operands = extractOperands(formula);
    switch(formula.back()) {
        case '!':
            switch(operands[0].back()) {
                case '!':
                    return eliminateDoubleNegation(formula);
                case '&':
                case '|':
                    return applyDeMorgan(formula);
                case '>':
                case '=':
                    return applyDeMorgan(rewriteFormula(operands[0]) + "!");
                default:
                    return formula;
            }
        case '>':
            return transformMaterialCondition(formula);
        case '=':
            return transformEquivalence(formula);
        case '|':
        case '&':
            return rewriteFormula(operands[0]) + rewriteFormula(operands[1]) + formula.back();
        case '^':
            return transformExclusiveDisjunction(formula);
        default:
            return formula;
    }
}


String eliminateDoubleNegation(String const &formula) {
    return rewriteFormula(formula.substr(0, formula.size() - 2));
}
String applyDeMorgan(String formula) {
    formula.pop_back();
    StringVector operands = extractOperands(formula);
    char op = (formula.back() == '&') ? '|' : '&';
    String operand1 = rewriteFormula(operands[0] + "!");
    String operand2 = rewriteFormula(operands[1] + "!");
    return operand1 + operand2 + op;
}

String transformMaterialCondition(String const &formula) {
    StringVector operands = extractOperands(formula);
    String operand1 = rewriteFormula(operands[0] + "!");
    String operand2 = rewriteFormula(operands[1]);
    return operand1 + operand2 + "|";
}

String transformEquivalence(String const &formula) {
    StringVector operands = extractOperands(formula);
    String operand1 = rewriteFormula(operands[0]);
    String operand2 = rewriteFormula(operands[1]);
    return (rewriteFormula(operand1 + operand2 + ">") + rewriteFormula(operand2 + operand1 + ">") + "&");
}

String transformExclusiveDisjunction(String const &formula) {
    StringVector operands = extractOperands(formula);
    String operand1 = rewriteFormula(operands[0] + "!");
    String operand2 = rewriteFormula(operands[1] + "!");
    return rewriteFormula(operand1 + operand2 + "&") + rewriteFormula(operands[0] + operands[1] + "&") + "|";
}
