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
    ASSERT_NE(sw_current_information.FileName, Exception().File());
    ASSERT_NE(sw_current_information.Line, Exception().Line());
    ASSERT_FALSE(Exception().HasInnerException);
    
    ASSERT_TRUE(is<Exception>(Exception(sw_current_information)));
    ASSERT_EQ((int32)0x80131500, Exception(sw_current_information).HResult());
    ASSERT_EQ(sw_current_information.FileName, Exception(sw_current_information).File());
    ASSERT_EQ(sw_current_information.Line, Exception(sw_current_information).Line());
    ASSERT_FALSE(Exception(sw_current_information).HasInnerException);
    
    ASSERT_TRUE(is<Exception>(Exception("Value is invalid.", sw_current_information)));
    ASSERT_EQ((int32)0x80131500, Exception("Value is invalid.", sw_current_information).HResult());
    ASSERT_EQ(sw_current_information.FileName, Exception("Value is invalid.", sw_current_information).File());
    ASSERT_EQ(sw_current_information.Line, Exception("Value is invalid.", sw_current_information).Line());
    ASSERT_FALSE(Exception("Value is invalid.", sw_current_information).HasInnerException);
  }
  
  TEST(Exception, GetStackTrace) {
    try { throw Exception(CurrentInformation("ExceptionUT.cpp", 43)); } catch (const Exception& e) { EXPECT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:43")); }
    try { throw ArgumentOutOfRangeException(CurrentInformation("ExceptionUT.cpp", 44)); } catch (const Exception& e) { EXPECT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:44")); }
  }
  
  TEST(Exception, GetMessage) {
    try { throw Exception(sw_current_information); } catch (const Exception& e) { EXPECT_EQ( "Exception of type 'Switch::System::Exception' was thrown.", e.Message()); }
    try { throw SystemException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
    try { throw AccessViolationException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."); }
    //try { throw AggregateException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One or more errors occured."); }
    try { throw AppDomainUnloadedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access an unloaded AppDomain."); }
    try { throw ApplicationException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Error in the application."); }
    try { throw ArgumentException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Value does not fall within the expected range."); }
    try { throw ArgumentNullException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Value cannot be null."); }
    try { throw ArgumentOutOfRangeException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(),"Specified argument is out of range of valid values."); }
    try { throw ArithmeticException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Overflow or underflow in the arithmetic operation."); }
    try { throw ArrayTypeMismatchException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to access an element as a type incompatible with the array."); }
  
    try { throw BadImageFormatException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Format for the executable or library is invalid."); }
    try { throw CannotUnloadAppDomainException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to unload the AppDomain failed."); }
    try { throw ContextMarshalException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to marshal an object across a context boundary."); }
    try { throw DataMisalignedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "A datatype misalignment was detected in a load or store instruction."); }
    try { throw DivideByZeroException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to divide by zero."); }
    try { throw DllNotFoundException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Dll was not found."); }
    try { throw DuplicateWaitObjectException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Duplicate object in argument."); }
    try { throw EntryPointNotFoundException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Entry point was not found."); }
    try { throw ExecutionEngineException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Internal error in the runtime."); }
    try { throw MemberAccessException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Cannot acces member."); }
    try { throw FieldAccessException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a field that is not accessible by the caller."); }
    try { throw FormatException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items is an invalid format."); }
    try { throw IndexOutOfRangeException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Index was outside the bounds of the array."); }
    try { throw InsufficientExecutionStackException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient stack to continue executing the program safety. This can happen from having too many functions on the call stack using too much stack space."); }
    try { throw OutOfMemoryException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InsufficientMemoryException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InvalidCastException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Specified cast is not valid."); }
    try { throw InvalidOperationException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
    try { throw InvalidProgramException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The system detected an invalid program."); }
    try { throw InvalidTimeZoneException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The time zone information is not valid."); }
    try { throw MethodAccessException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces the method failed."); }
    try { throw MissingMemberException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a missing member."); }
    try { throw MissingFieldException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a non-existing field."); }
    try { throw MissingMethodException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a missing method."); }
    try { throw MulticastNotSupportedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to add multiple callbacks to a delegate that does not support multicast."); }
    try { throw NotFiniteNumberException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Number encountered was not a finite quantity."); }
    try { throw NotImplementedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The method or operation is not implemented."); }
    try { throw NotSupportedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Specified method is not supported."); }
    try { throw NullPointerException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object pointer not set to an instance of an object."); }
    try { throw NullReferenceException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object reference not set to an instance of an object."); }
    try { throw ObjectClosedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Cannot access a closed object."); }
    try { throw OperationCanceledException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The operation was canceled."); }
    try { throw OverflowException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Arithmetic operation resulted in an overflow."); }
    try { throw PlatformNotSupportedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not supported on this platform."); }
    try { throw RankException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to operate on an array with the incorrect number of dimensions."); }
    try { throw StackOverflowException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation caused a stack overflow."); }
    try { throw TimeoutException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The operation has timed out."); }
    try { throw TimeZoneNotFoundException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The time zone cannot be found."); }
    try { throw TypeAccessException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to access the type failed."); }
    //try { throw TypeInitializationException(Type::GetName(Int32()), NullReferenceException(), sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The type initializer for '" + Type::GetName(Int32()) + "' threw an exception."); }
    try { throw TypeUnloadedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Type had been unloaded."); }
    try { throw UnauthorizedAccessException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to perform an unauthorized operation."); }
    try { throw UriFormatException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items was an invalid format."); }
    try { throw UriTemplateMatchException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
  
    try { throw KeyNotFoundException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ("The given key was not present in the dictionnary.", e.Message()); }
  
    try { throw IOException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "I/O error occured."); }
    try { throw DirectoryNotFoundException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a path that is not on the disk."); }
    try { throw DriveNotFoundException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a drive that is not avaible."); }
    try { throw EndOfStreamException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to read past the end of the stream."); }
    try { throw FileFormatException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Input file or data stream does not conform to the expected file format specification."); }
    try { throw FileLoadException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Could not load the specified file."); }
    try { throw FileNotFoundException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Unable to find the specified file."); }
    try { throw InternalBufferOverflowException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
    try { throw InvalidDataException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Found invalid data while decoding."); }
    try { throw PathTooLongException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The specified path, file name, or both are too long. The fully ualified file name must be less than 260 caracters, and the directory name must be less than 248 caracters."); }
    try { throw PipeException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "I/O error occured."); }
  
    try { throw CookieException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items is an invalid format."); }
    try { throw HttpListenerException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The HTTP request failed."); }
    try { throw ProtocolViolationException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
    try { throw WebException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
  
    try { throw SocketException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The Socket operation failed."); }
  
    try { throw SerializationException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Serialization error."); }
  
    try { throw AbandonedMutexException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The wait completed due to an abandoned mutex."); }
    try { throw BarrierPostPhaseException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The postPhaseAction failed with an exception."); }
    try { throw LockRecursionException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Exception of type 'Switch::System::Threading::LockRecursionException' was thrown."); }
    try { throw SemaphoreFullException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Adding the specified countto the semaphore wold cause it to exceed its maximum count."); }
    try { throw SynchronizationLockException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object synchronization method was called from an unsynchronized block of code."); }
    try { throw ThreadAbortException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was aborted."); }
    try { throw ThreadInterruptedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was interrupted from a waiting state."); }
    try { throw ThreadStartException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread start failure."); }
    try { throw ThreadStateException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was in an invalid state for the operation being executed."); }
    try { throw WaitHandleCannotBeOpenedException(sw_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "No handle of the given name exists."); }
  }
  
  TEST(Exception, ThrowException) {
    try {
      throw Exception(sw_current_information);
    } catch (const Exception& e) {
      EXPECT_TRUE(is<Exception>(e));
    }
    
    try {
      throw Exception(sw_current_information);
    } catch (const MyFirstOwnException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const MyFirstGroupException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const Exception& /*e*/) {
      //EXPECT_EQ(e.Message(), "Exception of type 'System::Exception' was thrown.");
    }
    
    try {
      throw Exception("My First Exception", sw_current_information);
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
      throw MyFirstGroupException(sw_current_information);
    } catch (const Exception& e) {
      if (is<MyFirstGroupException>(e))
        EXPECT_EQ(e.Message(), "My First Group Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstGroupException(sw_current_information);
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
      throw MyFirstOwnException(sw_current_information);
    } catch (const Exception& e) {
      if (is<MyFirstOwnException>(e))
        EXPECT_EQ(e.Message(), "My First Own Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstOwnException(sw_current_information);
    } catch (const MyFirstGroupException& e) {
      if (is<MyFirstOwnException>(e))
        EXPECT_EQ(e.Message(), "My First Own Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstOwnException(sw_current_information);
    } catch (const MyFirstOwnException& e) {
      EXPECT_EQ(e.Message(), "My First Own Exception");
    } catch (const MyFirstGroupException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const Exception& /*e*/) {
      EXPECT_TRUE(false);
    }
  }
  
}
