cmake_minimum_required(VERSION 3.2)

project(Thread2)
find_package(Switch REQUIRED)
add_executable(Thread2 Thread2.cpp)
target_link_libraries(Thread2 Switch.Core)
