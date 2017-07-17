cmake_minimum_required(VERSION 3.2)

project(HelloWorld)
find_package(Pcf REQUIRED)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld Pcf.Core)
