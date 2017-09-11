/// @file
/// @brief Contains Switch::CurrentInformation class and #_current_information keyword.
#pragma once

#include "Types.hpp"
#include "System/Object.hpp"
#include "System/_String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Current information class is used to store current file, current line and current function information.
  /// @par Examples
  /// Use #_current_information to get current information.
  /// @code
  /// CurrentInformation currentInformation = _current_information;
  /// Console::WriteLine("File = {0}", currentInformation.FilePath);
  /// Console::WriteLine("LineNumber = {0}", currentInformation.LineNumber);
  /// Console::WriteLine("Function = {0}", currentInformation.MemberNamne);
  /// @endcode
  class _export CurrentInformation : public System::Object {
  public:
    CurrentInformation() {}
    CurrentInformation(const System::String& filePath, int32 lineNumber) : filePath(filePath), lineNumber(lineNumber) {}
    CurrentInformation(const System::String& filePath, int32 lineNumber, const System::String& memberNamne) : filePath(filePath), lineNumber(lineNumber), memberNamne(memberNamne) {}

    /// @cond
    CurrentInformation(const CurrentInformation& currentInformation) : filePath(currentInformation.filePath),  lineNumber(currentInformation.lineNumber), memberNamne(currentInformation.memberNamne) {}
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
  
  /// @brief Get Current informations
  /// @return CurrentInformation Current informations.
  /// @par Examples
  /// @code
  /// CurrentInformation currentInformation = _current_information;
  /// Console::WriteLine("File = {0}", currentInformation.FilePath);
  /// Console::WriteLine("LineNUmber = {0}", currentInformation.LineNumber);
  /// Console::WriteLine("Function = {0}", currentInformation.MemberNamne);
  /// @endcode
  /// @ingroup Switch
  #define _current_information \
  CurrentInformation(__FILE__, __LINE__, __func__)
}

using namespace Switch;
