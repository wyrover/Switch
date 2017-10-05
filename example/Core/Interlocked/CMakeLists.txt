cmake_minimum_required(VERSION 3.2)

project(Interlocked)
find_package(Switch REQUIRED)
add_executable(Interlocked Interlocked.cpp)
target_link_libraries(Interlocked Switch.Core)
