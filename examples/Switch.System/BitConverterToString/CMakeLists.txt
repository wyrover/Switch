cmake_minimum_required(VERSION 3.2)

project(BitConverterToString)
find_package(Switch REQUIRED)
add_executable(BitConverterToString BitConverterToString.cpp)
target_link_libraries(BitConverterToString Switch.System)
