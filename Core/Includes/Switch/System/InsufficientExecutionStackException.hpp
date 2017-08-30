/// @file
/// @brief Contains Pcf::System::InsufficientExecutionStackException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is insufficient execution stack available to allow most methods to execute.
    class pcf_public InsufficientExecutionStackException : public SystemException {
    public:
      /// @brief Create a new instance of class InsufficientExecutionStackException
      /// @remarks Message is set with the default message associate to the error.
      InsufficientExecutionStackException() : SystemException() {}
      
      /// @brief Create a new instance of class InsufficientExecutionStackException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      InsufficientExecutionStackException(const InsufficientExecutionStackException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class InsufficientExecutionStackException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      InsufficientExecutionStackException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class InsufficientExecutionStackException
      /// @param message Message string associate to the error.
      InsufficientExecutionStackException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class InsufficientExecutionStackException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      InsufficientExecutionStackException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class InsufficientExecutionStackException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      InsufficientExecutionStackException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Insufficient stack to continue executing the program safety. This can happen from having too many functions on the call stack using too much stack space."; }
    };
  }
}

using namespace Pcf;

