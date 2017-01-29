#include "TestUtils.h"
#include <Pcf/System/Net/Dns.h>

using namespace System;
using namespace System::Net;

string TestUtils::mRemoteHost = "belgxtbuild-mac";
int32 TestUtils::mPort = 52020;

IPAddress TestUtils::GetLocalIPAddress() {
  return GetIPAddress(Dns::GetHostName());
}

IPAddress TestUtils::GetRemoteIPAddress() {
  return GetIPAddress(mRemoteHost);
}

IPAddress TestUtils::GetIPAddress(string hostname) {
  return Dns::GetHostAddresses(hostname)[0];
}

Array<byte> TestUtils::GetDataArray(string data) {
  Array<byte> bytes(data.Length());
  for (int32 index = 0; index < data.Length(); index++)
    bytes[index] = Convert::ToByte(Char(data[index]));
  return bytes;
}

