cmake_minimum_required(VERSION 3.5)

project(Examples.Core)

if (${BUILD_CORE_EXAMPLES})
  foreach(EXAMPLE ${CORE_EXAMPLES})
    add_subdirectory("${EXAMPLE}")
#    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/Core)
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Pcf/Core/Pcf.Core.Examples)
  endforeach()
endif()
