cmake_minimum_required(VERSION 3.5)

project(TextWriterTraceListener)
find_package(Pcf REQUIRED)
add_executable(TextWriterTraceListener TextWriterTraceListener.cpp)
target_link_libraries(TextWriterTraceListener Pcf.Core)
