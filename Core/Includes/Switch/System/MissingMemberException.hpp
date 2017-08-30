/// @file
/// @brief Contains Pcf::System::MissingMemberException exception.
#pragma once

#include "MemberAccessException.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to dynamically access a class member that does not exist.
    class pcf_public MissingMemberException : public MemberAccessException {
    public:
      /// @brief Create a new instance of class MissingMemberException
      /// @remarks Message is set with the default message associate to the error.
      MissingMemberException() : MemberAccessException() {}
      
      /// @brief Create a new instance of class MissingMemberException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      MissingMemberException(const MissingMemberException& value) : MemberAccessException(value) {}
      
      /// @brief Create a new instance of class MissingMemberException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      MissingMemberException(const CurrentInformation& information) : MemberAccessException(information) {}
      
      /// @brief Create a new instance of class MissingMemberException
      /// @param message Message string associate to the error.
      MissingMemberException(const System::String& message) : MemberAccessException(message) {}
      
      /// @brief Create a new instance of class MissingMemberException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      MissingMemberException(const System::String& message, const CurrentInformation& information) : MemberAccessException(message, information) {}
      
      /// @brief Create a new instance of class MissingMemberException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      MissingMemberException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : MemberAccessException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Attempt to acces a missing member."; }
    };
  }
}

using namespace Pcf;

