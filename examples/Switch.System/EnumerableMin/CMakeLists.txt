cmake_minimum_required(VERSION 3.2)

project(EnumerableMin)
find_package(Switch REQUIRED)
add_executable(EnumerableMin EnumerableMin.cpp)
target_link_libraries(EnumerableMin Switch.System)
