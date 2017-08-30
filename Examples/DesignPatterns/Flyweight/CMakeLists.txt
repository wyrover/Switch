cmake_minimum_required(VERSION 3.2)

project(Flyweight)
find_package(Switch REQUIRED)
add_executable(Flyweight Flyweight.cpp)
target_link_libraries(Flyweight Switch.Core)
