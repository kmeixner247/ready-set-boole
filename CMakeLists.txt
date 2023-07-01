cmake_minimum_required(VERSION 3.25)

project(rsb CXX)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(googletest)

set(Headers
    rsb.hpp
)
set(Sources
    src/adder.cpp
        src/multiplier.cpp src/grayCode.cpp src/evalFormula.cpp src/truthTable.cpp src/negationNormalForm.cpp src/conjunctiveNormalForm.cpp src/conjunctiveNormalForm.cpp src/truthTableString.cpp src/isSatisfiable.cpp src/powerSet.cpp src/Set.cpp src/Set.hpp src/evalSet.cpp src/spaceFillingCurve.cpp)

add_library(rsb STATIC ${Sources} ${Headers})

add_subdirectory(test)