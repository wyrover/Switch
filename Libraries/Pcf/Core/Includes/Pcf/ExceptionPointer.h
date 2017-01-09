/// @file
/// @brief Contains Pcf::ExceptionPointer class.
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
  /// This example show how to use ExceptionPointer, ExceptionPointer::CurrentExeption and Rethrow() :
  /// @include ExceptionPointer.Cpp
  class pcf_public ExceptionPointer {
  public:
    /// @cond
    ExceptionPointer() {}
    ExceptionPointer(std::nullptr_t) : exception(nullptr) {}
    ExceptionPointer(const ExceptionPointer& eptr) noexcept : exception(eptr.exception) {}
    ExceptionPointer& operator=(const ExceptionPointer& eptr) noexcept {this->exception = eptr.exception; return *this;}
    ExceptionPointer(const std::exception_ptr& eptr) noexcept : exception(eptr) {}
    ~ExceptionPointer() noexcept {}
    operator bool() const noexcept {return this->exception.operator bool();}
    bool operator!() const noexcept {return !this->operator bool();}
    bool operator==(const ExceptionPointer& eptr) const noexcept {return this->exception == eptr.exception;}
    bool operator!=(const ExceptionPointer& eptr) const noexcept {return !this->operator==(eptr);}
    /// @endcond
    
    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    bool IsNull() const {return this->operator!();}
    
    /// @brief Get a ExceptionPointer object to current exception.
    /// @return An ExceptionPointer object pointing to the currently handled exception, or some other exception if the internal process of the function would raise a new exception.
    /// @remarks If no exception is being handled, the ExceptionPointer contains a null-pointer value.
    /// @remarks ExceptionPointer is a shared smart pointer type: The pointed exception is guaranteed to remain valid for as long as at least one exception_ptr points to it, potentially extending the lifetime of the pointed exception object beyond its scope or across threads.
    static Property<ExceptionPointer, ReadOnly> CurrentException;
    
    /// @brief Create an ExceptionPointer object that points to a copy of specified Excpetion.
    /// @param excpetion exception The exception that copyied.
    /// @return ExceptionPointer The new ExceptinPointer object create
    template<class T>
    static ExceptionPointer Create(T exception) noexcept {
      try {
        throw exception;
      } catch (...) {
        return std::current_exception();
      }
    }
    
    /// @brief Create an ExceptionPointer object that points to a copy of specified Excpetion.
    /// @param excpetion exception The exception that copyied.
    /// @return ExceptionPointer The new ExceptinPointer object create
    static ExceptionPointer Create(const System::Exception& exception) noexcept {
      using namespace System;
      if (is<System::Threading::WaitHandleCannotBeOpenedException>(exception)) return ExceptionPointer::Create(as<System::Threading::WaitHandleCannotBeOpenedException>(exception));
      
      if (is<AccessViolationException>(exception)) return ExceptionPointer::Create(as<AccessViolationException>(exception));
      if (is<AppDomainUnloadedException>(exception)) return ExceptionPointer::Create(as<AppDomainUnloadedException>(exception));
      
      if (is<ArgumentNullException>(exception)) return ExceptionPointer::Create(as<ArgumentNullException>(exception));
      if (is<ArgumentOutOfRangeException>(exception)) return ExceptionPointer::Create(as<ArgumentOutOfRangeException>(exception));
      if (is<DuplicateWaitObjectException>(exception)) return ExceptionPointer::Create(as<DuplicateWaitObjectException>(exception));
      if (is<ArgumentException>(exception)) return ExceptionPointer::Create(as<ArgumentException>(exception));
      
      if (is<DivideByZeroException>(exception)) return ExceptionPointer::Create(as<DivideByZeroException>(exception));
      if (is<NotFiniteNumberException>(exception)) return ExceptionPointer::Create(as<NotFiniteNumberException>(exception));
      if (is<OverflowException>(exception)) return ExceptionPointer::Create(as<OverflowException>(exception));
      if (is<ArithmeticException>(exception)) return ExceptionPointer::Create(as<ArithmeticException>(exception));
      
      if (is<ArrayTypeMismatchException>(exception)) return ExceptionPointer::Create(as<ArrayTypeMismatchException>(exception));
      if (is<BadImageFormatException>(exception)) return ExceptionPointer::Create(as<BadImageFormatException>(exception));
      if (is<BadImageFormatException>(exception)) return ExceptionPointer::Create(as<BadImageFormatException>(exception));
      if (is<System::Collections::Generic::KeyNotFoundException>(exception)) return ExceptionPointer::Create(as<System::Collections::Generic::KeyNotFoundException>(exception));
      if (is<ContextMarshalException>(exception)) return ExceptionPointer::Create(as<ContextMarshalException>(exception));
      if (is<ExecutionEngineException>(exception)) return ExceptionPointer::Create(as<ExecutionEngineException>(exception));
      if (is<DataMisalignedException>(exception)) return ExceptionPointer::Create(as<DataMisalignedException>(exception));
      
      if (is<System::IO::FileFormatException>(exception)) return ExceptionPointer::Create(as<System::IO::FileFormatException>(exception));
      if (is<System::Net::CookieException>(exception)) return ExceptionPointer::Create(as<System::Net::CookieException>(exception));
      if (is<UriFormatException>(exception)) return ExceptionPointer::Create(as<UriFormatException>(exception));
      if (is<FormatException>(exception)) return ExceptionPointer::Create(as<FormatException>(exception));
      
      if (is<IndexOutOfRangeException>(exception)) return ExceptionPointer::Create(as<IndexOutOfRangeException>(exception));
      if (is<InsufficientExecutionStackException>(exception)) return ExceptionPointer::Create(as<InsufficientExecutionStackException>(exception));
      if (is<InvalidCastException>(exception)) return ExceptionPointer::Create(as<InvalidCastException>(exception));
      
      if (is<System::Net::ProtocolViolationException>(exception)) return ExceptionPointer::Create(as<System::Net::ProtocolViolationException>(exception));
      if (is<System::Net::WebException>(exception)) return ExceptionPointer::Create(as<System::Net::WebException>(exception));
      if (is<ObjectClosedException>(exception)) return ExceptionPointer::Create(as<ObjectClosedException>(exception));
      if (is<ObjectDisposedException>(exception)) return ExceptionPointer::Create(as<ObjectDisposedException>(exception));
      if (is<InvalidOperationException>(exception)) return ExceptionPointer::Create(as<InvalidOperationException>(exception));
      
      if (is<InvalidProgramException>(exception)) return ExceptionPointer::Create(as<InvalidProgramException>(exception));
      if (is<System::IO::IOException>(exception)) return ExceptionPointer::Create(as<System::IO::IOException>(exception));
      
      if (is<FieldAccessException>(exception)) return ExceptionPointer::Create(as<FieldAccessException>(exception));
      if (is<MethodAccessException>(exception)) return ExceptionPointer::Create(as<MethodAccessException>(exception));
      if (is<MissingFieldException>(exception)) return ExceptionPointer::Create(as<MissingFieldException>(exception));
      if (is<MissingMethodException>(exception)) return ExceptionPointer::Create(as<MissingMethodException>(exception));
      if (is<MissingMemberException>(exception)) return ExceptionPointer::Create(as<MissingMemberException>(exception));
      if (is<MemberAccessException>(exception)) return ExceptionPointer::Create(as<MemberAccessException>(exception));
      
      if (is<MulticastNotSupportedException>(exception)) return ExceptionPointer::Create(as<MulticastNotSupportedException>(exception));
      if (is<System::Net::HttpListenerException>(exception)) return ExceptionPointer::Create(as<System::Net::HttpListenerException>(exception));
      if (is<System::Net::Sockets::SocketException>(exception)) return ExceptionPointer::Create(as<System::Net::Sockets::SocketException>(exception));
      if (is<NotImplementedException>(exception)) return ExceptionPointer::Create(as<NotImplementedException>(exception));
      
      if (is<PlatformNotSupportedException>(exception)) return ExceptionPointer::Create(as<PlatformNotSupportedException>(exception));
      if (is<NotSupportedException>(exception)) return ExceptionPointer::Create(as<NotSupportedException>(exception));
      
      if (is<NullPointerException>(exception)) return ExceptionPointer::Create(as<NullPointerException>(exception));
      if (is<NullReferenceException>(exception)) return ExceptionPointer::Create(as<NullReferenceException>(exception));
      if (is<OperationCanceledException>(exception)) return ExceptionPointer::Create(as<OperationCanceledException>(exception));
      
      if (is<InsufficientMemoryException>(exception)) return ExceptionPointer::Create(as<InsufficientMemoryException>(exception));
      if (is<OutOfMemoryException>(exception)) return ExceptionPointer::Create(as<OutOfMemoryException>(exception));
      
      if (is<RankException>(exception)) return ExceptionPointer::Create(as<RankException>(exception));
      if (is<System::Runtime::Serialization::SerializationException>(exception)) return ExceptionPointer::Create(as<System::Runtime::Serialization::SerializationException>(exception));
      if (is<System::Security::HostProtectionException>(exception)) return ExceptionPointer::Create(as<System::Security::HostProtectionException>(exception));
      if (is<System::Security::SecurityException>(exception)) return ExceptionPointer::Create(as<System::Security::SecurityException>(exception));
      if (is<System::Security::VerificationException>(exception)) return ExceptionPointer::Create(as<System::Security::VerificationException>(exception));
      if (is<System::Security::XmlSyntaxException>(exception)) return ExceptionPointer::Create(as<System::Security::XmlSyntaxException>(exception));
      if (is<StackOverflowException>(exception)) return ExceptionPointer::Create(as<StackOverflowException>(exception));
      if (is<System::Threading::AbandonedMutexException>(exception)) return ExceptionPointer::Create(as<System::Threading::AbandonedMutexException>(exception));
      if (is<System::Threading::SemaphoreFullException>(exception)) return ExceptionPointer::Create(as<System::Threading::SemaphoreFullException>(exception));
      if (is<System::Threading::SynchronizationLockException>(exception)) return ExceptionPointer::Create(as<System::Threading::SynchronizationLockException>(exception));
      if (is<System::Threading::ThreadAbortException>(exception)) return ExceptionPointer::Create(as<System::Threading::ThreadAbortException>(exception));
      if (is<System::Threading::ThreadInterruptedException>(exception)) return ExceptionPointer::Create(as<System::Threading::ThreadInterruptedException>(exception));
      if (is<System::Threading::ThreadStartException>(exception)) return ExceptionPointer::Create(as<System::Threading::ThreadStartException>(exception));
      if (is<System::Threading::ThreadStateException>(exception)) return ExceptionPointer::Create(as<System::Threading::ThreadStateException>(exception));
      if (is<TimeoutException>(exception)) return ExceptionPointer::Create(as<TimeoutException>(exception));
      if (is<TimeZoneNotFoundException>(exception)) return ExceptionPointer::Create(as<TimeZoneNotFoundException>(exception));
      if (is<TypeInitializationException>(exception)) return ExceptionPointer::Create(as<TypeInitializationException>(exception));
      
      if (is<DllNotFoundException>(exception)) return ExceptionPointer::Create(as<DllNotFoundException>(exception));
      if (is<EntryPointNotFoundException>(exception)) return ExceptionPointer::Create(as<EntryPointNotFoundException>(exception));
      if (is<TypeAccessException>(exception)) return ExceptionPointer::Create(as<TypeAccessException>(exception));
      if (is<TypeLoadException>(exception)) return ExceptionPointer::Create(as<TypeLoadException>(exception));
      
      if (is<TypeUnloadedException>(exception)) return ExceptionPointer::Create(as<TypeUnloadedException>(exception));
      if (is<UnauthorizedAccessException>(exception)) return ExceptionPointer::Create(as<UnauthorizedAccessException>(exception));
      if (is<UriTemplateMatchException>(exception)) return ExceptionPointer::Create(as<UriTemplateMatchException>(exception));
      
      //if (is<AggregateException>(exception)) return ExceptionPointer::Create(as<AggregateException>(exception));
      if (is<ApplicationException>(exception)) return ExceptionPointer::Create(as<ApplicationException>(exception));
      if (is<InvalidTimeZoneException>(exception)) return ExceptionPointer::Create(as<InvalidTimeZoneException>(exception));
      if (is<SystemException>(exception)) return ExceptionPointer::Create(as<SystemException>(exception));
      if (is<System::Threading::BarrierPostPhaseException>(exception)) return ExceptionPointer::Create(as<System::Threading::BarrierPostPhaseException>(exception));
      if (is<System::Threading::LockRecursionException>(exception)) return ExceptionPointer::Create(as<System::Threading::LockRecursionException>(exception));
      
      return ExceptionPointer::Create(as<Exception>(exception));
    }
    
    /// @brief Throw the current ExceptionPointer.
    void Rethrow() const {std::rethrow_exception(this->exception);}
    
  private:
    std::exception_ptr exception;
  };
  
  /// @brief Smart pointer type that can refer to exception objects.
  using ep = ExceptionPointer;
}

using namespace Pcf;
