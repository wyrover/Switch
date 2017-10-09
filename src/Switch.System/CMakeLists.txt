project(Switch.System)

set(INCLUDE_FILES
  include/Switch/System/Collections/Concurrent/ConcurrentBag.hpp
  include/Switch/System/Net/FtpStatusCode.hpp
  include/Switch/System/Net/FtpWebRequest.hpp
  include/Switch/System/Net/FtpWebResponse.hpp
  include/Switch/System/Net/HttpListenerException.hpp
  include/Switch/System/Net/HttpStatusCode.hpp
  include/Switch/System/Net/HttpWebRequest.hpp
  include/Switch/System/Net/HttpWebResponse.hpp
  include/Switch/System/Net/WebRequest.hpp
  include/Switch/System/Net/WebRequestMethods.hpp
  include/Switch/System/Net/WebResponse.hpp
  include/Switch/System/Uri.hpp
  include/Switch/System/UriComponents.hpp
  include/Switch/System/UriFormat.hpp
  include/Switch/System/UriFormatException.hpp
  include/Switch/System/UriKind.hpp
  include/Switch/System/UriHostNameType.hpp
  include/Switch/System/UriPartial.hpp
  include/Switch/System/UriTemplateMatchException.hpp
  include/Switch/System.hpp
)

set(SOURCE_FILES
  src/Switch/System/Net/Internals/curl.cpp
  src/Switch/System/Net/Internals/curl.hpp
  src/Switch/System/Net/HttpWebRequest.cpp
  src/Switch/System/Net/HttpWebResponse.cpp
  src/Switch/System/Net/FtpWebRequest.cpp
  src/Switch/System/Net/FtpWebResponse.cpp
  src/Switch/System/Net/WebRequest.cpp
  src/Switch/System/Net/WebRequestMethods.cpp
  src/Switch/System/Net/WebResponse.cpp
  src/Switch/System/Uri.cpp
)

GroupSources(.)

add_library(Switch.System STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.System PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch.System Switch.Core ${CURL_LIBRARIES})
set_target_properties(Switch.System PROPERTIES FOLDER src)
add_custom_command(TARGET Switch.System POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Switch.System> ${CMAKE_HOME_DIRECTORY}/lib/$<TARGET_FILE_NAME:Switch.System>)

install(TARGETS Switch.System EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if (MSVC)
  target_compile_options(Switch.System PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.System>/Switch.System${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.System PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.System>/Switch.System.pdb>")
  install(FILES $<TARGET_FILE_DIR:Switch.System>/Switch.System${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES $<TARGET_FILE_DIR:Switch.System>/Switch.System.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
