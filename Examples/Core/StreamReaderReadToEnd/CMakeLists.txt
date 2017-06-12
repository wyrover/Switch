cmake_minimum_required(VERSION 3.5)

project(StreamReaderReadToEnd)
find_package(Pcf REQUIRED)
add_executable(StreamReaderReadToEnd StreamReaderReadToEnd.cpp)
target_link_libraries(StreamReaderReadToEnd Pcf.Core)
