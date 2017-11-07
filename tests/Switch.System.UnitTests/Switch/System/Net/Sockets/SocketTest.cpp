#include <Switch/System/Net/Sockets/Socket.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

namespace SwitchUnitTests {
  TEST(SockectTest, CatchExecptionWithTimeoutSocketErrorOnReceive) {
    Socket socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
    socket.ReceiveTimeout = 1;
    socket.Bind(IPEndPoint(IPAddress::Loopback, 8111));
    Array<byte> bytes(512);
    try {
      socket.Receive(bytes);
    } catch(const SocketException& e) {
      ASSERT_EQ(SocketError::TimedOut, e.SocketErrorCode());
    }
  }
}
