cmake_minimum_required(VERSION 3.2)

project(ExceptionPtr)
find_package(Switch REQUIRED)
add_executable(ExceptionPtr ExceptionPtr.cpp)
target_link_libraries(ExceptionPtr Switch.System)
