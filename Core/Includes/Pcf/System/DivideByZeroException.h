/// @file
/// @brief Contains Pcf::System::DivideByZeroException exception.
#pragma once

#include "ArithmeticException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to divide an integral or decimal value by zero.
    class pcf_public DivideByZeroException : public ArithmeticException {
    public:
      /// @brief Create a new instance of class DivideByZeroException
      /// @remarks Message is set with the default message associate to the error.
      DivideByZeroException() : ArithmeticException() {}
      
      /// @brief Create a new instance of class DivideByZeroException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      DivideByZeroException(const DivideByZeroException& value) : ArithmeticException(value) {}
      
      /// @brief Create a new instance of class DivideByZeroException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      DivideByZeroException(const CurrentInformation& information) : ArithmeticException(information) {}
      
      /// @brief Create a new instance of class DivideByZeroException
      /// @param message Message string associate to the error.
      DivideByZeroException(const System::String& message) : ArithmeticException(message) {}
      
      /// @brief Create a new instance of class DivideByZeroException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      DivideByZeroException(const System::String& message, const CurrentInformation& information) : ArithmeticException(message, information) {}
      
      /// @brief Create a new instance of class DivideByZeroException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      DivideByZeroException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : ArithmeticException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Attempt to divide by zero."; }
    };
  }
}

using namespace Pcf;

