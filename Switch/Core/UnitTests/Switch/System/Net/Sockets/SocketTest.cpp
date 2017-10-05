#include <Switch/System/Net/Sockets/Socket.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace TUnit;

namespace SwitchUnitTests {
  class SocketTest : public TestFixture {
  protected:
    void SetUp() override {}
    
    void TearDown() override {}
    
    void CatchExecptionWithTimeoutSocketErrorOnReceive() {
      Socket socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
      socket.ReceiveTimeout = 1;
      socket.Bind(IPEndPoint(IPAddress::Loopback, 8111));
      Array<byte> bytes(512);
      try {
        socket.Receive(bytes);
      } catch(const SocketException& e) {
        Assert::AreEqual(SocketError::TimedOut, e.SocketErrorCode(), _caller);
      }
    }
  };
  
  _test(SocketTest, CatchExecptionWithTimeoutSocketErrorOnReceive)
}
