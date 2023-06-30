#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include "../rsb.hpp"

void print_header(std::map<char, bool> &hashMap) {
    std::string line = "|";
    std::string line2 = "|---";
    for (auto el : hashMap) {
        line += " ";
        line += el.first;
        line += " |";
        line2 += "|---";
    }
    std::cout << line << " = |" << std::endl;
    std::cout << line2 << "|" << std::endl;
}

void print_map(std::map<char, bool> &hashMap, std::string formula) {
    std::cout << "|";
    for (auto el : hashMap) {
        std::cout << " " << el.second << " |";
        const char test = el.second + 48;
        std::replace(formula.begin(), formula.end(), el.first, test);
    }
    std::cout << " " << eval_formula(formula) << " |" << std::endl;
}

void print_truth_table(std::string &str) {
    std::map<char, bool> hashMap;
    for (auto symbol : str) {
        switch (symbol) {
            case 'A' ... 'Z':
                hashMap[symbol] = false;
                break ;
        }
    }
    if (hashMap.empty())
        return;
    print_header(hashMap);
    auto it = hashMap.rbegin();
    while (true) {
        print_map(hashMap, str);
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
}