#include <iostream>
#include "rsb.hpp"

uint32_t adder(uint32_t a, uint32_t b) {
    uint32_t carry = 1;
    while (carry != 0) {
        carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
