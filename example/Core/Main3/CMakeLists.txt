cmake_minimum_required(VERSION 3.2)

project(Main3)
find_package(Switch REQUIRED)
add_executable(Main3 Main3.cpp)
target_link_libraries(Main3 Switch.Core)
