cmake_minimum_required(VERSION 3.2)

project(String4)
find_package(Switch REQUIRED)
add_executable(String4 String4.cpp)
target_link_libraries(String4 Switch.System)
