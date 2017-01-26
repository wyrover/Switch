cmake_minimum_required(VERSION 3.5)

project(Examples.Core)

foreach(EXAMPLE ${CORE_EXAMPLES})
  if (BuildCore${EXAMPLE})
    add_subdirectory("${EXAMPLE}")
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/Core)
  endif()
endforeach()
