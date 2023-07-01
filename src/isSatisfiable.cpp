#include <iostream>
#include <map>
#include "../rsb.hpp"

bool evaluatePermutation(std::map<char, bool> &hashMap, std::string formula) {
    for (auto el : hashMap) {
        const char replaceValue = el.second ? 1 : 0;
        std::replace(formula.begin(), formula.end(), el.first, replaceValue);
    }
    return eval_formula(formula);
}

bool sat(std::string const &formula) {
    std::map<char, bool> hashMap;
    for (auto symbol : formula) {
        if (symbol >= 'A' && symbol <= 'Z')
            hashMap[symbol] = false;
    }
    if (hashMap.empty())
        return false;
    auto it = hashMap.rbegin();
    while (true) {
        if (evaluatePermutation(hashMap, formula))
            return true;
        while (it->second && it != hashMap.rend())
            it++;
        if (it == hashMap.rend())
            break;
        it->second = true;
        while (it != hashMap.rbegin())
            (--it)->second = false;
    }
    return false;
}
