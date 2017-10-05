project(Switch.System.UnitTests)

set(SOURCE_FILES
  Switch/System/UriTest.cpp
  CMakeLists.txt
)

GroupSources(.)

add_executable(Switch.System.UnitTests ${SOURCE_FILES})
target_link_libraries(Switch.System.UnitTests Switch.TUnit.Main Switch.TUnit Switch.System)
set_target_properties(Switch.System.UnitTests PROPERTIES FOLDER tests)

add_test(NAME Switch.System.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.System.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.System.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.System.UnitTests>)
