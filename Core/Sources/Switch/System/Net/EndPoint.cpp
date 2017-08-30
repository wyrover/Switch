#include "../../../../Includes/Pcf/System/Net/EndPoint.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

refptr<EndPoint> EndPoint::Create(const SocketAddress &) const {
  throw NotSupportedException(pcf_current_information);
}

string EndPoint::ToString() const {
  return Enum<Sockets::AddressFamily>::ToString(this->addressFamily);
}

SocketAddress EndPoint::Serialize() const {
  return SocketAddress(this->addressFamily, 2);
}

