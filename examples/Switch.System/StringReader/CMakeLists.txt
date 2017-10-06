cmake_minimum_required(VERSION 3.2)

project(StringReader)
find_package(Switch REQUIRED)
add_executable(StringReader StringReader.cpp)
target_link_libraries(StringReader Switch.System)
