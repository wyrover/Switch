include(${CMAKE_CURRENT_LIST_DIR}/Fl_Gel_Tabs.cmake)  

get_filename_component(FL_GEL_TABS_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(FL_GEL_TABS_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(FL_GEL_TABS_LIBRARIES Fl_Gel_Tabs)    

set(Fl_Gel_Tabs_FOUND TRUE)