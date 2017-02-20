#include "../../../../Includes/Pcf/System/Net/IPAddress.h"
#include "../../../../Includes/Pcf/System/Net/SocketAddress.h"
#include "../../../../Includes/Pcf/System/BitConverter.h"
#include "../../../../Includes/Pcf/System/Convert.h"
#include "../../../__OS/CoreApi.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

SocketAddress::SocketAddress(Sockets::AddressFamily addressFamily, int32 bufferSize) : bytes(bufferSize) {
  this->bytes[0] = __OS::CoreApi::Socket::AddressFamilyToNative(addressFamily);
  this->bytes[1] = 0;
}

SocketAddress::SocketAddress(const Array<byte>& buffer) : bytes(buffer) {}

Sockets::AddressFamily SocketAddress::GetAddressFamily() const {
  return __OS::CoreApi::Socket::NativeToAddressFamily(this->bytes[0]);
}

string SocketAddress::ToString() const noexcept {
  return string::Format("{0}:{1}:{{{2}}}", this->GetAddressFamily(), this->Size, string::Join(",", this->bytes, 2, this->Size - 2));
}

