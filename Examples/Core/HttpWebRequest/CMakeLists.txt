cmake_minimum_required(VERSION 3.5)

project(HttpWebRequest)

find_package(Pcf REQUIRED)
add_executable(HttpWebRequest HttpWebRequest.cpp)
target_link_libraries(HttpWebRequest Pcf.Core)
