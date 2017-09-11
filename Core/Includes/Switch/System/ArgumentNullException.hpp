/// @file
/// @brief Contains Switch::System::ArgumentNullException exception.
#pragma once

#include "ArgumentException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a null reference is passed to a method that does not accept it as a valid argument.
    class _export ArgumentNullException : public ArgumentException {
    public:
      /// @brief Create a new instance of class ArgumentNullException
      /// @remarks Message is set with the default message associate to the error.
      ArgumentNullException() : ArgumentException() {}
      
      /// @brief Create a new instance of class ArgumentNullException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ArgumentNullException(const ArgumentNullException& value) : ArgumentException(value) {}
      
      /// @brief Create a new instance of class ArgumentNullException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      /// @remarks Message is set with the default message associate to the error.
      ArgumentNullException(const CurrentInformation& information) : ArgumentException(information) {}
      
      /// @brief Create a new instance of class ArgumentNullException
      /// @param message Message string associate to the error.
      ArgumentNullException(const System::String& message) : ArgumentException(message) {}
      
      /// @brief Create a new instance of class ArgumentNullException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ArgumentNullException(const System::String& message, const CurrentInformation& information) : ArgumentException(message, information) {}
      
      /// @brief Create a new instance of class ArgumentNullException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ArgumentNullException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : ArgumentException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Value cannot be null."; }
    };
  }
}

using namespace Switch;

