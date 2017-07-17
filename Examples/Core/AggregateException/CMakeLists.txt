cmake_minimum_required(VERSION 3.2)

project(AggregateException)
find_package(Pcf REQUIRED)
add_executable(AggregateException AggregateException.cpp)
target_link_libraries(AggregateException Pcf.Core)
