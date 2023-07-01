#include <gtest/gtest.h>
#include "../rsb.hpp"
#include "../src/Set.hpp"

bool equalExists(Set const &s1, const IntVectorVector& resultSets) {
    bool b = false;
    for (const auto& set : resultSets) {
        if (s1 == Set(set))
            b = true;
    }
    return b;
}

void testEquivalence(const IntVectorVector &resultSets, const IntVectorVector &expectedSets) {
    for (const std::vector<int>& set : expectedSets) {
        EXPECT_TRUE(equalExists(Set(set), resultSets));
    }
}

TEST(powerSetTest, handlesEmptySet) {
    IntVector originalSet({});
    IntVectorVector resultSets = powerset(originalSet);
    IntVectorVector expectedSets({{}});
    EXPECT_EQ(resultSets.size(), expectedSets.size());
    testEquivalence(resultSets, expectedSets);
}

TEST(powerSetTest, handlesOneElement) {
    IntVector originalSet({1});
    IntVectorVector resultSets = powerset(originalSet);
    IntVectorVector expectedSets({{}, {1}});
    EXPECT_EQ(resultSets.size(), expectedSets.size());
    testEquivalence(resultSets, expectedSets);
}

TEST(powerSetTest, handlesTwoElements) {
    IntVector originalSet({1, 2});
    IntVectorVector resultSets = powerset(originalSet);
    IntVectorVector expectedSets({{}, {1}, {2}, {1, 2}});
    EXPECT_EQ(resultSets.size(), expectedSets.size());
    testEquivalence(resultSets, expectedSets);
}

TEST(powerSetTest, handlesThreeElements) {
    IntVector originalSet({1, 7, 3});
    IntVectorVector resultSets = powerset(originalSet);
    IntVectorVector expectedSets({{}, {1}, {7}, {3}, {1, 7}, {1, 3}, {3, 7}, {1, 7, 3}});
    EXPECT_EQ(resultSets.size(), expectedSets.size());
    testEquivalence(resultSets, expectedSets);
}

TEST(powerSetTest, handlesFourElements) {
    IntVector originalSet({1, 7, 3, 55});
    IntVectorVector resultSets = powerset(originalSet);
    IntVectorVector expectedSets({{}, {1}, {7}, {3}, {55}, {1, 7}, {1, 3}, {1, 55}, {3, 7}, {7, 55}, {3, 55}, {1, 7, 3}, {1, 7, 55}, {1, 3, 55}, {7, 3, 55}, {1, 7, 3, 55}});
    EXPECT_EQ(resultSets.size(), expectedSets.size());
    testEquivalence(resultSets, expectedSets);
}

TEST(powerSetTest, handlesMoreElements) {
    EXPECT_EQ(powerset({1,2,3,4,5}).size(), 32);
    EXPECT_EQ(powerset({1,2,3,4,5,6}).size(), 64);
    EXPECT_EQ(powerset({1,2,3,4,5,6,7}).size(), 128);
    EXPECT_EQ(powerset({1,2,3,4,5,6,7,8}).size(), 256);
    EXPECT_EQ(powerset({1,2,3,4,5,6,7,8,9}).size(), 512);
}