set(tests_files
./BinaryWriterIT.cpp
./FtpWebRequestIT.cpp
./HttpWebRequestIT.cpp
./DictionaryIT.cpp
./DirectoryIT.cpp
./DnsIT.cpp
./DriveIT.cpp
./EventWaitHandleIT.cpp
./FileStreamIT.cpp
./InterlockedIT.cpp
./ListIT.cpp
./MutexIT.cpp
./NetworkStreamIT.cpp
./PathIT.cpp
./QueueIT.cpp
./SemaphoreIT.cpp
./SerializationIT.cpp
./SocketAddress.cpp
./SocketIT.cpp
./StopwatchIT.cpp
./StreamIT.cpp
./StreamRWEncodingsIT.cpp
./TcpClientIT.cpp
./TcpListenerIT.cpp
./ThreadIT.cpp
./ThreadSyncIT.cpp
./TimerIT.cpp
./TestUtils.cpp
./UdpClientIT.cpp
./UnicodeCharsTest.cpp
./WaitHandleIT.cpp
)

set(include_files
./TestUtils.h
)

source_group(IntegrationTests REGULAR_EXPRESSION "/IntegrationTests/[-_,A-Za-z0-9]+\\.(c|h)*")

if (APPLE)
  #message("EXECUTABLE_OUTPUT_PATH Debug = ${EXECUTABLE_OUTPUT_PATH}/Debug")
  #message("EXECUTABLE_OUTPUT_PATH Release = ${EXECUTABLE_OUTPUT_PATH}/Release")
  configure_file(./isLetter.map ${EXECUTABLE_OUTPUT_PATH}/Debug/isLetter.map COPYONLY)
  configure_file(./isDigit.map ${EXECUTABLE_OUTPUT_PATH}/Debug/isDigit.map COPYONLY)
  configure_file(./isPunctuation.map ${EXECUTABLE_OUTPUT_PATH}/Debug/isPunctuation.map COPYONLY)
  configure_file(./isLetter.map ${EXECUTABLE_OUTPUT_PATH}/Release/isLetter.map COPYONLY)
  configure_file(./isDigit.map ${EXECUTABLE_OUTPUT_PATH}/Release/isDigit.map COPYONLY)
  configure_file(./isPunctuation.map ${EXECUTABLE_OUTPUT_PATH}/Release/isPunctuation.map COPYONLY)
else ()
  message("EXECUTABLE_OUTPUT_PATH = ${EXECUTABLE_OUTPUT_PATH}")
  configure_file(./isLetter.map ${EXECUTABLE_OUTPUT_PATH}/isLetter.map COPYONLY)
  configure_file(./isDigit.map ${EXECUTABLE_OUTPUT_PATH}/isDigit.map COPYONLY)
  configure_file(./isPunctuation.map ${EXECUTABLE_OUTPUT_PATH}/isPunctuation.map COPYONLY)
endif ()

add_executable(Pcf.Core.IntegrationTests ${tests_files})

target_link_libraries(Pcf.Core.IntegrationTests Pcf.Core Pcf.TUnit)

set_target_properties(Pcf.Core.IntegrationTests PROPERTIES FOLDER Pcf/Core)
