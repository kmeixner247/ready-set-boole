#include <iostream>
#include "../rsb.hpp"

uint32_t multiplier(uint32_t a, uint32_t b) {
    uint32_t result = 0;
    while (b != 0) {
        if ((b & 1) == 1)
            result = adder(result, a);
        a = a << 1;
        b = b >> 1;
    }
    return result;
}
