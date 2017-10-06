cmake_minimum_required(VERSION 3.2)

project(Async1)
find_package(Switch REQUIRED)
add_executable(Async1 Async1.cpp)
target_link_libraries(Async1 Switch.System)
