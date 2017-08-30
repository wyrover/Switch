cmake_minimum_required(VERSION 3.2)

project(EnvironmentNewLine)
find_package(Switch REQUIRED)
add_executable(EnvironmentNewLine EnvironmentNewLine.cpp)
target_link_libraries(EnvironmentNewLine Switch.Core)
