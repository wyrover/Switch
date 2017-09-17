cmake_minimum_required(VERSION 3.2)

project(StringFormat1)
find_package(Switch REQUIRED)
add_executable(StringFormat1 StringFormat1.cpp)
target_link_libraries(StringFormat1 Switch.Core)
