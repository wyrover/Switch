cmake_minimum_required(VERSION 3.2)

project(StringFormatBinary)
find_package(Switch REQUIRED)
add_executable(StringFormatBinary StringFormatBinary.cpp)
target_link_libraries(StringFormatBinary Switch.Core)
