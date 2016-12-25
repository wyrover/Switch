/// @file
/// @brief Contains Pcf::System::Windows::Forms::MessageBoxIcon enum.
#pragma once

#include <Pcf/System/Enum.h>

#include "Control.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        enum class MessageBoxIcon {
          None,
          Asterisk,
          Error,
          Exclamation,
          Hand,
          Information,
          Question,
          Stop,
          Warning,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::FormsD::MessageBoxIcon> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::MessageBoxIcon::None, "None"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Asterisk, "Asterisk"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Error, "Error"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Exclamation, "Exclamation"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Hand, "Hand"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Information, "Information"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Question, "Question"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Stop, "Stop"}, {(int64)System::Windows::FormsD::MessageBoxIcon::Warning, "Warning"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
