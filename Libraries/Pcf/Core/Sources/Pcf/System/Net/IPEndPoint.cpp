#include "../../../../Includes/Pcf/System/Net/IPEndPoint.h"
#include "../../../../Includes/Pcf/System/Convert.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

IPEndPoint::IPEndPoint(int64 address, int32 port) {
  SetAddress(IPAddress(address));
  SetPort(port);
}

IPEndPoint::IPEndPoint(const IPAddress& address, int32 port) {
  SetAddress(address);
  SetPort(port);
}

UniquePointer<EndPoint> IPEndPoint::Create(const SocketAddress & socketAddress) const {
  IPEndPoint* endPoint = new IPEndPoint(0, 0);
  
  endPoint->addressFamily = (Sockets::AddressFamily)(Convert::ToInt32(socketAddress[0]) + (Convert::ToInt32(socketAddress[1])<<8));
  endPoint->port = (Convert::ToInt32(socketAddress[2])<<8) + Convert::ToInt32(socketAddress[3]);
  endPoint->address = IPAddress(socketAddress[4], socketAddress[5], socketAddress[6], socketAddress[7]);
  if (endPoint->addressFamily != Sockets::AddressFamily::InterNetwork)
    endPoint->address.ScopeId = (Convert::ToInt64(socketAddress[8])<<56) + (Convert::ToInt64(socketAddress[9])<<48) + (Convert::ToInt64(socketAddress[10])<<40) + (Convert::ToInt64(socketAddress[11])<<32) + (Convert::ToInt64(socketAddress[12])<<24) + (Convert::ToInt64(socketAddress[13])<<16) + (Convert::ToInt64(socketAddress[14])<<8) + Convert::ToInt64(socketAddress[15]);
  return endPoint;
}

SocketAddress IPEndPoint::Serialize() const {
  Array<byte> addressBytes = this->Address().GetAddressBytes();
  uint16 port =  IPAddress::HostToNetworkOrder(Convert::ToUInt16(this->port));
  SocketAddress socketAddress(this->addressFamily, addressBytes.Length+8+4);
  socketAddress[2] = Convert::ToByte((port&0x00FF)>>0);
  socketAddress[3] = Convert::ToByte((port&0xFF00)>>8);
  int32 index = 4;
  for (byte quadPartAddress : addressBytes)
    socketAddress[index++] = quadPartAddress;

  if (AddressFamily != Sockets::AddressFamily::InterNetwork) {
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0xFF00000000000000LL >> 56));
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0x00FF000000000000LL) >> 48);
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0x0000FF0000000000LL) >> 40);
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0x000000FF00000000LL) >> 32);
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0x00000000FF000000LL) >> 24);
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0x0000000000FF0000LL) >> 16);
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0x000000000000FF00LL) >>  8);
    socketAddress[index++] = Convert::ToByte((Address().ScopeId & 0x00000000000000FFLL) >>  0);
  }
  return socketAddress;
}

void IPEndPoint::SetAddress(const IPAddress &address) {
  this->addressFamily = address.AddressFamily;
  this->address = address;
}

void IPEndPoint::SetPort(int32 port) {
  if (port < MinPort() || port > MaxPort())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  this->port = port;
}

string IPEndPoint::ToString() const {
  return string::Format("{0}:{1}", this->address, this->port);
}

