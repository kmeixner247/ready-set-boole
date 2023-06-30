//#include <string>
//#include <stack>
//#include <vector>
//
//std::string negation_normal_form(std::string const &formula) {
//    std::vector<std::string> stack;
//    std::string newFormula;
//    std::string operand1;
//    std::string operand2;
//    std::string temp;
//    for (std::string::const_iterator it = formula.begin(); it != formula.end(); it++) {
//        switch (*it) {
//            case '!':
//                if ((it + 1) != formula.end() && *(it + 1) == '!') {
//                    it++;
//                    break;
//                }
//                operand1 = stack.back();
//                stack.pop_back();
//                operand1 += "!";
//                stack.push_back(operand1);
//                break;
//            case '|':
//                operand2 = stack.back();
//                stack.pop_back();
//                operand1 = stack.back();
//                stack.pop_back();
//                if ((it + 1) != formula.end() && *(it + 1) == '!') {
//                    operand1 += "!";
//                    operand2 += "!";
//                    stack.push_back(negation_normal_form(operand1) + negation_normal_form(operand2) + "&");
//                    it++;
//                } else {
//                    stack.push_back(operand1 + operand2 + "|");
//                }
//                break;
//            case '&':
//                operand2 = stack.back();
//                stack.pop_back();
//                operand1 = stack.back();
//                stack.pop_back();
//                if ((it + 1) != formula.end() && *(it + 1) == '!') {
//                    operand1 += "!";
//                    operand2 += "!";
//                    stack.push_back(negation_normal_form(operand1) + negation_normal_form(operand2) + "|");
//                    it++;
//                } else {
//                    stack.push_back(operand1 + operand2 + "&");
//                }
//                break;
//            case '>':
//                operand2 = stack.back();
//                stack.pop_back();
//                operand1 = stack.back();
//                stack.pop_back();
//                operand1 += "!";
//                stack.push_back(negation_normal_form(operand1) + operand2 + "|");
//                break;
//            case '=':
//                operand2 = stack.back();
//                stack.pop_back();
//                operand1 = stack.back();
//                stack.pop_back();
//                temp = operand1 + operand2 + "&";
//                operand1 += "!";
//                operand2 += "!";
//                temp += negation_normal_form(operand1) + negation_normal_form(operand2) + "&|";
//                stack.push_back(temp);
//                break;
//            default:
//                std::string s;
//                s = *it;
//                stack.push_back(s);
//        }
//    }
//    for (auto const &s : stack) {
//        newFormula += s;
//    }
//    return newFormula;
//}
#include <iostream>
#include <vector>

typedef std::string String;
typedef std::vector<String> StringVector;

StringVector extractOperands(String const &formula);
String eliminateDoubleNegation(String const &formula);
String transformMaterialCondition(String const &formula);
String transformEquivalence(String const &formula);
String applyDeMorgan(String formula);
String transformExclusiveDisjunction(String const &formula);

String negation_normal_form(String const &formula) {
    StringVector operands = extractOperands(formula);
    String newFormula = formula;
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
                    return applyDeMorgan(negation_normal_form(operands[0]) + "!");
                default:
                    return formula;
            }
        case '>':
            return transformMaterialCondition(formula);
        case '=':
            return transformEquivalence(formula);
        case '|':
        case '&':
            return negation_normal_form(operands[0]) + negation_normal_form(operands[1]) + formula.back();
        case '^':
            return transformExclusiveDisjunction(formula);
        default:
            return formula;
    }
}


String eliminateDoubleNegation(String const &formula) {
    return negation_normal_form(formula.substr(0, formula.size() - 2));
}

String transformMaterialCondition(String const &formula) {
    StringVector operands = extractOperands(formula);
    String operand1 = negation_normal_form(operands[0] + "!");
    String operand2 = negation_normal_form(operands[1]);
    return operand1 + operand2 + "|";
}

String transformEquivalence(String const &formula) {
    StringVector operands = extractOperands(formula);
    String operand1 = negation_normal_form(operands[0]);
    String operand2 = negation_normal_form(operands[1]);
    return (negation_normal_form(operand1 + operand2 + ">") + negation_normal_form(operand2 + operand1 + ">") + "&");
}

String applyDeMorgan(String formula) {
    formula.pop_back();
    StringVector operands = extractOperands(formula);
    char op = (formula.back() == '&') ? '|' : '&';
    String operand1 = negation_normal_form(operands[0] + "!");
    String operand2 = negation_normal_form(operands[1] + "!");
    return operand1 + operand2 + op;
}

String transformExclusiveDisjunction(String const &formula) {
    StringVector operands = extractOperands(formula);
    String operand1 = negation_normal_form(operands[0] + "!");
    String operand2 = negation_normal_form(operands[1] + "!");
    return negation_normal_form(operand1 + operand2 + "&") + negation_normal_form(operands[0] + operands[1] + "&") + "|";
}
