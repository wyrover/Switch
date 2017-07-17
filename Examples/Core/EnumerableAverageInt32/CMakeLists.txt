cmake_minimum_required(VERSION 3.2)

project(EnumerableAverageInt32)
find_package(Pcf REQUIRED)
add_executable(EnumerableAverageInt32 EnumerableAverageInt32.cpp)
target_link_libraries(EnumerableAverageInt32 Pcf.Core)
