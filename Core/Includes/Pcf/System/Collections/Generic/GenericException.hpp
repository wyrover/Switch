/// @file
/// @brief Contains Pcf::System::Collections::Generic::KeyNotFoundException exception.
#pragma once

#include "../../SystemException.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief The exception that is thrown when the key specified for accessing an element in a collection does not match any key in the collection.
        class KeyNotFoundException : public SystemException {
        public:
          /// @brief Create a new instance of class KeyNotFoundException
          /// @remarks Message is set with the default message associate to the error.
          KeyNotFoundException() : SystemException() {}
          
          /// @brief Create a new instance of class KeyNotFoundException
          /// @param value The Excetion to copy.
          /// @remarks Message is set with the default message associate to the error.
          KeyNotFoundException(const KeyNotFoundException& value) : SystemException(value) {}
          
          /// @brief Create a new instance of class KeyNotFoundException
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
          /// @remarks Message is set with the default message associate to the error.
          KeyNotFoundException(const CurrentInformation& information) : SystemException(information) {}
          
          /// @brief Create a new instance of class KeyNotFoundException
          /// @param message Message string associate to the error.
          KeyNotFoundException(const System::String& message) : SystemException(message) {}
          
          /// @brief Create a new instance of class KeyNotFoundException
          /// @param message Message string associate to the error.
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
          KeyNotFoundException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
          
          /// @brief Create a new instance of class KeyNotFoundException
          /// @param message Message string associate to the error.
          /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
          KeyNotFoundException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
          
        private:
          System::String GetDefaultMessage() const override {return "The given key was not present in the dictionnary."; }
        };
      }
    }
  }
}

using namespace Pcf;