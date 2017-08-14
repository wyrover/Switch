cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesSingle)
find_package(Pcf REQUIRED)
add_executable(BitConverterGetBytesSingle BitConverterGetBytesSingle.cpp)
target_link_libraries(BitConverterGetBytesSingle Pcf.Core)
