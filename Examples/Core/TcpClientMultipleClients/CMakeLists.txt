cmake_minimum_required(VERSION 3.2)

project(TcpClientMultipleClients)
find_package(Switch REQUIRED)
add_executable(TcpClientMultipleClients TcpClientMultipleClients.cpp)
target_link_libraries(TcpClientMultipleClients Switch.Core)
