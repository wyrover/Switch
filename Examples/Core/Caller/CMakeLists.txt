cmake_minimum_required(VERSION 3.2)

project(Caller)
find_package(Switch REQUIRED)
add_executable(Caller Caller.cpp)
target_link_libraries(Caller Switch.Core)
