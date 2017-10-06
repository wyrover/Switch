cmake_minimum_required(VERSION 3.2)

project(Random1)
find_package(Switch REQUIRED)
add_executable(Random1 Random1.cpp)
target_link_libraries(Random1 Switch.System)
