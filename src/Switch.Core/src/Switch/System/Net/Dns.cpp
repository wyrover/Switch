#include "../../../../include/Switch/System/Net/Dns.hpp"
#include "../../../Native/CoreApi.hpp"

using namespace System::Net;
using namespace System::Net::Sockets;

namespace {
  class Hostent {
  public:
    Hostent() {Native::CoreApi::Dns::SetHostent(true);}
    ~Hostent() {Native::CoreApi::Dns::EndHostent();}
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
    host = Native::CoreApi::Dns::GetHostByName(hostNameOrAddress);
    if (host == 0)
      throw InvalidOperationException(_caller);
  } else {
    host = Native::CoreApi::Dns::GetHostByAddress(address.ToString(), address.AddressFamily());
    if (host == 0)
      throw InvalidOperationException(_caller);
  }
  IPHostEntry hostEntry(Native::CoreApi::Dns::GetAddresses(host), Native::CoreApi::Dns::GetAliases(host), Native::CoreApi::Dns::GetHostName(host));
  Native::CoreApi::Dns::Destroy(host);
  return hostEntry;
}

string Dns::GetHostName() {
  Hostent hotent;
  string hostName;
  if(Native::CoreApi::Dns::GetHostName(hostName) != 0)
    throw InvalidOperationException(_caller);
  return hostName;
}
