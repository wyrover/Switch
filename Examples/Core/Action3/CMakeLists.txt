cmake_minimum_required(VERSION 3.2)

project(Action3)
find_package(Switch REQUIRED)
add_executable(Action3 Action3.cpp)
target_link_libraries(Action3 Switch.Forms)
