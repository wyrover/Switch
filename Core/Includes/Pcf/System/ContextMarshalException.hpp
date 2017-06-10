/// @file
/// @brief Contains Pcf::System::ContextMarshalException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an attempt to marshal an object across a context boundary fails.
    class pcf_public ContextMarshalException : public SystemException {
    public:
      /// @brief Create a new instance of class ContextMarshalException
      /// @remarks Message is set with the default message associate to the error.
      ContextMarshalException() : SystemException() {}
      
      /// @brief Create a new instance of class ContextMarshalException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ContextMarshalException(const ContextMarshalException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class ContextMarshalException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      ContextMarshalException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class ContextMarshalException
      /// @param message Message string associate to the error.
      ContextMarshalException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class ContextMarshalException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      ContextMarshalException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class ContextMarshalException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      ContextMarshalException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Attempt to marshal an object across a context boundary."; }
    };
  }
}

using namespace Pcf;

