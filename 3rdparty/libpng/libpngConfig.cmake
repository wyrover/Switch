include(${CMAKE_CURRENT_LIST_DIR}/libpng.cmake)  

get_filename_component(PNG_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(PNG_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(PNG_LIBRARIES libpng)

set(png_FOUND TRUE)
set(PNG_FOUND TRUE)