cmake_minimum_required(VERSION 3.2)

project(StreamReader)
find_package(Switch REQUIRED)
add_executable(StreamReader StreamReader.cpp)
target_link_libraries(StreamReader Switch.System)
