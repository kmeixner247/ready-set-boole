#include "../rsb.hpp"

StringVector extractOperands(String const &formula) {
    StringVector operands;
    String temp;
    for (auto c : formula.substr(0, formula.size() - 1)) {
        switch (c) {
            case 'A' ... 'Z':
                operands.push_back(String() + c);
                break;
            case '!':
                operands.back() += '!';
                break;
            case '|':
            case '&':
            case '>':
            case '=':
            case '^':
                temp = operands.back();
                operands.pop_back();
                operands.back() += temp + c;
                break;
            default:
                throw std::runtime_error(String("invalid symbol in formula: ") + c);
        }
    }
    return operands;
}

bool isAndOrOr(char const &c) {
    String operators("&|");
    if (operators.find(c) == std::string::npos)
        return false;
    else
        return true;
}

void assertThatFormulaIsValid(String const &formula) {
    if (formula.empty())
        throw std::runtime_error("Invalid formula: Empty formula");
    uint32_t depth = 0;
    for (auto symbol : formula) {
        switch (symbol) {
            case 'A' ... 'Z':
                depth++;
                break;
            case '&':
            case '|':
            case '^':
            case '=':
            case '>':
                if (depth < 2)
                    throw std::runtime_error("Invalid formula: Encountered unexpected operator '" + String(1,symbol) + "'");
                depth--;
                break;
            case '!':
                if (depth == 0)
                    throw std::runtime_error("Invalid formula: Encountered unexpected operator '" + String(1,symbol) + "'");
                break;
            default:
                throw std::runtime_error("Invalid formula: Encountered unexpected symbol '" + String(1,symbol) + "'");
        }
    }
    if (depth > 1)
        throw std::runtime_error("Invalid formula: Not enough operators");
}