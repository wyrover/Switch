#include <Pcf/System/Net/Sockets.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace TUnit;

namespace PcfUnitTests {
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
        Assert::AreEqual(SocketError::TimedOut, e.SocketErrorCode(), pcf_current_information);
      }
    }
  };
  
  pcf_test(SocketTest, CatchExecptionWithTimeoutSocketErrorOnReceive)
}
