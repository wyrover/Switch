project(Switch.Core)
set(LINK_LIBRARIES call_stack easywsclient RS232 ${ZLIB_LIBRARIES} Threads::Threads ${STANDARD_CORE_LINK_LIBRARIES})
MakeLibraryProject()
