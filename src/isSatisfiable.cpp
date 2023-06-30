#include <iostream>
#include <map>
#include "../rsb.hpp"

bool evaluatePermutation(std::map<char, bool> &hashMap, std::string formula) {
    for (auto el : hashMap) {
        const char test = el.second + 48;
        std::replace(formula.begin(), formula.end(), el.first, test);
    }
    return eval_formula(formula);
}

bool sat(std::string const &formula) {
    std::map<char, bool> hashMap;
    for (auto symbol : formula) {
        switch (symbol) {
            case 'A' ... 'Z':
                hashMap[symbol] = false;
                break ;
        }
    }
    if (hashMap.empty())
        return false;
    auto it = hashMap.rbegin();
    while (true) {
        if (evaluatePermutation(hashMap, formula))
            return true;
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
    return false;
}
