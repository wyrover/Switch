cmake_minimum_required(VERSION 3.2)

project(BitConverterIsLittleEndian)
find_package(Switch REQUIRED)
add_executable(BitConverterIsLittleEndian BitConverterIsLittleEndian.cpp)
target_link_libraries(BitConverterIsLittleEndian Switch.System)
