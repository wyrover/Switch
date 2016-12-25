# Add include files here:
set(includeFiles
./Includes/Pcf/Toolbox.h
./Includes/Pcf/Toolbox
./Includes/Toolbox/IO.h
./Includes/Toolbox/IO/FileBrowsedEventArgs.h
./Includes/Toolbox/SystemInformations.h
./Includes/Toolbox/SystemInformations/Compiler.h
./Includes/Toolbox/SystemInformations/Language.h
)

# Add source files here:
set(sourceFiles
./Sources/Pcf/Toolbox.cpp
)

#Add include groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]")
source_group(Includes\\Toolbox REGULAR_EXPRESSION "/Includes/Toolbox/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Toolbox\\IO REGULAR_EXPRESSION "/Includes/Toolbox/IO/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Toolbox\\SystemInformations REGULAR_EXPRESSION "/Includes/Toolbox/SystemInformations/[-_,A-Za-z0-9]+\\.h*")

#Add source groups here:
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf REGULAR_EXPRESSION "/Sources/Pcf/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Toolbox REGULAR_EXPRESSION "/Sources/Toolbox/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Toolbox\\IO REGULAR_EXPRESSION "/Sources/Toolbox/IO/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Toolbox\\SystemInformations REGULAR_EXPRESSION "/Sources/Toolbox/SystemInformations/[-_,A-Za-z0-9]+\\.c*")

add_library(Pcf.Toolbox STATIC ${includeFiles} ${sourceFiles})
target_include_directories(Pcf.Toolbox PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Pcf.Toolbox Pcf)

set_target_properties(Pcf.Toolbox PROPERTIES FOLDER Pcf/Toolbox)

install(TARGETS Pcf.Toolbox EXPORT Toolbox DESTINATION lib)
install(DIRECTORY "./Includes/."  DESTINATION include)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:Pcf.Toolbox>/Pcf.Toolbox${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:Pcf.Toolbox>/Pcf.Toolbox.pdb")
  target_compile_options(Pcf.Toolbox PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(Pcf.Toolbox PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.Toolbox>/Pcf.Toolbox${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION bin CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.Toolbox>Pcf.Toolbox.pdb" DESTINATION bin CONFIGURATIONS Release OPTIONAL)
endif()
