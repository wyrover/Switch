cmake_minimum_required(VERSION 3.5)

project(Examples.Drawing)

foreach(EXAMPLE ${DRAWING_EXAMPLES})
  if (BuildDrawing${EXAMPLE})
    add_subdirectory("${EXAMPLE}")
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/Drawing)
  endif()
endforeach()
