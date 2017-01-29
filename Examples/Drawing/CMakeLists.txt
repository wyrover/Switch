cmake_minimum_required(VERSION 3.5)

project(Examples.Drawing)

if (BUILD_DRAWING_EXAMPLES)
  foreach(EXAMPLE ${DRAWING_EXAMPLES})
    add_subdirectory("${EXAMPLE}")
#    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/Drawing)
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Pcf/Drawing/Pcf.Drawing.Examples)
  endforeach()
endif()
