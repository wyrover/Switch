cmake_minimum_required(VERSION 3.2)

project(BitConverterGetBytesBoolean)
find_package(Switch REQUIRED)
add_executable(BitConverterGetBytesBoolean BitConverterGetBytesBoolean.cpp)
target_link_libraries(BitConverterGetBytesBoolean Switch.System)
