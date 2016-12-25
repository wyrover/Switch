/// @file
/// @brief Contains Pcf::System::Security::VerificationException exception.
#pragma once

#include "../SystemException.h"

namespace Pcf {
  namespace System {
    namespace Security {
      /// @brief The exception that is thrown when the security policy requires code to be type safe and the verification process is unable to verify that the code is type safe.
      class VerificationException : public SystemException {
      public:
        /// @brief Create a new instance of class VerificationException
        /// @remarks Message is set with the default message associate to the error.
        VerificationException() : SystemException() {}
        
        /// @brief Create a new instance of class VerificationException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        VerificationException(const VerificationException& value) : SystemException(value) {}
        
        /// @brief Create a new instance of class VerificationException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        /// @remarks Message is set with the default message associate to the error.
        VerificationException(const CurrentInformation& information) : SystemException(information) {}
        
        /// @brief Create a new instance of class VerificationException
        /// @param message Message string associate to the error.
        VerificationException(const System::String& message) : SystemException(message) {}
        
        /// @brief Create a new instance of class VerificationException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        VerificationException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
        
        /// @brief Create a new instance of class VerificationException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        VerificationException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "Policy requires code."; }
      };
    }
  }
}

using namespace Pcf;
