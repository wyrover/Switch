project(Switch.TUnit.UnitTests)

set(SOURCE_FILES
  Switch/TUnit/AssertTest.cpp
  Switch/TUnit/ExpectTest.cpp
  CMakeLists.txt
)

GroupSources(.)

add_executable(Switch.TUnit.UnitTests ${SOURCE_FILES})
target_link_libraries(Switch.TUnit.UnitTests Switch.TUnit.Main)
set_target_properties(Switch.TUnit.UnitTests PROPERTIES FOLDER tests)

enable_testing()
add_test(NAME Switch.TUnit.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.TUnit.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.TUnit.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.TUnit.UnitTests>)
