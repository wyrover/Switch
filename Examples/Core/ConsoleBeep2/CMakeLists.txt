cmake_minimum_required(VERSION 3.2)

project(ConsoleBeep2)
find_package(Pcf REQUIRED)
add_executable(ConsoleBeep2 ConsoleBeep2.cpp)
target_link_libraries(ConsoleBeep2 Pcf.Core)
