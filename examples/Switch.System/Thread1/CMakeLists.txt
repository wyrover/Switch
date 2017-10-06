cmake_minimum_required(VERSION 3.2)

project(Thread1)
find_package(Switch REQUIRED)
add_executable(Thread1 Thread1.cpp)
target_link_libraries(Thread1 Switch.System)
