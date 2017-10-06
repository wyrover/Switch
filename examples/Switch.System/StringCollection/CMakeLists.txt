cmake_minimum_required(VERSION 3.2)

project(StringCollection)
find_package(Switch REQUIRED)
add_executable(StringCollection StringCollection.cpp)
target_link_libraries(StringCollection Switch.System)
