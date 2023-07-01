#include <string>
#include <vector>
#include "../rsb.hpp"

bool isAndOrOr(char const &c);
String commutativity(String const &operand1, String const &operand2, char const &op);
String associativity(String operand1, String operand2, char const &op);
String distributivity(String const &operand1, String const &operand2, char const &op);
String factorise(String const &operand1, String const &operand2, char const &op);
StringVector extractOperands(String const &formula);

String conjunctive_normal_form(String const &formula) {
    if (formula.size() < 3)
        return formula;
    String newFormula = negation_normal_form(formula);
    StringVector operands = extractOperands(formula);
    String operand1 = conjunctive_normal_form(operands[0]);
    String operand2 = conjunctive_normal_form(operands[1]);
    char op1 = operand1.back();
    char op2 = operand2.back();
    char op3 = formula.back();
    if (op1 == op2 && op2 == op3)
        newFormula = associativity(operand1, operand2, op3);
    else if (!isAndOrOr(op1) && op2 == '&' && op3 == '|')
        newFormula = distributivity(operand1, operand2, op3);
    else if (op1 == '&' && !isAndOrOr(op2) && op3 == '&')
        newFormula = commutativity(operand1, operand2, op3);
    else if (op1 == '&' && !isAndOrOr(op2) && op3 == '|')
        newFormula = distributivity(operand1, operand2, op3);
    else if (op1 == '&' && op2 == '&' && op3 == '|')
        newFormula = factorise(operand1, operand2, op3);
    else if (op1 == '&' && op2 == '|' && op3 == '&')
        newFormula = commutativity(operand1, operand2, op3);
    else if (op1 == '&' && op2 == '|' && op3 == '|')
        newFormula = distributivity(operand1, operand2, op3);
    else if (op1 == '|' && !isAndOrOr(op2) && op3 == '&')
        newFormula = commutativity(operand1, operand2, op3);
    else if (op1 == '|' && !isAndOrOr(op2) && op3 == '|')
        newFormula = commutativity(operand1, operand2, op3);
    else if (op1 == '|' && op2 == '&' && op3 == '|')
        newFormula = distributivity(operand1, operand2, op3);
    else if (op1 == '|' && op2 == '|' && op3 == '|')
        newFormula = associativity(operand1, operand2, op3);
    return newFormula;
}

String commutativity(String const &operand1, String const &operand2, char const &op) {
    String newFormula = operand2 + operand1 + op;
    return conjunctive_normal_form(newFormula);
}

String associativity(String operand1, String operand2, char const &op) {
    String operators;
    if (operand1.back() == op) {
        operand1.pop_back();
        operators += op;
    }
    if (operand2.back() == op) {
        operand2.pop_back();
        operators += op;
    }
    operators += op;
    return operand1 + operand2 + operators;
}

String distributivity(String const &operand1, String const &operand2, char const &op) {
    StringVector innerOperands;
    String outerOperand;
    if (isAndOrOr(operand1.back()) && isAndOrOr(operand2.back()) ||
        !isAndOrOr(op) ||
        operand1.empty() || operand2.empty()) {
        return operand1 + operand2 + op;
    }
    if (isAndOrOr(operand1.back())) {
        innerOperands = extractOperands(operand1);
        innerOperands[0] = conjunctive_normal_form(innerOperands[0]);
        innerOperands[1] = conjunctive_normal_form(innerOperands[1]);
        outerOperand = conjunctive_normal_form(operand2);
    }
    else {
        innerOperands = extractOperands(operand2);
        innerOperands[0] = conjunctive_normal_form(innerOperands[0]);
        innerOperands[1] = conjunctive_normal_form(innerOperands[1]);
        outerOperand = conjunctive_normal_form(operand1);
    }
    if (op == '|') {
        return conjunctive_normal_form(conjunctive_normal_form(outerOperand + innerOperands[0] + '|') + conjunctive_normal_form(outerOperand + innerOperands[1] + '|') + '&');
    }
    else {
        return conjunctive_normal_form(conjunctive_normal_form(outerOperand + innerOperands[0] + '&') + conjunctive_normal_form(outerOperand + innerOperands[1] + '&') + '|');
    }
}

String factorise(String const &operand1, String const &operand2, char const &op) {
    StringVector firstOperands = extractOperands(operand1);
    StringVector secondOperands = extractOperands(operand2);
    String newFormula;
    char otherOp = operand1.back();
    newFormula += firstOperands[0] + secondOperands[0] + op;
    newFormula += firstOperands[0] + secondOperands[1] + op;
    newFormula += firstOperands[1] + secondOperands[0] + op;
    newFormula += firstOperands[1] + secondOperands[1] + op;
    newFormula += otherOp;
    newFormula += otherOp;
    newFormula += otherOp;
    return newFormula;
}