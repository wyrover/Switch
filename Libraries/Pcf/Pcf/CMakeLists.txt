# Add include files here:
set(include_files
./Includes/Pcf/Pcf
./Includes/Pcf/Pcf.h
)

# Add source files here:
set(source_files
./Sources/SystemVersion.cpp
)

#Add include groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.h*")

#Add source groups here:
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_library(Pcf STATIC ${include_files} ${source_files})
target_include_directories(Pcf PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Pcf Pcf.Forms)

install(TARGETS Pcf EXPORT Pcf DESTINATION lib/${COMPILER_SUBDIR})
install(DIRECTORY "./Includes/."  DESTINATION include)

set_target_properties(Pcf PROPERTIES FOLDER Pcf/Pcf)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:Pcf>/Pcf${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:Pcf>/Pcf.pdb")
  target_compile_options(Pcf PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(Pcf PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:Pcf>/Pcf${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION bin CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf>Pcf.pdb" DESTINATION bin CONFIGURATIONS Release OPTIONAL)
endif()
