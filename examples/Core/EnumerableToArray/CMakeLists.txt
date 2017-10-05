cmake_minimum_required(VERSION 3.2)

project(EnumerableToArray)
find_package(Switch REQUIRED)
add_executable(EnumerableToArray EnumerableToArray.cpp)
target_link_libraries(EnumerableToArray Switch.Core)
