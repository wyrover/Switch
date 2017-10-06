cmake_minimum_required(VERSION 3.2)

project(Thread)
find_package(Switch REQUIRED)
add_executable(Thread Thread.cpp)
target_link_libraries(Thread Switch.System)
