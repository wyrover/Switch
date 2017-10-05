set(INCLUDE_FILES
)

set(SOURCE_FILES
)

source_group(Includes\\Switch\\Microsoft\\Win32 REGULAR_EXPRESSION "/Includes/Switch/Microsoft/Win32/[-_,A-Za-z0-9]+\\.hpp*")

source_group(Sources\\Switch\\Microsoft\\Win32 REGULAR_EXPRESSION "/Sources/Switch/Microsoft/Win32/[-_,A-Za-z0-9]+\\.c*")

add_library(Switch.System STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.System PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch.System call_stack ${CURL_LIBRARIES} easywsclient Rs232 ZLIB::ZLIB Threads::Threads ${STANDARD_CORE_LINK_LIBRARIES})
set_target_properties(Switch.System PROPERTIES FOLDER Switch/System)

if (BUILD_TESTS)
#  add_subdirectory("ManualTests")
#  add_subdirectory("UnitTests")
endif()

install(TARGETS Switch.System EXPORT Switch DESTINATION lib)
install(DIRECTORY "Includes/Switch/." DESTINATION include/Switch)
if (MSVC)
  target_compile_options(Switch.System PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.System>/Switch.System${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.System PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.System>/Switch.System.pdb>")
  install(FILES $<TARGET_FILE_DIR:Switch.System>/Switch.System${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES $<TARGET_FILE_DIR:Switch.System>/Switch.System.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
