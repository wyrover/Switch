cmake_minimum_required(VERSION 3.2)

project(Boolean5)
find_package(Switch REQUIRED)
add_executable(Boolean5 Boolean5.cpp)
target_link_libraries(Boolean5 Switch.Core)
