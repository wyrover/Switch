include(${CMAKE_CURRENT_LIST_DIR}/easywsclient.cmake)

get_filename_component(easywsclient_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(easywsclient_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(easywsclient_LIBRARIES easywsclient)

set(easywsclient_FOUND TRUE)