cmake_minimum_required(VERSION 3.2)

project(EnumerableAgregate2)
find_package(Switch REQUIRED)
add_executable(EnumerableAgregate2 EnumerableAgregate2.cpp)
target_link_libraries(EnumerableAgregate2 Switch.System)
