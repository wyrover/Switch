/// @file
/// @brief Contains Switch::System::ArgumentException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when one of the arguments provided to a method is not valid.
    /// @par Examples
    /// The following example demonstrates how to throw and catch an ArgumentException.
    /// @include ArgumentException.cpp
    class pcf_public ArgumentException : public SystemException {
    public:
      /// @brief Create a new instance of class ArgumentException
      /// @remarks Message is set with the default message associate to the error.
      ArgumentException() : SystemException() {}
      
      /// @brief Create a new instance of class ArgumentException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ArgumentException(const ArgumentException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class ArgumentException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      ArgumentException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class ArgumentException
      /// @param message Message string associate to the error.
      ArgumentException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class ArgumentException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      ArgumentException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class ArgumentException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      ArgumentException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Value does not fall within the expected range."; }
    };
  }
}

using namespace Switch;

