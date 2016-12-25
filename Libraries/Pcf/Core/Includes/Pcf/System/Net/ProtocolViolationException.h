/// @file
/// @brief Contains Pcf::System::Net::ProtocolViolationException class.
#pragma once

#include "../SystemException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The exception that is thrown when an error is made while using a network protocol.
      class ProtocolViolationException : public InvalidOperationException {
      public:
        /// @brief Create a new instance of class ProtocolViolationException
        /// @remarks Message is set with the default message associate to the error.
        ProtocolViolationException() : InvalidOperationException() {}
        
        /// @brief Create a new instance of class ProtocolViolationException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        ProtocolViolationException(const ProtocolViolationException& value) : InvalidOperationException(value) {}
        
        /// @brief Create a new instance of class ProtocolViolationException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        /// @remarks Message is set with the default message associate to the error.
        ProtocolViolationException(const CurrentInformation& information) : InvalidOperationException(information) {}
        
        /// @brief Create a new instance of class ProtocolViolationException
        /// @param message Message string associate to the error.
        ProtocolViolationException(const System::String& message) : InvalidOperationException(message) {}
        
        /// @brief Create a new instance of class ProtocolViolationException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        ProtocolViolationException(const System::String& message, const CurrentInformation& information) : InvalidOperationException(message, information) {}
        
        /// @brief Create a new instance of class ProtocolViolationException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        ProtocolViolationException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : InvalidOperationException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "Operation is not valid due to the current state of the object."; }
      };
    }
  }
}

using namespace Pcf;
