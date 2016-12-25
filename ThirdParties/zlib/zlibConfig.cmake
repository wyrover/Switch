include(${CMAKE_CURRENT_LIST_DIR}/zlib.cmake)  

get_filename_component(ZLIB_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(ZLIB_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(ZLIB_LIBRARIES zlib)    

set(zlib_FOUND TRUE)