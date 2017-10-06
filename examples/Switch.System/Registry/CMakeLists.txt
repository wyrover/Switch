cmake_minimum_required(VERSION 3.2)

project(Registry)
find_package(Switch REQUIRED)
add_executable(Registry Registry.cpp)
target_link_libraries(Registry Switch.System)
