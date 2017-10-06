cmake_minimum_required(VERSION 3.2)

project(String3)
find_package(Switch REQUIRED)
add_executable(String3 String3.cpp)
target_link_libraries(String3 Switch.System)
