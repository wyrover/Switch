cmake_minimum_required(VERSION 3.2)

project(HttpWebRequestOnHttps)
find_package(Pcf REQUIRED)
add_executable(HttpWebRequestOnHttps HttpWebRequestOnHttps.cpp)
target_link_libraries(HttpWebRequestOnHttps Pcf.Core)
