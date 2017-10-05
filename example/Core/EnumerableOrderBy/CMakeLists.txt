cmake_minimum_required(VERSION 3.2)

project(EnumerableOrderBy)
find_package(Switch REQUIRED)
add_executable(EnumerableOrderBy EnumerableOrderBy.cpp)
target_link_libraries(EnumerableOrderBy Switch.Core)
