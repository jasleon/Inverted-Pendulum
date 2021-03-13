cmake_minimum_required (VERSION 3.5)
project(inverted_pendulum)

find_package(GTest REQUIRED)

add_subdirectory(src)

add_executable(app src/main.cpp)
target_link_libraries(app source)

add_executable(test tests/main.cpp tests/inverted_pendulum_test.cpp)
target_link_libraries(test source ${GTEST_LIBRARIES} pthread)