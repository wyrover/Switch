cmake_minimum_required(VERSION 3.2)

project(Boxing)
find_package(Switch REQUIRED)
add_executable(Boxing Boxing.cpp)
target_link_libraries(Boxing Switch.Core)
