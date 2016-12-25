include(${CMAKE_CURRENT_LIST_DIR}/gel_button.cmake)  

get_filename_component(ZLIB_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(ZLIB_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(GEL_BUTTON_LIBRARIES gel_button)    

set(gel_button_FOUND TRUE)