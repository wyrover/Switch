/// @file
/// @brief Contains Pcf::System::Net::Sockets::AddressFamily enum.
#pragma once

#include "../../Enum.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @enum AddressFamily
        /// @brief Specifies the addressing scheme that an instance of the System::Net::Sockets::Socket class can use.
        /// @see Socket
        enum class AddressFamily {
          /// @brief Unknown address family.
          Unknown = -1,
          /// @brief Unspecified address family.
          Unspecified,
          /// @brief Unix local to host address.
          Unix = 1,
          /// @brief Address for IP version 4.
          InterNetwork = 2,
          /// @brief ARPANET IMP address.
          ImpLink = 3,
          /// @brief Address for PUP protocols.
          Pup = 4,
          /// @brief Address for MIT CHAOS protocols.
          Chaos = 5,
          /// @brief Address for Xerox NS protocols.
          NS = 6,
          /// @brief IPX or SPX address.
          Ipx = 6,
          /// @brief Address for ISO protocols.
          Iso = 7,
          /// @brief Address for OSI protocols.
          Osi = 7,
          /// @brief European Computer Manufacturers Association (ECMA) address.
          Ecma = 8,
          /// @brief Address for Datakit protocols.
          DataKit = 9,
          /// @brief Addresses for CCITT protocols, such as X.25.
          Ccitt = 10,
          /// @brief IBM SNA address.
          Sna = 11,
          /// @brief DECnet address.
          DecNet = 12,
          /// @brief Direct data-link interface address.
          DataLink = 13,
          /// @brief LAT address.
          Lat = 14,
          /// @brief NSC Hyperchannel address.
          HyperChannel = 15,
          /// @brief AppleTalk address.
          AppleTalk = 16,
          /// @brief NetBios address.
          NetBios = 17,
          /// @brief VoiceView address.
          VoiceView = 18,
          /// @brief FireFox address.
          FireFox = 19,
          /// @brief Banyan address.
          Banyan = 21,
          /// @brief Native ATM services address.
          Atm = 22,
          /// @brief Address for IP version 6.
          InterNetworkV6 = 23,
          /// @brief Address for Microsoft cluster products.
          Cluster = 24,
          /// @brief IEEE 1284.4 workgroup address.
          Ieee12844 = 25,
          /// @brief IrDA address.
          Irda = 26,
          /// @brief Address for Network Designers OSI gateway-enabled protocols.
          NetworkDesigners = 28,
          /// @brief MAX address.
          Max = 29,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Net::Sockets::AddressFamily> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Net::Sockets::AddressFamily::Unknown, "Unknown"}, {(int64)System::Net::Sockets::AddressFamily::Unspecified, "Unspecified"}, {(int64)System::Net::Sockets::AddressFamily::Unix, "Unix"}, {(int64)System::Net::Sockets::AddressFamily::InterNetwork, "InterNetwork"}, {(int64)System::Net::Sockets::AddressFamily::ImpLink, "ImpLink"}, {(int64)System::Net::Sockets::AddressFamily::Pup, "Pup"}, {(int64)System::Net::Sockets::AddressFamily::Chaos, "Chaos"}, /*{(int64)System::Net::Sockets::AddressFamily::NS, "NS"},*/ {(int64)System::Net::Sockets::AddressFamily::Ipx, "Ipx"}, {(int64)System::Net::Sockets::AddressFamily::Iso, "Iso"}, /*{(int64)System::Net::Sockets::AddressFamily::Osi, "Osi"},*/ {(int64)System::Net::Sockets::AddressFamily::Ecma, "Ecma"}, {(int64)System::Net::Sockets::AddressFamily::DataKit, "DataKit"}, {(int64)System::Net::Sockets::AddressFamily::Ccitt, "Ccitt"}, {(int64)System::Net::Sockets::AddressFamily::Sna, "Sna"}, {(int64)System::Net::Sockets::AddressFamily::DecNet, "DecNet"}, {(int64)System::Net::Sockets::AddressFamily::DataLink, "DataLink"}, {(int64)System::Net::Sockets::AddressFamily::Lat, "Lat"}, {(int64)System::Net::Sockets::AddressFamily::HyperChannel, "HyperChannel"}, {(int64)System::Net::Sockets::AddressFamily::AppleTalk, "AppleTalk"}, {(int64)System::Net::Sockets::AddressFamily::NetBios, "NetBios"}, {(int64)System::Net::Sockets::AddressFamily::VoiceView, "VoiceView"}, {(int64)System::Net::Sockets::AddressFamily::FireFox, "FireFox"}, {(int64)System::Net::Sockets::AddressFamily::Banyan, "Banyan"}, {(int64)System::Net::Sockets::AddressFamily::Atm, "Atm"}, {(int64)System::Net::Sockets::AddressFamily::InterNetworkV6, "InterNetworkV6"}, {(int64)System::Net::Sockets::AddressFamily::Cluster, "Cluster"}, {(int64)System::Net::Sockets::AddressFamily::Ieee12844, "Ieee12844"}, {(int64)System::Net::Sockets::AddressFamily::Irda, "Irda"}, {(int64)System::Net::Sockets::AddressFamily::NetworkDesigners, "NetworkDesigners"}, {(int64)System::Net::Sockets::AddressFamily::Max, "Max"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
