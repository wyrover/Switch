/// @file
/// @brief Contains Switch::Caller class and #_caller keyword.
#pragma once

#include "../../../Types.hpp"
#include "../../Object.hpp"
#include "../../_String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Runtime namespaces contain types that support an application's interaction with the common language runtime, and types that enable features such as application data caching, advanced exception handling, application activation within application domains, COM interop, distributed applications, serialization and deserialization, and versioning.
    namespace Runtime {
      /// @brief The System::Runtime::CompilerServices namespace provides functionality for compiler writers who use managed code to specify attributes in metadata that affect the run-time behavior.
      namespace CompilerServices {
        /// @brief Caller information class is used to store current file, current line and current function information.
        /// @par Examples
        /// Use #_caller to get caller information.
        /// @code
        /// Caller caller = _caller;
        /// Console::WriteLine("File = {0}", caller.FilePath);
        /// Console::WriteLine("LineNumber = {0}", caller.LineNumber);
        /// Console::WriteLine("Function = {0}", caller.MemberNamne);
        /// @endcode
        class _export Caller : public System::Object {
        public:
          Caller() {}
          Caller(const System::String& filePath, int32 lineNumber) : filePath(filePath), lineNumber(lineNumber) {}
          Caller(const System::String& filePath, int32 lineNumber, const System::String& memberNamne) : filePath(filePath), lineNumber(lineNumber), memberNamne(memberNamne) {}
          
          /// @cond
          Caller(const Caller& caller) : filePath(caller.filePath),  lineNumber(caller.lineNumber), memberNamne(caller.memberNamne) {}
          /// @endcond
          
          /// Gets the FilePath
          _property<const System::String&, _readonly> FilePath {
            _get->const System::String& {return this->filePath;}
          };
          
          _property<int32, _readonly> LineNumber {
            _get {return this->lineNumber;}
          };
          
          _property<const System::String&, _readonly> MemberNamne {
            _get->const System::String& {return this->memberNamne;}
          };
          
          System::String ToString() const override {
            if (string::IsNullOrEmpty(this->filePath) && this->lineNumber == 0 && string::IsNullOrEmpty(this->memberNamne))
              return "{Empty}";
            if (string::IsNullOrEmpty(this->memberNamne))
              return System::String::Format("{{FilePath=\"{0}\", LineNumber={1}}}", this->filePath, this->lineNumber);
            return System::String::Format("{{FilePath=\"{0}\", LineNumber={1}, MemberName=\"{2}\"}}", this->filePath, this->lineNumber, this->memberNamne);
          }
          
        private:
          System::String filePath;
          int32 lineNumber = 0;
          System::String memberNamne;
        };
      }
    }
  }
  
  /// @brief Get Caller informations
  /// @return Caller caller informations.
  /// @par Examples
  /// @code
  /// Caller caller = _caller;
  /// Console::WriteLine("File = {0}", caller.FilePath);
  /// Console::WriteLine("LineNUmber = {0}", caller.LineNumber);
  /// Console::WriteLine("Function = {0}", caller.MemberNamne);
  /// @endcode
  /// @ingroup Keywords
  #define _caller \
  Switch::System::Runtime::CompilerServices::Caller(__FILE__, __LINE__, __func__)
}

using namespace Switch;
