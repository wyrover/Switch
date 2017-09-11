/// @file
/// @brief Contains Switch::System::ApplicationException exception.
#pragma once

#include "Exception.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a non-fatal application error occurs.
    class _export ApplicationException : public Exception {
    public:
      /// @brief Create a new instance of class ApplicationException
      /// @remarks Message is set with the default message associate to the error.
      ApplicationException() : Exception() {}
      
      /// @brief Create a new instance of class ApplicationException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ApplicationException(const ApplicationException& value) : Exception(value) {}
      
      /// @brief Create a new instance of class ApplicationException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      /// @remarks Message is set with the default message associate to the error.
      ApplicationException(const CurrentInformation& information) : Exception(information) {}
      
      /// @brief Create a new instance of class ApplicationException
      /// @param message Message string associate to the error.
      ApplicationException(const System::String& message) : Exception(message) {}
      
      /// @brief Create a new instance of class ApplicationException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ApplicationException(const System::String& message, const CurrentInformation& information) : Exception(message, information) {}
      
      /// @brief Create a new instance of class ApplicationException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ApplicationException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : Exception(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Error in the application."; }
    };
  }
}

using namespace Switch;

