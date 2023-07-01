#include <gtest/gtest.h>
#include "../rsb.hpp"
#include "../src/Set.hpp"
#include <vector>

typedef std::string String;
typedef std::vector<int32_t> IntVector;
typedef std::vector<IntVector> IntVectorVector;

TEST(evalSetTest, exists) {
    std::vector<std::vector<int32_t>> setSet;
    std::vector<int32_t> set;
    set.push_back(5);
    setSet.push_back(set);
    EXPECT_NO_THROW(eval_set("A", setSet));
}


TEST(evalSetTest, temptest) {
    IntVectorVector setSet;
    IntVector set;
    set.push_back(0);
    set.push_back(1);
    set.push_back(2);
    IntVector set2;
    set2.push_back(2);
    set2.push_back(4);
    set2.push_back(5);
    IntVector set3;
    set3.push_back(55);
    setSet.push_back(set);
    setSet.push_back(set2);
    setSet.push_back(set3);
    IntVector resultSet = eval_set("AB=", setSet);
    std::cout << Set(resultSet) << std::endl;
}
