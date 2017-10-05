cmake_minimum_required(VERSION 3.2)

project(BitConverterEndianess)
find_package(Switch REQUIRED)
add_executable(BitConverterEndianess BitConverterEndianess.cpp)
target_link_libraries(BitConverterEndianess Switch.Core)
