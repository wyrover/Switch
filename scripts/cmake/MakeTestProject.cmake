macro(MakeTestProject)
  if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /wd4996")
  endif()

  file(GLOB_RECURSE SOURCE_FILES "*.hpp" "*.cpp")

  GroupSources(.)

  add_executable(${PROJECT_NAME} ${SOURCE_FILES})
  target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES} ${GTEST_LIBRARIES})
  set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER tests)

  add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> --gtest_filter=*.* --gtest_output=xml:${PROJECT_NAME}.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endmacro()