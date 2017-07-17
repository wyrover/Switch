cmake_minimum_required(VERSION 3.2)

project(ConcurrentStack)
find_package(Pcf REQUIRED)
add_executable(ConcurrentStack ConcurrentStack.cpp)
target_link_libraries(ConcurrentStack Pcf.Core)
