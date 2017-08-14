cmake_minimum_required(VERSION 3.2)

project(BitConverterDoubleToInt64Bits)
find_package(Pcf REQUIRED)
add_executable(BitConverterDoubleToInt64Bits BitConverterDoubleToInt64Bits.cpp)
target_link_libraries(BitConverterDoubleToInt64Bits Pcf.Core)
