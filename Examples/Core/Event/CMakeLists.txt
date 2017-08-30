cmake_minimum_required(VERSION 3.2)

project(Event)
find_package(Switch REQUIRED)
add_executable(Event Event.cpp)
target_link_libraries(Event Switch.Core)
