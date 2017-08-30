#include <Pcf/System/AccessViolationException.hpp>
#include <Pcf/System/AppDomainUnloadedException.hpp>
#include <Pcf/System/ArrayTypeMismatchException.hpp>
#include <Pcf/System/BadImageFormatException.hpp>
#include <Pcf/System/CannotUnloadAppDomainException.hpp>
#include <Pcf/System/ContextMarshalException.hpp>
#include <Pcf/System/DataMisalignedException.hpp>
#include <Pcf/System/DivideByZeroException.hpp>
#include <Pcf/System/DllNotFoundException.hpp>
#include <Pcf/System/DuplicateWaitObjectException.hpp>
#include <Pcf/System/EntryPointNotFoundException.hpp>
#include <Pcf/System/FieldAccessException.hpp>
#include <Pcf/System/ExecutionEngineException.hpp>
#include <Pcf/System/Exception.hpp>
#include <Pcf/System/InsufficientExecutionStackException.hpp>
#include <Pcf/System/InsufficientMemoryException.hpp>
#include <Pcf/System/InvalidProgramException.hpp>
#include <Pcf/System/InvalidTimeZoneException.hpp>
#include <Pcf/System/MemberAccessException.hpp>
#include <Pcf/System/MethodAccessException.hpp>
#include <Pcf/System/MissingFieldException.hpp>
#include <Pcf/System/MissingMemberException.hpp>
#include <Pcf/System/MissingMethodException.hpp>
#include <Pcf/System/MulticastNotSupportedException.hpp>
#include <Pcf/System/NotFiniteNumberException.hpp>
#include <Pcf/System/NotImplementedException.hpp>
#include <Pcf/System/NullPointerException.hpp>
#include <Pcf/System/NullReferenceException.hpp>
#include <Pcf/System/ObjectClosedException.hpp>
#include <Pcf/System/OperationCanceledException.hpp>
#include <Pcf/System/PlatformNotSupportedException.hpp>
#include <Pcf/System/StackOverflowException.hpp>
#include <Pcf/System/SystemException.hpp>
#include <Pcf/System/TimeoutException.hpp>
#include <Pcf/System/TimeZoneNotFoundException.hpp>
#include <Pcf/System/TypeAccessException.hpp>
#include <Pcf/System/TypeUnloadedException.hpp>
#include <Pcf/System/UnauthorizedAccessException.hpp>
#include <Pcf/System/UriFormatException.hpp>
#include <Pcf/System/UriTemplateMatchException.hpp>
#include <Pcf/System/IO/DirectoryNotFoundException.hpp>
#include <Pcf/System/IO/DriveNotFoundException.hpp>
#include <Pcf/System/IO/EndOfStreamException.hpp>
#include <Pcf/System/IO/FileFormatException.hpp>
#include <Pcf/System/IO/FileLoadException.hpp>
#include <Pcf/System/IO/FileNotFoundException.hpp>
#include <Pcf/System/IO/InternalBufferOverflowException.hpp>
#include <Pcf/System/IO/InvalidDataException.hpp>
#include <Pcf/System/IO/IOException.hpp>
#include <Pcf/System/IO/PathTooLongException.hpp>
#include <Pcf/System/IO/PipeException.hpp>
#include <Pcf/System/Net/CookieException.hpp>
#include <Pcf/System/Net/HttpListenerException.hpp>
#include <Pcf/System/Net/ProtocolViolationException.hpp>
#include <Pcf/System/Net/WebException.hpp>
#include <Pcf/System/Net/Sockets/SocketException.hpp>
#include <Pcf/System/Threading/AbandonedMutexException.hpp>
#include <Pcf/System/Threading/BarrierPostPhaseException.hpp>
#include <Pcf/System/Threading/LockRecursionException.hpp>
#include <Pcf/System/Threading/SemaphoreFullException.hpp>
#include <Pcf/System/Threading/SynchronizationLockException.hpp>
#include <Pcf/System/Threading/ThreadAbortException.hpp>
#include <Pcf/System/Threading/ThreadInterruptedException.hpp>
#include <Pcf/System/Threading/ThreadStartException.hpp>
#include <Pcf/System/Threading/ThreadStateException.hpp>
#include <Pcf/System/Threading/WaitHandleCannotBeOpenedException.hpp>
#include <Pcf/System/Runtime/Serialization/SerializationException.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

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
    ASSERT_NE(pcf_current_information.FileName, Exception().File());
    ASSERT_NE(pcf_current_information.Line, Exception().Line());
    ASSERT_FALSE(Exception().HasInnerException);
    
    ASSERT_TRUE(is<Exception>(Exception(pcf_current_information)));
    ASSERT_EQ((int32)0x80131500, Exception(pcf_current_information).HResult());
    ASSERT_EQ(pcf_current_information.FileName, Exception(pcf_current_information).File());
    ASSERT_EQ(pcf_current_information.Line, Exception(pcf_current_information).Line());
    ASSERT_FALSE(Exception(pcf_current_information).HasInnerException);
    
    ASSERT_TRUE(is<Exception>(Exception("Value is invalid.", pcf_current_information)));
    ASSERT_EQ((int32)0x80131500, Exception("Value is invalid.", pcf_current_information).HResult());
    ASSERT_EQ(pcf_current_information.FileName, Exception("Value is invalid.", pcf_current_information).File());
    ASSERT_EQ(pcf_current_information.Line, Exception("Value is invalid.", pcf_current_information).Line());
    ASSERT_FALSE(Exception("Value is invalid.", pcf_current_information).HasInnerException);
  }
  
  TEST(Exception, GetStackTrace) {
    try { throw Exception(CurrentInformation("ExceptionUT.cpp", 43)); } catch (const Exception& e) { EXPECT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:43")); }
    try { throw ArgumentOutOfRangeException(CurrentInformation("ExceptionUT.cpp", 44)); } catch (const Exception& e) { EXPECT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:44")); }
  }
  
  TEST(Exception, GetMessage) {
    try { throw Exception(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ( "Exception of type 'Pcf::System::Exception' was thrown.", e.Message()); }
    try { throw SystemException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
    try { throw AccessViolationException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."); }
    //try { throw AggregateException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One or more errors occured."); }
    try { throw AppDomainUnloadedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access an unloaded AppDomain."); }
    try { throw ApplicationException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Error in the application."); }
    try { throw ArgumentException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Value does not fall within the expected range."); }
    try { throw ArgumentNullException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Value cannot be null."); }
    try { throw ArgumentOutOfRangeException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(),"Specified argument is out of range of valid values."); }
    try { throw ArithmeticException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Overflow or underflow in the arithmetic operation."); }
    try { throw ArrayTypeMismatchException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to access an element as a type incompatible with the array."); }
  
    try { throw BadImageFormatException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Format for the executable or library is invalid."); }
    try { throw CannotUnloadAppDomainException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to unload the AppDomain failed."); }
    try { throw ContextMarshalException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to marshal an object across a context boundary."); }
    try { throw DataMisalignedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "A datatype misalignment was detected in a load or store instruction."); }
    try { throw DivideByZeroException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to divide by zero."); }
    try { throw DllNotFoundException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Dll was not found."); }
    try { throw DuplicateWaitObjectException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Duplicate object in argument."); }
    try { throw EntryPointNotFoundException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Entry point was not found."); }
    try { throw ExecutionEngineException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Internal error in the runtime."); }
    try { throw MemberAccessException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Cannot acces member."); }
    try { throw FieldAccessException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a field that is not accessible by the caller."); }
    try { throw FormatException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items is an invalid format."); }
    try { throw IndexOutOfRangeException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Index was outside the bounds of the array."); }
    try { throw InsufficientExecutionStackException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient stack to continue executing the program safety. This can happen from having too many functions on the call stack using too much stack space."); }
    try { throw OutOfMemoryException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InsufficientMemoryException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InvalidCastException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Specified cast is not valid."); }
    try { throw InvalidOperationException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
    try { throw InvalidProgramException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The system detected an invalid program."); }
    try { throw InvalidTimeZoneException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The time zone information is not valid."); }
    try { throw MethodAccessException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces the method failed."); }
    try { throw MissingMemberException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a missing member."); }
    try { throw MissingFieldException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a non-existing field."); }
    try { throw MissingMethodException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to acces a missing method."); }
    try { throw MulticastNotSupportedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to add multiple callbacks to a delegate that does not support multicast."); }
    try { throw NotFiniteNumberException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Number encountered was not a finite quantity."); }
    try { throw NotImplementedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The method or operation is not implemented."); }
    try { throw NotSupportedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Specified method is not supported."); }
    try { throw NullPointerException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object pointer not set to an instance of an object."); }
    try { throw NullReferenceException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object reference not set to an instance of an object."); }
    try { throw ObjectClosedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Cannot access a closed object."); }
    try { throw OperationCanceledException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The operation was canceled."); }
    try { throw OverflowException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Arithmetic operation resulted in an overflow."); }
    try { throw PlatformNotSupportedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not supported on this platform."); }
    try { throw RankException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to operate on an array with the incorrect number of dimensions."); }
    try { throw StackOverflowException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation caused a stack overflow."); }
    try { throw TimeoutException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The operation has timed out."); }
    try { throw TimeZoneNotFoundException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The time zone cannot be found."); }
    try { throw TypeAccessException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to access the type failed."); }
    //try { throw TypeInitializationException(Type::GetName(Int32()), NullReferenceException(), pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The type initializer for '" + Type::GetName(Int32()) + "' threw an exception."); }
    try { throw TypeUnloadedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Type had been unloaded."); }
    try { throw UnauthorizedAccessException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempt to perform an unauthorized operation."); }
    try { throw UriFormatException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items was an invalid format."); }
    try { throw UriTemplateMatchException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
  
    try { throw KeyNotFoundException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ("The given key was not present in the dictionnary.", e.Message()); }
  
    try { throw IOException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "I/O error occured."); }
    try { throw DirectoryNotFoundException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a path that is not on the disk."); }
    try { throw DriveNotFoundException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to access a drive that is not avaible."); }
    try { throw EndOfStreamException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Attempted to read past the end of the stream."); }
    try { throw FileFormatException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Input file or data stream does not conform to the expected file format specification."); }
    try { throw FileLoadException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Could not load the specified file."); }
    try { throw FileNotFoundException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Unable to find the specified file."); }
    try { throw InternalBufferOverflowException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "System error."); }
    try { throw InvalidDataException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Found invalid data while decoding."); }
    try { throw PathTooLongException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The specified path, file name, or both are too long. The fully ualified file name must be less than 260 caracters, and the directory name must be less than 248 caracters."); }
    try { throw PipeException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "I/O error occured."); }
  
    try { throw CookieException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "One of identified items is an invalid format."); }
    try { throw HttpListenerException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The HTTP request failed."); }
    try { throw ProtocolViolationException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
    try { throw WebException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
  
    try { throw SocketException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The Socket operation failed."); }
  
    try { throw SerializationException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Serialization error."); }
  
    try { throw AbandonedMutexException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The wait completed due to an abandoned mutex."); }
    try { throw BarrierPostPhaseException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "The postPhaseAction failed with an exception."); }
    try { throw LockRecursionException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Exception of type 'Pcf::System::Threading::LockRecursionException' was thrown."); }
    try { throw SemaphoreFullException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Adding the specified countto the semaphore wold cause it to exceed its maximum count."); }
    try { throw SynchronizationLockException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Object synchronization method was called from an unsynchronized block of code."); }
    try { throw ThreadAbortException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was aborted."); }
    try { throw ThreadInterruptedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was interrupted from a waiting state."); }
    try { throw ThreadStartException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread start failure."); }
    try { throw ThreadStateException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "Thread was in an invalid state for the operation being executed."); }
    try { throw WaitHandleCannotBeOpenedException(pcf_current_information); } catch (const Exception& e) { EXPECT_EQ(e.Message(), "No handle of the given name exists."); }
  }
  
  TEST(Exception, ThrowException) {
    try {
      throw Exception(pcf_current_information);
    } catch (const Exception& e) {
      EXPECT_TRUE(is<Exception>(e));
    }
    
    try {
      throw Exception(pcf_current_information);
    } catch (const MyFirstOwnException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const MyFirstGroupException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const Exception& /*e*/) {
      //EXPECT_EQ(e.Message(), "Exception of type 'System::Exception' was thrown.");
    }
    
    try {
      throw Exception("My First Exception", pcf_current_information);
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
      throw MyFirstGroupException(pcf_current_information);
    } catch (const Exception& e) {
      if (is<MyFirstGroupException>(e))
        EXPECT_EQ(e.Message(), "My First Group Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstGroupException(pcf_current_information);
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
      throw MyFirstOwnException(pcf_current_information);
    } catch (const Exception& e) {
      if (is<MyFirstOwnException>(e))
        EXPECT_EQ(e.Message(), "My First Own Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstOwnException(pcf_current_information);
    } catch (const MyFirstGroupException& e) {
      if (is<MyFirstOwnException>(e))
        EXPECT_EQ(e.Message(), "My First Own Exception");
      else
        EXPECT_TRUE(false);
    }
    
    try {
      throw MyFirstOwnException(pcf_current_information);
    } catch (const MyFirstOwnException& e) {
      EXPECT_EQ(e.Message(), "My First Own Exception");
    } catch (const MyFirstGroupException& /*e*/) {
      EXPECT_TRUE(false);
    } catch (const Exception& /*e*/) {
      EXPECT_TRUE(false);
    }
  }
  
}
