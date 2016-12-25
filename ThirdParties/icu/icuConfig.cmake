include(${CMAKE_CURRENT_LIST_DIR}/zlib.cmake)  

get_filename_component(ICU_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(ICU_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(ICU_LIBRARIES icu)    

set(icu_FOUND TRUE)
set(ICU_FOUND TRUE)