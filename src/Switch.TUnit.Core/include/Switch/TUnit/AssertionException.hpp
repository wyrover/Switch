/// @file
/// @brief Contains Switch::TUnit::AssertionException exception.
#pragma once

#include <Switch/System/SystemException.hpp>
#include "../TUnitCoreExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #AddTest_ method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #AddTest_ method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief Thrown when an assertion failed.
    class tunit_core_export_ AssertionException : public System::Exception {
    public:
      /// @brief Create a new instance of class AssertionException
      /// @remarks Message is set with the default message associate to the error.
      AssertionException() : System::Exception() {}

      /// @brief Create a new instance of class AssertionException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      AssertionException(const AssertionException& value) : System::Exception(value) {}

      /// @brief Create a new instance of class AssertionException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      AssertionException(const System::Runtime::CompilerServices::Caller& information) : System::Exception(information) {}

      /// @brief Create a new instance of class AssertionException
      /// @param message Message string associate to the error.
      AssertionException(const System::String& message) : System::Exception(message) {}

      /// @brief Create a new instance of class AssertionException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AssertionException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : System::Exception(message, information) {}

      /// @brief Create a new instance of class AssertionException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AssertionException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : System::Exception(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const {return "Assertion failed."; }
    };
  }
}

using namespace Switch;
