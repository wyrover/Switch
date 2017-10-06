cmake_minimum_required(VERSION 3.2)

project(Thread3)
find_package(Switch REQUIRED)
add_executable(Thread3 Thread3.cpp)
target_link_libraries(Thread3 Switch.System)
