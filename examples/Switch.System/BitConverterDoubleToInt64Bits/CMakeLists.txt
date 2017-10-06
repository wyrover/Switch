cmake_minimum_required(VERSION 3.2)

project(BitConverterDoubleToInt64Bits)
find_package(Switch REQUIRED)
add_executable(BitConverterDoubleToInt64Bits BitConverterDoubleToInt64Bits.cpp)
target_link_libraries(BitConverterDoubleToInt64Bits Switch.System)
