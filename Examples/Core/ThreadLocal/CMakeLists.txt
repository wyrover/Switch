cmake_minimum_required(VERSION 3.5)

project(ThreadLocal)
find_package(Pcf REQUIRED)
add_executable(ThreadLocal ThreadLocal.cpp)
target_link_libraries(ThreadLocal Pcf.Core)
