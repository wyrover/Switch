cmake_minimum_required(VERSION 3.2)

project(Stopwatch)
find_package(Switch REQUIRED)
add_executable(Stopwatch Stopwatch.cpp)
target_link_libraries(Stopwatch Switch.System)
