/// @file
/// @brief Contains Switch::System::IO::FileNotFoundException exception.
#pragma once

#include "IOException.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The exception that is thrown when an attempt to access a file that does not exist on disk fails.
      class pcf_public FileNotFoundException : public IOException {
      public:
        /// @brief Create a new instance of class FileNotFoundException
        /// @remarks Message is set with the default message associate to the error.
        FileNotFoundException() : IOException() {}
        
        /// @brief Create a new instance of class FileNotFoundException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        FileNotFoundException(const FileNotFoundException& value) : IOException(value) {}
        
        /// @brief Create a new instance of class FileNotFoundException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        /// @remarks Message is set with the default message associate to the error.
        FileNotFoundException(const CurrentInformation& information) : IOException(information) {}
        
        /// @brief Create a new instance of class FileNotFoundException
        /// @param message Message string associate to the error.
        FileNotFoundException(const System::String& message) : IOException(message) {}
        
        /// @brief Create a new instance of class FileNotFoundException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        FileNotFoundException(const System::String& message, const CurrentInformation& information) : IOException(message, information) {}
        
        /// @brief Create a new instance of class FileNotFoundException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        FileNotFoundException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : IOException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "Unable to find the specified file."; }
      };
    }
  }
}

using namespace Switch;