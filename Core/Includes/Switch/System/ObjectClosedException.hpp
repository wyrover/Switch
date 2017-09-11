/// @file
/// @brief Contains Switch::System::ObjectClosedException exception.
#pragma once

#include "InvalidOperationException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to dereference a null object reference.
    class _export ObjectClosedException : public InvalidOperationException {
    public:
      /// @brief Create a new instance of class ObjectClosedException
      /// @remarks Message is set with the default message associate to the error.
      ObjectClosedException() : InvalidOperationException() {}
      
      /// @brief Create a new instance of class ObjectClosedException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ObjectClosedException(const ObjectClosedException& value) : InvalidOperationException(value) {}
      
      /// @brief Create a new instance of class ObjectClosedException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      /// @remarks Message is set with the default message associate to the error.
      ObjectClosedException(const CurrentInformation& information) : InvalidOperationException(information) {}
      
      /// @brief Create a new instance of class ObjectClosedException
      /// @param message Message string associate to the error.
      ObjectClosedException(const System::String& message) : InvalidOperationException(message) {}
      
      /// @brief Create a new instance of class ObjectClosedException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ObjectClosedException(const System::String& message, const CurrentInformation& information) : InvalidOperationException(message, information) {}
      
      /// @brief Create a new instance of class ObjectClosedException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #_current_information.
      ObjectClosedException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : InvalidOperationException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Cannot access a closed object."; }
    };
  }
}

using namespace Switch;

