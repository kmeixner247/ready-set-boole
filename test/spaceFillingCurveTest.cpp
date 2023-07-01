#include <gtest/gtest.h>
#include "../rsb.hpp"
#include <set>
#include <map>

TEST(spaceFillingCurveTest, reverseMapIsReverseOfMap) {
    std::map<std::pair<uint16_t, uint16_t>, double> mappedValues;
    for (uint32_t x = 0; x < UINT16_MAX; x += 73) {
        for (uint32_t y = 0; y < UINT16_MAX; y += 58) {
            mappedValues[{x, y}] = map(x, y);
        }
    }
    for (auto pair : mappedValues) {
        EXPECT_EQ(reverse_map(pair.second), pair.first);
    }
}

TEST(spaceFillingCurveTest, mapsUniqueValues) {
    std::set<double> doubleSet;
    uint32_t x;
    uint32_t y;
    uint16_t xLimit = 512;
    uint16_t yLimit = 5621;
    for (x = 0; x < xLimit; x++) {
        for (y = 0; y < yLimit; y++)
            doubleSet.insert(map(x, y));
    }
    EXPECT_EQ(doubleSet.size(), xLimit * yLimit);
}