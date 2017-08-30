/// @file
/// @brief Contains Switch::System::UriKind enum.
#pragma once

#include "Enum.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Defines the kinds of Uris for the Uri.IsWellFormedUriString(string, UriKind) and several Uri.Uri methods.
    enum class UriKind {
      /// @brief The kind of the Uri is indeterminate.
      RelativeOrAbsolute = 0,
      /// @brief The Uri is an absolute Uri.
      Absolute = 1,
      /// @brief The Uri is a relative Uri.
      Relative = 2,
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::UriKind> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::UriKind::RelativeOrAbsolute, "RelativeOrAbsolute"}, {(int64)System::UriKind::Absolute, "Absolute"}, {(int64)System::UriKind::Relative, "Relative"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
