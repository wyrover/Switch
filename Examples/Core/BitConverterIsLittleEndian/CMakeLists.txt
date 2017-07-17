cmake_minimum_required(VERSION 3.2)

project(BitConverterIsLittleEndian)
find_package(Pcf REQUIRED)
add_executable(BitConverterIsLittleEndian BitConverterIsLittleEndian.cpp)
target_link_libraries(BitConverterIsLittleEndian Pcf.Core)
