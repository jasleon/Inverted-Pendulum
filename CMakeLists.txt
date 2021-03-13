project(InvertedPendulum)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)
find_package(GTest REQUIRED)

add_library(model src/inverted_pendulum.cpp)

add_executable(app src/main.cpp)
target_link_libraries(app model)

add_executable(test tests/main.cpp tests/inverted_pendulum_test.cpp)
target_link_libraries(test model ${GTEST_LIBRARIES} pthread)