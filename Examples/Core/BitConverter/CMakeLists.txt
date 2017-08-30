cmake_minimum_required(VERSION 3.2)

project(BitConverter)
find_package(Switch REQUIRED)
add_executable(BitConverter BitConverter.cpp)
target_link_libraries(BitConverter Switch.Core)
