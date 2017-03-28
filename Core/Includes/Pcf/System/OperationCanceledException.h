/// @file
/// @brief Contains Pcf::System::OperationCanceledException exception.
#pragma once

#include "SystemException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown in a thread upon cancellation of an operation that the thread was executing.
    class pcf_public OperationCanceledException : public SystemException {
    public:
      /// @brief Create a new instance of class OperationCanceledException
      /// @remarks Message is set with the default message associate to the error.
      OperationCanceledException() : SystemException() {}
      
      /// @brief Create a new instance of class OperationCanceledException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      OperationCanceledException(const OperationCanceledException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class OperationCanceledException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      OperationCanceledException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class OperationCanceledException
      /// @param message Message string associate to the error.
      OperationCanceledException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class OperationCanceledException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      OperationCanceledException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class OperationCanceledException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      OperationCanceledException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "The operation was canceled."; }
    };
  }
}

using namespace Pcf;

