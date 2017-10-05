cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesInt64)
find_package(Switch REQUIRED)
add_executable(BitConverterGetBytesInt64 BitConverterGetBytesInt64.cpp)
target_link_libraries(BitConverterGetBytesInt64 Switch.Core)
