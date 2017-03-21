set(SOURCE_FILES
  Pcf/Microsoft/Win32/RegistryKeyUT.cpp
  Pcf/Microsoft/Win32/RegistryUT.cpp
  Pcf/System/Collections/Concurrent/ConcurrentBagTest.cpp
  Pcf/System/Collections/Generic/DictionaryUT.cpp
  Pcf/System/Collections/Generic/HashSetUT.cpp
  Pcf/System/Collections/Generic/KeyValuePairUT.cpp
  Pcf/System/Collections/Generic/LinkedListUT.cpp
  Pcf/System/Collections/Generic/ListUT.cpp
  Pcf/System/Collections/Generic/QueueUT.cpp
  Pcf/System/Collections/Generic/StackUT.cpp
  Pcf/System/Collections/Generic/SortedDictionaryUT.cpp
  Pcf/System/Collections/Generic/SortedSetUT.cpp
  Pcf/System/Collections/ObjectModel/ReadOnlyCollectionUT.cpp
  Pcf/System/Collections/ArrayListUT.cpp
  Pcf/System/Collections/BitArrayUT.cpp
  Pcf/System/Diagnostics/ProcessStartInfoUnitTests.cpp
  Pcf/System/Diagnostics/StackFrameUT.cpp
  Pcf/System/Diagnostics/TraceUT.cpp
  Pcf/System/IO/Ports/SerialPortUT.cpp
  Pcf/System/IO/DirectoryTest.cpp
  Pcf/System/IO/FileUT.cpp
  Pcf/System/IO/MemoryStreamUT.cpp
  Pcf/System/IO/PathUT.cpp
  Pcf/System/IO/StringReaderUT.cpp
  Pcf/System/IO/StreamReaderUT.cpp
  Pcf/System/IO/StreamWriterUT.cpp
  Pcf/System/Linq/EnumerableUT.cpp
  Pcf/System/Net/IPAddressUT.cpp
  Pcf/System/Net/IPEndPointUT.cpp
  Pcf/System/Net/Sockets/SocketTest.cpp
  Pcf/System/Runtime/Serialization/SerializationInfoUT.cpp
  Pcf/System/Text/ASCIIEncodingUT.cpp
  Pcf/System/Text/DecoderUT.cpp
  Pcf/System/Text/EncoderUT.cpp
  Pcf/System/Text/EncodingUT.cpp
  Pcf/System/Text/EncodingUT.h
  Pcf/System/Text/UnicodeEncodingUT.cpp
  Pcf/System/Text/UnicodeEncodingsUT.cpp
  Pcf/System/Text/UTF32EncodingUT.cpp
  Pcf/System/Text/UTF8EncodingUT.cpp
  Pcf/System/Threading/EventTest.cpp
  Pcf/System/Threading/InterlockedTest.cpp
  Pcf/System/Threading/LockGuardTest.cpp
  Pcf/System/Threading/MutexTest.cpp
  Pcf/System/Threading/SemaphoreTest.cpp
  Pcf/System/Threading/ThreadTest.cpp
  Pcf/System/Threading/TimerTest.cpp
  Pcf/System/ArrayUT.cpp
  Pcf/System/BitConverterUT.cpp
  Pcf/System/BooleanUT.cpp
  Pcf/System/BufferUT.cpp
  Pcf/System/ByteUT.cpp
  Pcf/System/CharUT.cpp
  Pcf/System/ConvertUT.cpp
  Pcf/System/DateTimeTest.cpp
  Pcf/System/DateTimeUT.cpp
  Pcf/System/DelegateUT.cpp
  Pcf/System/DoubleUT.cpp
  Pcf/System/EnumTest.cpp
  Pcf/System/EnvironmentTest.cpp
  Pcf/System/ExceptionUT.cpp
  Pcf/System/GuidTest.cpp
  Pcf/System/Int16UT.cpp
  Pcf/System/Int32UT.cpp
  Pcf/System/Int64UT.cpp
  Pcf/System/MathUT.cpp
  Pcf/System/NumericalFormat_B_UT.cpp
  Pcf/System/NumericalFormat_D_UT.cpp
  Pcf/System/NumericalFormat_F_UT.cpp
  Pcf/System/NumericalFormat_G_UT.cpp
  Pcf/System/NumericalFormat_N_UT.cpp
  Pcf/System/NumericalFormat_P_UT.cpp
  Pcf/System/NumericalFormat_X_UT.cpp
  Pcf/System/ObjectTest.cpp
  Pcf/System/PredicateUT.cpp
  Pcf/System/RandomUT.cpp
  Pcf/System/SByteUT.cpp
  Pcf/System/SingleUT.cpp
  Pcf/System/StringBuilderTest.cpp
  Pcf/System/StringTest.cpp
  Pcf/System/StringFormatUT.cpp
  Pcf/System/TimeSpanUT.cpp
  Pcf/System/TimeZoneInfoUT.cpp
  Pcf/System/TupleUT.cpp
  Pcf/System/TypeUT.cpp
  Pcf/System/UInt16UT.cpp
  Pcf/System/UInt32UT.cpp
  Pcf/System/UInt64UT.cpp
  Pcf/System/UriUT.cpp
  Pcf/System/ValueTypeUT.cpp
  Pcf/System/VersionUT.cpp
  Pcf/AbstractTest.cpp
  Pcf/AnyTest.cpp
  Pcf/AsTest.cpp
  Pcf/AsyncTest.cpp
  Pcf/AwaitTest.cpp
  Pcf/BoxingTest.cpp
  Pcf/CurrentInformationTest.cpp
  Pcf/Cpp11Test.cpp
  Pcf/ExceptionPointerTest.cpp
  Pcf/ForEachTest.cpp
  Pcf/FunctionPointerTest.cpp
  Pcf/InitializerListTest.cpp
  Pcf/InterfaceTest.cpp
  Pcf/IsTest.cpp
  Pcf/LiteralOperatorConverterTest.cpp
  Pcf/LockTest.cpp
  Pcf/MoveTest.cpp
  Pcf/NativesTest.cpp
  Pcf/PropertyTest.cpp
  Pcf/PropertyReadOnlyTest.cpp
  Pcf/PropertyWriteOnlyTest.cpp
  Pcf/ReferenceUT.cpp
  Pcf/SharedPointerUT.cpp
  Pcf/TestTest.cpp
  Pcf/UnboxingTest.cpp
  Pcf/UniquePointerUT.cpp
  CMakeLists.txt
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf REGULAR_EXPRESSION "/UnitTests/Pcf/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\Microsoft REGULAR_EXPRESSION "/UnitTests/Pcf/Microsoft/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\Microsoft\\Win32 REGULAR_EXPRESSION "/UnitTests/Pcf/Microsoft/Win32/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System REGULAR_EXPRESSION "/UnitTests/Pcf/System/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Collections REGULAR_EXPRESSION "/UnitTests/Pcf/System/Collections/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Collections\\Concurrent REGULAR_EXPRESSION "/UnitTests/Pcf/System/Collections/Concurrent/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Collections\\Generic REGULAR_EXPRESSION "/UnitTests/Pcf/System/Collections/Generic/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Collections\\ObjectModel REGULAR_EXPRESSION "/UnitTests/Pcf/System/Collections/ObjectModel/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Diagnostics REGULAR_EXPRESSION "/UnitTests/Pcf/System/Diagnostics/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\IO REGULAR_EXPRESSION "/UnitTests/Pcf/System/IO/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\IO\\Ports REGULAR_EXPRESSION "/UnitTests/Pcf/System/IO/Ports/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Linq REGULAR_EXPRESSION "/UnitTests/Pcf/System/Linq/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Net REGULAR_EXPRESSION "/UnitTests/Pcf/System/Net/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Net\\Sockects REGULAR_EXPRESSION "/UnitTests/Pcf/System/Net/Sockets/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Runtime\\Serialization REGULAR_EXPRESSION "/UnitTests/Pcf/System/Runtime/Serialization/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Text REGULAR_EXPRESSION "/UnitTests/Pcf/System/Text/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Pcf\\System\\Threading REGULAR_EXPRESSION "/UnitTests/Pcf/System/Threading/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Core.UnitTests ${SOURCE_FILES})
target_link_libraries(Pcf.Core.UnitTests Pcf.TUnit.Main Pcf.TUnit Pcf.Core)
set_target_properties(Pcf.Core.UnitTests PROPERTIES FOLDER Pcf/Core)

add_test(NAME Pcf.Core.UnitTests COMMAND $<TARGET_FILE_NAME:Pcf.Core.UnitTests> --tunit_filter=*.* --tunit_output=xml:Pcf.Core.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Pcf.Core.UnitTests>)
