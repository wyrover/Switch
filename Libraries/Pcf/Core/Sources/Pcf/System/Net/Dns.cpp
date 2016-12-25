#include "../../../../Includes/Pcf/System/Net/Dns.h"

#include <mutex>

#if _WIN32
#pragma warning(disable:4201)
#include <winsock2.h>
#pragma warning(default:4201)
#else
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#endif

namespace {
#if _WIN32
  void sethostent(int) {}
  void endhostent() {}
#endif
  
  class Hostent {
  public:
    Hostent() {sethostent(true);}
    ~Hostent() {endhostent();}
    
    static int GetHostByAddress(const string& hostAddress, System::Net::Sockets::AddressFamily hostAddressType, struct hostent& remoteHost) {
      std::lock_guard<std::mutex> lock(mutex);
      struct hostent* host = gethostbyaddr(hostAddress.Data(), hostAddressType == System::Net::Sockets::AddressFamily::InterNetwork ? 4 : 16, (int)hostAddressType);
      if (host == null)
        return -1;
      remoteHost = *host;
      return 0;
    }
    
    static int GetHostByName(const string& hostName, struct hostent& remoteHost) {
      std::lock_guard<std::mutex> lock(mutex);
      struct hostent* host = gethostbyname(hostName.Data());
      if (host == null)
        return -1;
      remoteHost = *host;
      return 0;
    }
    
    static System::Array<string> GetAliases(const struct hostent& host) {
      int32 index = 0;
      System::Collections::Generic::List<System::Net::IPAddress> ad;
      System::Collections::Generic::List<string> aliases;
      while (host.h_aliases[index] != null)
        aliases.Add(host.h_aliases[index++]);
      return aliases.ToArray();
    }
    
    static System::Array<System::Net::IPAddress> GetAddresses(const struct hostent& host) {
      int32 index = 0;
      System::Collections::Generic::List<System::Net::IPAddress> addresses;
      while (host.h_addr_list[index] != null)
        addresses.Add(System::Net::IPAddress(System::Array<byte>((const byte*)host.h_addr_list[index++],  (System::Net::Sockets::AddressFamily)host.h_addrtype == System::Net::Sockets::AddressFamily::InterNetwork ? 4 : 16)));
      return addresses.ToArray();
    }
    
    static int GetHostName(string& hostName) {
      char host[1024];
      int result =  gethostname(host, 1024);
      hostName = host;
      return result;
    }
    
  private:
    static std::mutex mutex;
  };
  std::mutex Hostent::mutex;
}

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

Array<IPAddress> Dns::GetHostAddresses(const string& hostNameOrAddress) {
  IPHostEntry hostEntry = GetHostEntry(hostNameOrAddress);
  return hostEntry.addresses;
}

IPHostEntry Dns::GetHostEntry(const IPAddress& address) {
  return GetHostEntry(address.ToString());
}

IPHostEntry Dns::GetHostEntry(const string& hostNameOrAddress) {
  IPHostEntry hostEntry;
  IPAddress address;
  Hostent hostent;
  struct hostent remoteHost;
  if (IPAddress::TryParse(hostNameOrAddress, address) == false) {
    if (Hostent::GetHostByName(hostNameOrAddress, remoteHost) != 0)
      throw InvalidOperationException(pcf_current_information);
  } else {
    if (Hostent::GetHostByAddress(address.ToString(), address.AddressFamily(), remoteHost) != 0)
      throw InvalidOperationException(pcf_current_information);
  }
  hostEntry.hostName = remoteHost.h_name;
  hostEntry.aliases = Hostent::GetAliases(remoteHost);
  hostEntry.addresses = Hostent::GetAddresses(remoteHost);
  
  return hostEntry;
}

string Dns::GetHostName() {
  string hostName;
  Hostent hotent;
  if(Hostent::GetHostName(hostName) != 0)
    throw InvalidOperationException(pcf_current_information);
  return hostName;
}
