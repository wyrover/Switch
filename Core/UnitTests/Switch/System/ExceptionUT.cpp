#include <Switch/System/AccessViolationException.hpp>
#include <Switch/System/AppDomainUnloadedException.hpp>
#include <Switch/System/ArrayTypeMismatchException.hpp>
#include <Switch/System/BadImageFormatException.hpp>
#include <Switch/System/CannotUnloadAppDomainException.hpp>
#include <Switch/System/ContextMarshalException.hpp>
#include <Switch/System/DataMisalignedException.hpp>
#include <Switch/System/DivideByZeroException.hpp>
#include <Switch/System/DllNotFoundException.hpp>
#include <Switch/System/DuplicateWaitObjectException.hpp>
#include <Switch/System/EntryPointNotFoundException.hpp>
#include <Switch/System/FieldAccessException.hpp>
#include <Switch/System/ExecutionEngineException.hpp>
#include <Switch/System/Exception.hpp>
#include <Switch/System/InsufficientExecutionStackException.hpp>
#include <Switch/System/InsufficientMemoryException.hpp>
#include <Switch/System/InvalidProgramException.hpp>
#include <Switch/System/InvalidTimeZoneException.hpp>
#include <Switch/System/MemberAccessException.hpp>
#include <Switch/System/MethodAccessException.hpp>
#include <Switch/System/MissingFieldException.hpp>
#include <Switch/System/MissingMemberException.hpp>
#include <Switch/System/MissingMethodException.hpp>
#include <Switch/System/MulticastNotSupportedException.hpp>
#include <Switch/System/NotFiniteNumberException.hpp>
#include <Switch/System/NotImplementedException.hpp>
#include <Switch/System/NullPointerException.hpp>
#include <Switch/System/NullReferenceException.hpp>
#include <Switch/System/ObjectClosedException.hpp>
#include <Switch/System/OperationCanceledException.hpp>
#include <Switch/System/PlatformNotSupportedException.hpp>
#include <Switch/System/StackOverflowException.hpp>
#include <Switch/System/SystemException.hpp>
#include <Switch/System/TimeoutException.hpp>
#include <Switch/System/TimeZoneNotFoundException.hpp>
#include <Switch/System/TypeAccessException.hpp>
#include <Switch/System/TypeUnloadedException.hpp>
#include <Switch/System/UnauthorizedAccessException.hpp>
#include <Switch/System/UriFormatException.hpp>
#include <Switch/System/UriTemplateMatchException.hpp>
#include <Switch/System/IO/DirectoryNotFoundException.hpp>
#include <Switch/System/IO/DriveNotFoundException.hpp>
#include <Switch/System/IO/EndOfStreamException.hpp>
#include <Switch/System/IO/FileFormatException.hpp>
#include <Switch/System/IO/FileLoadException.hpp>
#include <Switch/System/IO/FileNotFoundException.hpp>
#include <Switch/System/IO/InternalBufferOverflowException.hpp>
#include <Switch/System/IO/InvalidDataException.hpp>
#include <Switch/System/IO/IOException.hpp>
#include <Switch/System/IO/PathTooLongException.hpp>
#include <Switch/System/IO/PipeException.hpp>
#include <Switch/System/Net/CookieException.hpp>
#include <Switch/System/Net/HttpListenerException.hpp>
#include <Switch/System/Net/ProtocolViolationException.hpp>
#include <Switch/System/Net/WebException.hpp>
#include <Switch/System/Net/Sockets/SocketException.hpp>
#include <Switch/System/Threading/AbandonedMutexException.hpp>
#include <Switch/System/Threading/BarrierPostPhaseException.hpp>
#include <Switch/System/Threading/LockRecursionException.hpp>
#include <Switch/System/Threading/SemaphoreFullException.hpp>
#include <Switch/System/Threading/SynchronizationLockException.hpp>
#include <Switch/System/Threading/ThreadAbortException.hpp>
#include <Switch/System/Threading/ThreadInterruptedException.hpp>
#include <Switch/System/Threading/ThreadStartException.hpp>
#include <Switch/System/Threading/ThreadStateException.hpp>
#include <Switch/System/Threading/WaitHandleCannotBeOpenedException.hpp>
#include <Switch/System/Runtime/Serialization/SerializationException.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Runtime::Serialization;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class MyFirstGroupException : public System::Exception {
  public:
    MyFirstGroupException() : System::Exception() {}
    MyFirstGroupException(const MyFirstGroupException& value) : System::Exception(value) {}
    MyFirstGroupException(const CurrentInformation& information) : System::Exception(information) {} \
    MyFirstGroupException(const System::String& message) : System::Exception(message) {}
    MyFirstGroupException(const System::String& message, const CurrentInformation& information) : System::Exception(message, information) {}
    MyFirstGroupException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : System::Exception(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My First Group Exception"; }
  };

  class MySecondGroupException : public System::Exception {
  public:
    MySecondGroupException() : System::Exception() {}
    MySecondGroupException(const MySecondGroupException& value) : System::Exception(value) {}
    MySecondGroupException(const CurrentInformation& information) : System::Exception(information) {}
    MySecondGroupException(const System::String& message) : System::Exception(message) {}
    MySecondGroupException(const System::String& message, const CurrentInformation& information) : System::Exception(message, information) {}
    MySecondGroupException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : System::Exception(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Second Group Exception"; }
  };
  
  class MyFirstOwnException : public MyFirstGroupException {
  public:
    MyFirstOwnException() : MyFirstGroupException() {}
    MyFirstOwnException(const MyFirstOwnException& value) : MyFirstGroupException(value) {}
    MyFirstOwnException(const CurrentInformation& information) : MyFirstGroupException(information) {}
    MyFirstOwnException(const System::String& message) : MyFirstGroupException(message) {}
    MyFirstOwnException(const System::String& message, const CurrentInformation& information) : MyFirstGroupException(message, information) {}
    MyFirstOwnException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : MyFirstGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My First Own Exception"; }
  };
  
  class MySecondOwnException : public MyFirstGroupException {
  public:
    MySecondOwnException() : MyFirstGroupException() {}
    MySecondOwnException(const MySecondOwnException& value) : MyFirstGroupException(value) {}
    MySecondOwnException(const CurrentInformation& information) : MyFirstGroupException(information) {}
    MySecondOwnException(const System::String& message) : MyFirstGroupException(message) {}
    MySecondOwnException(const System::String& message, const CurrentInformation& information) : MyFirstGroupException(message, information) {}
    MySecondOwnException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : MyFirstGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Second Own Exception"; }
  };
  
  class MyThirdOwnException : public MySecondGroupException {
  public:
    MyThirdOwnException() : MySecondGroupException() {}
    MyThirdOwnException(const MyThirdOwnException& value) : MySecondGroupException(value) {}
    MyThirdOwnException(const CurrentInformation& information) : MySecondGroupException(information) {}
    MyThirdOwnException(const System::String& message) : MySecondGroupException(message) {}
    MyThirdOwnException(const System::String& message, const CurrentInformation& information) : MySecondGroupException(message, information) {}
    MyThirdOwnException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : MySecondGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Third Own Exception"; }
  };
  
  class MyFourthOwnException : public MySecondGroupException {
  public:
    MyFourthOwnException() : MySecondGroupException() {}
    MyFourthOwnException(const MyFourthOwnException& value) : MySecondGroupException(value) {}
    MyFourthOwnException(const CurrentInformation& information) : MySecondGroupException(information) {}
    MyFourthOwnException(const System::String& message) : MySecondGroupException(message) {}
    MyFourthOwnException(const System::String& message, const CurrentInformation& information) : MySecondGroupException(message, information) {}
    MyFourthOwnException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : MySecondGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Fourth Own Exception"; }
  };
  
  TEST(Exception, Constructor) {
    ASSERT_TRUE(is<Exception>(Exception()));
    ASSERT_EQ((int32)0x80131500, Exception().HResult());
    ASSERT_NE(_current_information.FilePath, Exception().FilePath());
    ASSERT_NE(_current_information.LineNumber, Exception().LineNumber());
    ASSERT_FALSE(Exception().HasInnerException);
    
    ASSERT_TRUE(is<Exception>(Exception(_current_information)));
    ASSERT_EQ((int32)0x80131500, Exception(_current_information).HResult());
    ASSERT_EQ(_current_information.FilePath, Exception(_current_information).FilePath());
    ASSERT_EQ(_current_information.LineNumber, Exception(_current_information).LineNumber());
    ASSERT_FALSE(Exception(_current_information).HasInnerException);
    
    ASSERT_TRUE(is<Exception>(Exception("Value is invalid.", _current_information)));
    ASSERT_EQ((int32)0x80131500, Exception("Value is invalid.", _current_information).HResult());
    ASSERT_EQ(_current_information.FilePath, Exception("Value is invalid.", _current_information).FilePath());
    ASSERT_EQ(_current_information.LineNumber, Exception("Value is invalid.", _current_information).LineNumber());
    ASSERT_FALSE(Exception("Value is invalid.", _current_information).HasInnerException);
  }
  
  TEST(Exception, GetStackTrace) {
    try { throw Exception(CurrentInformation("ExceptionUT.cpp", 43)); } catch (const Exception& e) { EXPECT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:43")); }
    try { throw ArgumentOutOfRangeException(CurrentInformation("ExceptionUT.cpp", 44)); } catch (const Exception& e) { EXPECT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:44")); }
  }
  
  TEST(Exception, GetMessage) {
    try { throw Exception(_current_information); } catch (const Exception& e) { EXPECT_EQ( "Exception of type 'Switch::System::Exception' was thrown.", e.Message()); }
    try { throw SystemException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
    try { throw AccessViolationException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."); }
    //try { throw AggregateException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One or more errors occured."); }
    try { throw AppDomainUnloadedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access an unloaded AppDomain."); }
    try { throw ApplicationException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Error in the application."); }
    try { throw ArgumentException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Value does not fall within the expected range."); }
    try { throw ArgumentNullException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Value cannot be null."); }
    try { throw ArgumentOutOfRangeException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(),"Specified argument is out of range of valid values."); }
    try { throw ArithmeticException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Overflow or underflow in the arithmetic operation."); }
    try { throw ArrayTypeMismatchException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to access an element as a type incompatible with the array."); }
  
    try { throw BadImageFormatException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Format for the executable or library is invalid."); }
    try { throw CannotUnloadAppDomainException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to unload the AppDomain failed."); }
    try { throw ContextMarshalException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to marshal an object across a context boundary."); }
    try { throw DataMisalignedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "A datatype misalignment was detected in a load or store instruction."); }
    try { throw DivideByZeroException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to divide by zero."); }
    try { throw DllNotFoundException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Dll was not found."); }
    try { throw DuplicateWaitObjectException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Duplicate object in argument."); }
    try { throw EntryPointNotFoundException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Entry point was not found."); }
    try { throw ExecutionEngineException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Internal error in the runtime."); }
    try { throw MemberAccessException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Cannot acces member."); }
    try { throw FieldAccessException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a field that is not accessible by the caller."); }
    try { throw FormatException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items is an invalid format."); }
    try { throw IndexOutOfRangeException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Index was outside the bounds of the array."); }
    try { throw InsufficientExecutionStackException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient stack to continue executing the program safety. This can happen from having too many functions on the call stack using too much stack space."); }
    try { throw OutOfMemoryException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InsufficientMemoryException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InvalidCastException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Specified cast is not valid."); }
    try { throw InvalidOperationException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
    try { throw InvalidProgramException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The system detected an invalid program."); }
    try { throw InvalidTimeZoneException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The time zone information is not valid."); }
    try { throw MethodAccessException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces the method failed."); }
    try { throw MissingMemberException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a missing member."); }
    try { throw MissingFieldException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a non-existing field."); }
    try { throw MissingMethodException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a missing method."); }
    try { throw MulticastNotSupportedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to add multiple callbacks to a delegate that does not support multicast."); }
    try { throw NotFiniteNumberException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Number encountered was not a finite quantity."); }
    try { throw NotImplementedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The method or operation is not implemented."); }
    try { throw NotSupportedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Specified method is not supported."); }
    try { throw NullPointerException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object pointer not set to an instance of an object."); }
    try { throw NullReferenceException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object reference not set to an instance of an object."); }
    try { throw ObjectClosedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Cannot access a closed object."); }
    try { throw OperationCanceledException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The operation was canceled."); }
    try { throw OverflowException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Arithmetic operation resulted in an overflow."); }
    try { throw PlatformNotSupportedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not supported on this platform."); }
    try { throw RankException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to operate on an array with the incorrect number of dimensions."); }
    try { throw StackOverflowException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation caused a stack overflow."); }
    try { throw TimeoutException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The operation has timed out."); }
    try { throw TimeZoneNotFoundException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The time zone cannot be found."); }
    try { throw TypeAccessException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to access the type failed."); }
    //try { throw TypeInitializationException(Type::GetName(Int32()), NullReferenceException(), _current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The type initializer for '" + Type::GetName(Int32()) + "' threw an exception."); }
    try { throw TypeUnloadedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Type had been unloaded."); }
    try { throw UnauthorizedAccessException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to perform an unauthorized operation."); }
    try { throw UriFormatException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items was an invalid format."); }
    try { throw UriTemplateMatchException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
  
    try { throw KeyNotFoundException(_current_information); } catch (const Exception& e) { EXPECT_EQ("The given key was not present in the dictionnary.", e.Message()); }
  
    try { throw IOException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "I/O error occured."); }
    try { throw DirectoryNotFoundException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a path that is not on the disk."); }
    try { throw DriveNotFoundException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a drive that is not avaible."); }
    try { throw EndOfStreamException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to read past the end of the stream."); }
    try { throw FileFormatException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Input file or data stream does not conform to the expected file format specification."); }
    try { throw FileLoadException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Could not load the specified file."); }
    try { throw FileNotFoundException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Unable to find the specified file."); }
    try { throw InternalBufferOverflowException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
    try { throw InvalidDataException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Found invalid data while decoding."); }
    try { throw PathTooLongException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The specified path, file name, or both are too long. The fully ualified file name must be less than 260 caracters, and the directory name must be less than 248 caracters."); }
    try { throw PipeException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "I/O error occured."); }
  
    try { throw CookieException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items is an invalid format."); }
    try { throw HttpListenerException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The HTTP request failed."); }
    try { throw ProtocolViolationException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
    try { throw WebException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
  
    try { throw SocketException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The Socket operation failed."); }
  
    try { throw SerializationException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Serialization error."); }
  
    try { throw AbandonedMutexException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The wait completed due to an abandoned mutex."); }
    try { throw BarrierPostPhaseException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The postPhaseAction failed with an exception."); }
    try { throw LockRecursionException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Exception of type 'Switch::System::Threading::LockRecursionException' was thrown."); }
    try { throw SemaphoreFullException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Adding the specified countto the semaphore wold cause it to exceed its maximum count."); }
    try { throw SynchronizationLockException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object synchronization method was called from an unsynchronized block of code."); }
    try { throw ThreadAbortException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was aborted."); }
    try { throw ThreadInterruptedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was interrupted from a waiting state."); }
    try { throw ThreadStartException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread start failure."); }
    try { throw ThreadStateException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was in an invalid state for the operation being executed."); }
    try { throw WaitHandleCannotBeOpenedException(_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "No handle of the given name exists."); }
  }
  
  TEST(Exception, ThrowException) {
    try {
      throw Exception(_current_information);
    } catch (const Exception& e) {
      EXPECT_TRUE(is<Exception>(e));
    }
    
    try {
      throw Exception(_current_information);
    } catch (const MyFirstOwnException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const MyFirstGroupException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const Exception& /*e*/) {
      //EXPECT_EQ(e.Message(), "Exception of type 'System::Exception' was thrown.");
    }
    
    try {
      throw Exception("My First Exception", _current_information);
    } catch (const MyFirstOwnException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const MyFirstGroupException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const Exception& e) {
      EXPECT_EQ(e.Message(), "My First Exception");
    }
  }
  
  TEST(Exception, ThrowMyFirstGroupException) {
    try {
      throw MyFirstGroupException(_current_information);
    } catch (const Exception& e) {
      if (is<MyFirstGroupException>(e))
        EXPECT_EQ(e.Message(), "My First Group Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstGroupException(_current_information);
    }  catch (const MyFirstOwnException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const MyFirstGroupException& e) {
      //Console::WriteLine(e);
      EXPECT_EQ(e.Message(), "My First Group Exception");
    } catch (const Exception& /*e*/) {
      EXPECT_TRUE(false);
    }
  }
  
  TEST(Exception, ThrowMyFirstOwnException) {
    try {
      throw MyFirstOwnException(_current_information);
    } catch (const Exception& e) {
      if (is<MyFirstOwnException>(e))
        EXPECT_EQ(e.Message(), "My First Own Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstOwnException(_current_information);
    } catch (const MyFirstGroupException& e) {
      if (is<MyFirstOwnException>(e))
        EXPECT_EQ(e.Message(), "My First Own Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstOwnException(_current_information);
    } catch (const MyFirstOwnException& e) {
      EXPECT_EQ(e.Message(), "My First Own Exception");
    } catch (const MyFirstGroupException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const Exception& /*e*/) {
      EXPECT_TRUE(false);
    }
  }
  
}
