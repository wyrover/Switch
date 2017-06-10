#include "../../../../Includes/Pcf/System/Net/DnsEndPoint.hpp"
#include "../../../../Includes/Pcf/System/Net/Dns.hpp"
#include "../../../../Includes/Pcf/System/Net/IPEndPoint.hpp"
#include "../../../../Includes/Pcf/System/Net/IPHostEntry.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

DnsEndPoint::DnsEndPoint(const string& host, int32 port) {
  SetHost(host);
  SetPort(port);
}

DnsEndPoint::DnsEndPoint(const string& host, int32 port, Sockets::AddressFamily addressFamily) {
  SetHost(host);
  SetPort(port);
  this->addressFamily = addressFamily;
}

SocketAddress DnsEndPoint::Serialize() const {
  throw NotSupportedException(pcf_current_information);
}

void DnsEndPoint::SetHost(const string& host) {
  if (string::IsNullOrEmpty(host))
    throw ArgumentException(pcf_current_information);
  
  IPHostEntry IPHostEntry = Dns::GetHostEntry(this->host);
  this->host = IPHostEntry.HostName;
}

void DnsEndPoint::SetPort(int32 port) {
  if (port < IPEndPoint::MinPort || port > IPEndPoint::MaxPort)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  this->port = port;
}

string DnsEndPoint::ToString() const {
  return string::Format("{0}:{1}", this->host, this->port);
}

