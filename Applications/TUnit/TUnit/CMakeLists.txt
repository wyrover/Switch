# Add include files here:
set(includeFiles
./Includes/Test.h
./Includes/TestCase.h
./Includes/TestCaseCollection.h
./Includes/TestCollection.h
./Includes/TUnitForm.h
)

# Add source files here:
set(sourceFiles
./Sources/Program.cpp
./Sources/TUnitForm.cpp
./Sources/TUnitForm.Designer.cpp
)

#Add source groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(TUnit WIN32 ${includeFiles} ${sourceFiles})
target_link_libraries(TUnit Pcf.Forms)
