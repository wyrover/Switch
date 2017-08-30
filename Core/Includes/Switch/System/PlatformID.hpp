/// @file
/// @brief Contains Switch::System::PlatformID enum.
#pragma once

#include "Enum.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum PlatformID
    /// @brief Identifies the operating system, or platform, supported by an assembly.
    /// @see OperatingSystem
    enum class PlatformID {
      /// @brief The operating system is unknown.
      Unknown = -1,
      /// @brief The operating system is Win32s. Win32s is a layer that runs on 16-bit versions of Windows to provide access to 32-bit applications.
      Win32S,
      /// @brief The operating system is Windows 95 or Windows 98.
      Win32Windows,
      /// @brief The operating system is Windows NT or later.
      Win32NT,
      /// @brief The operating system is Windows CE.
      WinCE,
      /// @brief The operating system is Unix.
      Unix,
      /// @brief The development platform is Xbox 360.
      Xbox,
      /// @brief The operating system is Macintosh.
      MacOSX,
      /// @brief The operating system is IOs Apple.
      IOs,
      /// @brief The operating system is Android.
      Android,
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::PlatformID> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::PlatformID::Unknown, "Unknown"}, {(int64)System::PlatformID::Win32S, "Win32S"}, {(int64)System::PlatformID::Win32Windows, "Win32Windows"}, {(int64)System::PlatformID::Win32NT, "Win32NT"}, {(int64)System::PlatformID::WinCE, "WinCE"}, {(int64)System::PlatformID::Unix, "Unix"}, {(int64)System::PlatformID::Xbox, "Xbox"}, {(int64)System::PlatformID::MacOSX, "MacOSX"}, {(int64)System::PlatformID::IOs, "IOs"}, {(int64)System::PlatformID::Android, "Android"}};
    flags = false;
  }
};
/// @endocnd

using namespace Switch;
