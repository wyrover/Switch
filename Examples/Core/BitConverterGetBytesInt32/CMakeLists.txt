cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesInt32)
find_package(Switch REQUIRED)
add_executable(BitConverterGetBytesInt32 BitConverterGetBytesInt32.cpp)
target_link_libraries(BitConverterGetBytesInt32 Switch.Core)
