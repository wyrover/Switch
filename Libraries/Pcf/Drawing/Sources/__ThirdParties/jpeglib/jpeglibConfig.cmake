include(${CMAKE_CURRENT_LIST_DIR}/jpeglib.cmake)  

get_filename_component(JPEGLIB_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(JPEGLIB_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(JPEGLIB_LIBRARIES jpeglib)    

set(jpeglib_FOUND TRUE)