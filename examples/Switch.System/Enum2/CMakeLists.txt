cmake_minimum_required(VERSION 3.2)

project(Enum2)
find_package(Switch REQUIRED)
add_executable(Enum2 Enum2.cpp)
target_link_libraries(Enum2 Switch.System)
