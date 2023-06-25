#include <string>
#include <stack>
#include <vector>

std::string negation_normal_form(std::string const &formula) {
    std::vector<std::string> stack;
    std::string newFormula;
    std::string operand1;
    std::string operand2;
    std::string temp;
    for (std::string::const_iterator it = formula.begin(); it != formula.end(); it++) {
        switch (*it) {
            case '!':
                if ((it + 1) != formula.end() && *(it + 1) == '!') {
                    it++;
                    break;
                }
                operand1 = stack.back();
                stack.pop_back();
                operand1 += "!";
                stack.push_back(operand1);
                break;
            case '|':
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                if ((it + 1) != formula.end() && *(it + 1) == '!') {
                    operand1 += "!";
                    operand2 += "!";
                    stack.push_back(negation_normal_form(operand1) + negation_normal_form(operand2) + "&");
                    it++;
                } else {
                    stack.push_back(operand1 + operand2 + "|");
                }
                break;
            case '&':
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                if ((it + 1) != formula.end() && *(it + 1) == '!') {
                    operand1 += "!";
                    operand2 += "!";
                    stack.push_back(negation_normal_form(operand1) + negation_normal_form(operand2) + "|");
                    it++;
                } else {
                    stack.push_back(operand1 + operand2 + "&");
                }
                break;
            case '>':
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                operand1 += "!";
                stack.push_back(negation_normal_form(operand1) + operand2 + "|");
                break;
            case '=':
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                temp += operand1 + operand2 + "&";
//                stack.push_back(operand1 + operand2 + "&");
                operand1 += "!";
                operand2 += "!";
                temp += negation_normal_form(operand1) + negation_normal_form(operand2) + "&|";
//                stack.push_back(negation_normal_form(operand1) + negation_normal_form(operand2) + "&|");
                stack.push_back(temp);
                break;
            default:
                std::string s;
                s = *it;
                stack.push_back(s);
        }
    }

    for (auto const &s : stack) {
        newFormula += s;
    }
    return newFormula;
}