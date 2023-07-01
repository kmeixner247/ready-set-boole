#pragma once
#include <vector>
#include <iostream>
class Set {
private:
    std::vector<int32_t> _set;
public:
    static std::vector<int32_t> _global;
    Set();
    explicit Set(const std::vector<int32_t>&v);
    Set operator&(Set const &rhs) const;
    Set operator|(Set const &rhs) const;
    Set operator^(Set const &rhs) const;
    Set operator!() const;
    int32_t operator[](uint32_t const &i) const;
    Set &operator=(Set const &rhs);
    uint32_t size() const;
    std::vector<int32_t> getSet() const;
    static void setGlobalSet(std::vector<int32_t> &s);
    static void setGlobalSet(Set &s);
};

std::ostream &operator<<(std::ostream &o, Set const &s);