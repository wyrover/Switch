cmake_minimum_required(VERSION 3.5)

project(Stopwatch)
find_package(Pcf REQUIRED)
add_executable(Stopwatch Stopwatch.cpp)
target_link_libraries(Stopwatch Pcf.Core)
