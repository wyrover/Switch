#include "../../../../Includes/Pcf/System/Net/Dns.hpp"
#include "../../../__OS/CoreApi.hpp"

using namespace System::Net;
using namespace System::Net::Sockets;

namespace {
  class Hostent {
  public:
    Hostent() {__OS::CoreApi::Dns::SetHostent(true);}
    ~Hostent() {__OS::CoreApi::Dns::EndHostent();}
  };
}

System::Array<IPAddress> Dns::GetHostAddresses(const string& hostNameOrAddress) {
  IPHostEntry hostEntry = GetHostEntry(hostNameOrAddress);
  return hostEntry.addresses;
}

IPHostEntry Dns::GetHostEntry(const IPAddress& address) {
  return GetHostEntry(address.ToString());
}

IPHostEntry Dns::GetHostEntry(const string& hostNameOrAddress) {
  Hostent hostent;
  IPAddress address;
  intptr host;
  if (IPAddress::TryParse(hostNameOrAddress, address) == false) {
    host = __OS::CoreApi::Dns::GetHostByName(hostNameOrAddress);
    if (host == 0)
      throw InvalidOperationException(pcf_current_information);
  } else {
    host = __OS::CoreApi::Dns::GetHostByAddress(address.ToString(), address.AddressFamily());
    if (host == 0)
      throw InvalidOperationException(pcf_current_information);
  }
  IPHostEntry hostEntry(__OS::CoreApi::Dns::GetAddresses(host), __OS::CoreApi::Dns::GetAliases(host), __OS::CoreApi::Dns::GetHostName(host));
  __OS::CoreApi::Dns::Destroy(host);
  return hostEntry;
}

string Dns::GetHostName() {
  Hostent hotent;
  string hostName;
  if(__OS::CoreApi::Dns::GetHostName(hostName) != 0)
    throw InvalidOperationException(pcf_current_information);
  return hostName;
}
