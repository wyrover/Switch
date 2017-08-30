cmake_minimum_required(VERSION 3.2)

project(Foreach4)
find_package(Switch REQUIRED)
add_executable(Foreach4 Foreach4.cpp)
target_link_libraries(Foreach4 Switch.Core)
