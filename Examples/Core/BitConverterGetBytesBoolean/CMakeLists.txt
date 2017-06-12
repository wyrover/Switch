cmake_minimum_required(VERSION 3.5)

project(BitConverterGetBytesBoolean)
find_package(Pcf REQUIRED)
add_executable(BitConverterGetBytesBoolean BitConverterGetBytesBoolean.cpp)
target_link_libraries(BitConverterGetBytesBoolean Pcf.Core)
