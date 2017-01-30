include(${CMAKE_CURRENT_LIST_DIR}/jpeg.cmake)  

get_filename_component(JPEG_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(JPEG_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(JPEG_LIBRARIES jpeg)    

set(jpeg_FOUND TRUE)