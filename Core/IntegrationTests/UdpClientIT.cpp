#include "TestUtils.h"
#include <Pcf/System/Net/Sockets/UdpClient.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Buffer.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Threading;
using namespace TUnit;

namespace {

class UdpClient : public testing::Test {

protected:
  void CheckUdpSocket(const sp<Sockets::Socket>& socket) {
    CheckUdpSocket(socket, Sockets::AddressFamily::InterNetwork);
  }

  void CheckUdpSocket(const sp<Sockets::Socket>& socket, Sockets::AddressFamily addressFamily) {
    ASSERT_EQ(socket->AddressFamily(), addressFamily);
    ASSERT_EQ(socket->SocketType(), Sockets::SocketType::Dgram);
    ASSERT_EQ(socket->ProtocolType(), Sockets::ProtocolType::Udp);
  }

  static void ReceiveThread(Object& data) {
    IncomingData& incomingData = as<IncomingData>(data);
    Array<byte> response(256);
    incomingData.mDataLength = incomingData.mUdpClient->Receive(response, incomingData.mFromEndPoint);
    for (Int32 index = 0; index < incomingData.mDataLength; index++)
      incomingData.mResponse += Char(Convert::ToChar(response[index])).ToString();
  }

  static void ReceiveUsingNativeArrayThread(Object& data);

  class IncomingData : public object {
  public:
    explicit IncomingData(const sp<Sockets::UdpClient>& client) : mUdpClient(client), mDataLength(0), mResponse(""), mFromEndPoint(0, 0) {}

    sp<Sockets::UdpClient> mUdpClient;
    int32 mDataLength;
    string mResponse;
    IPEndPoint mFromEndPoint;
  };

  void DoReceiveTest(Boolean nativeArray);

  static const int32_t mBufferLength;
};

const int32_t UdpClient::mBufferLength = 256;

void UdpClient::ReceiveUsingNativeArrayThread(Object& data) {
  IncomingData& incomingData = as<IncomingData>(data);
  byte response[mBufferLength] = {0};
  incomingData.mDataLength = incomingData.mUdpClient->Receive(response, mBufferLength, incomingData.mFromEndPoint);
  for (int32 index = 0; index < incomingData.mDataLength; index++)
    incomingData.mResponse += Char(Convert::ToChar(Byte(response[index]))).ToString();
}

void UdpClient::DoReceiveTest(Boolean nativeArray) {
  // Create an endpoint on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, TestUtils::mPort);
  sp<Sockets::UdpClient> receivingClient = new Sockets::UdpClient(new IPEndPoint(endPoint));

  IncomingData incomingData(receivingClient);
  sp<Thread> receivingThread;
  if (nativeArray) {
    receivingThread = sp<Thread>::Create((ParameterizedThreadStart)ReceiveUsingNativeArrayThread);
  } else { 
    receivingThread = sp<Thread>::Create((ParameterizedThreadStart)ReceiveThread);
  }
  
  receivingThread->Start(incomingData);

  // Send data to loopback address
  sp<Sockets::UdpClient> sendingClient = new Sockets::UdpClient();
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  EXPECT_EQ(sendingClient->Send(data, endPoint), data.Length);

  receivingThread->Join();

  ASSERT_EQ(data.Length, incomingData.mDataLength);
  ASSERT_EQ(dataStr, incomingData.mResponse);
  ASSERT_EQ(IPAddress::Loopback, incomingData.mFromEndPoint.Address);
  ASSERT_GT(incomingData.mFromEndPoint.Port, 0);
}

TEST_F(UdpClient, CtorTest) {
  Sockets::UdpClient client;
  CheckUdpSocket(client.GetClient());
  ASSERT_FALSE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
  client.Close();
  ASSERT_FALSE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
}

TEST_F(UdpClient, CtorTest_AddressFamily) {
  Sockets::AddressFamily family = Sockets::AddressFamily::InterNetworkV6;
  Sockets::UdpClient client(family);
  CheckUdpSocket(client.GetClient(), Sockets::AddressFamily::InterNetworkV6);
  ASSERT_FALSE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
  client.Close();
  ASSERT_FALSE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
}

TEST_F(UdpClient, CtorTest_Port)
{
  int32 port = TestUtils::mPort;
  Sockets::UdpClient client(port);
  CheckUdpSocket(client.GetClient());
  ASSERT_TRUE(client.GetClient()->IsBound());
  ASSERT_FALSE(client.GetConnected());
  client.Close();
  ASSERT_FALSE(client.GetClient()->IsBound());
}

TEST_F(UdpClient, CtorTest_EndPoint) {
  IPEndPoint* endPoint = new IPEndPoint(TestUtils::GetLocalIPAddress(), TestUtils::mPort);
  Sockets::UdpClient client(endPoint);
  CheckUdpSocket(client.GetClient());
  ASSERT_TRUE(client.GetClient()->IsBound());
  ASSERT_FALSE(client.GetConnected());
  client.Close();
  ASSERT_FALSE(client.GetClient()->IsBound());
}

TEST_F(UdpClient, CtorTest_PortAndAddressFamily) {
  Sockets::UdpClient client(TestUtils::mPort, Sockets::AddressFamily::InterNetwork);
  CheckUdpSocket(client.GetClient());
  ASSERT_TRUE(client.GetClient()->IsBound());
  ASSERT_FALSE(client.GetConnected());
  client.Close();
  ASSERT_FALSE(client.GetClient()->IsBound());
}

TEST_F(UdpClient, CtorTest_HostnameAndPort) {
  Sockets::UdpClient client(TestUtils::mRemoteHost, TestUtils::mPort);
  CheckUdpSocket(client.GetClient());
  ASSERT_TRUE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
  client.Close();
  ASSERT_FALSE(client.GetConnected());
}

TEST_F(UdpClient, ConnectTest_EndPoint) {
  Sockets::UdpClient client;
  IPEndPoint* endPoint = new IPEndPoint(TestUtils::GetRemoteIPAddress(), TestUtils::mPort);
  client.Connect(endPoint);
  ASSERT_TRUE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
  client.Close();
  ASSERT_FALSE(client.GetConnected());
}

TEST_F(UdpClient, ConnectTest_IPAddressAndPort) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::GetRemoteIPAddress(), TestUtils::mPort);
  ASSERT_TRUE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
  client.Close();
  ASSERT_FALSE(client.GetConnected());
}

TEST_F(UdpClient, ConnectTest_HostnameAndPort) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::mRemoteHost, TestUtils::mPort);
  ASSERT_TRUE(client.GetConnected());
  ASSERT_FALSE(client.GetClient()->IsBound());
  client.Close();
  ASSERT_FALSE(client.GetConnected());
}

TEST_F(UdpClient, SendTest) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::mRemoteHost, TestUtils::mPort);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_EQ(data.Length, client.Send(data));
}

TEST_F(UdpClient, SendTest_NativeArray) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::mRemoteHost, TestUtils::mPort);
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  ASSERT_EQ(messageStr.Length(), client.Send(buffer, messageStr.Length()));
}

TEST_F(UdpClient, SendTest_NotConnected) {
  Sockets::UdpClient client;
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_THROW(client.Send(data), Sockets::SocketException);
}

TEST_F(UdpClient, SendTest_NotConnected_NativeArray) {
  Sockets::UdpClient client;
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  ASSERT_THROW(client.Send(buffer, messageStr.Length()), Sockets::SocketException);
}

TEST_F(UdpClient, SendTest_EndPoint) {
  Sockets::UdpClient client;
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), TestUtils::mPort);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_EQ(data.Length, client.Send(data, endPoint));
}

TEST_F(UdpClient, SendTest_EndPoint_NativeArray) {
  Sockets::UdpClient client;
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), TestUtils::mPort);
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  ASSERT_EQ(messageStr.Length(), client.Send(buffer, messageStr.Length(), endPoint));
}

TEST_F(UdpClient, SendTest_EndPointBroadcast) {
  Sockets::UdpClient client;
  IPEndPoint endPoint(IPAddress::Broadcast, TestUtils::mPort);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_EQ(data.Length, client.Send(data, endPoint));
}

TEST_F(UdpClient, SendTest_EndPointLoopback) {
  Sockets::UdpClient client;
  IPEndPoint endPoint(IPAddress::Loopback, TestUtils::mPort);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_EQ(data.Length, client.Send(data, endPoint));
}

TEST_F(UdpClient, SendTest_EndPointConnected) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::mRemoteHost, TestUtils::mPort);
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), TestUtils::mPort);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_THROW(client.Send(data, endPoint), InvalidOperationException);
}

TEST_F(UdpClient, SendTest_EndPointConnected_NativeArray) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::mRemoteHost, TestUtils::mPort);
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), TestUtils::mPort);
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  ASSERT_THROW(client.Send(buffer, messageStr.Length(), endPoint), InvalidOperationException);
}

TEST_F(UdpClient, SendTest_Hostname) {
  Sockets::UdpClient client;
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_EQ(data.Length, client.Send(data, TestUtils::mRemoteHost, TestUtils::mPort));
}

TEST_F(UdpClient, SendTest_Hostname_NativeArray) {
  Sockets::UdpClient client;
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  ASSERT_EQ(messageStr.Length(), client.Send(buffer, messageStr.Length(), TestUtils::mRemoteHost, TestUtils::mPort));
}

TEST_F(UdpClient, SendTest_HostnameBroadcast) {
  Sockets::UdpClient client;
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_EQ(data.Length, client.Send(data, "255.255.255.255", 12000));
}

TEST_F(UdpClient, SendTest_HostnameBroadcast_NativeArray) {
  Sockets::UdpClient client;
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  ASSERT_EQ(messageStr.Length(), client.Send(buffer, messageStr.Length(), "255.255.255.255", 12000));
}

TEST_F(UdpClient, SendTest_HostnameConnected) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::mRemoteHost, TestUtils::mPort);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  ASSERT_THROW(client.Send(data, TestUtils::mRemoteHost, TestUtils::mPort), InvalidOperationException);
}

TEST_F(UdpClient, SendTest_HostnameConnected_NativeArray) {
  Sockets::UdpClient client;
  client.Connect(TestUtils::mRemoteHost, TestUtils::mPort);
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  ASSERT_THROW(client.Send(buffer, messageStr.Length(), TestUtils::mRemoteHost, TestUtils::mPort), InvalidOperationException);
}

TEST_F(UdpClient, ReceiveTest) {
  DoReceiveTest(false);
}

TEST_F(UdpClient, ReceiveTest_NativeArray) {
  DoReceiveTest(true);
}

TEST_F(UdpClient, SendReceiveTest_SameClient) {
  // Create an endpoint on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, TestUtils::mPort);
  sp<Sockets::UdpClient> client = new Sockets::UdpClient(new IPEndPoint(endPoint));

  IncomingData incomingData(client);
  Thread receivingThread((ParameterizedThreadStart)ReceiveThread);
  receivingThread.Start(incomingData);

  // Send data to loopback address
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  EXPECT_EQ(client->Send(data, endPoint), data.Length);

  receivingThread.Join();

  ASSERT_EQ(data.Length, incomingData.mDataLength);
  ASSERT_EQ(dataStr, incomingData.mResponse);
  ASSERT_EQ(IPAddress::Loopback, incomingData.mFromEndPoint.Address);
  ASSERT_GT(incomingData.mFromEndPoint.Port, 0);
}

}
