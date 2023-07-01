#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include "../rsb.hpp"

void getHeader(std::map<char, bool> &hashMap, std::string &result) {
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

void getMap(std::map<char, bool> const &hashMap, std::string formula, std::string &result) {
    result += "|";
    for (auto el : hashMap) {
        result += " " + std::to_string(el.second) + " |";
        const char test = el.second ? '1' : '0';
        std::replace(formula.begin(), formula.end(), el.first, test);
    }
    result += " " + std::to_string(eval_formula(formula)) + " |\n";
}

std::string get_truth_table(const std::string& str) {
    std::map<char, bool> hashMap;
    for (auto symbol : str) {
        if (symbol >= 'A' && symbol <= 'Z')
            hashMap[symbol] = false;
    }
    if (hashMap.empty())
        return "";
    std::string result;
    getHeader(hashMap, result);
    auto it = hashMap.rbegin();
    while (true) {
        getMap(hashMap, str, result);
        while (it->second && it != hashMap.rend()) {
            it++;
        }
        if (it == hashMap.rend())
            break;
        it->second = true;
        while (it != hashMap.rbegin()) {
            (--it)->second = false;
        }
    }
    return result;
}