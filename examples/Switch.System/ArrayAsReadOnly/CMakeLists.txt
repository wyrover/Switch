cmake_minimum_required(VERSION 3.2)

project(ArrayAsReadOnly)
find_package(Switch REQUIRED)
add_executable(ArrayAsReadOnly ArrayAsReadOnly.cpp)
target_link_libraries(ArrayAsReadOnly Switch.System)
