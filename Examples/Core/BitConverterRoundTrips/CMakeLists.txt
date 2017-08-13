cmake_minimum_required(VERSION 3.2)

project(BitConverterRoundTrips)
find_package(Pcf REQUIRED)
add_executable(BitConverterRoundTrips BitConverterRoundTrips.cpp)
target_link_libraries(BitConverterRoundTrips Pcf.Core)
