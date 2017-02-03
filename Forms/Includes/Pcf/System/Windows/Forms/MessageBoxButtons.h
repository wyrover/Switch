/// @file
/// @brief Contains Pcf::System::Windows::Forms::MessageBoxButtons enum.
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
      namespace Forms {
        enum class MessageBoxButtons {
          OK,
          OKCancel,
          AbortRetryIgnore,
          YesNoCancel,
          YesNo,
          RetryCancel
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::MessageBoxButtons> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::MessageBoxButtons::OK, "OK"}, {(int64)System::Windows::Forms::MessageBoxButtons::OKCancel, "OKCancel"}, {(int64)System::Windows::Forms::MessageBoxButtons::AbortRetryIgnore, "AbortRetryIgnore"}, {(int64)System::Windows::Forms::MessageBoxButtons::YesNoCancel, "YesNoCancel"}, {(int64)System::Windows::Forms::MessageBoxButtons::YesNo, "YesNo"}, {(int64)System::Windows::Forms::MessageBoxButtons::RetryCancel, "RetryCancel"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
