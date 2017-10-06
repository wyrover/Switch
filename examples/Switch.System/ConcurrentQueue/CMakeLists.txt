cmake_minimum_required(VERSION 3.2)

project(ConcurrentQueue)
find_package(Switch REQUIRED)
add_executable(ConcurrentQueue ConcurrentQueue.cpp)
target_link_libraries(ConcurrentQueue Switch.System)
