# Add include files here:
set(includeFiles
)

# Add source files here:
set(sourceFiles
./Sources/Program.cpp
)

#Add source groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(ConsoleApp ${includeFiles} ${sourceFiles})
target_link_libraries(ConsoleApp Pcf)
