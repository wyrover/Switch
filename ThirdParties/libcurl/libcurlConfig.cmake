include(${CMAKE_CURRENT_LIST_DIR}/libcurl.cmake)  

get_filename_component(LIBCURL_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)

SET(LIBCURL_LIBRARIES
  libcurl
)    

if(MSVC)
  SET(LIBCURL_LIBRARIES
    ${LIBCURL_LIBRARIES}
    Ws2_32.lib
  )
endif()

set(libcurl_FOUND TRUE)