cmake_minimum_required(VERSION 3.2)

project(UdpClientListener)
find_package(Pcf REQUIRED)
add_executable(UdpClientListener UdpClientListener.cpp)
target_link_libraries(UdpClientListener Pcf.Core)
