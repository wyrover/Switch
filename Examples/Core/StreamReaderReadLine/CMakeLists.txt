cmake_minimum_required(VERSION 3.2)

project(StreamReaderReadLine)
find_package(Pcf REQUIRED)
add_executable(StreamReaderReadLine StreamReaderReadLine.cpp)
target_link_libraries(StreamReaderReadLine Pcf.Core)
