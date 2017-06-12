cmake_minimum_required(VERSION 3.5)

project(BitConverterGetBytesChar)
find_package(Pcf REQUIRED)
add_executable(BitConverterGetBytesChar BitConverterGetBytesChar.cpp)
target_link_libraries(BitConverterGetBytesChar Pcf.Core)
