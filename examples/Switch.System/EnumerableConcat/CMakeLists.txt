cmake_minimum_required(VERSION 3.2)

project(EnumerableConcat)
find_package(Switch REQUIRED)
add_executable(EnumerableConcat EnumerableConcat.cpp)
target_link_libraries(EnumerableConcat Switch.System)
