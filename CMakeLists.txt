cmake_minimum_required (VERSION 3.5)

# Set project name
project(inverted_pendulum)

# Required to plot states
add_definitions(-std=c++17)

# Add library
add_subdirectory(src)

# Add executable to plot states
add_executable(app src/main.cpp)
target_link_libraries(app source)

# Add executable to run unit tests
find_package(GTest REQUIRED)
add_executable(test tests/main.cpp tests/inverted_pendulum_test.cpp)
target_link_libraries(test source ${GTEST_LIBRARIES} pthread)

# Additional resources like images and fonts
configure_file(res/Roboto-Regular.ttf Roboto-Regular.ttf COPYONLY)

# Add executable to open game environment
find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(game game/main.cpp)
target_link_libraries(game source sfml-graphics sfml-window sfml-system)