project(Switch.Core)
set(LINK_LIBRARIES call_stack easywsclient Rs232 ZLIB::ZLIB Threads::Threads ${STANDARD_CORE_LINK_LIBRARIES})
MakeProject()
