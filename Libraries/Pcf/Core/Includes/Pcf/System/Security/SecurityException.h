/// @file
/// @brief Contains Pcf::System::Security::SecurityException exception.
#pragma once

#include "../SystemException.h"

namespace Pcf {
  namespace System {
    namespace Security {
      /// @brief The exception that is thrown when a security error is detected.
      class SecurityException : public SystemException {
      public:
        /// @brief Create a new instance of class SecurityException
        /// @remarks Message is set with the default message associate to the error.
        SecurityException() : SystemException() {}
        
        /// @brief Create a new instance of class SecurityException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        SecurityException(const SecurityException& value) : SystemException(value) {}
        
        /// @brief Create a new instance of class SecurityException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        /// @remarks Message is set with the default message associate to the error.
        SecurityException(const CurrentInformation& information) : SystemException(information) {}
        
        /// @brief Create a new instance of class SecurityException
        /// @param message Message string associate to the error.
        SecurityException(const System::String& message) : SystemException(message) {}
        
        /// @brief Create a new instance of class SecurityException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        SecurityException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
        
        /// @brief Create a new instance of class SecurityException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        SecurityException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "Security error detected."; }
      };
    }
  }
}

using namespace Pcf;
