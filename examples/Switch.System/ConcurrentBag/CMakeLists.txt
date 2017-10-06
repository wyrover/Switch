cmake_minimum_required(VERSION 3.2)

project(ConcurrentBag)
find_package(Switch REQUIRED)
add_executable(ConcurrentBag ConcurrentBag.cpp)
target_link_libraries(ConcurrentBag Switch.System)
