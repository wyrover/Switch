cmake_minimum_required(VERSION 3.2)

project(String1)
find_package(Switch REQUIRED)
add_executable(String1 String1.cpp)
target_link_libraries(String1 Switch.System)
