cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesInt64)
find_package(Pcf REQUIRED)
add_executable(BitConverterGetBytesInt64 BitConverterGetBytesInt64.cpp)
target_link_libraries(BitConverterGetBytesInt64 Pcf.Core)
