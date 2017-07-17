cmake_minimum_required(VERSION 3.2)

project(Action1)
find_package(Pcf REQUIRED)
add_executable(Action1 Action1.cpp)
target_link_libraries(Action1 Pcf.Forms)
