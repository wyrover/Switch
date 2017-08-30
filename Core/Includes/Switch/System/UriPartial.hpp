/// @file
/// @brief Contains Switch::System::UriPartial enum.
#pragma once

#include "Enum.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Defines the parts of a URI for the Uri.GetLeftPart method.
    enum class UriPartial {
      /// @brief The scheme segment of the URI.
      Scheme = 0,
      /// @brief The scheme and authority segments of the URI.
      Authority = 1,
      /// @brief The scheme, authority, and path segments of the URI.
      Path = 2,
      /// @brief The scheme, authority, path, and query segments of the URI.
      Query = 3,
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::UriPartial> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::UriPartial::Scheme, "Scheme"}, {(int64)System::UriPartial::Authority, "Authority"}, {(int64)System::UriPartial::Path, "Path"}, {(int64)System::UriPartial::Query, "Query"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;