cmake_minimum_required(VERSION 3.2)

project(FunctionPointer)
find_package(Switch REQUIRED)
add_executable(FunctionPointer FunctionPointer.cpp)
target_link_libraries(FunctionPointer Switch.Core)
