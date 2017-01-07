set(tests_files
./AssertTest.cpp
./ExpectTest.cpp
./CMakeLists.txt
)

set(include_files
)

source_group(TUnit REGULAR_EXPRESSION "/TUnit/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.TUnit.UnitTests ${tests_files} ${include_files})

target_link_libraries(Pcf.TUnit.UnitTests Pcf.TUnit)

add_test(NAME Pcf.TUnit.UnitTests COMMAND $<TARGET_FILE_NAME:Pcf.TUnit.UnitTests> --tunit_filter=*.* --tunit_output=xml:Pcf.TUnit.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Pcf.TUnit.UnitTests>)

set_target_properties(Pcf.TUnit.UnitTests PROPERTIES FOLDER Pcf/TUnit)
