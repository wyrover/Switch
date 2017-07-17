cmake_minimum_required(VERSION 3.2)

project(TcpClientMultipleClients)
find_package(Pcf REQUIRED)
add_executable(TcpClientMultipleClients TcpClientMultipleClients.cpp)
target_link_libraries(TcpClientMultipleClients Pcf.Core)
