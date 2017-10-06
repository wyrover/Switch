cmake_minimum_required(VERSION 3.2)

project(ListCopyTo)
find_package(Switch REQUIRED)
add_executable(ListCopyTo ListCopyTo.cpp)
target_link_libraries(ListCopyTo Switch.System)
