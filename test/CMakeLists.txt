cmake_minimum_required(VERSION 3.25)

set(Sources
    adderTest.cpp
        multiplierTest.cpp grayCodeTest.cpp evalFormulaTest.cpp truthTableTest.cpp negationNormalFormTest.cpp)

add_executable(rsbTest ${Sources})

target_link_libraries(rsbTest PUBLIC
        gtest_main
        rsb
)

add_test(
        NAME rsbTest
        COMMAND rsbTest
)