cmake_minimum_required(VERSION 3.5)

project(Lock)
find_package(Pcf REQUIRED)
add_executable(Lock Lock.cpp)
target_link_libraries(Lock Pcf.Core)
