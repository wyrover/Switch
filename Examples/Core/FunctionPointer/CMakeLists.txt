cmake_minimum_required(VERSION 3.5)

project(FunctionPointer)
find_package(Pcf REQUIRED)
add_executable(FunctionPointer FunctionPointer.cpp)
target_link_libraries(FunctionPointer Pcf.Core)
