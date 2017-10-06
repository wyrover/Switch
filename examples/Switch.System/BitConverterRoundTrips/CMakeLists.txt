cmake_minimum_required(VERSION 3.2)

project(BitConverterRoundTrips)
find_package(Switch REQUIRED)
add_executable(BitConverterRoundTrips BitConverterRoundTrips.cpp)
target_link_libraries(BitConverterRoundTrips Switch.System)
