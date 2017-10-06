cmake_minimum_required(VERSION 3.2)

project(DateTimeSpecifyKind)
find_package(Switch REQUIRED)
add_executable(DateTimeSpecifyKind DateTimeSpecifyKind.cpp)
target_link_libraries(DateTimeSpecifyKind Switch.System)
