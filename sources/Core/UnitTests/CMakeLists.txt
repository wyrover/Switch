set(SOURCE_FILES
  Switch/Microsoft/Win32/RegistryKeyUT.cpp
  Switch/Microsoft/Win32/RegistryUT.cpp
  Switch/System/Collections/Concurrent/ConcurrentBagTest.cpp
  Switch/System/Collections/Generic/DictionaryUT.cpp
  Switch/System/Collections/Generic/HashSetUT.cpp
  Switch/System/Collections/Generic/KeyValuePairUT.cpp
  Switch/System/Collections/Generic/LinkedListUT.cpp
  Switch/System/Collections/Generic/ListUT.cpp
  Switch/System/Collections/Generic/QueueUT.cpp
  Switch/System/Collections/Generic/StackUT.cpp
  Switch/System/Collections/Generic/SortedDictionaryUT.cpp
  Switch/System/Collections/Generic/SortedSetUT.cpp
  Switch/System/Collections/ObjectModel/ReadOnlyCollectionUT.cpp
  Switch/System/Collections/ArrayListUT.cpp
  Switch/System/Collections/BitArrayUT.cpp
  Switch/System/Diagnostics/ProcessStartInfoUnitTests.cpp
  Switch/System/Diagnostics/StackFrameUT.cpp
  Switch/System/Diagnostics/TraceUT.cpp
  Switch/System/IO/Ports/SerialPortUT.cpp
  Switch/System/IO/DirectoryTest.cpp
  Switch/System/IO/FileUT.cpp
  Switch/System/IO/MemoryStreamUT.cpp
  Switch/System/IO/PathUT.cpp
  Switch/System/IO/StringReaderUT.cpp
  Switch/System/IO/StreamReaderUT.cpp
  Switch/System/IO/StreamWriterUT.cpp
  Switch/System/Linq/EnumerableUT.cpp
  Switch/System/Net/IPAddressUT.cpp
  Switch/System/Net/IPEndPointUT.cpp
  Switch/System/Net/Sockets/SocketTest.cpp
  Switch/System/Runtime/CompilerServices/CallerTest.cpp
  Switch/System/Runtime/Serialization/SerializationInfoUT.cpp
  Switch/System/Text/ASCIIEncodingUT.cpp
  Switch/System/Text/DecoderUT.cpp
  Switch/System/Text/EncoderUT.cpp
  Switch/System/Text/EncodingUT.cpp
  Switch/System/Text/EncodingUT.hpp
  Switch/System/Text/UnicodeEncodingUT.cpp
  Switch/System/Text/UnicodeEncodingsUT.cpp
  Switch/System/Text/UTF32EncodingUT.cpp
  Switch/System/Text/UTF8EncodingUT.cpp
  Switch/System/Threading/EventTest.cpp
  Switch/System/Threading/InterlockedTest.cpp
  Switch/System/Threading/LockGuardTest.cpp
  Switch/System/Threading/MutexTest.cpp
  Switch/System/Threading/SemaphoreTest.cpp
  Switch/System/Threading/ThreadTest.cpp
  Switch/System/Threading/TimerTest.cpp
  Switch/System/ArrayUT.cpp
  Switch/System/BitConverterUT.cpp
  Switch/System/BooleanUT.cpp
  Switch/System/BufferUT.cpp
  Switch/System/ByteUT.cpp
  Switch/System/CharUT.cpp
  Switch/System/ConvertUT.cpp
  Switch/System/DateTimeTest.cpp
  Switch/System/DateTimeUT.cpp
  Switch/System/DelegateUT.cpp
  Switch/System/DoubleUT.cpp
  Switch/System/EnumTest.cpp
  Switch/System/EnvironmentTest.cpp
  Switch/System/ExceptionUT.cpp
  Switch/System/GuidTest.cpp
  Switch/System/Int16UT.cpp
  Switch/System/Int32UT.cpp
  Switch/System/Int64UT.cpp
  Switch/System/MathUT.cpp
  Switch/System/NumericalFormat_B_UT.cpp
  Switch/System/NumericalFormat_D_UT.cpp
  Switch/System/NumericalFormat_F_UT.cpp
  Switch/System/NumericalFormat_G_UT.cpp
  Switch/System/NumericalFormat_N_UT.cpp
  Switch/System/NumericalFormat_P_UT.cpp
  Switch/System/NumericalFormat_X_UT.cpp
  Switch/System/ObjectTest.cpp
  Switch/System/PredicateUT.cpp
  Switch/System/RandomUT.cpp
  Switch/System/SByteUT.cpp
  Switch/System/SingleUT.cpp
  Switch/System/StringBuilderTest.cpp
  Switch/System/StringTest.cpp
  Switch/System/StringFormatUT.cpp
  Switch/System/TimeSpanUT.cpp
  Switch/System/TimeZoneInfoUT.cpp
  Switch/System/TupleUT.cpp
  Switch/System/TypeUT.cpp
  Switch/System/UInt16UT.cpp
  Switch/System/UInt32UT.cpp
  Switch/System/UInt64UT.cpp
  Switch/System/UriUT.cpp
  Switch/System/ValueTypeUT.cpp
  Switch/System/VersionUT.cpp
  Switch/AbstractTest.cpp
  Switch/AnyTest.cpp
  Switch/AsTest.cpp
  Switch/AsyncTest.cpp
  Switch/AwaitTest.cpp
  Switch/BoxingTest.cpp
  Switch/Cpp11Test.cpp
  Switch/ExceptionPointerTest.cpp
  Switch/ForEachTest.cpp
  Switch/FunctionPointerTest.cpp
  Switch/InitializerListTest.cpp
  Switch/InterfaceTest.cpp
  Switch/IsTest.cpp
  Switch/LiteralOperatorConverterTest.cpp
  Switch/LockTest.cpp
  Switch/MoveTest.cpp
  Switch/NativesTest.cpp
  Switch/PropertyTest.cpp
  Switch/PropertyReadOnlyTest.cpp
  Switch/PropertyWriteOnlyTest.cpp
  Switch/ReferenceUT.cpp
  Switch/SharedPointerUT.cpp
  Switch/TestTest.cpp
  Switch/UnboxingTest.cpp
  CMakeLists.txt
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch REGULAR_EXPRESSION "/UnitTests/Switch/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\Microsoft REGULAR_EXPRESSION "/UnitTests/Switch/Microsoft/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\Microsoft\\Win32 REGULAR_EXPRESSION "/UnitTests/Switch/Microsoft/Win32/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System REGULAR_EXPRESSION "/UnitTests/Switch/System/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Collections REGULAR_EXPRESSION "/UnitTests/Switch/System/Collections/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Collections\\Concurrent REGULAR_EXPRESSION "/UnitTests/Switch/System/Collections/Concurrent/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Collections\\Generic REGULAR_EXPRESSION "/UnitTests/Switch/System/Collections/Generic/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Collections\\ObjectModel REGULAR_EXPRESSION "/UnitTests/Switch/System/Collections/ObjectModel/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Diagnostics REGULAR_EXPRESSION "/UnitTests/Switch/System/Diagnostics/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\IO REGULAR_EXPRESSION "/UnitTests/Switch/System/IO/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\IO\\Ports REGULAR_EXPRESSION "/UnitTests/Switch/System/IO/Ports/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Linq REGULAR_EXPRESSION "/UnitTests/Switch/System/Linq/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Net REGULAR_EXPRESSION "/UnitTests/Switch/System/Net/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Net\\Sockects REGULAR_EXPRESSION "/UnitTests/Switch/System/Net/Sockets/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Runtime\\CompilerServices REGULAR_EXPRESSION "/UnitTests/Switch/System/Runtime/CompilerServices/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Runtime\\Serialization REGULAR_EXPRESSION "/UnitTests/Switch/System/Runtime/Serialization/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Text REGULAR_EXPRESSION "/UnitTests/Switch/System/Text/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Switch\\System\\Threading REGULAR_EXPRESSION "/UnitTests/Switch/System/Threading/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.Core.UnitTests ${SOURCE_FILES})
target_link_libraries(Switch.Core.UnitTests Switch.TUnit.Main Switch.TUnit Switch.Core)
set_target_properties(Switch.Core.UnitTests PROPERTIES FOLDER sources/Core)

add_test(NAME Switch.Core.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.Core.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.Core.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.Core.UnitTests>)
