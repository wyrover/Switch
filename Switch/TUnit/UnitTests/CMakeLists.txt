set(SOURCE_FILES
  AssertTest.cpp
  ExpectTest.cpp
  CMakeLists.txt
)

source_group(TUnit REGULAR_EXPRESSION "/TUnit/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.TUnit.UnitTests ${SOURCE_FILES})
target_link_libraries(Switch.TUnit.UnitTests Switch.TUnit.Main Switch.TUnit)
set_target_properties(Switch.TUnit.UnitTests PROPERTIES FOLDER Switch/TUnit)

enable_testing()
add_test(NAME Switch.TUnit.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.TUnit.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.TUnit.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.TUnit.UnitTests>)
