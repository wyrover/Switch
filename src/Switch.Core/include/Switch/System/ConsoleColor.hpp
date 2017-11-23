/// @file
/// @brief Contains Switch::System::ConsoleColor enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum ConsoleColor
    /// @brief Specifies constants that define foreground and background colors for the console.
    /// @see Console
    enum class ConsoleColor {
      /// @brief The color black.
      Black,
      /// @brief The color dark blue.
      DarkBlue,
      /// @brief The color dark green.
      DarkGreen,
      /// @brief The color dark cyan (dark blue-green).
      DarkCyan,
      /// @brief The color dark red.
      DarkRed,
      /// @brief The color dark magenta (dark purplish-red).
      DarkMagenta,
      /// @brief The color dark yellow (ochre).
      DarkYellow,
      /// @brief The color gray.
      Gray,
      /// @brief The color dark gray.
      DarkGray,
      /// @brief The color blue.
      Blue,
      /// @brief The color green.
      Green,
      /// @brief The color cyan (blue-green).
      Cyan,
      /// @brief The color red.
      Red,
      /// @brief The color magenta (purplish red).
      Magenta,
      /// @brief The color yellow.
      Yellow,
      /// @brief The color white.
      White
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::ConsoleColor> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::ConsoleColor::Black, "Black"}, {(int64)System::ConsoleColor::DarkBlue, "DarkBlue"}, {(int64)System::ConsoleColor::DarkGreen, "DarkGreen"}, {(int64)System::ConsoleColor::DarkCyan, "DarkCyan"}, {(int64)System::ConsoleColor::DarkRed, "DarkRed"}, {(int64)System::ConsoleColor::DarkMagenta, "DarkMagenta"}, {(int64)System::ConsoleColor::DarkYellow, "DarkYellow"}, {(int64)System::ConsoleColor::Gray, "Gray"}, {(int64)System::ConsoleColor::DarkGray, "DarkGray"}, {(int64)System::ConsoleColor::Blue, "Blue"}, {(int64)System::ConsoleColor::Green, "Green"}, {(int64)System::ConsoleColor::Cyan, "Cyan"}, {(int64)System::ConsoleColor::Red, "Red"}, {(int64)System::ConsoleColor::Magenta, "Magenta"}, {(int64)System::ConsoleColor::Yellow, "Yellow"}, {(int64)System::ConsoleColor::White, "White"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
