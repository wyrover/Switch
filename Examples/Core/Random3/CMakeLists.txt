cmake_minimum_required(VERSION 3.2)

project(Random3)
find_package(Switch REQUIRED)
add_executable(Random3 Random3.cpp)
target_link_libraries(Random3 Switch.Core)
