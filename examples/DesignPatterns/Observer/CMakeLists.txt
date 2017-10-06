cmake_minimum_required(VERSION 3.2)

project(Observer)
find_package(Switch REQUIRED)
add_executable(Observer Observer.cpp)
target_link_libraries(Observer Switch.System)
