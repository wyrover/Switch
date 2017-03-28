include(${CMAKE_CURRENT_LIST_DIR}/call_stack.cmake)  

get_filename_component(call_stack_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(call_stack_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(call_stack_LIBRARIES call_stack)    

set(call_stack_FOUND TRUE)