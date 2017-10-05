cmake_minimum_required(VERSION 3.2)

project(Enum)
find_package(Switch REQUIRED)
add_executable(Enum Enum.cpp)
target_link_libraries(Enum Switch.Core)
