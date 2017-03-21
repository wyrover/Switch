#include "TestUtils.h"
#include <Pcf/System/Net/Sockets/Socket.h>
#include <Pcf/System/Net/Dns.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Buffer.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Threading;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {

class Socket : public testing::Test {
  public :
  void SetUp() {    
    mLastException = sp<Exception>::Null();
  }
  
  void TearDown() {
    if (!mLastException.IsNull())
      mLastException.Reset();
  }
  
protected:
  static IPAddress GetIPAddressFromServer(const string& server) {
    return Dns::GetHostAddresses(server)[0];
  }
  
  static string BuildStringRequest(const IPAddress& ipAddress) {
    return string::Format("GET / HTTP/1.1\r\nHost: {0}\r\nConnection: Close\r\n\r\n", ipAddress);
  }

  static Array<byte> BuildHttpRequest() {
    return Text::Encoding::UTF8()->GetBytes(BuildStringRequest(GetIPAddressFromServer("www.google.com")));
  }
  
  static Array<byte> BuildHttpRequest(const IPAddress& ipAddress) {
    return Text::Encoding::UTF8()->GetBytes(BuildStringRequest(ipAddress));
  }
  
  static void ReceiveThread(Object& data) {
    mResponse = "";
    Sockets::Socket& receivingSocket = as<Sockets::Socket>(data);
    Array<byte> response(256);
    
    try {
      mDataLength = receivingSocket.Receive(response);
    } catch (const Sockets::SocketException& ex) {
      mLastException = sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(ex);
    } catch (ObjectClosedException& ex) {
      mLastException = sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(ex);
    }
    
    for (Int32 index = 0; index < mDataLength; index++) {
      mResponse += Char(Convert::ToChar(response[index])).ToString();
    }
  }
  
  static void ReceiveFromThread(Object& data) {
    mResponse = "";
    Sockets::Socket& receivingSocket = as<Sockets::Socket>(data);
    Array<byte> response(256);
    
    try {
      mDataLength = receivingSocket.ReceiveFrom(response, mFromEndPoint);
    } catch (Sockets::SocketException& ex) {
      mLastException = sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(ex);
    } catch (ObjectClosedException& ex) {
      mLastException = sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(ex);
    }
    
    for (Int32 index = 0; index < mDataLength; index++) {
      mResponse += Char(Convert::ToChar(response[index])).ToString();
    }
  }
  
  static void ReceiveFromUsingNativeArrayThread(Object& data);
  
  static Int32 mDataLength;
  static string mResponse;
  static IPEndPoint mFromEndPoint;
  static const int32_t mBufferLength;
  
  static sp<Exception> mLastException;
};

Int32 Socket::mDataLength = 0;
string Socket::mResponse = "";
IPEndPoint Socket::mFromEndPoint(0, 0);
const int32_t Socket::mBufferLength = 256;

sp<Exception> Socket::mLastException = sp<Exception>::Null();

void Socket::ReceiveFromUsingNativeArrayThread(Object& data) {
  mResponse = "";
  Sockets::Socket& receivingSocket = as<Sockets::Socket>(data);
  Array<byte> response(mBufferLength);
  mDataLength = receivingSocket.ReceiveFrom(response, mFromEndPoint);
  for (Int32 index = 0; index < mDataLength; index++)
  {
    mResponse += Char(Convert::ToChar(Byte(response[index]))).ToString();
  }
}

TEST_F(Socket, ConnectTest) {
  sp<Sockets::Socket> mySocket1;
  mySocket1 = sp<Sockets::Socket>::Create(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket1->Connect(new IPEndPoint(IPAddress(209, 164, 60, 154), 80));
}

TEST_F(Socket, SendTest_ArrayOfBytes) {
  IPAddress address = GetIPAddressFromServer("www.google.com");
  Array<byte> request = BuildHttpRequest(address);
  
  sp<Sockets::Socket> mySocket1 = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket1->Connect(new IPEndPoint(address, 80));
  EXPECT_EQ(mySocket1->Send(request), request.Length);
}

TEST_F(Socket, Sendest_NativeArray) {
  Array<byte> request(mBufferLength);
  int32 requestLength = 0;
  IPAddress address;
  BuildHttpRequest(request, requestLength, address);
  sp<Sockets::Socket> mySocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket->Connect(new IPEndPoint(address, 80));
  ASSERT_EQ(mySocket->Send(request, mBufferLength, 0, requestLength, Sockets::SocketFlags::None), requestLength);
}

TEST_F(Socket, ReceiveTest_ArrayOfBytes) {
  Array<byte> request;
  IPAddress address;
  BuildHttpRequest(request, address);
  
  sp<Sockets::Socket> mySocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket->Connect(new IPEndPoint(address, 80));
  mySocket->Send(request);
  
  string responseStr;
  Array<byte> response(256);
  int32 nbRead = 0;
  do {
    nbRead = mySocket->Receive(response);
    for (int32 index = 0; index < nbRead; index++)
      responseStr += Char(Convert::ToChar(response[index])).ToString();
  } while (nbRead > 0);
}

TEST_F(Socket, ReceiveTest_NativeArray) {
  uint8_t request[mBufferLength] = {0};
  int32 requestLength = 0;
  IPAddress address;
  BuildHttpRequest(request, requestLength, address);
  sp<Sockets::Socket> mySocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket->Connect(new IPEndPoint(address, 80));
  ASSERT_EQ(mySocket->Send(request, mBufferLength, 0, requestLength, Sockets::SocketFlags::None), requestLength);
  uint8_t response[mBufferLength] = {0};
  int32 nbRead = 0;
  do {
    nbRead = mySocket->Receive(response, mBufferLength);
  } while (nbRead > 0);
}

//In Macos there are no error when calling receive after shutdown it always wait
/*
TEST_F(Socket, ReceiveTest_ReceiveAfterShutdown) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback(), ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveThread);
  
  receivingSocket->Shutdown(SocketShutdown::Both);
  
  receivingThread.Start(receivingSocket.ToObject());
  
  receivingThread.Join();

  //In Linux there are no error when calling receive after shutdown it return 0
  ASSERT_FALSE(sp<Exception>::IsNullOrEmpty(mLastException));
  Console::WriteLine("Error = " + mLastException->GetError());
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_TRUE((sp<Sockets::SocketException>(mLastException))->GetSocketError() == SocketError::Shutdown);
}
*/

//In linux close doesn't allways unblock recv because of race condition on the reuse of the socket
//So it's better to call shutdown before close to unblock the thread
/*
TEST_F(Socket, ReceiveTest_ReceiveBeforeClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback(), TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveFromThread);
  receivingThread.Start(receivingSocket.ToObject());
  
  while (!receivingThread.IsAlive())
    Thread::Sleep(100);
  Thread::Sleep(100);
  
  receivingSocket->Close();
  
  receivingThread.Join();
  
  
  ASSERT_FALSE(sp<Exception>::IsNullOrEmpty(mLastException));
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_EQ((sp<Sockets::SocketException>(mLastException))->GetSocketError().ToInt32(), SocketError::Interrupted);
}
*/

TEST_F(Socket, ReceiveTest_ReceiveBeforeShutdownAndClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveThread);
  receivingThread.Start(receivingSocket.ToObject());
  while (!receivingThread.IsAlive())
      Thread::Sleep(10);
    Thread::Sleep(10);
  receivingSocket->Shutdown(Sockets::SocketShutdown::Both);
  receivingSocket->Close();
  receivingThread.Join();
}

TEST_F(Socket, ReceiveTest_ReceiveAfterClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveThread);
  receivingSocket->Close();
  receivingThread.Start(receivingSocket.ToObject());
  receivingThread.Join();
  ASSERT_FALSE(mLastException.IsNull());
  ASSERT_TRUE(is<ObjectClosedException>(*mLastException));
}

TEST_F(Socket, SendToTest_ArrayOfBytes) {
  sp<Sockets::Socket> socket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), 80);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  EXPECT_EQ(socket->SendTo(data, endPoint), data.Length);
}

TEST_F(Socket, SendToTest_NativeArray) {
  sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), 80);
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  EXPECT_EQ(socket->SendTo(buffer, mBufferLength, messageStr.Length(), Sockets::SocketFlags::None, endPoint), messageStr.Length());
}

TEST_F(Socket, ReceiveFromTest_ArrayOfBytes) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveFromThread);
  receivingThread.Start(receivingSocket.ToObject());
  // Send data to loopback address
  sp<Sockets::Socket> sendingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  EXPECT_EQ(sendingSocket->SendTo(data, endPoint), data.Length);
  receivingThread.Join();
  ASSERT_EQ(data.Length, mDataLength);
  ASSERT_EQ(dataStr, mResponse);
  ASSERT_EQ(IPAddress::Loopback, mFromEndPoint.Address);
  ASSERT_GT(mFromEndPoint.Port, 0);
}

TEST_F(Socket, ReceiveFromTest_NativeArray) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveFromUsingNativeArrayThread);
  receivingThread.Start(receivingSocket.ToObject());
  // Send data to loopback address
  sp<Sockets::Socket> sendingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  EXPECT_EQ(sendingSocket->SendTo(data, endPoint), data.Length);
  receivingThread.Join();
  ASSERT_EQ(data.Length, mDataLength);
  ASSERT_EQ(dataStr, mResponse);
  ASSERT_EQ(IPAddress::Loopback, mFromEndPoint.Address);
  ASSERT_GT(mFromEndPoint.Port, 0);
}

//In Macos there are no error when calling receive after shutdown it always wait
/*
TEST_F(Socket, ReceiveFromTest_ReceiveFromAfterShutdown)
{
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback(), ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveFromThread);
  
  receivingSocket->Shutdown(SocketShutdown::Both);
  
  receivingThread.Start(receivingSocket.ToObject());
  
  receivingThread.Join();
  
  //There are no exception in linux when shutdown during recv
  ASSERT_FALSE(sp<Exception>::IsNullOrEmpty(mLastException));
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_TRUE((sp<Sockets::SocketException>(mLastException))->GetSocketError() == SocketError::Shutdown);
}
*/

//In linux close doesn't allways unblock recv because of race condition on the reuse of the socket
//So it's better to call shutdown before close to unblock the thread
/*
TEST_F(Socket, ReceiveFromTest_ReceiveFromBeforeClose)
{
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback(), TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveFromThread);
  receivingThread.Start(receivingSocket.ToObject());
  
  while (!receivingThread.IsAlive())
    Thread::Sleep(100);
  Thread::Sleep(100);
  
  receivingSocket->Close();
  
  receivingThread.Join();
  
  ASSERT_FALSE(sp<Exception>::IsNullOrEmpty(mLastException));
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_TRUE((sp<Sockets::SocketException>(mLastException))->GetSocketError() == SocketError::Interrupted);
}
*/
TEST_F(Socket, ReceiveFromTest_ReceiveFromBeforeShutdownAndClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveFromThread);
  receivingThread.Start(receivingSocket.ToObject());
  Thread::Sleep(10);
  receivingSocket->Shutdown(Sockets::SocketShutdown::Both);
  receivingSocket->Close();
  receivingThread.Join();
}

TEST_F(Socket, ReceiveFromTest_ReceiveFromAfterClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveFromThread);
  receivingSocket->Close();
  receivingThread.Start(receivingSocket.ToObject());
  receivingThread.Join();
  ASSERT_FALSE(mLastException.IsNull());
  ASSERT_TRUE(is<ObjectClosedException>(*mLastException));
}

TEST_F(Socket, SelectTrivialIntegrationTest) {
  sp<Sockets::Socket> socket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  List<sp<Sockets::Socket>> checkRead;
  checkRead.Add(socket);
  List<sp<Sockets::Socket>> checkWrite;
  checkWrite.Add(socket);
  List<sp<Sockets::Socket>> checkError;
  checkError.Add(socket);
  EXPECT_TRUE(checkRead.Count == 1 && checkWrite.Count == 1 && checkError.Count == 1);
  Sockets::Socket::Select(checkRead, checkWrite, checkError, 0);
  ASSERT_TRUE(checkRead.Count == 0 && checkWrite.Count == 0 && checkError.Count == 0);
  socket->Close();
}

TEST_F(Socket, DISABLED_SelectAndReceive) {
  sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  sp<Sockets::Socket> socket2 = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint2(IPAddress::Loopback, TestUtils::mPort + 1);
  socket2->Bind(new IPEndPoint(endPoint2));
  socket2->Listen(64);
  sp<Sockets::Socket> sendingSocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  sendingSocket->SendTo(data, endPoint);
  List<sp<Sockets::Socket>> checkRead;
  checkRead.Add(socket);
  checkRead.Add(socket2);
  List<sp<Sockets::Socket>> checkWrite;
  checkWrite.Add(socket);
  List<sp<Sockets::Socket>> checkError;
  checkError.Add(socket);
  EXPECT_TRUE(checkRead.Count == 2 && checkWrite.Count == 1 && checkError.Count == 1);
  Sockets::Socket::Select(checkRead, checkWrite, checkError, -1);
  ASSERT_TRUE(checkRead.Count == 1 && checkWrite.Count == 0 && checkError.Count == 0);
  if (checkRead.Count > 0) {
    Array<byte> buffer(data.Length);
    int32 rcvSize = checkRead[0]->Receive(buffer);
    string receivedMessage = "";
    for (byte b : buffer)
      receivedMessage += Char(Convert::ToChar(b)).ToString();

    ASSERT_TRUE(dataStr.Equals(receivedMessage));
    EXPECT_EQ(dataStr.Length(), rcvSize);
  }

  socket->Close();
  socket2->Close();
  sendingSocket->Close();
}

TEST_F(Socket, PollAndNoReceiveIntegrationTest) {
  sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  ASSERT_FALSE(socket->Poll(0, Sockets::SelectMode::SelectRead));
  socket->Close();
}

TEST_F(Socket, PollAndReceiveIntegrationTest) {
  sp<Sockets::Socket> socket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  sp<Sockets::Socket> sendingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  sendingSocket->SendTo(data, endPoint);
  ASSERT_TRUE(socket->Poll(-1, Sockets::SelectMode::SelectRead));
  socket->Close();
  sendingSocket->Close();
}

TEST_F(Socket, EnableBroadcastTest) {
  sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  try {
    socket->SetEnableBroadcast(true);
  } catch (Sockets::SocketException& ex) {
    mLastException = sp<Exception>::Create(ex);
  }
  ASSERT_TRUE(mLastException.IsNull());
}

TEST_F(Socket, ConstructorTest_TCP) { 
  sp<Sockets::Socket> mySocket1;
  mySocket1 = sp<Sockets::Socket>::Create(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  EXPECT_EQ(mySocket1->AddressFamily(), Sockets::AddressFamily::InterNetwork);
  EXPECT_EQ(mySocket1->SocketType(), Sockets::SocketType::Stream);
  EXPECT_EQ(mySocket1->ProtocolType(), Sockets::ProtocolType::Tcp);
}

TEST_F(Socket, ConstructorTest_UDP)
{
  sp<Sockets::Socket> mySocket2;
  mySocket2 = sp<Sockets::Socket>::Create(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  EXPECT_EQ(mySocket2->AddressFamily(), Sockets::AddressFamily::InterNetwork);
  EXPECT_EQ(mySocket2->SocketType(), Sockets::SocketType::Dgram);
  EXPECT_EQ(mySocket2->ProtocolType(), Sockets::ProtocolType::Udp);
}

}
