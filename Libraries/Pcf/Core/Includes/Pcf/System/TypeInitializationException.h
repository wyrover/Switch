/// @file
/// @brief Contains Pcf::System::TypeInitializationException exception.
#pragma once

#include "SystemException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown as a wrapper around the exception thrown by the class initializer.
    class TypeInitializationException : public SystemException {
    public:
      TypeInitializationException(const System::TypeInitializationException& exception) : SystemException(exception) { this->fullTypeName = exception.fullTypeName; SetStackTrace(*this); }
      TypeInitializationException(const String& fullTypeName, const System::Exception& innerException) : SystemException() { this->innerException = innerException; this->fullTypeName = fullTypeName; SetStackTrace(*this); }
      TypeInitializationException(const String& fullTypeName, const System::Exception& innerException, const CurrentInformation& information) : SystemException(information) { this->innerException = innerException; this->fullTypeName = fullTypeName; SetStackTrace(*this); }
      ~TypeInitializationException() noexcept {}
    private:
      String GetDefaultMessage() const override {return String::Format("The type initializer for '{0}' threw an exception.", this->fullTypeName);}
      String fullTypeName;
    };
  }
}

using namespace Pcf;

