include(${CMAKE_CURRENT_LIST_DIR}/call_stack.cmake)  

get_filename_component(CALL_STACK_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(CALL_STACK_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(CALL_STACK_LIBRARIES call_stack)

set(call_stack_FOUND TRUE)
set(CALL_STACK_FOUND TRUE)