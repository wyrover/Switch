# Add include files here:
set(includeFiles)

# Add source files here:
set(sourceFiles ./Sources/Program.cpp)

#Add source groups here:
source_group(Sources REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_executable(ConsoleAppGenerator ${includeFiles} ${sourceFiles})
target_link_libraries(ConsoleAppGenerator Pcf.Core)
set_target_properties(ConsoleAppGenerator PROPERTIES FOLDER Tools/CodeGenerators)

