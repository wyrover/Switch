/// @file
/// @brief Contains Switch::System::Windows::Forms::MessageBoxIcon enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies constants defining which information to display.
        /// @remarks This enumeration is used by the MessageBox class. The description of each member of this enumeration contains a typical representation of the symbol. The actual graphic displayed is a function of the operating system constants. In current implementations there are four unique symbols with multiple values assigned to them.
        enum class MessageBoxIcon {
          /// @brief The message box contain no symbols.
          None = 0,
          /// @brief The message box contains a symbol consisting of a white X in a circle with a red background.
          Hand = 0x00000010L,
          /// @brief The message box contains a symbol consisting of white X in a circle with a red background.
          Stop = 0x00000010L,
          /// @brief The message box contains a symbol consisting of white X in a circle with a red background.
          Error = 0x00000010L,
          /// @brief The message box contains a symbol consisting of a question mark in a circle. The question-mark message icon is no longer recommended because it does not clearly represent a specific type of message and because the phrasing of a message as a question could apply to any message type. In addition, users can confuse the message symbol question mark with Help information. Therefore, do not use this question mark message symbol in your message boxes. The system continues to support its inclusion only for backward compatibility.
          Question = 0x00000020L,
          /// @brief The message box contains a symbol consisting of an exclamation point in a triangle with a yellow background.
          Exclamation = 0x00000030L,
          /// @brief The message box contains a symbol consisting of an exclamation point in a triangle with a yellow background.
          Warning = 0x00000030L,
          /// @brief The message box contains a symbol consisting of a lowercase letter i in a circle.
          Asterisk = 0x00000040L,
          /// @brief The message box contains a symbol consisting of a lowercase letter i in a circle.
          Information = 0x00000040L,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::MessageBoxIcon> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = { {(int64)System::Windows::Forms::MessageBoxIcon::None, "None"}, {(int64)System::Windows::Forms::MessageBoxIcon::Asterisk, "Asterisk"}, {(int64)System::Windows::Forms::MessageBoxIcon::Error, "Error"}, {(int64)System::Windows::Forms::MessageBoxIcon::Exclamation, "Exclamation"}, {(int64)System::Windows::Forms::MessageBoxIcon::Hand, "Hand"}, {(int64)System::Windows::Forms::MessageBoxIcon::Information, "Information"}, {(int64)System::Windows::Forms::MessageBoxIcon::Question, "Question"}, {(int64)System::Windows::Forms::MessageBoxIcon::Stop, "Stop"}, {(int64)System::Windows::Forms::MessageBoxIcon::Warning, "Warning"} };
    flags = false;
  }
};
/// @endcond

using namespace Switch;
