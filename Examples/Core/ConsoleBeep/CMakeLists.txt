cmake_minimum_required(VERSION 3.2)

project(ConsoleBeep)
find_package(Pcf REQUIRED)
add_executable(ConsoleBeep ConsoleBeep.cpp)
target_link_libraries(ConsoleBeep Pcf.Core)
