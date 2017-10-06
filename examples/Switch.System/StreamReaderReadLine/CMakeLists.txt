cmake_minimum_required(VERSION 3.2)

project(StreamReaderReadLine)
find_package(Switch REQUIRED)
add_executable(StreamReaderReadLine StreamReaderReadLine.cpp)
target_link_libraries(StreamReaderReadLine Switch.System)
