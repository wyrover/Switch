set(tests_files
./Microsoft/Win32/RegistryKeyUT.cpp
./Microsoft/Win32/RegistryUT.cpp
./System/Collections/Concurrent/ConcurrentBagTest.cpp
./System/Collections/Generic/DictionaryUT.cpp
./System/Collections/Generic/HashSetUT.cpp
./System/Collections/Generic/KeyValuePairUT.cpp
./System/Collections/Generic/LinkedListUT.cpp
./System/Collections/Generic/ListUT.cpp
./System/Collections/Generic/QueueUT.cpp
./System/Collections/Generic/StackUT.cpp
./System/Collections/Generic/SortedDictionaryUT.cpp
./System/Collections/Generic/SortedSetUT.cpp
./System/Collections/ObjectModel/ReadOnlyCollectionUT.cpp
./System/Collections/ArrayListUT.cpp
./System/Collections/BitArrayUT.cpp
./System/Diagnostics/StackFrameUT.cpp
./System/Diagnostics/TraceUT.cpp
./System/IO/Ports/SerialPortUT.cpp
./System/IO/DirectoryTest.cpp
./System/IO/FileUT.cpp
./System/IO/MemoryStreamUT.cpp
./System/IO/PathUT.cpp
./System/IO/StringReaderUT.cpp
./System/IO/StreamReaderUT.cpp
./System/IO/StreamWriterUT.cpp
./System/Linq/EnumerableUT.cpp
./System/Net/IPAddressUT.cpp
./System/Net/IPEndPointUT.cpp
./System/Net/Sockets/SocketTest.cpp
./System/Runtime/Serialization/SerializationInfoUT.cpp
./System/Text/ASCIIEncodingUT.cpp
./System/Text/DecoderUT.cpp
./System/Text/EncoderUT.cpp
./System/Text/EncodingUT.cpp
./System/Text/EncodingUT.h
./System/Text/UnicodeEncodingUT.cpp
./System/Text/UnicodeEncodingsUT.cpp
./System/Text/UTF32EncodingUT.cpp
./System/Text/UTF8EncodingUT.cpp
./System/Threading/EventTest.cpp
./System/Threading/InterlockedTest.cpp
./System/Threading/LockTest.cpp
./System/Threading/MutexTest.cpp
./System/Threading/SemaphoreTest.cpp
./System/Threading/ThreadTest.cpp
./System/Threading/TimerTest.cpp
./System/ArrayUT.cpp
./System/BitConverterUT.cpp
./System/BooleanUT.cpp
./System/BufferUT.cpp
./System/ByteUT.cpp
./System/CharUT.cpp
./System/ConvertUT.cpp
./System/DateTimeTest.cpp
./System/DateTimeUT.cpp
./System/DelegateUT.cpp
./System/DoubleUT.cpp
./System/EnumTest.cpp
./System/EnvironmentTest.cpp
./System/ExceptionUT.cpp
./System/GuidTest.cpp
./System/Int16UT.cpp
./System/Int32UT.cpp
./System/Int64UT.cpp
./System/MathUT.cpp
./System/NumericalFormat_B_UT.cpp
./System/NumericalFormat_D_UT.cpp
./System/NumericalFormat_F_UT.cpp
./System/NumericalFormat_G_UT.cpp
./System/NumericalFormat_N_UT.cpp
./System/NumericalFormat_P_UT.cpp
./System/NumericalFormat_X_UT.cpp
./System/ObjectTest.cpp
./System/PredicateUT.cpp
./System/RandomUT.cpp
./System/SByteUT.cpp
./System/SingleUT.cpp
./System/StringBuilderTest.cpp
./System/StringTest.cpp
./System/StringFormatUT.cpp
./System/TimeSpanUT.cpp
./System/TimeZoneInfoUT.cpp
./System/TupleUT.cpp
./System/TypeUT.cpp
./System/UInt16UT.cpp
./System/UInt32UT.cpp
./System/UInt64UT.cpp
./System/UriUT.cpp
./System/ValueTypeUT.cpp
./System/VersionUT.cpp
./AbstractTest.cpp
./AnyTest.cpp
./AsTest.cpp
./AsyncTest.cpp
./AwaitTest.cpp
./BoxingTest.cpp
./CurrentInformationTest.cpp
./Main.cpp
./CMakeLists.txt
./Cpp11Test.cpp
./ForEachTest.cpp
./IsUT.cpp
./NativesTest.cpp
./ReferenceUT.cpp
./SharedPointerUT.cpp
./TestTest.cpp
./UnboxingTest.cpp
./UniquePointerUT.cpp
)

set(include_files
./TestUtils.h
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Microsoft REGULAR_EXPRESSION "/UnitTests/Microsoft/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\Microsoft\\Win32 REGULAR_EXPRESSION "/UnitTests/Microsoft/Win32/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System REGULAR_EXPRESSION "/UnitTests/System/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Collections REGULAR_EXPRESSION "/UnitTests/System/Collections/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Collections\\Concurrent REGULAR_EXPRESSION "/UnitTests/System/Collections/Concurrent/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Collections\\Generic REGULAR_EXPRESSION "/UnitTests/System/Collections/Generic/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Collections\\ObjectModel REGULAR_EXPRESSION "/UnitTests/System/Collections/ObjectModel/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Diagnostics REGULAR_EXPRESSION "/UnitTests/System/Diagnostics/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\IO REGULAR_EXPRESSION "/UnitTests/System/IO/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\IO\\Ports REGULAR_EXPRESSION "/UnitTests/System/IO/Ports/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Linq REGULAR_EXPRESSION "/UnitTests/System/Linq/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Net REGULAR_EXPRESSION "/UnitTests/System/Net/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Net\\Sockects REGULAR_EXPRESSION "/UnitTests/System/Net/Sockets/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Runtime\\Serialization REGULAR_EXPRESSION "/UnitTests/System/Runtime/Serialization/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Text REGULAR_EXPRESSION "/UnitTests/System/Text/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(UnitTests\\System\\Threading REGULAR_EXPRESSION "/UnitTests/System/Threading/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Core.UnitTests ${tests_files})

target_link_libraries(Pcf.Core.UnitTests Pcf.Core Pcf.TUnit)

set(test_arguments "--tunit_filter=*")
add_test(NAME Pcf.Core.UnitTests COMMAND $<TARGET_FILE_NAME:Pcf.Core.UnitTests> --gtest_output=xml:${CMAKE_BINARY_DIR}/GTestReports/$<CONFIG>/Pcf.Core.UnitTests.xml ${test_arguments} WORKING_DIRECTORY $<TARGET_FILE_DIR:Pcf.Core.UnitTests> )

set_target_properties(Pcf.Core.UnitTests PROPERTIES FOLDER Pcf/Core)

