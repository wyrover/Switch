cmake_minimum_required(VERSION 3.2)

project(EnumerableAny)
find_package(Switch REQUIRED)
add_executable(EnumerableAny EnumerableAny.cpp)
target_link_libraries(EnumerableAny Switch.System)
