include(${CMAKE_CURRENT_LIST_DIR}/easywsclient.cmake)

get_filename_component(EASY_WS_CLIENT_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(EASY_WS_CLIENT_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(EASY_WS_CLIENT_LIBRARIES easywsclient)

set(easywsclient_FOUND TRUE)