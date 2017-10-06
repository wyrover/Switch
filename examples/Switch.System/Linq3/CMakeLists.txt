cmake_minimum_required(VERSION 3.2)

project(Linq3)
find_package(Switch REQUIRED)
add_executable(Linq3 Linq3.cpp)
target_link_libraries(Linq3 Switch.System)
