cmake_minimum_required(VERSION 3.2)

project(Random2)
find_package(Switch REQUIRED)
add_executable(Random2 Random2.cpp)
target_link_libraries(Random2 Switch.System)
