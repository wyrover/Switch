include(${CMAKE_CURRENT_LIST_DIR}/libpng.cmake)  

get_filename_component(LIBPNG_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(LIBPNG_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(LIBPNG_LIBRARIES libpng)    

set(libpng_FOUND TRUE)