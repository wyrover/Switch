cmake_minimum_required(VERSION 3.2)

project(EnumerableCast)
find_package(Switch REQUIRED)
add_executable(EnumerableCast EnumerableCast.cpp)
target_link_libraries(EnumerableCast Switch.System)
