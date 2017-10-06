cmake_minimum_required(VERSION 3.2)

project(Timer2)
find_package(Switch REQUIRED)
add_executable(Timer2 Timer2.cpp)
target_link_libraries(Timer2 Switch.System)
