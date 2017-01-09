/// @file
/// @brief Contains Pcf::System::Threading::LockRecursionException exception.
#pragma once

#include "../SystemException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// Exception addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The exception that is thrown when the post-phase action of a Barrier fails
      class pcf_public LockRecursionException : public Exception {
      public:
        /// @brief Create a new instance of class LockRecursionException
        /// @remarks Message is set with the default message associate to the error.
        LockRecursionException() : Exception() {}
        
        /// @brief Create a new instance of class LockRecursionException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        LockRecursionException(const LockRecursionException& value) : Exception(value) {}
        
        /// @brief Create a new instance of class LockRecursionException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        /// @remarks Message is set with the default message associate to the error.
        LockRecursionException(const CurrentInformation& information) : Exception(information) {}
        
        /// @brief Create a new instance of class LockRecursionException
        /// @param message Message string associate to the error.
        LockRecursionException(const System::String& message) : Exception(message) {}
        
        /// @brief Create a new instance of class LockRecursionException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        LockRecursionException(const System::String& message, const CurrentInformation& information) : Exception(message, information) {}
        
        /// @brief Create a new instance of class LockRecursionException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        LockRecursionException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : Exception(message, innerException, information) {}
      };
    }
  }
}

using namespace Pcf;
