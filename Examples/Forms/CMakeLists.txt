cmake_minimum_required(VERSION 3.5)

project(Examples.Forms)

foreach(EXAMPLE ${FORMS_EXAMPLES})
  if (BuildForms${EXAMPLE})
    add_subdirectory("${EXAMPLE}")
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/Forms)
  endif()
endforeach()
