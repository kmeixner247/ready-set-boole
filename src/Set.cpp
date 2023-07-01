#include "Set.hpp"
#include <algorithm>

std::vector<int32_t> Set::_global;

Set Set::operator&(const Set &rhs) const {
    std::vector<int32_t> conjunction;
    for (auto &el : _set) {
        if (std::find(rhs._set.begin(), rhs._set.end(), el) != rhs._set.end()) {
            conjunction.push_back(el);
        }
    }
    return Set(conjunction);
}

Set Set::operator|(const Set &rhs)  const {
    std::vector<int32_t> disjunction(_set);
    for (auto &el : rhs._set) {
        if (std::find(disjunction.begin(), disjunction.end(), el) == disjunction.end()) {
            disjunction.push_back(el);
        }
    }
    return Set(disjunction);
}

Set Set::operator^(const Set &rhs) const {
    std::vector<int32_t> exclusiveDisjunction;
    for (auto &el : _set) {
        if (std::find(rhs._set.begin(), rhs._set.end(), el) == rhs._set.end()) {
            exclusiveDisjunction.push_back(el);
        }
    }
    for (auto &el : rhs._set) {
        if (std::find(_set.begin(), _set.end(), el) == _set.end()) {
            exclusiveDisjunction.push_back(el);
        }
    }
    return Set(exclusiveDisjunction);
}

Set Set::operator!() const {
    std::vector<int32_t> newSet;
    for (auto &el : _global) {
        if (std::find(_set.begin(), _set.end(), el) == _set.end())
            newSet.push_back(el);
    }
    return Set(newSet);
}

Set::Set() = default;

Set::Set(const std::vector<int32_t>&v) {
    _set = v;
}

uint32_t Set::size() const {
    return _set.size();
}

int32_t Set::operator[](uint32_t const &i) const {
    return _set[i];
}

void Set::setGlobalSet(std::vector<int32_t> &s) {
    _global = s;
}

void Set::setGlobalSet(Set &s) {
    _global = s._set;
}

std::vector<int32_t> Set::getSet() const {
    return _set;
}

Set &Set::operator=(const Set &rhs) {
    _set = rhs._set;
    return *this;
}

std::ostream &operator<<(std::ostream &o, Set const &s) {
    o << "{";
    for (uint32_t i = 0; i < s.size(); i++) {
        o << s[i];
        if (i != s.size() - 1)
            o << ", ";
    }
    o << "}";
    return o;
}
