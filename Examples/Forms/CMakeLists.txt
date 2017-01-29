cmake_minimum_required(VERSION 3.5)

project(Examples.Forms)

if (BUILD_FORMS_EAXMPLES)
  foreach(EXAMPLE ${FORMS_EXAMPLES})
    add_subdirectory("${EXAMPLE}")
#    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Examples/Forms)
    set_target_properties(${EXAMPLE} PROPERTIES FOLDER Pcf/Forms/Pcf.Forms.Examples)
  endforeach()
endif()
