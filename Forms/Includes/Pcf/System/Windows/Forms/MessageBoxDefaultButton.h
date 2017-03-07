/// @file
/// @brief Contains Pcf::System::Windows::Forms::MessageBoxButtons enum.
#pragma once

#include <Pcf/System/Enum.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies constants defining the default button on a MessageBox.
        /// @remarks This enumeration is used by the MessageBox class.
        enum class MessageBoxDefaultButton {
          /// @brief The first button on the message box is the default button.
          Button1,
          /// @brief The second button on the message box is the default button.
          Button2,
          /// @brief The third button on the message box is the default button.
          Button3
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::MessageBoxDefaultButton> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::MessageBoxDefaultButton::Button1, "Button1"}, {(int64)System::Windows::Forms::MessageBoxDefaultButton::Button2, "Button2"}, {(int64)System::Windows::Forms::MessageBoxDefaultButton::Button3, "Button3"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
