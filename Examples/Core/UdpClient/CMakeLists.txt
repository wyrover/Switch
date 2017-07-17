cmake_minimum_required(VERSION 3.2)

project(UdpClient)
find_package(Pcf REQUIRED)
add_executable(UdpClient UdpClient.cpp)
target_link_libraries(UdpClient Pcf.Core)
