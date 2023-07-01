#include <iostream>

double map(uint16_t x, uint16_t y) {
    uint32_t temp = (x << 16) | y;
    return (double)temp;
}

std::pair<uint16_t, uint16_t> reverse_map(double n) {
    auto temp = (int32_t) n;
    return std::make_pair(temp >> 16, temp | (1 << 16));
}
