#include "../../../../Includes/Pcf/System/Net/SocketAddress.h"
#include "../../../../Includes/Pcf/System/Convert.h"
#include "../../Os/Socket.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

SocketAddress::SocketAddress(Sockets::AddressFamily addressFamily) : bytes(DefaultBufferSize) {
  int16 family = Convert::ToInt16(Os::Socket::AddressFamilyToNative(addressFamily));
  bytes[0] = Convert::ToByte(family & 0x00FF);
  bytes[1] = Convert::ToByte((family & 0xFF00) >> 8);
}

SocketAddress::SocketAddress(Sockets::AddressFamily addressFamily, int32 bufferSize) : bytes(bufferSize) {
  int16 family = Convert::ToInt16(Os::Socket::AddressFamilyToNative(addressFamily));
  bytes[0] = Convert::ToByte(family & 0x00FF);
  bytes[1] = Convert::ToByte((family & 0xFF00) >> 8);
}

SocketAddress::SocketAddress(byte* buffer, int32 bufferSize) : bytes(bufferSize) {
  if (buffer == null)
    throw ArgumentNullException(pcf_current_information);
  
  for (int32 index = 0; index < bufferSize; index++)
    bytes[index] = buffer[index];
}

Sockets::AddressFamily SocketAddress::GetAddressFamily() const {
  return Sockets::AddressFamily(Os::Socket::NativeToAddressFamily(int32(bytes[0]) + (int32(bytes[1]) << 8)));
}

string SocketAddress::ToString() const {
  string str = Enum<Sockets::AddressFamily>(GetAddressFamily()) + ":" + Size + ":{";
  
  for (int32 index = 2; index < Size; index++) {
    str += Byte(bytes[index]).ToString();
    if (index < Size-1)
      str += ", ";
  }
  
  str += "}";
  return str;
}

