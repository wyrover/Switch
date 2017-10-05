cmake_minimum_required(VERSION 3.2)

project(Trace)
find_package(Switch REQUIRED)
add_executable(Trace Trace.cpp)
target_link_libraries(Trace Switch.Core)
