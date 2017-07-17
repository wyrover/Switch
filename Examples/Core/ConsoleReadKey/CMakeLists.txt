cmake_minimum_required(VERSION 3.2)

project(ConsoleReadKey)
find_package(Pcf REQUIRED)
add_executable(ConsoleReadKey ConsoleReadKey.cpp)
target_link_libraries(ConsoleReadKey Pcf.Core)
