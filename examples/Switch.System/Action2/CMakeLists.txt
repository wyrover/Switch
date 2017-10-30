cmake_minimum_required(VERSION 3.2)

project(Action2)
find_package(Switch REQUIRED)
add_executable(Action2 Action2.cpp)
target_link_libraries(Action2 Switch.System.Windows.Forms)
