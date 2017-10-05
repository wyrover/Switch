cmake_minimum_required(VERSION 3.2)

project(Main5)
find_package(Switch REQUIRED)
add_executable(Main5 Main5.cpp)
target_link_libraries(Main5 Switch.Core)
