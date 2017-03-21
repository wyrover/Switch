/// @file
/// @brief Contains Pcf::System::AggregateException exception.
#pragma once

#include "../ExceptionPointer.h"
#include "Environment.h"
#include "Exception.h"
#include "Collections/Generic/List.h"
#include "AccessViolationException.h"
#include "AppDomainUnloadedException.h"
#include "ArgumentNullException.h"
#include "ArrayTypeMismatchException.h"
#include "BadImageFormatException.h"
#include "CannotUnloadAppDomainException.h"
#include "ContextMarshalException.h"
#include "DataMisalignedException.h"
#include "DivideByZeroException.h"
#include "DllNotFoundException.h"
#include "DuplicateWaitObjectException.h"
#include "EntryPointNotFoundException.h"
#include "ExecutionEngineException.h"
#include "Exception.h"
#include "FieldAccessException.h"
#include "InsufficientExecutionStackException.h"
#include "InsufficientMemoryException.h"
#include "InvalidProgramException.h"
#include "InvalidTimeZoneException.h"
#include "MemberAccessException.h"
#include "MethodAccessException.h"
#include "MissingFieldException.h"
#include "MissingMemberException.h"
#include "MissingMethodException.h"
#include "MulticastNotSupportedException.h"
#include "NotFiniteNumberException.h"
#include "NotImplementedException.h"
#include "NullPointerException.h"
#include "NullReferenceException.h"
#include "ObjectClosedException.h"
#include "ObjectDisposedException.h"
#include "OperationCanceledException.h"
#include "PlatformNotSupportedException.h"
#include "StackOverflowException.h"
#include "SystemException.h"
#include "TimeoutException.h"
#include "TimeZoneNotFoundException.h"
#include "TypeAccessException.h"
#include "TypeInitializationException.h"
#include "TypeUnloadedException.h"
#include "UnauthorizedAccessException.h"
#include "UriFormatException.h"
#include "UriTemplateMatchException.h"
#include "IO/DirectoryNotFoundException.h"
#include "IO/DriveNotFoundException.h"
#include "IO/EndOfStreamException.h"
#include "IO/FileFormatException.h"
#include "IO/FileLoadException.h"
#include "IO/FileNotFoundException.h"
#include "IO/InternalBufferOverflowException.h"
#include "IO/InvalidDataException.h"
#include "IO/IOException.h"
#include "IO/PathTooLongException.h"
#include "IO/PipeException.h"
#include "Net/CookieException.h"
#include "Net/HttpListenerException.h"
#include "Net/ProtocolViolationException.h"
#include "Net/WebException.h"
#include "Net/Sockets/SocketException.h"
#include "Security/HostProtectionException.h"
#include "Security/SecurityException.h"
#include "Security/VerificationException.h"
#include "Security/XmlSyntaxException.h"
#include "Threading/AbandonedMutexException.h"
#include "Threading/BarrierPostPhaseException.h"
#include "Threading/LockRecursionException.h"
#include "Threading/SemaphoreFullException.h"
#include "Threading/SynchronizationLockException.h"
#include "Threading/ThreadAbortException.h"
#include "Threading/ThreadInterruptedException.h"
#include "Threading/ThreadStartException.h"
#include "Threading/ThreadStateException.h"
#include "Threading/WaitHandleCannotBeOpenedException.h"
#include "Runtime/Serialization/SerializationException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents one or more errors that occur during application execution.
    /// @remarks AggregateException is used to consolidate multiple failures into a single, throwable exception object.
    /// @par Examples
    /// The following example catches the AggregateException exception and calls the Handle method to handle each exception it contains. Compiling and running the example with the first task1 variable should result in an AggregateException object that contains an UnauthorizedAccessException exception. Commenting out that line, uncommenting the second task1 variable, and compiling and running the example produces an AggregateException object that contains an IndexOutOfRangeException exception.
    /// @include AggregateException.cpp
    class pcf_public AggregateException : public Exception {
    public:
      /// @brief Gets a read-only collection of the Exception instances that caused the current exception.
      /// @return Returns a read-only collection of the Exception instances that caused the current exception.
      Property<const Array<ExceptionPointer>&, ReadOnly> InnerExceptions {
        pcf_get->const Array<ExceptionPointer>& {return this->innerExceptions;}
      };
 
      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const Array<ExceptionPointer>& innerExceptions) : innerExceptions(innerExceptions) {}
      
      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const Exception& innerException) {
        this->innerExceptions = Array<ExceptionPointer>(1);
        this->innerExceptions[0] = ExceptionPointer::Create(innerException);
      }
      
      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const Array<Reference<Exception>>& innerExceptions) {
        this->innerExceptions = Array<ExceptionPointer>(innerExceptions.Count);
        for (int index= 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = ExceptionPointer::Create(innerExceptions[index]());
      }
      
      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      AggregateException(const Array<ExceptionPointer>& innerExceptions, const CurrentInformation& information) : Exception(information), innerExceptions(innerExceptions) {}

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      AggregateException(const Array<Reference<Exception>>& innerExceptions, const CurrentInformation& information) : Exception(information) {
        this->innerExceptions = Array<ExceptionPointer>(innerExceptions.Count);
        for (int index= 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = ExceptionPointer::Create(innerExceptions[index]());
      }

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const System::Collections::Generic::IEnumerable<ExceptionPointer>& innerExceptions) : innerExceptions(innerExceptions) {}
      
      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      AggregateException(const System::Collections::Generic::IEnumerable<ExceptionPointer>& innerExceptions, const CurrentInformation& information) : Exception(information), innerExceptions(innerExceptions) {}
      
      /// @brief Create a new instance of class AggregateException
      /// @remarks Message is set with the default message associate to the error.
      AggregateException() : Exception() {}
      
      /// @brief Create a new instance of class AggregateException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      AggregateException(const AggregateException& value) : Exception(value), innerExceptions(value.innerExceptions) {}
      
      /// @brief Create a new instance of class AggregateException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      AggregateException(const CurrentInformation& information) : Exception(information) {}
      
      /// @brief Create a new instance of class AggregateException
      /// @param message Message string associate to the error.
      AggregateException(const System::String& message) : Exception(message) {}
      
      /// @brief Create a new instance of class AggregateException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      AggregateException(const System::String& message, const CurrentInformation& information) : Exception(message, information) {}
      
      /// @brief Create a new instance of class AggregateException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      AggregateException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : Exception(message, information) {
        this->innerExceptions = Array<ExceptionPointer>(1);
        this->innerExceptions[0] = ExceptionPointer::Create(innerException);
      }
      
      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const System::String& message, const Array<ExceptionPointer>& innerExceptions) : innerExceptions(innerExceptions) {}
      
      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const System::String& message, const Array<Reference<Exception>>& innerExceptions) {
        this->innerExceptions = Array<ExceptionPointer>(innerExceptions.Count);
        for (int index= 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = ExceptionPointer::Create(innerExceptions[index]());
      }
      
      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      AggregateException(const System::String& message, const Array<ExceptionPointer>& innerExceptions, const CurrentInformation& information) : Exception(message, information), innerExceptions(innerExceptions) {}
      
      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      AggregateException(const System::String& message, const Array<Reference<Exception>>& innerExceptions, const CurrentInformation& information) : Exception(message, information) {
        this->innerExceptions = Array<ExceptionPointer>(innerExceptions.Count);
        for (int index= 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = ExceptionPointer::Create(innerExceptions[index]());
      }
      
      /// @cond
      ~AggregateException() noexcept {}
      /// @endcond
      
      /// @brief Invokes a handler on each Exception contained by this AggregateException.
      /// @param predicate The predicate to execute for each exception. The predicate accepts as an argument the Exception to be processed and returns a Boolean to indicate whether the exception was handled.
      /// @remarks Each invocation of the predicate returns true or false to indicate whether the Exception was handled. After all invocations, if any exceptions went unhandled, all unhandled exceptions will be put into a new AggregateException which will be thrown. Otherwise, the Handle method simply returns. If any invocations of the predicate throws an exception, it will halt the processing of any more exceptions and immediately propagate the thrown exception as-is.
      void Handle(const Func<const Exception&, bool>& predicate) const {
        System::Collections::Generic::List<ExceptionPointer> notHandledExceptions;
        for (int32 index = 0; index < this->innerExceptions.Count; ++index) {
          try {
            this->innerExceptions[index].Rethrow();
          } catch(const Exception& innerException) {
            if (!predicate(innerException))
              notHandledExceptions.Add(this->innerExceptions[index]);
          }
        }
        
        if (notHandledExceptions.Count != 0) {
          throw AggregateException(notHandledExceptions, pcf_current_information);
        }
      }
      
      String ToString() const noexcept override {
        string result = this->Exception::ToString();
        result += string::Format("   --- End of inner exception stack trace ---{0}", Environment::NewLine);
        for (int32 index = 0; index < this->innerExceptions.Count; index++) {
          try {
            this->innerExceptions[index].Rethrow();
          } catch(const Exception& innerException) {
            result += string::Format("---> (Inner Exception {0}) {1}", index, innerException.ToString());
          }
        }
        return result;
      }

    private:
      String GetDefaultMessage() const override {return "One or more errors occured."; }
      Array<ExceptionPointer> innerExceptions;
    };
  }
}

using namespace Pcf;

