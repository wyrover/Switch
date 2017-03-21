source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_library(Pcf.TUnit.Main STATIC Sources/Main.cpp)
target_link_libraries(Pcf.TUnit.Main Pcf.TUnit Pcf.Core)

set_target_properties(Pcf.TUnit.Main PROPERTIES FOLDER Pcf/TUnit.Main)

install(TARGETS Pcf.TUnit.Main EXPORT Pcf DESTINATION lib)
if(MSVC)
  target_compile_options(Pcf.TUnit.Main PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Pcf.TUnit.Main>/Pcf.TUnit.Main${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Pcf.TUnit.Main PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Pcf.TUnit.Main>/Pcf.TUnit.Main.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.TUnit>/Pcf.TUnit.Main${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.TUnit>Pcf.TUnit.Main.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
