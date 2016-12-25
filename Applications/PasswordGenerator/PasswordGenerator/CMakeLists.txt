# Add include files here:
set(includeFiles
./Includes/FormPasswordGenerator.h
)

# Add source files here:
set(sourceFiles
./Sources/FormPasswordGenerator.cpp
./Sources/FormPasswordGenerator.Designer.cpp
./Sources/Program.cpp
)

#Add source groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(PasswordGenerator WIN32 ${includeFiles} ${sourceFiles})
target_link_libraries(PasswordGenerator Pcf)
