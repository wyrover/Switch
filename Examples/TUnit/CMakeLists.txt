cmake_minimum_required(VERSION 3.5)

project(Examples.TUnit)

foreach(EXAMPLE ${TUNIT_EXAMPLES})
  if (BuildTUnit${EXAMPLE})
    add_subdirectory("${EXAMPLE}")
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/TUnit)
  endif()
endforeach()
