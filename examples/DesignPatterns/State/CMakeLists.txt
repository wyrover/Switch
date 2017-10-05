cmake_minimum_required(VERSION 3.2)

project(State)
find_package(Switch REQUIRED)
add_executable(State State.cpp)
target_link_libraries(State Switch.Core)
