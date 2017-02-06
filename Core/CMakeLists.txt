project(Pcf.Core)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(INCLUDE_FILES
  Includes/Pcf/Microsoft/Win32.h
  Includes/Pcf/Microsoft/Win32/Registry.h
  Includes/Pcf/Microsoft/Win32/RegistryKey.h
  Includes/Pcf/Microsoft/Win32/RegistryKeyPermissionCheck.h
  Includes/Pcf/Microsoft/Win32/RegistryHive.h
  Includes/Pcf/Microsoft/Win32/RegistryOptions.h
  Includes/Pcf/Microsoft/Win32/RegistryValueKind.h
  Includes/Pcf/Microsoft/Win32/RegistryValueOptions.h
  Includes/Pcf/System/Collections/Concurrent/ConcurrentBag.h
  Includes/Pcf/System/Collections/Concurrent/ConcurrentQueue.h
  Includes/Pcf/System/Collections/Concurrent/ConcurrentStack.h
  Includes/Pcf/System/Collections/Concurrent/IProducerConsumerCollection.h
  Includes/Pcf/System/Collections/Generic/Comparer.h
  Includes/Pcf/System/Collections/Generic/Dictionary.h
  Includes/Pcf/System/Collections/Generic/GenericException.h
  Includes/Pcf/System/Collections/Generic/HashSet.h
  Includes/Pcf/System/Collections/Generic/ICollection.h
  Includes/Pcf/System/Collections/Generic/IComparer.h
  Includes/Pcf/System/Collections/Generic/IDictionary.h
  Includes/Pcf/System/Collections/Generic/IEnumerable.h
  Includes/Pcf/System/Collections/Generic/IEnumerator.h
  Includes/Pcf/System/Collections/Generic/IList.h
  Includes/Pcf/System/Collections/Generic/ISet.h
  Includes/Pcf/System/Collections/Generic/KeyValuePair.h
  Includes/Pcf/System/Collections/Generic/LinkedList.h
  Includes/Pcf/System/Collections/Generic/List.h
  Includes/Pcf/System/Collections/Generic/Queue.h
  Includes/Pcf/System/Collections/Generic/SortedDictionary.h
  Includes/Pcf/System/Collections/Generic/SortedSet.h
  Includes/Pcf/System/Collections/Generic/Stack.h
  Includes/Pcf/System/Collections/ObjectModel/Collection.h
  Includes/Pcf/System/Collections/ObjectModel/ReadOnlyCollection.h
  Includes/Pcf/System/Collections/Specialized/StringCollection.h
  Includes/Pcf/System/Collections/Specialized/StringDictionary.h
  Includes/Pcf/System/Collections/Specialized/StringEnumerator.h
  Includes/Pcf/System/Collections/ArrayList.h
  Includes/Pcf/System/Collections/BitArray.h
  Includes/Pcf/System/Collections/Comparer.h
  Includes/Pcf/System/Collections/Concurrent.h
  Includes/Pcf/System/Collections/DictionaryEntry.h
  Includes/Pcf/System/Collections/Generic.h
  Includes/Pcf/System/Collections/Hashtable.h
  Includes/Pcf/System/Collections/ICollection.h
  Includes/Pcf/System/Collections/IComparer.h
  Includes/Pcf/System/Collections/IDictionary.h
  Includes/Pcf/System/Collections/IEnumerable.h
  Includes/Pcf/System/Collections/IEnumerator.h
  Includes/Pcf/System/Collections/IList.h
  Includes/Pcf/System/Collections/ObjectModel.h
  Includes/Pcf/System/Collections/Queue.h
  Includes/Pcf/System/Collections/Specialized.h
  Includes/Pcf/System/Collections/Stack.h
  Includes/Pcf/System/ComponentModel/InvalidEnumArgumentException.h
  Includes/Pcf/System/Diagnostics/ConsoleTraceListener.h
  Includes/Pcf/System/Diagnostics/Debug.h
  Includes/Pcf/System/Diagnostics/DefaultTraceListener.h
  Includes/Pcf/System/Diagnostics/NullTraceListener.h
  Includes/Pcf/System/Diagnostics/Process.h
  Includes/Pcf/System/Diagnostics/ProcessStartInfo.h
  Includes/Pcf/System/Diagnostics/ProcessWindowStyle.h
  Includes/Pcf/System/Diagnostics/StackFrame.h
  Includes/Pcf/System/Diagnostics/StackTrace.h
  Includes/Pcf/System/Diagnostics/Stopwatch.h
  Includes/Pcf/System/Diagnostics/TextWriterTraceListener.h
  Includes/Pcf/System/Diagnostics/Trace.h
  Includes/Pcf/System/Diagnostics/TraceEventCache.h
  Includes/Pcf/System/Diagnostics/TraceEventType.h
  Includes/Pcf/System/Diagnostics/TraceFilter.h
  Includes/Pcf/System/Diagnostics/TraceListener.h
  Includes/Pcf/System/Diagnostics/TraceListenerCollection.h
  Includes/Pcf/System/Diagnostics/TraceOptions.h
  Includes/Pcf/System/Diagnostics/TraceSource.h
  Includes/Pcf/System/Globalization/NumberStyles.h
  Includes/Pcf/System/IO/Ports/Handshake.h
  Includes/Pcf/System/IO/Ports/Parity.h
  Includes/Pcf/System/IO/Ports/SerialData.h
  Includes/Pcf/System/IO/Ports/SerialError.h
  Includes/Pcf/System/IO/Ports/SerialPinChange.h
  Includes/Pcf/System/IO/Ports/SerialPort.h
  Includes/Pcf/System/IO/Ports/StopBits.h
  Includes/Pcf/System/IO/Ports/SerialDataReceivedEventArgs.h
  Includes/Pcf/System/IO/Ports/SerialErrorReceivedEventArgs.h
  Includes/Pcf/System/IO/Ports/SerialPinChangedEventArgs.h
  Includes/Pcf/System/IO/Ports/SerialDataReceivedEventHandler.h
  Includes/Pcf/System/IO/Ports/SerialErrorReceivedEventHandler.h
  Includes/Pcf/System/IO/Ports/SerialPinChangedEventHandler.h
  Includes/Pcf/System/IO/BinaryReader.h
  Includes/Pcf/System/IO/BinaryWriter.h
  Includes/Pcf/System/IO/Compression.h
  Includes/Pcf/System/IO/Directory.h
  Includes/Pcf/System/IO/DirectoryInfo.h
  Includes/Pcf/System/IO/DirectoryNotFoundException.h
  Includes/Pcf/System/IO/DriveInfo.h
  Includes/Pcf/System/IO/DriveNotFoundException.h
  Includes/Pcf/System/IO/DriveType.h
  Includes/Pcf/System/IO/EndOfStreamException.h
  Includes/Pcf/System/IO/ErrorEventArgs.h
  Includes/Pcf/System/IO/File.h
  Includes/Pcf/System/IO/FileAccess.h
  Includes/Pcf/System/IO/FileAttributes.h
  Includes/Pcf/System/IO/FileFormatException.h
  Includes/Pcf/System/IO/FileInfo.h
  Includes/Pcf/System/IO/FileLoadException.h
  Includes/Pcf/System/IO/FileNotFoundException.h
  Includes/Pcf/System/IO/FileMode.h
  Includes/Pcf/System/IO/FileShare.h
  Includes/Pcf/System/IO/FileStream.h
  Includes/Pcf/System/IO/FileSystemEventArgs.h
  Includes/Pcf/System/IO/FileSystemInfo.h
  Includes/Pcf/System/IO/InternalBufferOverflowException.h
  Includes/Pcf/System/IO/InvalidDataException.h
  Includes/Pcf/System/IO/IOException.h
  Includes/Pcf/System/IO/IsolatedStorage.h
  Includes/Pcf/System/IO/MemoryStream.h
  Includes/Pcf/System/IO/Packaging.h
  Includes/Pcf/System/IO/Path.h
  Includes/Pcf/System/IO/PathTooLongException.h
  Includes/Pcf/System/IO/Pipes.h
  Includes/Pcf/System/IO/PipeException.h
  Includes/Pcf/System/IO/Ports.h
  Includes/Pcf/System/IO/SeekOrigin.h
  Includes/Pcf/System/IO/Stream.h
  Includes/Pcf/System/IO/StreamReader.h
  Includes/Pcf/System/IO/StreamWriter.h
  Includes/Pcf/System/IO/StringReader.h
  Includes/Pcf/System/IO/StringWriter.h
  Includes/Pcf/System/IO/TextReader.h
  Includes/Pcf/System/IO/TextWriter.h
  Includes/Pcf/System/IO/WatcherChangeTypes.h
  Includes/Pcf/System/Linq/Enumerable.h
  Includes/Pcf/System/Net/Sockets/AddressFamily.h
  Includes/Pcf/System/Net/Sockets/IOControlCode.h
  Includes/Pcf/System/Net/Sockets/IPv6MulticastOption.h
  Includes/Pcf/System/Net/Sockets/LingerOption.h
  Includes/Pcf/System/Net/Sockets/MulticastOption.h
  Includes/Pcf/System/Net/Sockets/NetworkStream.h
  Includes/Pcf/System/Net/Sockets/ProtocolFamily.h
  Includes/Pcf/System/Net/Sockets/ProtocolType.h
  Includes/Pcf/System/Net/Sockets/SelectMode.h
  Includes/Pcf/System/Net/Sockets/Socket.h
  Includes/Pcf/System/Net/Sockets/SocketError.h
  Includes/Pcf/System/Net/Sockets/SocketFlags.h
  Includes/Pcf/System/Net/Sockets/SocketInformation.h
  Includes/Pcf/System/Net/Sockets/SocketInformationOptions.h
  Includes/Pcf/System/Net/Sockets/SocketOptionLevel.h
  Includes/Pcf/System/Net/Sockets/SocketOptionName.h
  Includes/Pcf/System/Net/Sockets/SocketShutdown.h
  Includes/Pcf/System/Net/Sockets/SocketException.h
  Includes/Pcf/System/Net/Sockets/SocketType.h
  Includes/Pcf/System/Net/Sockets/UdpClient.h
  Includes/Pcf/System/Net/Sockets/TcpClient.h
  Includes/Pcf/System/Net/Sockets/TcpListener.h
  Includes/Pcf/System/Net/WebSockets/ClientWebSocket.h
  Includes/Pcf/System/Net/WebSockets/WebSocket.h
  Includes/Pcf/System/Net/WebSockets/WebSocketCloseStatus.h
  Includes/Pcf/System/Net/WebSockets/WebSocketMessageType.h
  Includes/Pcf/System/Net/WebSockets/WebSocketState.h
  Includes/Pcf/System/Net/CookieException.h
  Includes/Pcf/System/Net/Dns.h
  Includes/Pcf/System/Net/DnsEndPoint.h
  Includes/Pcf/System/Net/EndPoint.h
  Includes/Pcf/System/Net/IPAddress.h
  Includes/Pcf/System/Net/IPEndPoint.h
  Includes/Pcf/System/Net/IPHostEntry.h
  Includes/Pcf/System/Net/HttpListenerException.h
  Includes/Pcf/System/Net/HttpStatusCode.h
  Includes/Pcf/System/Net/HttpWebRequest.h
  Includes/Pcf/System/Net/HttpWebResponse.h
  Includes/Pcf/System/Net/FtpStatusCode.h
  Includes/Pcf/System/Net/FtpWebRequest.h
  Includes/Pcf/System/Net/FtpWebResponse.h
  Includes/Pcf/System/Net/NetworkCredential.h
  Includes/Pcf/System/Net/ProtocolViolationException.h
  Includes/Pcf/System/Net/SocketAddress.h
  Includes/Pcf/System/Net/Sockets.h
  Includes/Pcf/System/Net/WebException.h
  Includes/Pcf/System/Net/WebRequest.h
  Includes/Pcf/System/Net/WebRequestMethods.h
  Includes/Pcf/System/Net/WebResponse.h
  Includes/Pcf/System/Net/WebSockets.h
  Includes/Pcf/System/Runtime/Serialization/Formatter.h
  Includes/Pcf/System/Runtime/Serialization/IFormatter.h
  Includes/Pcf/System/Runtime/Serialization/ISerializable.h
  Includes/Pcf/System/Runtime/Serialization/SerializationException.h
  Includes/Pcf/System/Runtime/Serialization/SerializationEntry.h
  Includes/Pcf/System/Runtime/Serialization/SerializationInfo.h
  Includes/Pcf/System/Runtime/Serialization.h
  Includes/Pcf/System/Security/HostProtectionException.h
  Includes/Pcf/System/Security/SecureString.h
  Includes/Pcf/System/Security/SecurityException.h
  Includes/Pcf/System/Security/VerificationException.h
  Includes/Pcf/System/Security/XmlSyntaxException.h
  Includes/Pcf/System/Text/ASCIIEncoding.h
  Includes/Pcf/System/Text/Decoder.h
  Includes/Pcf/System/Text/Encoder.h
  Includes/Pcf/System/Text/Encoding.h
  Includes/Pcf/System/Text/ANSIEncoding.h
  Includes/Pcf/System/Text/StringBuilder.h
  Includes/Pcf/System/Text/UnicodeEncoding.h
  Includes/Pcf/System/Text/UTF8Encoding.h
  Includes/Pcf/System/Text/UTF32Encoding.h
  Includes/Pcf/System/Threading/AbandonedMutexException.h
  Includes/Pcf/System/Threading/AutoResetEvent.h
  Includes/Pcf/System/Threading/Barrier.h
  Includes/Pcf/System/Threading/BarrierPostPhaseException.h
  Includes/Pcf/System/Threading/EventResetMode.h
  Includes/Pcf/System/Threading/EventWaitHandle.h
  Includes/Pcf/System/Threading/Interlocked.h
  Includes/Pcf/System/Threading/LockGuard.h
  Includes/Pcf/System/Threading/LockRecursionException.h
  Includes/Pcf/System/Threading/ManualResetEvent.h
  Includes/Pcf/System/Threading/Monitor.h
  Includes/Pcf/System/Threading/Mutex.h
  Includes/Pcf/System/Threading/ParameterizedThreadStart.h
  Includes/Pcf/System/Threading/RegisteredWaitHandle.h
  Includes/Pcf/System/Threading/Semaphore.h
  Includes/Pcf/System/Threading/SemaphoreFullException.h
  Includes/Pcf/System/Threading/SynchronizationLockException.h
  Includes/Pcf/System/Threading/Tasks.h
  Includes/Pcf/System/Threading/Thread.h
  Includes/Pcf/System/Threading/ThreadLocal.h
  Includes/Pcf/System/Threading/ThreadAbortException.h
  Includes/Pcf/System/Threading/ThreadInterruptedException.h
  Includes/Pcf/System/Threading/ThreadPool.h
  Includes/Pcf/System/Threading/ThreadPriority.h
  Includes/Pcf/System/Threading/ThreadStart.h
  Includes/Pcf/System/Threading/ThreadStartException.h
  Includes/Pcf/System/Threading/ThreadState.h
  Includes/Pcf/System/Threading/ThreadStateException.h
  Includes/Pcf/System/Threading/TimeOut.h
  Includes/Pcf/System/Threading/TimerCallback.h
  Includes/Pcf/System/Threading/Timer.h
  Includes/Pcf/System/Threading/TryLockGuard.h
  Includes/Pcf/System/Threading/WaitHandle.h
  Includes/Pcf/System/Threading/WaitHandleCannotBeOpenedException.h
  Includes/Pcf/System/Threading/Tasks/ITask.h
  Includes/Pcf/System/Threading/Tasks/Parallel.h
  Includes/Pcf/System/Threading/Tasks/Task.h
  Includes/Pcf/System/Threading/Tasks/TaskFactory.h
  Includes/Pcf/System/Threading/Tasks/TaskStatus.h
  Includes/Pcf/System/Threading/Tasks/TaskTResult.h
  Includes/Pcf/System/_String.h
  Includes/Pcf/System/_String.hpp
  Includes/Pcf/System/_ustring.h
  Includes/Pcf/System/Action.h
  Includes/Pcf/System/AccessViolationException.h
  Includes/Pcf/System/AggregateException.h
  Includes/Pcf/System/Allocator.h
  Includes/Pcf/System/AppDomainUnloadedException.h
  Includes/Pcf/System/ApplicationException.h
  Includes/Pcf/System/ArgumentException.h
  Includes/Pcf/System/ArgumentNullException.h
  Includes/Pcf/System/ArgumentOutOfRangeException.h
  Includes/Pcf/System/ArithmeticException.h
  Includes/Pcf/System/Array.h
  Includes/Pcf/System/ArraySegment.h
  Includes/Pcf/System/ArrayTypeMismatchException.h
  Includes/Pcf/System/AsyncCallback.h
  Includes/Pcf/System/BadImageFormatException.h
  Includes/Pcf/System/BitConverter.h
  Includes/Pcf/System/Boolean.h
  Includes/Pcf/System/BoxEnum.h
  Includes/Pcf/System/Buffer.h
  Includes/Pcf/System/Byte.h
  Includes/Pcf/System/CannotUnloadAppDomainException.h
  Includes/Pcf/System/Char.h
  Includes/Pcf/System/CharEnumerator.h
  Includes/Pcf/System/Collections.h
  Includes/Pcf/System/Comparison.h
  Includes/Pcf/System/ComponentModel.h
  Includes/Pcf/System/Console.h
  Includes/Pcf/System/ConsoleCancelEventArgs.h
  Includes/Pcf/System/ConsoleCancelEventHandler.h
  Includes/Pcf/System/ConsoleColor.h
  Includes/Pcf/System/ConsoleKey.h
  Includes/Pcf/System/ConsoleKeyInfo.h
  Includes/Pcf/System/ConsoleModifiers.h
  Includes/Pcf/System/ConsoleSpecialKey.h
  Includes/Pcf/System/ContextMarshalException.h
  Includes/Pcf/System/Convert.h
  Includes/Pcf/System/DataMisalignedException.h
  Includes/Pcf/System/DateTime.h
  Includes/Pcf/System/DateTimeKind.h
  Includes/Pcf/System/DayOfWeek.h
  Includes/Pcf/System/Decimal.h
  Includes/Pcf/System/Delegate.h
  Includes/Pcf/System/Diagnostics.h
  Includes/Pcf/System/DivideByZeroException.h
  Includes/Pcf/System/DllNotFoundException.h
  Includes/Pcf/System/DuplicateWaitObjectException.h
  Includes/Pcf/System/Double.h
  Includes/Pcf/System/Environment.h
  Includes/Pcf/System/EntryPointNotFoundException.h
  Includes/Pcf/System/Enum.h
  Includes/Pcf/System/EventArgs.h
  Includes/Pcf/System/EventHandler.h
  Includes/Pcf/System/ExecutionEngineException.h
  Includes/Pcf/System/Exception.h
  Includes/Pcf/System/FieldAccessException.h
  Includes/Pcf/System/FormatException.h
  Includes/Pcf/System/Func.h
  Includes/Pcf/System/Globalization.h
  Includes/Pcf/System/Guid.h
  Includes/Pcf/System/Hash.h
  Includes/Pcf/System/IAsyncResult.h
  Includes/Pcf/System/ICloneable.h
  Includes/Pcf/System/IComparable.h
  Includes/Pcf/System/IConvertible.h
  Includes/Pcf/System/ICustomFormatter.h
  Includes/Pcf/System/IFormatProvider.h
  Includes/Pcf/System/IFormattable.h
  Includes/Pcf/System/IndexOutOfRangeException.h
  Includes/Pcf/System/InsufficientExecutionStackException.h
  Includes/Pcf/System/InsufficientMemoryException.h
  Includes/Pcf/System/Int16.h
  Includes/Pcf/System/Int32.h
  Includes/Pcf/System/Int64.h
  Includes/Pcf/System/IntPtr.h
  Includes/Pcf/System/InvalidCastException.h
  Includes/Pcf/System/InvalidOperationException.h
  Includes/Pcf/System/InvalidProgramException.h
  Includes/Pcf/System/InvalidTimeZoneException.h
  Includes/Pcf/System/IO.h
  Includes/Pcf/System/Linq.h
  Includes/Pcf/System/Math.h
  Includes/Pcf/System/MemberAccessException.h
  Includes/Pcf/System/MethodAccessException.h
  Includes/Pcf/System/MissingMemberException.h
  Includes/Pcf/System/MissingFieldException.h
  Includes/Pcf/System/MissingMethodException.h
  Includes/Pcf/System/MulticastNotSupportedException.h
  Includes/Pcf/System/Net.h
  Includes/Pcf/System/NotFiniteNumberException.h
  Includes/Pcf/System/NotImplementedException.h
  Includes/Pcf/System/NotSupportedException.h
  Includes/Pcf/System/NullPointerException.h
  Includes/Pcf/System/NullReferenceException.h
  Includes/Pcf/System/Nullable.h
  Includes/Pcf/System/NullType.h
  Includes/Pcf/System/NumberRepresentationBase.h
  Includes/Pcf/System/NumericalFormat.h
  Includes/Pcf/System/NumericalParsing.h
  Includes/Pcf/System/FormatProvider.h
  Includes/Pcf/System/Object.h
  Includes/Pcf/System/ObjectClosedException.h
  Includes/Pcf/System/ObjectDisposedException.h
  Includes/Pcf/System/OperatingSystem.h
  Includes/Pcf/System/OperationCanceledException.h
  Includes/Pcf/System/OutOfMemoryException.h
  Includes/Pcf/System/OverflowException.h
  Includes/Pcf/System/PlatformID.h
  Includes/Pcf/System/PlatformNotSupportedException.h
  Includes/Pcf/System/Predicate.h
  Includes/Pcf/System/Random.h
  Includes/Pcf/System/RankException.h
  Includes/Pcf/System/Runtime.h
  Includes/Pcf/System/SByte.h
  Includes/Pcf/System/Security.h
  Includes/Pcf/System/Single.h
  Includes/Pcf/System/String.h
  Includes/Pcf/System/StackOverflowException.h
  Includes/Pcf/System/StringSplitOptions.h
  Includes/Pcf/System/SystemException.h
  Includes/Pcf/System/SystemVersion.h
  Includes/Pcf/System/Text.h
  Includes/Pcf/System/Threading.h
  Includes/Pcf/System/TimeoutException.h
  Includes/Pcf/System/TimeSpan.h
  Includes/Pcf/System/TimeZoneInfo.h
  Includes/Pcf/System/TimeZoneNotFoundException.h
  Includes/Pcf/System/Tuple.h
  Includes/Pcf/System/TupleImpl.h
  Includes/Pcf/System/Type.h
  Includes/Pcf/System/TypeAccessException.h
  Includes/Pcf/System/TypeCode.h
  Includes/Pcf/System/TypeInitializationException.h
  Includes/Pcf/System/TypeLoadException.h
  Includes/Pcf/System/TypeUnloadedException.h
  Includes/Pcf/System/UInt16.h
  Includes/Pcf/System/UInt32.h
  Includes/Pcf/System/UInt64.h
  Includes/Pcf/System/UIntPtr.h
  Includes/Pcf/System/UnauthorizedAccessException.h
  Includes/Pcf/System/Uri.h
  Includes/Pcf/System/UriComponents.h
  Includes/Pcf/System/UriFormat.h
  Includes/Pcf/System/UriFormatException.h
  Includes/Pcf/System/UriKind.h
  Includes/Pcf/System/UriHostNameType.h
  Includes/Pcf/System/UriPartial.h
  Includes/Pcf/System/UriTemplateMatchException.h
  Includes/Pcf/System/ValueType.h
  Includes/Pcf/System/Version.h
  Includes/Pcf/Abstract.h
  Includes/Pcf/Any.h
  Includes/Pcf/As.h
  Includes/Pcf/Async.h
  Includes/Pcf/Await.h
  Includes/Pcf/Boxing.h
  Includes/Pcf/ExceptionPointer.h
  Includes/Pcf/CurrentInformation.h
  Includes/Pcf/FunctionPointer.h
  Includes/Pcf/InitializerList.h
  Includes/Pcf/Interface.h
  Includes/Pcf/Is.h
  Includes/Pcf/LiteralOperatorConverter.h
  Includes/Pcf/Lock.h
  Includes/Pcf/Move.h
  Includes/Pcf/Property.h
  Includes/Pcf/Public.h
  Includes/Pcf/Ref.h
  Includes/Pcf/Startup.h
  Includes/Pcf/Static.h
  Includes/Pcf/SharedPointer.h
  Includes/Pcf/Types.h
  Includes/Pcf/UniquePointer.h
  Includes/Pcf/Unused.h
  Includes/Pcf/Using.h
  Includes/Pcf/Var.h
  Includes/Pcf/Core.h
  Includes/Pcf/Pcf
  Includes/Pcf/Pcf.h
)

set(SOURCE_FILES
  Sources/__OS/CoreApi.h
  Sources/__OS/ConsoleGcc.cpp
  Sources/__OS/ConsoleW32.cpp
  Sources/__OS/DateTimeGcc.cpp
  Sources/__OS/DateTimeW32.cpp
  Sources/__OS/DebuggerGcc.cpp
  Sources/__OS/DebuggerW32.cpp
  Sources/__OS/DirectoryGcc.cpp
  Sources/__OS/DirectoryW32.cpp
  Sources/__OS/Dns.cpp
  Sources/__OS/DriveGcc.cpp
  Sources/__OS/DriveW32.cpp
  Sources/__OS/EnvironmentGcc.cpp
  Sources/__OS/EnvironmentW32.cpp
  Sources/__OS/Format.cpp
  Sources/__OS/InterlockedGcc.cpp
  Sources/__OS/InterlockedW32.cpp
  Sources/__OS/ProcessGcc.cpp
  Sources/__OS/ProcessW32.cpp
  Sources/__OS/RegistryGcc.cpp
  Sources/__OS/RegistryW32.cpp
  Sources/__OS/Security.cpp
  Sources/__OS/SocketGcc.cpp
  Sources/__OS/SocketW32.cpp
  Sources/__OS/ThreadGcc.cpp
  Sources/__OS/ThreadW32.cpp
  Sources/__OS/TypeGcc.cpp
  Sources/__OS/TypeW32.cpp
  Sources/__OS/UnicodeCharacters.cpp
  Sources/__OS/UnicodeEncodings.cpp
  Sources/Pcf/Microsoft/Win32/RegistryKeyWin.cpp
  Sources/Pcf/Microsoft/Win32/RegistryKeyAll.cpp
  Sources/Pcf/System/Diagnostics/Debug.cpp
  Sources/Pcf/System/Diagnostics/DefaultTraceListener.cpp
  Sources/Pcf/System/Diagnostics/Process.cpp
  Sources/Pcf/System/Diagnostics/ProcessStartInfo.cpp
  Sources/Pcf/System/Diagnostics/StackFrame.cpp
  Sources/Pcf/System/Diagnostics/StackTrace.cpp
  Sources/Pcf/System/Diagnostics/Stopwatch.cpp
  Sources/Pcf/System/Diagnostics/Trace.cpp
  Sources/Pcf/System/Diagnostics/TraceSource.cpp
  Sources/Pcf/System/IO/BinaryReader.cpp
  Sources/Pcf/System/IO/BinaryWriter.cpp
  Sources/Pcf/System/IO/Directory.cpp
  Sources/Pcf/System/IO/DirectoryInfo.cpp
  Sources/Pcf/System/IO/DriveInfo.cpp
  Sources/Pcf/System/IO/File.cpp
  Sources/Pcf/System/IO/FileInfo.cpp
  Sources/Pcf/System/IO/FileStream.cpp
  Sources/Pcf/System/IO/FileSystemInfo.cpp
  Sources/Pcf/System/IO/MemoryStream.cpp
  Sources/Pcf/System/IO/Path.cpp
  Sources/Pcf/System/IO/Ports/SerialPort.cpp
  Sources/Pcf/System/IO/Stream.cpp
  Sources/Pcf/System/IO/StreamReader.cpp
  Sources/Pcf/System/IO/StringReader.cpp
  Sources/Pcf/System/IO/StringWriter.cpp
  Sources/Pcf/System/IO/StreamWriter.cpp
  Sources/Pcf/System/IO/TextReader.cpp
  Sources/Pcf/System/IO/TextWriter.cpp
  Sources/Pcf/System/Net/Dns.cpp
  Sources/Pcf/System/Net/DnsEndPoint.cpp
  Sources/Pcf/System/Net/EndPoint.cpp
  Sources/Pcf/System/Net/Internals/curl.cpp
  Sources/Pcf/System/Net/Internals/curl.h
  Sources/Pcf/System/Net/IPAddress.cpp
  Sources/Pcf/System/Net/IPEndPoint.cpp
  Sources/Pcf/System/Net/IPHostEntry.cpp
  Sources/Pcf/System/Net/SocketAddress.cpp
  Sources/Pcf/System/Net/HttpWebRequest.cpp
  Sources/Pcf/System/Net/HttpWebResponse.cpp
  Sources/Pcf/System/Net/FtpWebRequest.cpp
  Sources/Pcf/System/Net/FtpWebResponse.cpp
  Sources/Pcf/System/Net/WebRequest.cpp
  Sources/Pcf/System/Net/WebRequestMethods.cpp
  Sources/Pcf/System/Net/WebResponse.cpp
  Sources/Pcf/System/Net/Sockets/Socket.cpp
  Sources/Pcf/System/Net/Sockets/UdpClient.cpp
  Sources/Pcf/System/Net/Sockets/NetworkStream.cpp
  Sources/Pcf/System/Net/Sockets/TcpClient.cpp
  Sources/Pcf/System/Net/Sockets/TcpListener.cpp
  Sources/Pcf/System/Net/WebSockets/ClientWebSocket.cpp
  Sources/Pcf/System/Net/WebSockets/WebSocket.cpp
  Sources/Pcf/System/Security/SecureString.cpp
  Sources/Pcf/System/Text/ANSIEncoding.cpp
  Sources/Pcf/System/Text/ASCIIEncoding.cpp
  Sources/Pcf/System/Text/Decoder.cpp
  Sources/Pcf/System/Text/Encoder.cpp
  Sources/Pcf/System/Text/Encoding.cpp
  Sources/Pcf/System/Text/UnicodeEncoding.cpp
  Sources/Pcf/System/Text/UTF8Encoding.cpp
  Sources/Pcf/System/Text/UTF32Encoding.cpp
  Sources/Pcf/System/Threading/EventWaitHandle.cpp
  Sources/Pcf/System/Threading/Interlocked.cpp
  Sources/Pcf/System/Threading/LockGuard.cpp
  Sources/Pcf/System/Threading/Monitor.cpp
  Sources/Pcf/System/Threading/Mutex.cpp
  Sources/Pcf/System/Threading/Semaphore.cpp
  Sources/Pcf/System/Threading/Thread.cpp
  Sources/Pcf/System/Threading/ThreadPool.cpp
  Sources/Pcf/System/Threading/TryLockGuard.cpp
  Sources/Pcf/System/Threading/WaitHandle.cpp
  Sources/Pcf/System/Threading/Tasks/Task.cpp
  Sources/Pcf/System/ArrayAlgorithms.h
  Sources/Pcf/System/BitConverter.cpp
  Sources/Pcf/System/Boolean.cpp
  Sources/Pcf/System/Buffer.cpp
  Sources/Pcf/System/Byte.cpp
  Sources/Pcf/System/Char.cpp
  Sources/Pcf/System/Console.cpp
  Sources/Pcf/System/Convert.cpp
  Sources/Pcf/System/DateTime.cpp
  Sources/Pcf/System/Double.cpp
  Sources/Pcf/System/Environment.cpp
  Sources/Pcf/System/EventArgs.cpp
  Sources/Pcf/System/Exception.cpp
  Sources/Pcf/System/Guid.cpp
  Sources/Pcf/System/Hash.cpp
  Sources/Pcf/System/Int16.cpp
  Sources/Pcf/System/Int32.cpp
  Sources/Pcf/System/Int64.cpp
  Sources/Pcf/System/IntPtr.cpp
  Sources/Pcf/System/Math.cpp
  Sources/Pcf/System/NumericalFormat.cpp
  Sources/Pcf/System/NumericalParsing.cpp
  Sources/Pcf/System/Object.cpp
  Sources/Pcf/System/Random.cpp
  Sources/Pcf/System/Runtime/Serialization/SerializationInfo.cpp
  Sources/Pcf/System/SByte.cpp
  Sources/Pcf/System/Single.cpp
  Sources/Pcf/System/String.cpp
  Sources/Pcf/System/SystemVersion.cpp
  Sources/Pcf/System/TimeSpan.cpp
  Sources/Pcf/System/TimeZoneInfo.cpp
  Sources/Pcf/System/Type.cpp
  Sources/Pcf/System/UInt16.cpp
  Sources/Pcf/System/UInt32.cpp
  Sources/Pcf/System/UInt64.cpp
  Sources/Pcf/System/UIntPtr.cpp
  Sources/Pcf/System/Uri.cpp
  Sources/Pcf/System/ustring.cpp
  Sources/Pcf/System/ValueType.cpp
  Sources/Pcf/System/Version.cpp
  Sources/Pcf/ExceptionPointer.cpp
)

source_group(Documentations REGULAR_EXPRESSION "/Includes/Pcf/Documentations/[-_,A-Za-z0-9]+\\.h*")
source_group(Documentations\\DesignPatterns REGULAR_EXPRESSION "/Includes/Pcf/Documentations/DesignPatterns/[-_,A-Za-z0-9]+\\.h*")
source_group(Documentations\\Examples REGULAR_EXPRESSION "/Includes/Pcf/Documentations/Examples/[-_,A-Za-z0-9]+\\.h*")
source_group(Documentations\\FrameworkDesignGuidelines REGULAR_EXPRESSION "/Includes/Pcf/Documentations/FrameworkDesignGuidelines/[-_,A-Za-z0-9]+\\.h*")
source_group(Documentations\\FrameworkDesignGuidelines\\NamingGuidelines REGULAR_EXPRESSION "/Includes/Pcf/Documentations/FrameworkDesignGuidelines/NamingGuidelines/[-_,A-Za-z0-9]+\\.h*")
source_group(Documentations\\FrameworkDesignGuidelines\\TypeDesignGuidelines REGULAR_EXPRESSION "/Includes/Pcf/Documentations/FrameworkDesignGuidelines/TypeDesignGuidelines/[-_,A-Za-z0-9]+\\.h*")
source_group(Documentations\\FrameworkDesignGuidelines\\MemberDesignGuidelines REGULAR_EXPRESSION "/Includes/Pcf/Documentations/FrameworkDesignGuidelines/MemberDesignGuidelines/[-_,A-Za-z0-9]+\\.h*")
source_group(Documentations\\Tutorials REGULAR_EXPRESSION "/Includes/Pcf/Documentations/Tutorials/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\Microsoft\\Win32 REGULAR_EXPRESSION "/Includes/Pcf/Microsoft/Win32/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\Microsoft REGULAR_EXPRESSION "/Includes/Pcf/Microsoft/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Collections\\Concurrent REGULAR_EXPRESSION "/Includes/Pcf/System/Collections/Concurrent/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Collections\\Internal REGULAR_EXPRESSION "/Includes/Pcf/System/Collections/Internal/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Collections\\Generic REGULAR_EXPRESSION "/Includes/Pcf/System/Collections/Generic/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Collections\\ObjectModel REGULAR_EXPRESSION "/Includes/Pcf/System/Collections/ObjectModel/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Collections\\Specialized REGULAR_EXPRESSION "/Includes/Pcf/System/Collections/Specialized/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Collections REGULAR_EXPRESSION "/Includes/Pcf/System/Collections/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\ComponentModel REGULAR_EXPRESSION "/Includes/Pcf/System/ComponentModel/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Diagnostics REGULAR_EXPRESSION "/Includes/Pcf/System/Diagnostics/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Globalization REGULAR_EXPRESSION "/Includes/Pcf/System/Globalization/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\IO\\Ports REGULAR_EXPRESSION "/Includes/Pcf/System/IO/Ports/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\IO REGULAR_EXPRESSION "/Includes/Pcf/System/IO/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Linq REGULAR_EXPRESSION "/Includes/Pcf/System/Linq/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Net\\Sockets REGULAR_EXPRESSION "/Includes/Pcf/System/Net/Sockets/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Net\\WebSockets REGULAR_EXPRESSION "/Includes/Pcf/System/Net/WebSockets/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Net REGULAR_EXPRESSION "/Includes/Pcf/System/Net/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Security REGULAR_EXPRESSION "/Includes/Pcf/System/Security/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Runtime\\Serialization REGULAR_EXPRESSION "/Includes/Pcf/System/Runtime/Serialization/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Runtime REGULAR_EXPRESSION "/Includes/Pcf/System/Runtime/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Text REGULAR_EXPRESSION "/Includes/Pcf/System/Text/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Threading REGULAR_EXPRESSION "/Includes/Pcf/System/Threading/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Threading\\Tasks REGULAR_EXPRESSION "/Includes/Pcf/System/Threading/Tasks/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System REGULAR_EXPRESSION "/Includes/Pcf/System/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]")
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")

source_group(Sources\\Pcf\\Microsoft\\Win32 REGULAR_EXPRESSION "/Sources/Pcf/Microsoft/Win32/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\Microsoft REGULAR_EXPRESSION "/Sources/Pcf/Microsoft/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\__OS REGULAR_EXPRESSION "/Sources/__OS/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf\\System\\Collections\\Internal REGULAR_EXPRESSION "/Sources/Pcf/System/Collections/Internal/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Collections REGULAR_EXPRESSION "/Sources/Pcf/System/Collections/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\ComponentModel REGULAR_EXPRESSION "/Sources/Pcf/System/ComponentModel/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Diagnostics REGULAR_EXPRESSION "/Sources/Pcf/System/Diagnostics/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\IO\\Ports REGULAR_EXPRESSION "/Sources/Pcf/System/IO/Ports/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\IO REGULAR_EXPRESSION "/Sources/Pcf/System/IO/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Net\\Internals REGULAR_EXPRESSION "/Sources/Pcf/System/Net/Internals/[-_,A-Za-z0-9]+\\.(c*|h*)")
source_group(Sources\\Pcf\\System\\Net\\Sockets REGULAR_EXPRESSION "/Sources/Pcf/System/Net/Sockets/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Net\\WebSockets REGULAR_EXPRESSION "/Sources/Pcf/System/Net/WebSockets/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Net REGULAR_EXPRESSION "/Sources/Pcf/System/Net/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Runtime\\Serialization REGULAR_EXPRESSION "/Sources/Pcf/System/Runtime/Serialization/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Runtime REGULAR_EXPRESSION "/Sources/Pcf/System/Runtime/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Security REGULAR_EXPRESSION "/Sources/Pcf/System/Security/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Text REGULAR_EXPRESSION "/Sources/Pcf/System/Text/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Threading REGULAR_EXPRESSION "/Sources/Pcf/System/Threading/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Threading\\Tasks REGULAR_EXPRESSION "/Sources/Pcf/System/Threading/Tasks/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System REGULAR_EXPRESSION "/Sources/Pcf/System/[-_,A-Za-z0-9]+\\.(c*|h*)")
source_group(Sources\\Pcf REGULAR_EXPRESSION "/Sources/Pcf/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

if(APPLE)
  set(STANDARD_LINK_LIBRARIES dl)
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)    
endif ()	

find_package(Threads REQUIRED)
find_package(call_stack REQUIRED)
find_package(CURL REQUIRED)
find_package(easywsclient REQUIRED)
find_package(Rs232 REQUIRED)
find_package(ZLIB REQUIRED)

add_library(Pcf.Core STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Pcf.Core PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Pcf.Core ${call_stack_LIBRARIES} ${CURL_LIBRARIES} ${easywsclient_LIBRARIES} ${Rs232_LIBRARIES} ${ZLIB_LIBRARIES} Threads::Threads ${STANDARD_LINK_LIBRARIES})
set_target_properties(Pcf.Core PROPERTIES FOLDER Pcf/Core)

install(TARGETS Pcf.Core EXPORT Pcf DESTINATION lib)
install(DIRECTORY "Includes/Pcf/." DESTINATION include/Pcf)
if (MSVC)
  target_compile_options(Pcf.Core PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Pcf.Core>/Pcf.Core${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Pcf.Core PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Pcf.Core>/Pcf.Core.pdb>")
  install(FILES $<TARGET_FILE_DIR:Pcf.Core>/Pcf.Core${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES $<TARGET_FILE_DIR:Pcf.Core>/Pcf.Core.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()

if (BUILD_CORE_INTEGRATION_TESTS)
  add_subdirectory("IntegrationTests")
endif ()
if (BUILD_CORE_MANUAL_TESTS)
  add_subdirectory("ManualTests")
endif ()
if (BUILD_CORE_UNIT_TESTS)
  add_subdirectory("UnitTests")
endif ()
