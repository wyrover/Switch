#include "../../../../include/Switch/System/Net/Dns.hpp"
#include "../../../Native/SystemApi.hpp"

using namespace System::Net;
using namespace System::Net::Sockets;

namespace {
  class Hostent {
  public:
    Hostent() {Native::SystemApi::Dns::SetHostent(true);}
    ~Hostent() {Native::SystemApi::Dns::EndHostent();}
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
    host = Native::SystemApi::Dns::GetHostByName(hostNameOrAddress);
    if (host == 0)
      throw InvalidOperationException(_caller);
  } else {
    host = Native::SystemApi::Dns::GetHostByAddress(address.ToString(), address.AddressFamily());
    if (host == 0)
      throw InvalidOperationException(_caller);
  }
  IPHostEntry hostEntry(Native::SystemApi::Dns::GetAddresses(host), Native::SystemApi::Dns::GetAliases(host), Native::SystemApi::Dns::GetHostName(host));
  Native::SystemApi::Dns::Destroy(host);
  return hostEntry;
}

string Dns::GetHostName() {
  Hostent hotent;
  string hostName;
  if(Native::SystemApi::Dns::GetHostName(hostName) != 0)
    throw InvalidOperationException(_caller);
  return hostName;
}
