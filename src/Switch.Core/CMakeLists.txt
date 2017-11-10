project(Switch.Core)
set(LINK_LIBRARIES call_stack easywsclient Rs232 zlib Threads::Threads ${STANDARD_CORE_LINK_LIBRARIES})
MakeLibraryProject()
