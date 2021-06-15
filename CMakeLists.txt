cmake_minimum_required (VERSION 3.5)

# Set project name
project(inverted_pendulum)

# Required to plot states
add_definitions(-std=c++17)

# Add library
add_subdirectory(src)

# Add executable to plot states
find_package(sciplot)
if(sciplot_FOUND)
  add_executable(plot src/main.cpp)
  target_link_libraries(plot sciplot::sciplot source)
else()
  message("sciplot need to be installed to generate the plot executable")
endif()

# Add executable to run unit tests
find_package(GTest)
if(GTest_FOUND)
  add_executable(test tests/main.cpp tests/inverted_pendulum_test.cpp)
  target_link_libraries(test source ${GTEST_LIBRARIES} pthread)
else()
  message("gloogletest need to be installed to generate the test executable")
endif()

# Additional resources like images and fonts
configure_file(res/Roboto-Regular.ttf Roboto-Regular.ttf COPYONLY)

# Add executable to open game environment
find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(cartpole game/main.cpp)
target_link_libraries(cartpole source sfml-graphics sfml-window sfml-system)

add_executable(solver main.cpp)
target_link_libraries(solver source)