#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include "../rsb.hpp"

void print_header(std::map<char, bool> &hashMap, std::string &result) {
    std::string line = "|";
    std::string line2 = "|---";
    for (auto el : hashMap) {
        line += " ";
        line += el.first;
        line += " |";
        line2 += "|---";
    }
    result += line + " = |\n";
    result += line2 + "|\n";
}

void print_map(std::map<char, bool> &hashMap, std::string formula, std::string &result) {
    result += "|";
    for (auto el : hashMap) {
        result += " " + std::to_string(el.second) + " |";
        const char test = el.second + 48;
        std::replace(formula.begin(), formula.end(), el.first, test);
    }
    result += " " + std::to_string(eval_formula(formula)) + " |\n";
}

std::string get_truth_table(std::string str) {
    std::map<char, bool> hashMap;
    for (auto symbol : str) {
        switch (symbol) {
            case 'A' ... 'Z':
                hashMap[symbol] = false;
                break ;
        }
    }
    if (hashMap.empty())
        return "";
    std::string result;
    print_header(hashMap, result);
    std::map<char, bool>::reverse_iterator it = hashMap.rbegin();
    while (true) {
        print_map(hashMap, str, result);
        while (it->second && it != hashMap.rend()) {
            it++;
        }
        if (it == hashMap.rend())
            break;
        it->second = true;
        while (it != hashMap.rbegin()) {
            it--;
            it->second = false;
        }
    }
    return result;
}