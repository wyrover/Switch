using System;
using System.Net;
using System.Net.Sockets;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class SocketTest {
    [Test]
    public void CatchExecptionWithTimeoutSocketErrorOnReceive() {
      Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
      socket.ReceiveTimeout = 1;
      socket.Bind(new IPEndPoint(IPAddress.Loopback, 8111));
      byte[] bytes = new byte[512];
      try {
        socket.Receive(bytes);
      } catch (SocketException e) {
        Assert.AreEqual(SocketError.TimedOut, e.SocketErrorCode);
      }
      }
    }
  }
