project(Switch.System)

set(INCLUDE_FILES
  include/Switch/System/Collections/Concurrent/ConcurrentBag.hpp
  include/Switch/System/Collections/Specialized/StringCollection.hpp
  include/Switch/System/Collections/Specialized/StringDictionary.hpp
  include/Switch/System/Collections/Specialized/StringEnumerator.hpp
  include/Switch/System/Diagnostics/ConsoleTraceListener.hpp
  include/Switch/System/Diagnostics/Debug.hpp
  include/Switch/System/Diagnostics/DefaultTraceListener.hpp
  include/Switch/System/Diagnostics/NullTraceListener.hpp
  include/Switch/System/Diagnostics/TextWriterTraceListener.hpp
  include/Switch/System/Diagnostics/Trace.hpp
  include/Switch/System/Diagnostics/TraceEventCache.hpp
  include/Switch/System/Diagnostics/TraceEventType.hpp
  include/Switch/System/Diagnostics/TraceFilter.hpp
  include/Switch/System/Diagnostics/TraceListener.hpp
  include/Switch/System/Diagnostics/TraceListenerCollection.hpp
  include/Switch/System/Diagnostics/TraceOptions.hpp
  include/Switch/System/Diagnostics/TraceSource.hpp
  include/Switch/System/IO/Ports/Handshake.hpp
  include/Switch/System/IO/Ports/Parity.hpp
  include/Switch/System/IO/Ports/SerialData.hpp
  include/Switch/System/IO/Ports/SerialError.hpp
  include/Switch/System/IO/Ports/SerialPinChange.hpp
  include/Switch/System/IO/Ports/SerialPort.hpp
  include/Switch/System/IO/Ports/StopBits.hpp
  include/Switch/System/IO/Ports/SerialDataReceivedEventArgs.hpp
  include/Switch/System/IO/Ports/SerialErrorReceivedEventArgs.hpp
  include/Switch/System/IO/Ports/SerialPinChangedEventArgs.hpp
  include/Switch/System/IO/Ports/SerialDataReceivedEventHandler.hpp
  include/Switch/System/IO/Ports/SerialErrorReceivedEventHandler.hpp
  include/Switch/System/IO/Ports/SerialPinChangedEventHandler.hpp
  include/Switch/System/IO/ErrorEventArgs.hpp
  include/Switch/System/Net/Sockets/AddressFamily.hpp
  include/Switch/System/Net/Sockets/IOControlCode.hpp
  include/Switch/System/Net/Sockets/IPv6MulticastOption.hpp
  include/Switch/System/Net/Sockets/LingerOption.hpp
  include/Switch/System/Net/Sockets/MulticastOption.hpp
  include/Switch/System/Net/Sockets/NetworkStream.hpp
  include/Switch/System/Net/Sockets/ProtocolFamily.hpp
  include/Switch/System/Net/Sockets/ProtocolType.hpp
  include/Switch/System/Net/Sockets/SelectMode.hpp
  include/Switch/System/Net/Sockets/Socket.hpp
  include/Switch/System/Net/Sockets/SocketError.hpp
  include/Switch/System/Net/Sockets/SocketFlags.hpp
  include/Switch/System/Net/Sockets/SocketInformation.hpp
  include/Switch/System/Net/Sockets/SocketInformationOptions.hpp
  include/Switch/System/Net/Sockets/SocketOptionLevel.hpp
  include/Switch/System/Net/Sockets/SocketOptionName.hpp
  include/Switch/System/Net/Sockets/SocketShutdown.hpp
  include/Switch/System/Net/Sockets/SocketException.hpp
  include/Switch/System/Net/Sockets/SocketType.hpp
  include/Switch/System/Net/Sockets/UdpClient.hpp
  include/Switch/System/Net/Sockets/TcpClient.hpp
  include/Switch/System/Net/Sockets/TcpListener.hpp
  include/Switch/System/Net/WebSockets/ClientWebSocket.hpp
  include/Switch/System/Net/WebSockets/WebSocket.hpp
  include/Switch/System/Net/WebSockets/WebSocketCloseStatus.hpp
  include/Switch/System/Net/WebSockets/WebSocketMessageType.hpp
  include/Switch/System/Net/WebSockets/WebSocketState.hpp
  include/Switch/System/Net/CookieException.hpp
  include/Switch/System/Net/Dns.hpp
  include/Switch/System/Net/DnsEndPoint.hpp
  include/Switch/System/Net/EndPoint.hpp
  include/Switch/System/Net/FtpStatusCode.hpp
  include/Switch/System/Net/FtpWebRequest.hpp
  include/Switch/System/Net/FtpWebResponse.hpp
  include/Switch/System/Net/HttpListenerException.hpp
  include/Switch/System/Net/HttpStatusCode.hpp
  include/Switch/System/Net/HttpWebRequest.hpp
  include/Switch/System/Net/HttpWebResponse.hpp
  include/Switch/System/Net/IPAddress.hpp
  include/Switch/System/Net/IPEndPoint.hpp
  include/Switch/System/Net/IPHostEntry.hpp
  include/Switch/System/Net/NetworkCredential.hpp
  include/Switch/System/Net/ProtocolViolationException.hpp
  include/Switch/System/Net/SocketAddress.hpp
  include/Switch/System/Net/WebException.hpp
  include/Switch/System/Net/WebRequest.hpp
  include/Switch/System/Net/WebRequestMethods.hpp
  include/Switch/System/Net/WebResponse.hpp
  include/Switch/System/Threading/Barrier.hpp
  include/Switch/System/Threading/BarrierPostPhaseException.hpp
  include/Switch/System/Threading/Semaphore.hpp
  include/Switch/System/Threading/SemaphoreFullException.hpp
  include/Switch/System/Uri.hpp
  include/Switch/System/UriComponents.hpp
  include/Switch/System/UriFormat.hpp
  include/Switch/System/UriFormatException.hpp
  include/Switch/System/UriKind.hpp
  include/Switch/System/UriHostNameType.hpp
  include/Switch/System/UriPartial.hpp
  include/Switch/System/UriTemplateMatchException.hpp
  include/Switch/Switch.System.hpp
  include/Switch/Switch.System
)

set(SOURCE_FILES
  src/Native/Api.hpp
  src/Native/CurlApi.cpp
  src/Native/DebuggerApiGcc.cpp
  src/Native/DebuggerApiW32.cpp
  src/Native/DnsApi.cpp
  src/Native/SocketApiGcc.cpp
  src/Native/SocketApiW32.cpp
  src/Switch/System/Diagnostics/Debug.cpp
  src/Switch/System/Diagnostics/DefaultTraceListener.cpp
  src/Switch/System/Diagnostics/Trace.cpp
  src/Switch/System/Diagnostics/TraceSource.cpp
  src/Switch/System/IO/Ports/SerialPort.cpp
  src/Switch/System/Net/Sockets/Socket.cpp
  src/Switch/System/Net/Sockets/UdpClient.cpp
  src/Switch/System/Net/Sockets/NetworkStream.cpp
  src/Switch/System/Net/Sockets/TcpClient.cpp
  src/Switch/System/Net/Sockets/TcpListener.cpp
  src/Switch/System/Net/WebSockets/ClientWebSocket.cpp
  src/Switch/System/Net/WebSockets/WebSocket.cpp
  src/Switch/System/Net/Dns.cpp
  src/Switch/System/Net/DnsEndPoint.cpp
  src/Switch/System/Net/EndPoint.cpp
  src/Switch/System/Net/FtpWebRequest.cpp
  src/Switch/System/Net/FtpWebResponse.cpp
  src/Switch/System/Net/HttpWebRequest.cpp
  src/Switch/System/Net/HttpWebResponse.cpp
  src/Switch/System/Net/IPAddress.cpp
  src/Switch/System/Net/IPEndPoint.cpp
  src/Switch/System/Net/IPHostEntry.cpp
  src/Switch/System/Net/SocketAddress.cpp
  src/Switch/System/Net/WebRequest.cpp
  src/Switch/System/Net/WebRequestMethods.cpp
  src/Switch/System/Net/WebResponse.cpp
  src/Switch/System/Threading/Semaphore.cpp
  src/Switch/System/Uri.cpp
  src/Switch/Switch.System.cpp
)

GroupSources(.)

add_library(Switch.System STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.System PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch.System Switch.Core ${CURL_LIBRARIES})
set_target_properties(Switch.System PROPERTIES FOLDER src)
add_custom_command(TARGET Switch.System POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Switch.System> ${CMAKE_HOME_DIRECTORY}/lib/$<TARGET_FILE_NAME:Switch.System>)

install(TARGETS Switch.System EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if (MSVC)
  target_compile_options(Switch.System PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.System>/Switch.System${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.System PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.System>/Switch.System.pdb>")
  install(FILES $<TARGET_FILE_DIR:Switch.System>/Switch.System${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES $<TARGET_FILE_DIR:Switch.System>/Switch.System.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
