cmake_minimum_required(VERSION 3.2)

project(Decorator)
find_package(Switch REQUIRED)
add_executable(Decorator Decorator.cpp)
target_link_libraries(Decorator Switch.System)
