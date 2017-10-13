Project(Switch)

set(INCLUDE_FILES
  include/Switch/Switch
  include/Switch/Switch.hpp
)

set(SOURCE_FILES
  src/Switch/Switch.cpp
)

GroupSources(.)

add_library(Switch STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch Switch.System.Windows.Forms Switch.System.Drawing Switch.TUnit.Core Switch.System.Core  Switch.System Switch.Core)
set_target_properties(Switch PROPERTIES FOLDER src)
add_custom_command(TARGET Switch POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Switch> ${CMAKE_HOME_DIRECTORY}/lib/$<TARGET_FILE_NAME:Switch>)

install(TARGETS Switch EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if (MSVC)
  target_compile_options(Switch PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch>/Switch${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch>/Switch.pdb>")
  install(FILES $<TARGET_FILE_DIR:Switch>/Switch${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES $<TARGET_FILE_DIR:Switch>/Switch.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
