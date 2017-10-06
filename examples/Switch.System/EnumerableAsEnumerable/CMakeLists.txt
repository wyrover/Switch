cmake_minimum_required(VERSION 3.2)

project(EnumerableAsEnumerable)
find_package(Switch REQUIRED)
add_executable(EnumerableAsEnumerable EnumerableAsEnumerable.cpp)
target_link_libraries(EnumerableAsEnumerable Switch.System)
