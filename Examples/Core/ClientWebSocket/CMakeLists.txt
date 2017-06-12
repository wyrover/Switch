cmake_minimum_required(VERSION 3.5)

project(ClientWebSocket)
find_package(Pcf REQUIRED)
add_executable(ClientWebSocket ClientWebSocket.cpp)
target_link_libraries(ClientWebSocket Pcf.Core)
