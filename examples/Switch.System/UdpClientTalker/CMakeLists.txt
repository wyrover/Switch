cmake_minimum_required(VERSION 3.2)

project(UdpClientTalker)
find_package(Switch REQUIRED)
add_executable(UdpClientTalker UdpClientTalker.cpp)
target_link_libraries(UdpClientTalker Switch.System)
