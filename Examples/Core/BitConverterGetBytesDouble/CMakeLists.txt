cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesDouble)
find_package(Switch REQUIRED)
add_executable(BitConverterGetBytesDouble BitConverterGetBytesDouble.cpp)
target_link_libraries(BitConverterGetBytesDouble Switch.Core)
