#include "../rsb.hpp"
#include "Set.hpp"
#include <vector>
#include <string>
#include <map>

typedef std::map<char, Set> CharSetMap;

IntVector eval_set(String const &formula, const IntVectorVector& sets) {
    if (sets.size() > 26)
        throw std::runtime_error("Too many sets");
    String simpleFormula = negation_normal_form(formula);
    CharSetMap setMap;
    char c = 'A';
    for (const auto& set : sets) {
        setMap[c] = Set(set);
        c++;
    }
    Set superSet;
    for (const auto& set : setMap) {
        superSet = superSet | set.second;
    }
    Set::setGlobalSet(superSet);
    std::vector<Set> setStack;
    Set temp;
    Set temp2;
    for (char it : simpleFormula) {
        switch (it) {
            case 'A'...'Z':
                if (setMap.count(it) == 0)
                    throw std::runtime_error("Not enough sets");
                setStack.push_back(setMap[it]);
                break;
            case '!':
                temp = setStack.back();
                setStack.pop_back();
                setStack.push_back(!temp);
                break;
            case '&':
                temp2 = setStack.back();
                setStack.pop_back();
                temp = setStack.back();
                setStack.pop_back();
                setStack.push_back(temp & temp2);
                break;
            case '|':
                temp2 = setStack.back();
                setStack.pop_back();
                temp = setStack.back();
                setStack.pop_back();
                setStack.push_back(temp | temp2);
                break;
            default: throw std::runtime_error("Invalid character in formula");
        }
    }
    return setStack[0].getSet();
}