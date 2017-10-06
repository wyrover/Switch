/// @file
/// @brief Contains Switch::System::UriComponents enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
    /// @par Library
    /// Switch.System
    enum class UriComponents {
      /// @brief None data.
      None = 0x00000000,
      /// @brief The Scheme data.
      Scheme = 0x00000001,
      /// @brief The UserInfo data.
      UserInfo = 0x00000002,
      /// @brief The Host data.
      Host = 0x00000004,
      /// @brief The Port data.
      Port = 0x000000008,
      /// @brief The LocalPath data.
      Path = 0x00000010,
      /// @brief The Query data.
      Query = 0x00000020,
      /// @brief The Fragment data.
      Fragment = 0x00000040,
      /// @brief The Port data. If no port data is in the Uri and a default port has been assigned to the Scheme, the default port is returned. If there is no default port, -1 is returned.
      StrongPort = 0x00000080,
      /// @brief Specifies that the delimiter should be included.
      KeepDelimiter = 0x40000000,
      /// @brief The Host and Port data. If no port data is in the Uri and a default port has been assigned to the Scheme, the default port is returned. If there is no default port, -1 is returned.
      HostAndPort = 0x00000084,
      /// @brief The UserInfo, Host, and Port data. If no port data is in the Uri and a default port has been assigned to the Scheme, the default port is returned. If there is no default port, -1 is returned.
      StrongAuthority = 0x00000086,
      /// @brief The Scheme, UserInfo, Host, Port, LocalPath, Query, and Fragment data.
      AbsoluteUri = 0x0000007F,
      /// @brief The LocalPath and Query data. Also see PathAndQuery.
      PathAndQuery = 0x00000030,
      /// @brief The Scheme, Host, Port, LocalPath, and Query data.
      HttpRequestUrl = 0x0000003D,
      /// @brief The Scheme, Host, and Port data.
      SchemeAndServer = 0x0000000D,
      /// @brief The complete Uri context that is needed for Uri Serializers. The context includes the IPv6 scope.
      SerializationInfoString = 0x08000000 //0x80000000
    };
  }
}

/// @cond
template <>
class AddFlagOperators<System::UriComponents> : public TrueType {};

template<>
class EnumToStrings<System::UriComponents> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::UriComponents::None, "None"}, {(int64)System::UriComponents::Scheme, "Scheme"}, {(int64)System::UriComponents::UserInfo, "UserInfo"}, {(int64)System::UriComponents::Host, "Host"}, {(int64)System::UriComponents::Port, "Port"}, {(int64)System::UriComponents::Path, "Path"}, {(int64)System::UriComponents::Query, "Query"}, {(int64)System::UriComponents::Fragment, "Fragment"}, {(int64)System::UriComponents::StrongPort, "StrongPort"}, {(int64)System::UriComponents::KeepDelimiter, "KeepDelimiter"}, {(int64)System::UriComponents::HostAndPort, "HostAndPort"}, {(int64)System::UriComponents::StrongAuthority, "StrongAuthority"}, {(int64)System::UriComponents::AbsoluteUri, "AbsoluteUri"}, {(int64)System::UriComponents::PathAndQuery, "PathAndQuery"}, {(int64)System::UriComponents::HttpRequestUrl, "HttpRequestUrl"}, {(int64)System::UriComponents::SchemeAndServer, "SchemeAndServer"}, {(int64)System::UriComponents::SerializationInfoString, "SerializationInfoString"}};
    flags = true;
  }
};
/// @endcond

using namespace Switch;
