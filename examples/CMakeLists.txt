cmake_minimum_required(VERSION 3.2)

project(Examples VERSION 0.2.0)

option(BUILD_CORE_EXAMPLES "Build Switch.Core examples" ON)
option(BUILD_DESIGNPATTERNS_EXAMPLES "Build DesignPatterns examples" ON)
option(BUILD_DRAWING_EXAMPLES "Build Switch.Drawing examples" ON)
option(BUILD_FORMS_EXAMPLES "Build Switch.Forms examples" ON)
option(BUILD_TUNIT_EXAMPLES "Build Switch.TUnit examples" ON)

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
      LIST(APPEND dirlist ${child})
    endif ()
  endforeach ()
  set(${RESULT} ${dirlist})
endmacro()

macro(add_subdirectory_childrens CURRENT_DIR)
  subdirlist(SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DIR}")
  foreach (SUBDIR ${SUBDIRS})
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DIR}/${SUBDIR}")
    set_target_properties(${SUBDIR} PROPERTIES FOLDER ${CURRENT_DIR})
  endforeach ()
endmacro ()

if (BUILD_CORE_EXAMPLES)
  add_subdirectory_childrens("Core")
endif()

if (BUILD_CORE_EXAMPLES)
  add_subdirectory_childrens("DesignPatterns")
endif()

if (BUILD_DRAWING_EXAMPLES)
  add_subdirectory_childrens("Drawing")
endif()

if (BUILD_FORMS_EXAMPLES)
  add_subdirectory_childrens("Forms")
endif()

if (BUILD_TUNIT_EXAMPLES)
  add_subdirectory_childrens("TUnit")
endif()
