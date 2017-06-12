cmake_minimum_required(VERSION 3.5)

project(ExceptionPtr)
find_package(Pcf REQUIRED)
add_executable(ExceptionPtr ExceptionPtr.cpp)
target_link_libraries(ExceptionPtr Pcf.Core)
