cmake_minimum_required (VERSION 3.5)
project(inverted_pendulum)
add_definitions(-std=c++17)

find_package(GTest REQUIRED)

add_subdirectory(src)

# Additional resources like images and fonts
configure_file(res/Roboto-Regular.ttf Roboto-Regular.ttf COPYONLY)

add_executable(app src/main.cpp)
target_link_libraries(app source)

add_executable(test tests/main.cpp tests/inverted_pendulum_test.cpp)
target_link_libraries(test source ${GTEST_LIBRARIES} pthread)

find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(SFMLTest viz/main.cpp)
target_link_libraries(SFMLTest source sfml-graphics sfml-window sfml-system)