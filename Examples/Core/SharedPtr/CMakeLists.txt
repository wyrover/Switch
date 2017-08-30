cmake_minimum_required(VERSION 3.2)

project(SharedPtr)
find_package(Switch REQUIRED)
add_executable(SharedPtr SharedPtr.cpp)
target_link_libraries(SharedPtr Switch.Core)
