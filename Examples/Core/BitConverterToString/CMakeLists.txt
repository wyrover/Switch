cmake_minimum_required(VERSION 3.2)

project(BitConverterToString)
find_package(Pcf REQUIRED)
add_executable(BitConverterToString BitConverterToString.cpp)
target_link_libraries(BitConverterToString Pcf.Core)
