cmake_minimum_required(VERSION 3.2)

project(Interpreter)
find_package(Switch REQUIRED)
add_executable(Interpreter Interpreter.cpp)
target_link_libraries(Interpreter Switch.Core)
