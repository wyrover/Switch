cmake_minimum_required(VERSION 3.2)

project(ThreadLocal)
find_package(Switch REQUIRED)
add_executable(ThreadLocal ThreadLocal.cpp)
target_link_libraries(ThreadLocal Switch.System)
