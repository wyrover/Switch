cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesChar)
find_package(Switch REQUIRED)
add_executable(BitConverterGetBytesChar BitConverterGetBytesChar.cpp)
target_link_libraries(BitConverterGetBytesChar Switch.Core)
