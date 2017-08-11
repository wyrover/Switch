cmake_minimum_required(VERSION 3.2)

project(ConsoleBuffer)
find_package(Pcf REQUIRED)
add_executable(ConsoleBuffer ConsoleBuffer.cpp)
target_link_libraries(ConsoleBuffer Pcf.Core)
