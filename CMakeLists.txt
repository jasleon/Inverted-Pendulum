project(InvertedPendulum)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

set(sources main.cpp inverted_pendulum.cpp)

add_executable(InvertedPendulum ${sources})