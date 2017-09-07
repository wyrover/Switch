cmake_minimum_required(VERSION 3.2)

project(Action1)
find_package(Switch REQUIRED)
add_executable(Action1 Action1.cpp README.md)
target_link_libraries(Action1 Switch.Forms)
