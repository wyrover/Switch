cmake_minimum_required(VERSION 3.2)

project(ClientWebSocket)
find_package(Switch REQUIRED)
add_executable(ClientWebSocket ClientWebSocket.cpp)
target_link_libraries(ClientWebSocket Switch.System)
