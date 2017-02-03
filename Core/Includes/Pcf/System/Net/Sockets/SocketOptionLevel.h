/// @file
/// @brief Contains Pcf::System::Net::Sockets::SocketOptionLevel enum.
#pragma once

#include "../../Enum.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Defines socket option levels for the Socket::SetSocketOption and Socket::GetSocketOption methods.
        /// @remarks The SocketOptionLevel enumeration defines the socket option levels that can be passed to the Socket.SetSocketOption and Socket.GetSocketOption methods. SocketOptionName enumerated values are grouped by SocketOptionLevel.
        enum class SocketOptionLevel {
          /// @brief Socket options apply to all sockets.
          Socket = 65535,
          /// @brief Socket options apply only to IP sockets.
          IP = 0,
          /// @brief Socket options apply only to IPv6 sockets.
          IPv6 = 41,
          /// @brief Socket options apply only to TCP sockets.
          Tcp = 6,
          /// @brief Socket options apply only to UDP sockets.
          Udp = 17,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Net::Sockets::SocketOptionLevel> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Net::Sockets::SocketOptionLevel::Socket, "Socket"}, {(int64)System::Net::Sockets::SocketOptionLevel::IP, "IP"}, {(int64)System::Net::Sockets::SocketOptionLevel::IPv6, "IPv6"}, {(int64)System::Net::Sockets::SocketOptionLevel::Tcp, "Tcp"}, {(int64)System::Net::Sockets::SocketOptionLevel::Udp, "Udp"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
