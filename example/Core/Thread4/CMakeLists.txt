cmake_minimum_required(VERSION 3.2)

project(Thread4)
find_package(Switch REQUIRED)
add_executable(Thread4 Thread4.cpp)
target_link_libraries(Thread4 Switch.Core)
