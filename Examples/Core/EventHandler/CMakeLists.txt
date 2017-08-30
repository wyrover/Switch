cmake_minimum_required(VERSION 3.2)

project(EventHandler)
find_package(Switch REQUIRED)
add_executable(EventHandler EventHandler.cpp)
target_link_libraries(EventHandler Switch.Core)
