cmake_minimum_required(VERSION 3.5)

project(UdpClientTalker)
find_package(Pcf REQUIRED)
add_executable(UdpClientTalker UdpClientTalker.cpp)
target_link_libraries(UdpClientTalker Pcf.Core)
