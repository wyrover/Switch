cmake_minimum_required(VERSION 3.5)

project(Examples.TUnit)

if (BUILD_TUNIT_EXAMPLES)
  foreach(EXAMPLE ${TUNIT_EXAMPLES})
    add_subdirectory("${EXAMPLE}")
#    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/TUnit)
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Pcf/TUnit/Pcf.TUnit.Examples)
  endforeach()
endif()
