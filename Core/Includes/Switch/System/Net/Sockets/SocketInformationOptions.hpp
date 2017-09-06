/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketInformationOptions enum.
#pragma once

#include "../../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @see Socket
        enum class SocketInformationOptions {
          /// @brief None SockectInformationOptions.
          None = 0x00,
          /// @brief The Socket is nonblocking.
          NonBlocking = 0x01,
          /// @brief The Socket is connected.
          Connected = 0x02,
          /// @brief The Socket is listening for new connections.
          Listening = 0x04,
          /// @brief The Socket uses overlapped I/O.
          UseOnlyOverlappedIO = 0x08,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Net::Sockets::SocketInformationOptions> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Net::Sockets::SocketInformationOptions::None, "None"}, {(int64)System::Net::Sockets::SocketInformationOptions::NonBlocking, "NonBlocking"}, {(int64)System::Net::Sockets::SocketInformationOptions::Connected, "Connected"}, {(int64)System::Net::Sockets::SocketInformationOptions::Listening, "Listening"}, {(int64)System::Net::Sockets::SocketInformationOptions::UseOnlyOverlappedIO, "UseOnlyOverlappedIO"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
