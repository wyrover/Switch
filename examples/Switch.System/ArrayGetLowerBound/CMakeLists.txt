cmake_minimum_required(VERSION 3.2)

project(ArrayGetLowerBound)
find_package(Switch REQUIRED)
add_executable(ArrayGetLowerBound ArrayGetLowerBound.cpp)
target_link_libraries(ArrayGetLowerBound Switch.System)
