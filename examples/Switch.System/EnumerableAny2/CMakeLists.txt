cmake_minimum_required(VERSION 3.2)

project(EnumerableAny2)
find_package(Switch REQUIRED)
add_executable(EnumerableAny2 EnumerableAny2.cpp)
target_link_libraries(EnumerableAny2 Switch.System)
