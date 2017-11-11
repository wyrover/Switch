project(Switch.System)
set(LINK_LIBRARIES Switch.Core libcurl)
MakeLibraryProject()
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:libcurl> ${CMAKE_HOME_DIRECTORY}/lib/$<TARGET_FILE_NAME:libcurl>)
