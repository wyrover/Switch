cmake_minimum_required(VERSION 3.2)

project(Any)
find_package(Switch REQUIRED)
add_executable(Any Any.cpp)
target_link_libraries(Any Switch.Core)
