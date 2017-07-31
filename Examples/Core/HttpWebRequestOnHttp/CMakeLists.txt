cmake_minimum_required(VERSION 3.2)

project(HttpWebRequestOnHttp)
find_package(Pcf REQUIRED)
add_executable(HttpWebRequestOnHttp HttpWebRequestOnHttp.cpp)
target_link_libraries(HttpWebRequestOnHttp Pcf.Core)
