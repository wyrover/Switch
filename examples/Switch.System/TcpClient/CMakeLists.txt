cmake_minimum_required(VERSION 3.2)

project(TcpClient)
find_package(Switch REQUIRED)
add_executable(TcpClient TcpClient.cpp)
target_link_libraries(TcpClient Switch.System)
