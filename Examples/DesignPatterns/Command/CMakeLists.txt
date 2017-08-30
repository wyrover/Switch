cmake_minimum_required(VERSION 3.2)

project(Command)
find_package(Switch REQUIRED)
add_executable(Command Command.cpp)
target_link_libraries(Command Switch.Core)
