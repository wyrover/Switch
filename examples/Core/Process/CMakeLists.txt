cmake_minimum_required(VERSION 3.2)

project(Process)
find_package(Switch REQUIRED)
add_executable(Process Process.cpp)
target_link_libraries(Process Switch.Core)
