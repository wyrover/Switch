cmake_minimum_required(VERSION 3.5)

project(ConcurrentQueue)
find_package(Pcf REQUIRED)
add_executable(ConcurrentQueue ConcurrentQueue.cpp)
target_link_libraries(ConcurrentQueue Pcf.Core)
