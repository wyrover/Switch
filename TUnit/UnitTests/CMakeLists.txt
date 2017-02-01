set(SOURCE_FILES
  AssertTest.cpp
  ExpectTest.cpp
  CMakeLists.txt
)

source_group(TUnit REGULAR_EXPRESSION "/TUnit/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.TUnit.UnitTests ${SOURCE_FILES})
target_link_libraries(Pcf.TUnit.UnitTests Pcf.TUnit.Main Pcf.TUnit)
set_target_properties(Pcf.TUnit.UnitTests PROPERTIES FOLDER Pcf/TUnit)

enable_testing()
add_test(NAME Pcf.TUnit.UnitTests COMMAND $<TARGET_FILE_NAME:Pcf.TUnit.UnitTests> --tunit_filter=*.* --tunit_output=xml:Pcf.TUnit.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Pcf.TUnit.UnitTests>)
