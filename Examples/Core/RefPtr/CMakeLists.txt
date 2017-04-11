cmake_minimum_required(VERSION 3.5)

project(RefPtr)
find_package(Pcf REQUIRED)
add_executable(RefPtr RefPtr.cpp)
target_link_libraries(RefPtr Pcf.Core)
