cmake_minimum_required(VERSION 3.5)

project(Examples VERSION 0.2.0)

option(BUILD_CORE_EXAMPLES "Build Pcf.Core examples" ON)
option(BUILD_DRAWING_EXAMPLES "Build Pcf.Drawing examples" ON)
option(BUILD_FORMS_EXAMPLES "Build Pcf.Forms examples" ON)
option(BUILD_TUNIT_EXAMPLES "Build Pcf.TUnit examples" ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else ()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif ()

macro(subdirlist RESULT CURRENT_DIR)
  file(GLOB children RELATIVE ${CURRENT_DIR} ${CURRENT_DIR}/*)
  set(dirlist "")
  foreach (child ${children})
    if (IS_DIRECTORY ${CURRENT_DIR}/${child})
      LIST(APPEND dirlist ${CURRENT_DIR}/${child})
    endif ()
  endforeach ()
  set(${RESULT} ${dirlist})
endmacro()

macro(add_subdirectory_childrens CURRENT_DIR)
  subdirlist(SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DIR}")
  foreach (SUBDIR ${SUBDIRS})
    add_subdirectory("${SUBDIR}")
  endforeach ()
endmacro ()

add_subdirectory_childrens("Core")
add_subdirectory_childrens("Drawing")
add_subdirectory_childrens("Forms")
add_subdirectory_childrens("TUnit")
