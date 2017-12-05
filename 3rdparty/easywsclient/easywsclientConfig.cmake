include(${CMAKE_CURRENT_LIST_DIR}/easywsclient.cmake)

get_filename_component(easywsclient_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(EASYWSCLIENT_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(easywsclient_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)
get_filename_component(EASYWSCLIENT_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(easywsclient_LIBRARY easywsclient)
SET(EASYWSCLIENT_LIBRARY easywsclient)
SET(easywsclient_LIBRARIES ${EASYWSCLIENT_LIBRARY})
SET(EASYWSCLIENT_LIBRARIES ${EASYWSCLIENT_LIBRARY})

set(easywsclient_FOUND TRUE)
set(EASYWSCLIENT_FOUND TRUE)
