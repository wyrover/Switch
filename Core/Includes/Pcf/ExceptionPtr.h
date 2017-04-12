/// @file
/// @brief Contains Pcf::ExceptionPtr class.
#pragma once

#include <exception>
#include "Property.h"
#include "System/Allocator.h"
#include "System/Exception.h"
#include "System/Collections/Generic/List.h"
#include "System/AccessViolationException.h"
//#include "System/AggregateException.h"
#include "System/AppDomainUnloadedException.h"
#include "System/ArgumentNullException.h"
#include "System/ArrayTypeMismatchException.h"
#include "System/BadImageFormatException.h"
#include "System/CannotUnloadAppDomainException.h"
#include "System/ContextMarshalException.h"
#include "System/DataMisalignedException.h"
#include "System/DivideByZeroException.h"
#include "System/DllNotFoundException.h"
#include "System/DuplicateWaitObjectException.h"
#include "System/EntryPointNotFoundException.h"
#include "System/ExecutionEngineException.h"
#include "System/Exception.h"
#include "System/FieldAccessException.h"
#include "System/InsufficientExecutionStackException.h"
#include "System/InsufficientMemoryException.h"
#include "System/InvalidProgramException.h"
#include "System/InvalidTimeZoneException.h"
#include "System/MemberAccessException.h"
#include "System/MethodAccessException.h"
#include "System/MissingFieldException.h"
#include "System/MissingMemberException.h"
#include "System/MissingMethodException.h"
#include "System/MulticastNotSupportedException.h"
#include "System/NotFiniteNumberException.h"
#include "System/NotImplementedException.h"
#include "System/NullPointerException.h"
#include "System/NullReferenceException.h"
#include "System/ObjectClosedException.h"
#include "System/ObjectDisposedException.h"
#include "System/OperationCanceledException.h"
#include "System/PlatformNotSupportedException.h"
#include "System/StackOverflowException.h"
#include "System/SystemException.h"
#include "System/TimeoutException.h"
#include "System/TimeZoneNotFoundException.h"
#include "System/TypeAccessException.h"
#include "System/TypeInitializationException.h"
#include "System/TypeUnloadedException.h"
#include "System/UnauthorizedAccessException.h"
#include "System/UriFormatException.h"
#include "System/UriTemplateMatchException.h"
#include "System/IO/DirectoryNotFoundException.h"
#include "System/IO/DriveNotFoundException.h"
#include "System/IO/EndOfStreamException.h"
#include "System/IO/FileFormatException.h"
#include "System/IO/FileLoadException.h"
#include "System/IO/FileNotFoundException.h"
#include "System/IO/InternalBufferOverflowException.h"
#include "System/IO/InvalidDataException.h"
#include "System/IO/IOException.h"
#include "System/IO/PathTooLongException.h"
#include "System/IO/PipeException.h"
#include "System/Net/CookieException.h"
#include "System/Net/HttpListenerException.h"
#include "System/Net/ProtocolViolationException.h"
#include "System/Net/WebException.h"
#include "System/Net/Sockets/SocketException.h"
#include "System/Security/HostProtectionException.h"
#include "System/Security/SecurityException.h"
#include "System/Security/VerificationException.h"
#include "System/Security/XmlSyntaxException.h"
#include "System/Threading/AbandonedMutexException.h"
#include "System/Threading/BarrierPostPhaseException.h"
#include "System/Threading/LockRecursionException.h"
#include "System/Threading/SemaphoreFullException.h"
#include "System/Threading/SynchronizationLockException.h"
#include "System/Threading/ThreadAbortException.h"
#include "System/Threading/ThreadInterruptedException.h"
#include "System/Threading/ThreadStartException.h"
#include "System/Threading/ThreadStateException.h"
#include "System/Threading/WaitHandleCannotBeOpenedException.h"
#include "System/Runtime/Serialization/SerializationException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief Smart pointer type that can refer to exception objects.
  /// @remarks It is a shared pointer-like type: The pointed exception is guaranteed to remain valid for as long as at least one exception_ptr points to it, potentially extending its lifetime beyond the scope of a catch statement or across threads.
  /// @remarks Different libraries may implement this type differently, but it shall at least support the following operations without throwing:
  /// * Being default-constructed (acquiring a null-pointer value).
  /// * Being copied, including being copied a null-pointer value (or null).
  /// * Being compared against another exception_ptr object (or null) using either operator== or operator!=, where two null-pointers are always considered equivalent, and two non-null pointers are considered equivalent only if they refer to the same exception object.
  /// * Being contextually convertible to bool, as false if having null-pointer value, and as true otherwise.
  /// * Being swapped, and being destructed.
  /// @remarks The type is also required to not be implicitly convertible to an arithmetic, enumeration, or pointer type.
  /// @remarks Performing any other operation on the object (such as dereferencing it), if at all supported by the library implementation, causes undefined behavior.
  /// @par Examples
  /// This example show how to use ExceptionPtr, ExceptionPtr::CurrentExeption and Rethrow() :
  /// @include ExceptionPtr.Cpp
  class pcf_public ExceptionPtr {
  public:
    /// @cond
    ExceptionPtr() {}
    ExceptionPtr(std::nullptr_t) : exception(nullptr) {}
    ExceptionPtr(const ExceptionPtr& eptr) : exception(eptr.exception) {}
    ExceptionPtr& operator=(const ExceptionPtr& eptr) {this->exception = eptr.exception; return *this;}
    ExceptionPtr(const std::exception_ptr& eptr) : exception(eptr) {}
    ~ExceptionPtr() {}
    operator bool() const {return this->exception.operator bool();}
    bool operator!() const {return !this->operator bool();}
    bool operator==(const ExceptionPtr& eptr) const {return this->exception == eptr.exception;}
    bool operator!=(const ExceptionPtr& eptr) const {return !this->operator==(eptr);}
    /// @endcond
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    bool IsNull() const {return this->operator!();}
    
    /// @brief Get a ExceptionPtr object to current exception.
    /// @return An ExceptionPtr object pointing to the currently handled exception, or some other exception if the internal process of the function would raise a new exception.
    /// @remarks If no exception is being handled, the ExceptionPtr contains a null-pointer value.
    /// @remarks ExceptionPtr is a shared smart pointer type: The pointed exception is guaranteed to remain valid for as long as at least one exception_ptr points to it, potentially extending the lifetime of the pointed exception object beyond its scope or across threads.
    static Property<ExceptionPtr, ReadOnly> CurrentException;
    
    /// @brief Create an ExceptionPtr object that points to a copy of specified Excpetion.
    /// @param excpetion exception The exception that copyied.
    /// @return ExceptionPtr The new ExceptinPointer object create
    template<class T>
    static ExceptionPtr Create(T exception) {
      try {
        throw exception;
      } catch (...) {
        return std::current_exception();
      }
    }
    
    /// @brief Create an ExceptionPtr object that points to a copy of specified Excpetion.
    /// @param excpetion exception The exception that copyied.
    /// @return ExceptionPtr The new ExceptinPointer object create
    static ExceptionPtr Create(const System::Exception& exception) {
      using namespace System;
      if (is<System::Threading::WaitHandleCannotBeOpenedException>(exception)) return ExceptionPtr::Create(as<System::Threading::WaitHandleCannotBeOpenedException>(exception));
      
      if (is<AccessViolationException>(exception)) return ExceptionPtr::Create(as<AccessViolationException>(exception));
      if (is<AppDomainUnloadedException>(exception)) return ExceptionPtr::Create(as<AppDomainUnloadedException>(exception));
      
      if (is<ArgumentNullException>(exception)) return ExceptionPtr::Create(as<ArgumentNullException>(exception));
      if (is<ArgumentOutOfRangeException>(exception)) return ExceptionPtr::Create(as<ArgumentOutOfRangeException>(exception));
      if (is<DuplicateWaitObjectException>(exception)) return ExceptionPtr::Create(as<DuplicateWaitObjectException>(exception));
      if (is<ArgumentException>(exception)) return ExceptionPtr::Create(as<ArgumentException>(exception));
      
      if (is<DivideByZeroException>(exception)) return ExceptionPtr::Create(as<DivideByZeroException>(exception));
      if (is<NotFiniteNumberException>(exception)) return ExceptionPtr::Create(as<NotFiniteNumberException>(exception));
      if (is<OverflowException>(exception)) return ExceptionPtr::Create(as<OverflowException>(exception));
      if (is<ArithmeticException>(exception)) return ExceptionPtr::Create(as<ArithmeticException>(exception));
      
      if (is<ArrayTypeMismatchException>(exception)) return ExceptionPtr::Create(as<ArrayTypeMismatchException>(exception));
      if (is<BadImageFormatException>(exception)) return ExceptionPtr::Create(as<BadImageFormatException>(exception));
      if (is<BadImageFormatException>(exception)) return ExceptionPtr::Create(as<BadImageFormatException>(exception));
      if (is<System::Collections::Generic::KeyNotFoundException>(exception)) return ExceptionPtr::Create(as<System::Collections::Generic::KeyNotFoundException>(exception));
      if (is<ContextMarshalException>(exception)) return ExceptionPtr::Create(as<ContextMarshalException>(exception));
      if (is<ExecutionEngineException>(exception)) return ExceptionPtr::Create(as<ExecutionEngineException>(exception));
      if (is<DataMisalignedException>(exception)) return ExceptionPtr::Create(as<DataMisalignedException>(exception));
      
      if (is<System::IO::FileFormatException>(exception)) return ExceptionPtr::Create(as<System::IO::FileFormatException>(exception));
      if (is<System::Net::CookieException>(exception)) return ExceptionPtr::Create(as<System::Net::CookieException>(exception));
      if (is<UriFormatException>(exception)) return ExceptionPtr::Create(as<UriFormatException>(exception));
      if (is<FormatException>(exception)) return ExceptionPtr::Create(as<FormatException>(exception));
      
      if (is<IndexOutOfRangeException>(exception)) return ExceptionPtr::Create(as<IndexOutOfRangeException>(exception));
      if (is<InsufficientExecutionStackException>(exception)) return ExceptionPtr::Create(as<InsufficientExecutionStackException>(exception));
      if (is<InvalidCastException>(exception)) return ExceptionPtr::Create(as<InvalidCastException>(exception));
      
      if (is<System::Net::ProtocolViolationException>(exception)) return ExceptionPtr::Create(as<System::Net::ProtocolViolationException>(exception));
      if (is<System::Net::WebException>(exception)) return ExceptionPtr::Create(as<System::Net::WebException>(exception));
      if (is<ObjectClosedException>(exception)) return ExceptionPtr::Create(as<ObjectClosedException>(exception));
      if (is<ObjectDisposedException>(exception)) return ExceptionPtr::Create(as<ObjectDisposedException>(exception));
      if (is<InvalidOperationException>(exception)) return ExceptionPtr::Create(as<InvalidOperationException>(exception));
      
      if (is<InvalidProgramException>(exception)) return ExceptionPtr::Create(as<InvalidProgramException>(exception));
      if (is<System::IO::IOException>(exception)) return ExceptionPtr::Create(as<System::IO::IOException>(exception));
      
      if (is<FieldAccessException>(exception)) return ExceptionPtr::Create(as<FieldAccessException>(exception));
      if (is<MethodAccessException>(exception)) return ExceptionPtr::Create(as<MethodAccessException>(exception));
      if (is<MissingFieldException>(exception)) return ExceptionPtr::Create(as<MissingFieldException>(exception));
      if (is<MissingMethodException>(exception)) return ExceptionPtr::Create(as<MissingMethodException>(exception));
      if (is<MissingMemberException>(exception)) return ExceptionPtr::Create(as<MissingMemberException>(exception));
      if (is<MemberAccessException>(exception)) return ExceptionPtr::Create(as<MemberAccessException>(exception));
      
      if (is<MulticastNotSupportedException>(exception)) return ExceptionPtr::Create(as<MulticastNotSupportedException>(exception));
      if (is<System::Net::HttpListenerException>(exception)) return ExceptionPtr::Create(as<System::Net::HttpListenerException>(exception));
      if (is<System::Net::Sockets::SocketException>(exception)) return ExceptionPtr::Create(as<System::Net::Sockets::SocketException>(exception));
      if (is<NotImplementedException>(exception)) return ExceptionPtr::Create(as<NotImplementedException>(exception));
      
      if (is<PlatformNotSupportedException>(exception)) return ExceptionPtr::Create(as<PlatformNotSupportedException>(exception));
      if (is<NotSupportedException>(exception)) return ExceptionPtr::Create(as<NotSupportedException>(exception));
      
      if (is<NullPointerException>(exception)) return ExceptionPtr::Create(as<NullPointerException>(exception));
      if (is<NullReferenceException>(exception)) return ExceptionPtr::Create(as<NullReferenceException>(exception));
      if (is<OperationCanceledException>(exception)) return ExceptionPtr::Create(as<OperationCanceledException>(exception));
      
      if (is<InsufficientMemoryException>(exception)) return ExceptionPtr::Create(as<InsufficientMemoryException>(exception));
      if (is<OutOfMemoryException>(exception)) return ExceptionPtr::Create(as<OutOfMemoryException>(exception));
      
      if (is<RankException>(exception)) return ExceptionPtr::Create(as<RankException>(exception));
      if (is<System::Runtime::Serialization::SerializationException>(exception)) return ExceptionPtr::Create(as<System::Runtime::Serialization::SerializationException>(exception));
      if (is<System::Security::HostProtectionException>(exception)) return ExceptionPtr::Create(as<System::Security::HostProtectionException>(exception));
      if (is<System::Security::SecurityException>(exception)) return ExceptionPtr::Create(as<System::Security::SecurityException>(exception));
      if (is<System::Security::VerificationException>(exception)) return ExceptionPtr::Create(as<System::Security::VerificationException>(exception));
      if (is<System::Security::XmlSyntaxException>(exception)) return ExceptionPtr::Create(as<System::Security::XmlSyntaxException>(exception));
      if (is<StackOverflowException>(exception)) return ExceptionPtr::Create(as<StackOverflowException>(exception));
      if (is<System::Threading::AbandonedMutexException>(exception)) return ExceptionPtr::Create(as<System::Threading::AbandonedMutexException>(exception));
      if (is<System::Threading::SemaphoreFullException>(exception)) return ExceptionPtr::Create(as<System::Threading::SemaphoreFullException>(exception));
      if (is<System::Threading::SynchronizationLockException>(exception)) return ExceptionPtr::Create(as<System::Threading::SynchronizationLockException>(exception));
      if (is<System::Threading::ThreadAbortException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadAbortException>(exception));
      if (is<System::Threading::ThreadInterruptedException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadInterruptedException>(exception));
      if (is<System::Threading::ThreadStartException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadStartException>(exception));
      if (is<System::Threading::ThreadStateException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadStateException>(exception));
      if (is<TimeoutException>(exception)) return ExceptionPtr::Create(as<TimeoutException>(exception));
      if (is<TimeZoneNotFoundException>(exception)) return ExceptionPtr::Create(as<TimeZoneNotFoundException>(exception));
      if (is<TypeInitializationException>(exception)) return ExceptionPtr::Create(as<TypeInitializationException>(exception));
      
      if (is<DllNotFoundException>(exception)) return ExceptionPtr::Create(as<DllNotFoundException>(exception));
      if (is<EntryPointNotFoundException>(exception)) return ExceptionPtr::Create(as<EntryPointNotFoundException>(exception));
      if (is<TypeAccessException>(exception)) return ExceptionPtr::Create(as<TypeAccessException>(exception));
      if (is<TypeLoadException>(exception)) return ExceptionPtr::Create(as<TypeLoadException>(exception));
      
      if (is<TypeUnloadedException>(exception)) return ExceptionPtr::Create(as<TypeUnloadedException>(exception));
      if (is<UnauthorizedAccessException>(exception)) return ExceptionPtr::Create(as<UnauthorizedAccessException>(exception));
      if (is<UriTemplateMatchException>(exception)) return ExceptionPtr::Create(as<UriTemplateMatchException>(exception));
      
      //if (is<AggregateException>(exception)) return ExceptionPtr::Create(as<AggregateException>(exception));
      if (is<ApplicationException>(exception)) return ExceptionPtr::Create(as<ApplicationException>(exception));
      if (is<InvalidTimeZoneException>(exception)) return ExceptionPtr::Create(as<InvalidTimeZoneException>(exception));
      if (is<SystemException>(exception)) return ExceptionPtr::Create(as<SystemException>(exception));
      if (is<System::Threading::BarrierPostPhaseException>(exception)) return ExceptionPtr::Create(as<System::Threading::BarrierPostPhaseException>(exception));
      if (is<System::Threading::LockRecursionException>(exception)) return ExceptionPtr::Create(as<System::Threading::LockRecursionException>(exception));
      
      return ExceptionPtr::Create(as<Exception>(exception));
    }
    
    /// @brief Throw the current ExceptionPtr.
    /// @remarks If is null, it throws nothing.
    void Rethrow() const {
      if (this->exception)
        std::rethrow_exception(this->exception);
    }
    
  private:
    std::exception_ptr exception;
  };
  
  /// @brief Smart pointer type that can refer to exception objects.
  using excptr = ExceptionPtr;
}

using namespace Pcf;
