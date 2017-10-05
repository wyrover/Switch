cmake_minimum_required(VERSION 3.2)

project(SpecializedEventHandler)
find_package(Switch REQUIRED)
add_executable(SpecializedEventHandler SpecializedEventHandler.cpp)
target_link_libraries(SpecializedEventHandler Switch.Core)
