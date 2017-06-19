cmake_minimum_required(VERSION 3.5)

project(Event)
find_package(Pcf REQUIRED)
add_executable(Event Event.cpp)
target_link_libraries(Event Pcf.Core)
