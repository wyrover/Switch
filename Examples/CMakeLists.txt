cmake_minimum_required(VERSION 3.0.2)

project(Examples VERSION 1.0.0)

set(CORE_EXAMPLES Action Action1 Action2 Action3 AggregateException Any ArgumentException Array1 Array2 ArrayArrayOperator ArrayArrayOperatorFunctor ArrayAsReadOnly ArrayConstructor ArrayCopyTo ArrayCopyTo2 ArrayGetEnumerator ArrayGetLength ArrayGetLowerBound ArrayGetSyncRoot ArrayIndexOf ArrayList Async1 Async2 Barrier BitArray BitConverterGetBytesBoolean BitConverterGetBytesChar BitConverterIsLittleEndian BitConverterToString Boolean1 Boolean2 Boolean3 Boolean4 Boolean5 Boolean6 Boolean8 Boxing ClientWebSocket ConcurrentBag ConcurrentQueue ConcurrentStack Console ConsoleOut ConsoleReadKey DateTime DateTimeSpecifyKind Debug Delegate Delegate2 Dictionary DictionaryAdd DictionaryOperators DirectorySeparatorChar Enum Enum2 Environment EventHandler Exception ExceptionPointer Factorial FlagsEnum Foreach1 Foreach2 Foreach3 Foreach4 Format FunctionPointer HashSet HelloWorld HttpWebRequest Interlocked InterlockedDecrement List List2 List3 ListBinarySearch ListCopyTo ListExists ListFind ListReverse Main Math Nullable Object ParallelInvoke Process Profile Properties 
    Random1 Random2 Random3 Socket SortedDictionary SortedDictionaryAdd SortedDictionaryOperators SortedSet Stopwatch StreamReader StreamReaderReadLine StreamReaderReadToEnd StringCollection StringDictionary StringReader Task TaskDelay TcpClient Thread Thread1 Thread2 Thread3 Thread4 ThreadLocal TextWriterTraceListener Timer Timer2 Trace UdpClient UdpClientListener UdpClientTalker Unused Var)
set(DRAWING_EXAMPLES Color)
set(FORMS_EXAMPLES Application Button Calculator CheckBox CheckedListBox Chrono Colors Controls Cursor DockedControls DragAndDrop FolderBrowserDialog Font FontFamily Form FormAndThread FormException FormHelloWorld FormTimer GroupBox ImageList KeyEvents Label ListBox MainMenu MaskedTextBox MessageBox MouseEvents MulticamInstaller NumericUpDown OpenFileDialog Paint Panel PictureBox ProgressBar RadioButton Resource RichTextBox SaveFileDialog Sudoku SystemSound TabControl TextBox UserControl)
set(TUNIT_EXAMPLES Assert Expect TestFixture)

foreach(EXAMPLE ${CORE_EXAMPLES}) 
  option(BuildCore${EXAMPLE} "Build Core examples ${EXAMPLE}" ON)
endforeach()

foreach(EXAMPLE ${DRAWING_EXAMPLES}) 
  option(BuildDrawing${EXAMPLE} "Build Drawing examples ${EXAMPLE}" ON)
endforeach()

foreach(EXAMPLE ${FORMS_EXAMPLES}) 
  option(BuildForms${EXAMPLE} "Build Forms examples ${EXAMPLE}" ON)
endforeach()

foreach(EXAMPLE ${TUNIT_EXAMPLES}) 
  option(BuildTUnit${EXAMPLE} "Build TUnit examples ${EXAMPLE}" ON)
endforeach()


include(Dependences.cmake)

if (APPLE)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (MSVC)
  set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /W4 /wd4100 /wd4127 /wd4132 /wd4133 /wd4189 /wd4244 /wd4245 /wd4310 /wd4312 /wd4355 /wd4389 /wd4456 /wd4458 /wd4505 /wd4510 /wd4512 /wd4610 /wd4701 /wd4702 /wd4706 /wd4996")
  set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Od /Zi /RTC1 /D_DEBUG /DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT /Gy /O2 /Oi /GL- /DNDEBUG /DRELEASE")
endif ()

if (APPLE)
  set(STANDARD_LINK_LIBRARIES pthread)	
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl pthread rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)    
endif ()	

if (APPLE OR UNIX)
  set(HOME $ENV{HOME})
elseif (MSVC)
  set(HOME $ENV{HOMEDRIVE}$ENV{HOMEPATH} CACHE PATH "Home path")
endif()
set(CMAKE_INSTALL_PREFIX "${HOME}/Libraries/${PLATFORM_NAME}/${PROJECT_NAME}/${PROJECT_VERSION}${INSTALL_REV}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else ()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif ()

add_subdirectory("Core")
add_subdirectory("Drawing")
#add_subdirectory("Forms")
add_subdirectory("TUnit")
