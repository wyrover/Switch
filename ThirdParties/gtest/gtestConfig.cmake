#include the generated configuration according to the compiler version for visual studio
include(${CMAKE_CURRENT_LIST_DIR}/gtest.cmake)
 
#Set the fullpath for libraries and include files
get_filename_component(GTEST_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(GTEST_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)
 
#Set the library names imported
SET(GTEST_LIBRARIES gtest)
 
#Set that the library has been found
set(gtest_FOUND TRUE)
