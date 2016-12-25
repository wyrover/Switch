#include "TestUtils.h"
#include <Pcf/System/Net/SocketAddress.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace TUnit;

TEST(SocketAddress, CtorTest) {
  uint8_t buffer[16] = {2, 0, 42, 248, 172, 16, 10, 30, 0, 0, 0, 0, 0, 0, 0, 0};
  SocketAddress address(buffer, 16);
  ASSERT_EQ(address.ToString(), "InterNetwork:16:{42, 248, 172, 16, 10, 30, 0, 0, 0, 0, 0, 0, 0, 0}");
}

