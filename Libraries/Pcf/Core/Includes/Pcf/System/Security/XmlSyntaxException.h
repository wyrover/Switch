/// @file
/// @brief Contains Pcf::System::Security::XmlSyntaxException exception.
#pragma once

#include "../SystemException.h"

namespace Pcf {
  namespace System {
    namespace Security {
      /// @brief The exception that is thrown when there is a syntax error in XML parsing. This class cannot be inherited.
      class XmlSyntaxException : public SystemException {
      public:
        /// @brief Create a new instance of class XmlSyntaxException
        /// @remarks Message is set with the default message associate to the error.
        XmlSyntaxException() : SystemException() {}
        
        /// @brief Create a new instance of class XmlSyntaxException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        XmlSyntaxException(const XmlSyntaxException& value) : SystemException(value) {}
        
        /// @brief Create a new instance of class XmlSyntaxException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        /// @remarks Message is set with the default message associate to the error.
        XmlSyntaxException(const CurrentInformation& information) : SystemException(information) {}
        
        /// @brief Create a new instance of class XmlSyntaxException
        /// @param message Message string associate to the error.
        XmlSyntaxException(const System::String& message) : SystemException(message) {}
        
        /// @brief Create a new instance of class XmlSyntaxException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        XmlSyntaxException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
        
        /// @brief Create a new instance of class XmlSyntaxException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        XmlSyntaxException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "Syntax error in XML."; }
      };
    }
  }
}

using namespace Pcf;
