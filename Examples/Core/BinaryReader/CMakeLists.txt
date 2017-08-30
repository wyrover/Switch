cmake_minimum_required(VERSION 3.2)

project(BinaryReader)
find_package(Switch REQUIRED)
add_executable(BinaryReader BinaryReader.cpp)
target_link_libraries(BinaryReader Switch.Core)
