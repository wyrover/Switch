cmake_minimum_required(VERSION 3.5)

project(Boxing)
find_package(Pcf REQUIRED)
add_executable(Boxing Boxing.cpp)
target_link_libraries(Boxing Pcf.Core)
