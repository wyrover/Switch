cmake_minimum_required(VERSION 3.2)

project(DirectorySeparatorChar)
find_package(Switch REQUIRED)
add_executable(DirectorySeparatorChar DirectorySeparatorChar.cpp)
target_link_libraries(DirectorySeparatorChar Switch.Core)
