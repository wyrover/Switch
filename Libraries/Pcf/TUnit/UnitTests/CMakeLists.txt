set(tests_files
./AssertTest.cpp
./ExpectTest.cpp
./Main.cpp
./CMakeLists.txt
)

set(include_files
)

source_group(TUnit REGULAR_EXPRESSION "/TUnit/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.TUnit.UnitTests ${tests_files} ${include_files})

target_link_libraries(Pcf.TUnit.UnitTests Pcf.TUnit)

#AddGTest(Pcf.TUnit.UnitTests "--tunit_filter=*")

set_target_properties(Pcf.TUnit.UnitTests PROPERTIES FOLDER Pcf/TUnit)
