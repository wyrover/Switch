/// @file
/// @brief Contains Switch::System::Net::Sockets::MulticastOption enum.
#pragma once

#include "../../../Property.hpp"
#include "../../../Types.hpp"
#include "../../Object.hpp"
#include "../IPAddress.hpp"
#include "SocketException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Contains IPAddress values used to join and drop multicast groups.
        /// @remarks Use a MulticastOption to store the IPAddress of a multicast group you want to join or drop. Use the Socket.SetSocketOption method with the following parameters to join a multicast group.
        /// | Parameter         | Value                |
        /// |-------------------|----------------------|
        /// | SocketOptionLevel | SocketOptionLevelUdp |
        /// | SocketOptionName  | AddMembership        |
        /// | object            | MulticastOption      |
        /// @remarks Use DropMembership to drop a multicast group.
        class _public MulticastOption : public Object {
        public:
          /// @brief Initializes a new version of the MulticastOption class for the specified IP multicast group.
          /// @param group The IPAddress of the multicast group.
          /// @exception ArgumentNullException group is null.
          MulticastOption(const IPAddress& group) : group(group) {}

          /// @brief Initializes a new instance of the MulticastOption class with the specified IP multicast group address and interface index.
          /// @param group The IPAddress of the multicast group.
          /// @param interfaceIndex The local interface address.
          /// @exception ArgumentNullException group is null.
          /// @exception ArgumentOutOfRangeException interfaceIndex is less than 0.
          MulticastOption(const IPAddress& group, int32 interfaceIndex) : group(group) {InterfaceIndex = interfaceIndex;}

          /// @brief Initializes a new instance of the MulticastOption class with the specified IP multicast group address and local IP address associated with a network interface.
          /// @param group The IPAddress of the multicast group.
          /// @param interfaceIndex The local interface address.
          /// @param localAddress The local IPAddress.
          /// @exception ArgumentNullException group or localAddress is null.
          /// @exception ArgumentOutOfRangeException interfaceIndex is less than 0.
          MulticastOption(const IPAddress& group, IPAddress localAddress) : group(group), localAddress(localAddress) {}
          
          /// @cond
          MulticastOption(const MulticastOption& multicastOption) : group(multicastOption.group), interfaceIndex(multicastOption.interfaceIndex), localAddress(multicastOption.localAddress) {}
          /// @endcond

          /// @brief Gets or sets the IP address of a multicast group.
          /// @param group An IPAddress that contains the Internet address of a multicast group.
          /// @return IPAddress An IPAddress that contains the Internet address of a multicast group.
          Property<const IPAddress&> Group {
            _get->const IPAddress& {return this->group;},
            _set {this->group = value;}
          };

          /// @brief Gets or sets the interface index that is associated with a multicast group.
          /// @param interfaceIndex A int32 value that specifies the address of the interface.
          /// @return int32 A Int32 value that specifies the address of the interface.
          /// @exception ArgumentOutOfRangeException interfaceIndex is less than 0.
          Property<int32> InterfaceIndex {
            _get {return this->interfaceIndex;},
            _set {
              if (value < 0)
                throw ArgumentOutOfRangeException(_current_information);
              this->interfaceIndex = value;
            }
          };

          /// @brief Gets or sets the local address associated with a multicast group.
          /// @param localAddress An IPAddress that contains the local address associated with a multicast group.
          /// @return IPAddress An IPAddress that contains the local address associated with a multicast group.
          /// @remarks The LocalAddress property contains the IP address of the interface associated with the multicast group membership. If LocalAddress is set to Any, the default interface is used.
          Property<const IPAddress&> LocalAddress {
            _get->const IPAddress& {return this->localAddress;},
            _set {this->localAddress = value;}
          };

        private:
          IPAddress group;
          int32 interfaceIndex = 0;
          IPAddress localAddress;
        };
      }
    }
  }
}

using namespace Switch;
