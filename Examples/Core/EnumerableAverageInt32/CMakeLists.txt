cmake_minimum_required(VERSION 3.2)

project(EnumerableAverageInt32)
find_package(Switch REQUIRED)
add_executable(EnumerableAverageInt32 EnumerableAverageInt32.cpp)
target_link_libraries(EnumerableAverageInt32 Switch.Core)
