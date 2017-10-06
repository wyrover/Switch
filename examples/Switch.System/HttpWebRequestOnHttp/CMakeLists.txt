cmake_minimum_required(VERSION 3.2)

project(HttpWebRequestOnHttp)
find_package(Switch REQUIRED)
add_executable(HttpWebRequestOnHttp HttpWebRequestOnHttp.cpp)
target_link_libraries(HttpWebRequestOnHttp Switch.System)
