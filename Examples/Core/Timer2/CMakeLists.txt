cmake_minimum_required(VERSION 3.5)

project(Timer2)
find_package(Pcf REQUIRED)
add_executable(Timer2 Timer2.cpp)
target_link_libraries(Timer2 Pcf.Core)
