macro(AddCustomTargets)
  print("Custom Targets:")

  #_______________________________________________________________________________________
  #                                                                             Switch.All
  print("  [X] ${PROJECT_NAME}.All")
  if (WIN32)
    add_custom_target(${PROJECT_NAME}.All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif(XCODE)
    add_custom_target(${PROJECT_NAME}.All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif(UNIX)
    add_custom_target(${PROJECT_NAME}.All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" -- -j 8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  endif()

  #_______________________________________________________________________________________
  #                                                                           Switch.Check
  print("  [X] ${PROJECT_NAME}.Check")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive.txt ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive.txt @ONLY)
  add_custom_target(${PROJECT_NAME}.Check COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_______________________________________________________________________________________
  #                                                                          Switch.Format
  print("  [X] ${PROJECT_NAME}.Format")
  add_custom_target(${PROJECT_NAME}.Format COMMAND ${ASTYLE_EXECUTABLE} ${ASTYLE_ARGS} COMMENT "running astyle" DEPENDS ${ASTYLE_PROJECT})

  #_______________________________________________________________________________________
  #                                                                        Switch.Gitcheck
  print("  [X] ${PROJECT_NAME}.GitCheck")
  add_custom_target(${PROJECT_NAME}.GitCheck COMMAND git diff --check HEAD^ COMMENT "running git check")

  #_______________________________________________________________________________________
  #                                                                         Switch.Install
  print("  [X] ${PROJECT_NAME}.Install")
  if (WIN32)
    add_custom_target(${PROJECT_NAME}.Install "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif (XCODE)
    add_custom_target(${PROJECT_NAME}.Install "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif (UNIX)
    add_custom_target(${PROJECT_NAME}.Install "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install -- -j 8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  endif()

  #_______________________________________________________________________________________
  #                                                                  Switch.ReferenceGuide
  print("  [X] ${PROJECT_NAME}.ReferenceGuide")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.doxygen.txt ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt @ONLY)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide)
  add_custom_target(${PROJECT_NAME}.ReferenceGuide ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide COMMENT "Doxygen Reference Guide generation" DEPENDS ${DOXYGEN_PROJECT} VERBATIM)

  #_______________________________________________________________________________________
  #                                                                           Switch.Tests
  print("  [X] ${PROJECT_NAME}.Tests")
  add_custom_target(${PROJECT_NAME}.Tests COMMAND ctest --output-on-failure -C ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME}.All)
endmacro()
