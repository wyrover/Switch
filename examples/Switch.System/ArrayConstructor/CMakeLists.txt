cmake_minimum_required(VERSION 3.2)

project(ArrayConstructor)
find_package(Switch REQUIRED)
add_executable(ArrayConstructor ArrayConstructor.cpp README.md)
target_link_libraries(ArrayConstructor Switch.System)
