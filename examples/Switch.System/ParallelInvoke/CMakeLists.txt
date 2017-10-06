cmake_minimum_required(VERSION 3.2)

project(ParallelInvoke)
find_package(Switch REQUIRED)
add_executable(ParallelInvoke ParallelInvoke.cpp)
target_link_libraries(ParallelInvoke Switch.System)
