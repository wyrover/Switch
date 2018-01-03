#include <Switch/System/String.hpp>
#include <Switch/System/AccessViolationException.hpp>
#include <Switch/System/AppDomainUnloadedException.hpp>
#include <Switch/System/ArgumentException.hpp>
#include <Switch/System/ArgumentNullException.hpp>
#include <Switch/System/ArgumentOutOfRangeException.hpp>
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
#include <Switch/System/Collections/Generic/GenericException.hpp>
#include <Switch/System/IndexOutOfRangeException.hpp>
#include <Switch/System/InsufficientExecutionStackException.hpp>
#include <Switch/System/InsufficientMemoryException.hpp>
#include <Switch/System/InvalidCastException.hpp>
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
#include <Switch/System/ObjectDisposedException.hpp>
#include <Switch/System/OperationCanceledException.hpp>
#include <Switch/System/OverflowException.hpp>
#include <Switch/System/PlatformNotSupportedException.hpp>
#include <Switch/System/RankException.hpp>
#include <Switch/System/StackOverflowException.hpp>
#include <Switch/System/SystemException.hpp>
#include <Switch/System/TimeoutException.hpp>
#include <Switch/System/TimeZoneNotFoundException.hpp>
#include <Switch/System/TypeAccessException.hpp>
#include <Switch/System/TypeUnloadedException.hpp>
#include <Switch/System/UnauthorizedAccessException.hpp>
#include <Switch/System/IO/DirectoryNotFoundException.hpp>
#include <Switch/System/IO/DriveNotFoundException.hpp>
#include <Switch/System/IO/EndOfStreamException.hpp>
#include <Switch/System/IO/FileFormatException.hpp>
#include <Switch/System/IO/FileLoadException.hpp>
#include <Switch/System/IO/FileNotFoundException.hpp>
#include <Switch/System/IO/IOException.hpp>
#include <Switch/System/IO/PathTooLongException.hpp>
#include <Switch/System/Threading/AbandonedMutexException.hpp>
#include <Switch/System/Threading/LockRecursionException.hpp>
#include <Switch/System/Threading/SynchronizationLockException.hpp>
#include <Switch/System/Threading/ThreadAbortException.hpp>
#include <Switch/System/Threading/ThreadInterruptedException.hpp>
#include <Switch/System/Threading/ThreadStartException.hpp>
#include <Switch/System/Threading/ThreadStateException.hpp>
#include <Switch/System/Threading/WaitHandleCannotBeOpenedException.hpp>
#include <Switch/System/Runtime/Serialization/SerializationException.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::Serialization;
using namespace System::Threading;

namespace {
  class MyFirstGroupException : public System::Exception {
  public:
    MyFirstGroupException() : System::Exception() {}
    MyFirstGroupException(const MyFirstGroupException& value) : System::Exception(value) {}
    MyFirstGroupException(const System::Runtime::CompilerServices::Caller& information) : System::Exception(information) {} \
    MyFirstGroupException(const System::String& message) : System::Exception(message) {}
    MyFirstGroupException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : System::Exception(message, information) {}
    MyFirstGroupException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : System::Exception(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My First Group Exception"; }
  };

  class MySecondGroupException : public System::Exception {
  public:
    MySecondGroupException() : System::Exception() {}
    MySecondGroupException(const MySecondGroupException& value) : System::Exception(value) {}
    MySecondGroupException(const System::Runtime::CompilerServices::Caller& information) : System::Exception(information) {}
    MySecondGroupException(const System::String& message) : System::Exception(message) {}
    MySecondGroupException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : System::Exception(message, information) {}
    MySecondGroupException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : System::Exception(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Second Group Exception"; }
  };

  class MyFirstOwnException : public MyFirstGroupException {
  public:
    MyFirstOwnException() : MyFirstGroupException() {}
    MyFirstOwnException(const MyFirstOwnException& value) : MyFirstGroupException(value) {}
    MyFirstOwnException(const System::Runtime::CompilerServices::Caller& information) : MyFirstGroupException(information) {}
    MyFirstOwnException(const System::String& message) : MyFirstGroupException(message) {}
    MyFirstOwnException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : MyFirstGroupException(message, information) {}
    MyFirstOwnException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : MyFirstGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My First Own Exception"; }
  };

  class MySecondOwnException : public MyFirstGroupException {
  public:
    MySecondOwnException() : MyFirstGroupException() {}
    MySecondOwnException(const MySecondOwnException& value) : MyFirstGroupException(value) {}
    MySecondOwnException(const System::Runtime::CompilerServices::Caller& information) : MyFirstGroupException(information) {}
    MySecondOwnException(const System::String& message) : MyFirstGroupException(message) {}
    MySecondOwnException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : MyFirstGroupException(message, information) {}
    MySecondOwnException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : MyFirstGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Second Own Exception"; }
  };

  class MyThirdOwnException : public MySecondGroupException {
  public:
    MyThirdOwnException() : MySecondGroupException() {}
    MyThirdOwnException(const MyThirdOwnException& value) : MySecondGroupException(value) {}
    MyThirdOwnException(const System::Runtime::CompilerServices::Caller& information) : MySecondGroupException(information) {}
    MyThirdOwnException(const System::String& message) : MySecondGroupException(message) {}
    MyThirdOwnException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : MySecondGroupException(message, information) {}
    MyThirdOwnException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : MySecondGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Third Own Exception"; }
  };

  class MyFourthOwnException : public MySecondGroupException {
  public:
    MyFourthOwnException() : MySecondGroupException() {}
    MyFourthOwnException(const MyFourthOwnException& value) : MySecondGroupException(value) {}
    MyFourthOwnException(const System::Runtime::CompilerServices::Caller& information) : MySecondGroupException(information) {}
    MyFourthOwnException(const System::String& message) : MySecondGroupException(message) {}
    MyFourthOwnException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : MySecondGroupException(message, information) {}
    MyFourthOwnException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : MySecondGroupException(message, innerException, information) {}
  private:
    System::String GetDefaultMessage() const override {return "My Fourth Own Exception"; }
  };

  TEST(ExceptionTest, Constructor) {
    ASSERT_TRUE(is<Exception>(Exception()));
    ASSERT_EQ((int32)0x80131500, Exception().HResult());
    ASSERT_NE(caller_.FilePath, Exception().FilePath());
    ASSERT_NE(caller_.LineNumber, Exception().LineNumber());
    ASSERT_FALSE(Exception().HasInnerException);

    ASSERT_TRUE(is<Exception>(Exception(caller_)));
    ASSERT_EQ((int32)0x80131500, Exception(caller_).HResult());
    ASSERT_EQ(caller_.FilePath, Exception(caller_).FilePath());
    ASSERT_EQ(caller_.LineNumber, Exception(caller_).LineNumber());
    ASSERT_FALSE(Exception(caller_).HasInnerException);

    ASSERT_TRUE(is<Exception>(Exception("Value is invalid.", caller_)));
    ASSERT_EQ((int32)0x80131500, Exception("Value is invalid.", caller_).HResult());
    ASSERT_EQ(caller_.FilePath, Exception("Value is invalid.", caller_).FilePath());
    ASSERT_EQ(caller_.LineNumber, Exception("Value is invalid.", caller_).LineNumber());
    ASSERT_FALSE(Exception("Value is invalid.", caller_).HasInnerException);
  }

  TEST(ExceptionTest, GetStackTrace) {
    try { throw Exception(Caller("ExceptionUT.cpp", 43)); } catch (const Exception& e) { ASSERT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:43")); }
    try { throw ArgumentOutOfRangeException(Caller("ExceptionUT.cpp", 44)); } catch (const Exception& e) { ASSERT_TRUE(e.ToString().Contains(" in ExceptionUT.cpp:44")); }
  }

  TEST(ExceptionTest, GetMessage) {
    try { throw Exception(caller_); } catch (const Exception& e) { ASSERT_EQ("Exception of type 'Switch::System::Exception' was thrown.", e.Message()); }
    try { throw SystemException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "System error."); }
    try { throw AccessViolationException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."); }
    //try { throw AggregateException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "One or more errors occured."); }
    try { throw AppDomainUnloadedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempted to access an unloaded AppDomain."); }
    try { throw ApplicationException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Error in the application."); }
    try { throw ArgumentException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Value does not fall within the expected range."); }
    try { throw ArgumentNullException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Value cannot be null."); }
    try { throw ArgumentOutOfRangeException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Specified argument is out of range of valid values."); }
    try { throw ArithmeticException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Overflow or underflow in the arithmetic operation."); }
    try { throw ArrayTypeMismatchException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to access an element as a type incompatible with the array."); }

    try { throw BadImageFormatException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Format for the executable or library is invalid."); }
    try { throw CannotUnloadAppDomainException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to unload the AppDomain failed."); }
    try { throw ContextMarshalException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to marshal an object across a context boundary."); }
    try { throw DataMisalignedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "A datatype misalignment was detected in a load or store instruction."); }
    try { throw DivideByZeroException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to divide by zero."); }
    try { throw DllNotFoundException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Dll was not found."); }
    try { throw DuplicateWaitObjectException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Duplicate object in argument."); }
    try { throw EntryPointNotFoundException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Entry point was not found."); }
    try { throw ExecutionEngineException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Internal error in the runtime."); }
    try { throw MemberAccessException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Cannot acces member."); }
    try { throw FieldAccessException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempted to access a field that is not accessible by the caller."); }
    try { throw FormatException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "One of identified items is an invalid format."); }
    try { throw IndexOutOfRangeException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Index was outside the bounds of the array."); }
    try { throw InsufficientExecutionStackException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Insufficient stack to continue executing the program safety. This can happen from having too many functions on the call stack using too much stack space."); }
    try { throw OutOfMemoryException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InsufficientMemoryException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Insufficient memory to continue the execution of the program."); }
    try { throw InvalidCastException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Specified cast is not valid."); }
    try { throw InvalidOperationException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Operation is not valid due to the current state of the object."); }
    try { throw InvalidProgramException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The system detected an invalid program."); }
    try { throw InvalidTimeZoneException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The time zone information is not valid."); }
    try { throw MethodAccessException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to acces the method failed."); }
    try { throw MissingMemberException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to acces a missing member."); }
    try { throw MissingFieldException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to acces a non-existing field."); }
    try { throw MissingMethodException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to acces a missing method."); }
    try { throw MulticastNotSupportedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to add multiple callbacks to a delegate that does not support multicast."); }
    try { throw NotFiniteNumberException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Number encountered was not a finite quantity."); }
    try { throw NotImplementedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The method or operation is not implemented."); }
    try { throw NotSupportedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Specified method is not supported."); }
    try { throw NullPointerException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Object pointer not set to an instance of an object."); }
    try { throw NullReferenceException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Object reference not set to an instance of an object."); }
    try { throw ObjectDisposedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Cannot access a disposed object."); }
    try { throw OperationCanceledException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The operation was canceled."); }
    try { throw OverflowException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Arithmetic operation resulted in an overflow."); }
    try { throw PlatformNotSupportedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Operation is not supported on this platform."); }
    try { throw RankException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to operate on an array with the incorrect number of dimensions."); }
    try { throw StackOverflowException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Operation caused a stack overflow."); }
    try { throw TimeoutException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The operation has timed out."); }
    try { throw TimeZoneNotFoundException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The time zone cannot be found."); }
    try { throw TypeAccessException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to access the type failed."); }
    //try { throw TypeInitializationException(Type::GetName(Int32()), NullReferenceException(), caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The type initializer for '" + Type::GetName(Int32()) + "' threw an exception."); }
    try { throw TypeUnloadedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Type had been unloaded."); }
    try { throw UnauthorizedAccessException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempt to perform an unauthorized operation."); }

    try { throw KeyNotFoundException(caller_); } catch (const Exception& e) { ASSERT_EQ("The given key was not present in the dictionnary.", e.Message()); }

    try { throw IOException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "I/O error occured."); }
    try { throw DirectoryNotFoundException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempted to access a path that is not on the disk."); }
    try { throw DriveNotFoundException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempted to access a drive that is not avaible."); }
    try { throw EndOfStreamException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Attempted to read past the end of the stream."); }
    try { throw FileFormatException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Input file or data stream does not conform to the expected file format specification."); }
    try { throw FileLoadException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Could not load the specified file."); }
    try { throw FileNotFoundException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Unable to find the specified file."); }
    try { throw PathTooLongException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The specified path, file name, or both are too long. The fully ualified file name must be less than 260 caracters, and the directory name must be less than 248 caracters."); }

    try { throw SerializationException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Serialization error."); }

    try { throw AbandonedMutexException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "The wait completed due to an abandoned mutex."); }
    try { throw LockRecursionException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Exception of type 'Switch::System::Threading::LockRecursionException' was thrown."); }
    try { throw SynchronizationLockException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Object synchronization method was called from an unsynchronized block of code."); }
    try { throw ThreadAbortException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Thread was aborted."); }
    try { throw ThreadInterruptedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Thread was interrupted from a waiting state."); }
    try { throw ThreadStartException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Thread start failure."); }
    try { throw ThreadStateException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "Thread was in an invalid state for the operation being executed."); }
    try { throw WaitHandleCannotBeOpenedException(caller_); } catch (const Exception& e) { ASSERT_EQ(e.Message(), "No handle of the given name exists."); }
  }

  TEST(ExceptionTest, ThrowException) {
    try {
      throw Exception(caller_);
    } catch (const Exception& e) {
      ASSERT_TRUE(is<Exception>(e));
    }

    try {
      throw Exception(caller_);
    } catch (const MyFirstOwnException& /*e*/) {
      ASSERT_TRUE(false);
    } catch (const MyFirstGroupException& /*e*/) {
      ASSERT_TRUE(false);
    } catch (const Exception& /*e*/) {
      //ASSERT_EQ(e.Message(), "Exception of type 'System::Exception' was thrown.");
    }

    try {
      throw Exception("My First Exception", caller_);
    } catch (const MyFirstOwnException& /*e*/) {
      ASSERT_TRUE(false);
    } catch (const MyFirstGroupException& /*e*/) {
      ASSERT_TRUE(false);
    } catch (const Exception& e) {
      ASSERT_EQ(e.Message(), "My First Exception");
    }
  }

  TEST(ExceptionTest, ThrowMyFirstGroupException) {
    try {
      throw MyFirstGroupException(caller_);
    } catch (const Exception& e) {
      if (is<MyFirstGroupException>(e))
        ASSERT_EQ(e.Message(), "My First Group Exception");
      else
        ASSERT_TRUE(false);
    }

    try {
      throw MyFirstGroupException(caller_);
    }  catch (const MyFirstOwnException& /*e*/) {
      ASSERT_TRUE(false);
    } catch (const MyFirstGroupException& e) {
      //Console::WriteLine(e);
      ASSERT_EQ(e.Message(), "My First Group Exception");
    } catch (const Exception& /*e*/) {
      ASSERT_TRUE(false);
    }
  }

  TEST(ExceptionTest, ThrowMyFirstOwnException) {
    try {
      throw MyFirstOwnException(caller_);
    } catch (const Exception& e) {
      if (is<MyFirstOwnException>(e))
        ASSERT_EQ(e.Message(), "My First Own Exception");
      else
        ASSERT_TRUE(false);
    }

    try {
      throw MyFirstOwnException(caller_);
    } catch (const MyFirstGroupException& e) {
      if (is<MyFirstOwnException>(e))
        ASSERT_EQ(e.Message(), "My First Own Exception");
      else
        ASSERT_TRUE(false);
    }

    try {
      throw MyFirstOwnException(caller_);
    } catch (const MyFirstOwnException& e) {
      ASSERT_EQ(e.Message(), "My First Own Exception");
    } catch (const MyFirstGroupException& /*e*/) {
      ASSERT_TRUE(false);
    } catch (const Exception& /*e*/) {
      ASSERT_TRUE(false);
    }
  }

}
