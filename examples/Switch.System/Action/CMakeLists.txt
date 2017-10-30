cmake_minimum_required(VERSION 3.2)

project(Action)
find_package(Switch REQUIRED)
add_executable(Action Action.cpp)
target_link_libraries(Action Switch.System)
