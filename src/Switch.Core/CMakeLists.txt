project(Switch.Core)
set(LINK_LIBRARIES call_stack easywsclient RS232 ZLIB::ZLIB Threads::Threads ${STANDARD_CORE_LINK_LIBRARIES})
MakeLibraryProject()
