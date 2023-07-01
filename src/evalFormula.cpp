#include <string>
#include <stack>
#include "../rsb.hpp"

void handle_operator(std::stack<bool> &truthStack, const char op) {
    if (truthStack.empty())
        throw std::runtime_error("Invalid formula: Too many operators");
    bool b = truthStack.top();
    truthStack.pop();
    if (op == '!') {
        truthStack.push(!b);
        return;
    }
    if (truthStack.empty())
        throw std::runtime_error("Invalid formula: Too many operators");
    bool a = truthStack.top();
    truthStack.pop();
    switch (op) {
        case '&':
            truthStack.push(a & b);
            break;
        case '|':
            truthStack.push(a | b);
            break;
        case '^':
            truthStack.push(a ^ b);
            break;
        case '>':
            truthStack.push(!a | b);
            break;
        case '=':
            truthStack.push(a == b);
            break;
        default:
            throw std::runtime_error("Invalid character in formula");
    }
}

bool eval_formula(std::string &formula) {
    if (formula.empty())
        throw std::runtime_error("Empty String can't be evaluated");
    std::stack<bool> truthStack;
    for (std::string::const_iterator it = formula.begin(); it != formula.end(); it++) {
        switch(*it) {
            case '0':
                truthStack.push(false);
                break;
            case '1':
                truthStack.push(true);
                break;
            case '!':
            case '&':
            case '|':
            case '^':
            case '>':
            case '=':
                handle_operator(truthStack, *it);
                break;
            default:
                throw std::runtime_error("Invalid character in formula");
        }
    }
    if (truthStack.size() != 1)
        throw std::runtime_error("Invalid formula: Too few operators");
    return truthStack.top();
}