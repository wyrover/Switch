cmake_minimum_required(VERSION 3.2)

project(EnumerableAgregate3)
find_package(Switch REQUIRED)
add_executable(EnumerableAgregate3 EnumerableAgregate3.cpp)
target_link_libraries(EnumerableAgregate3 Switch.System)
