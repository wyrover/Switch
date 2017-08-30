cmake_minimum_required(VERSION 3.2)

project(UniquePtr)
find_package(Switch REQUIRED)
add_executable(UniquePtr UniquePtr.cpp)
target_link_libraries(UniquePtr Switch.Core)
