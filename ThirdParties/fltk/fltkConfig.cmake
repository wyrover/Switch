include(${CMAKE_CURRENT_LIST_DIR}/fltk.cmake)

get_filename_component(FLTK_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_FILE}/../include" ABSOLUTE)
get_filename_component(FLTK_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_FILE}/../lib" ABSOLUTE)

SET(FLTK_LIBRARIES fltk fltk_forms fltk_images fltk_jpeg fltk_gl)    

if(APPLE)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")
elseif (UNIX)
  set(FLTK_LIBRARIES ${FLTK_LIBRARIES} X11.lib)
endif()

set(fltk_FOUND TRUE)