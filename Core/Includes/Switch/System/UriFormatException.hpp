/// @file
/// @brief Contains Switch::System::UriFormatException exception.
#pragma once

#include "FormatException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an invalid Uniform Resource Identifier (URI) is detected.
    class _export UriFormatException : public FormatException {
    public:
      /// @brief Create a new instance of class UriFormatException
      /// @remarks Message is set with the default message associate to the error.
      UriFormatException() : FormatException() {}
      
      /// @brief Create a new instance of class UriFormatException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      UriFormatException(const UriFormatException& value) : FormatException(value) {}
      
      /// @brief Create a new instance of class UriFormatException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_caller.
      /// @remarks Message is set with the default message associate to the error.
      UriFormatException(const Caller& information) : FormatException(information) {}
      
      /// @brief Create a new instance of class UriFormatException
      /// @param message Message string associate to the error.
      UriFormatException(const System::String& message) : FormatException(message) {}
      
      /// @brief Create a new instance of class UriFormatException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_caller.
      UriFormatException(const System::String& message, const Caller& information) : FormatException(message, information) {}
      
      /// @brief Create a new instance of class UriFormatException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_caller.
      UriFormatException(const System::String& message, const System::Exception& innerException, const Caller& information) : FormatException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "One of identified items was an invalid format."; }
    };
  }
}

using namespace Switch;

