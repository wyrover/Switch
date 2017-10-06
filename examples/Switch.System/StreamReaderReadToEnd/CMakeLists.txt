cmake_minimum_required(VERSION 3.2)

project(StreamReaderReadToEnd)
find_package(Switch REQUIRED)
add_executable(StreamReaderReadToEnd StreamReaderReadToEnd.cpp)
target_link_libraries(StreamReaderReadToEnd Switch.System)
