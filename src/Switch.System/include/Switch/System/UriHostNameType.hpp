/// @file
/// @brief Contains Switch::System::UriHostNameType enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Defines host name types for the Uri.CheckHostName method.
    /// @remarks The UriHostNameType enumeration defines the values that the Uri.CheckHostName method can return.
    enum class UriHostNameType {
      /// @brief The type of the host name is not supplied.
      Unknown = 0,
      /// @brief The host is set, but the type cannot be determined.
      Basic = 1,
      /// @brief The host name is a domain name system (DNS) style host name.
      Dns = 2,
      /// @brief The Uri is a relative Uri.
      IPv4 = 3,
      /// @brief The Uri is a relative Uri.
      IPv6 = 4,
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::UriHostNameType> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::UriHostNameType::Unknown, "Unknown"}, {(int64)System::UriHostNameType::Basic, "Basic"}, {(int64)System::UriHostNameType::Dns, "Dns"}, {(int64)System::UriHostNameType::IPv4, "IPv4"}, {(int64)System::UriHostNameType::IPv6, "IPv6"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
