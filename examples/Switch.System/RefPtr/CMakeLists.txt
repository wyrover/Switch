cmake_minimum_required(VERSION 3.2)

project(RefPtr)
find_package(Switch REQUIRED)
add_executable(RefPtr RefPtr.cpp)
target_link_libraries(RefPtr Switch.System)
