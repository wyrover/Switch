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
    mLastException = Sp<Exception>::Null();
  }
  
  void TearDown() {
    if (!mLastException.IsNull())
      mLastException.Reset();
  }
  
protected:
  static void BuildStringRequest(string& request, IPAddress& ipAddress) {
    string server = "www.google.com";
    Array<IPAddress> hostAddresses = Dns::GetHostAddresses(server);
    ipAddress = hostAddresses[0];
    request = "GET / HTTP/1.1\r\nHost: " + ipAddress + "\r\nConnection: Close\r\n\r\n";
  }
  
  static void BuildHttpRequest(uint8_t* request, int32& requestLength, IPAddress& ipAddress) {
    string requestStr;
    BuildStringRequest(requestStr, ipAddress);
    ASSERT_LT(requestStr.Length(), mBufferLength);
    Buffer::BlockCopy(IntPtr((void*)requestStr.ToCCharArray().Data()), requestStr.Length(), 0, request, mBufferLength, 0, requestStr.Length());
    requestLength = requestStr.Length();
  }
  
  static void BuildHttpRequest(Array<byte>& request, IPAddress& ipAddress) {
    string requestStr;
    BuildStringRequest(requestStr, ipAddress);
    Array<byte>::Resize(request, requestStr.Length());
    
    for (Int32 index= 0; index < requestStr.Length(); index++)
      request[index] = Convert::ToByte(Char(requestStr[index]));
  }
  
  static void ReceiveThread(Object& data) {
    mResponse = "";
    Sockets::Socket& receivingSocket = as<Sockets::Socket>(data);
    Array<byte> response(256);
    
    try {
      mDataLength = receivingSocket.Receive(response);
    } catch (const Sockets::SocketException& ex) {
      mLastException = Sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(ex);
    } catch (ObjectClosedException& ex) {
      mLastException = Sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(ex);
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
      mLastException = Sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(ex);
    } catch (ObjectClosedException& ex) {
      mLastException = Sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(ex);
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
  
  static Sp<Exception> mLastException;
};

Int32 Socket::mDataLength = 0;
string Socket::mResponse = "";
IPEndPoint Socket::mFromEndPoint(0, 0);
const int32_t Socket::mBufferLength = 256;

Sp<Exception> Socket::mLastException = Sp<Exception>::Null();

void Socket::ReceiveFromUsingNativeArrayThread(Object& data) {
  mResponse = "";
  Sockets::Socket& receivingSocket = as<Sockets::Socket>(data);
  uint8_t response[mBufferLength] = {0};
  mDataLength = receivingSocket.ReceiveFrom(response, mBufferLength, mFromEndPoint);
  for (Int32 index = 0; index < mDataLength; index++)
  {
    mResponse += Char(Convert::ToChar(Byte(response[index]))).ToString();
  }
}

TEST_F(Socket, ConnectTest) {
  Sp<Sockets::Socket> mySocket1;
  mySocket1 = Sp<Sockets::Socket>::Create(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket1->Connect(new IPEndPoint(IPAddress(209, 164, 60, 154), 80));
}

TEST_F(Socket, SendTest_ArrayOfBytes) {
  Array<byte> request;
  IPAddress address;
  BuildHttpRequest(request, address);
  
  Sp<Sockets::Socket> mySocket1 = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket1->Connect(new IPEndPoint(address, 80));
  EXPECT_EQ(mySocket1->Send(request), request.Length);
}

TEST_F(Socket, Sendest_NativeArray) {
  uint8_t request[mBufferLength] = {0};
  int32 requestLength = 0;
  IPAddress address;
  BuildHttpRequest(request, requestLength, address);
  Sp<Sockets::Socket> mySocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  mySocket->Connect(new IPEndPoint(address, 80));
  ASSERT_EQ(mySocket->Send(request, mBufferLength, 0, requestLength, Sockets::SocketFlags::None), requestLength);
}

TEST_F(Socket, ReceiveTest_ArrayOfBytes) {
  Array<byte> request;
  IPAddress address;
  BuildHttpRequest(request, address);
  
  Sp<Sockets::Socket> mySocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
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
  Sp<Sockets::Socket> mySocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
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
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveThread);
  
  receivingSocket->Shutdown(SocketShutdown::Both);
  
  receivingThread.Start(receivingSocket.ToObject());
  
  receivingThread.Join();

  //In Linux there are no error when calling receive after shutdown it return 0
  ASSERT_FALSE(Sp<Exception>::IsNullOrEmpty(mLastException));
  Console::WriteLine("Error = " + mLastException->GetError());
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_TRUE((Sp<Sockets::SocketException>(mLastException))->GetSocketError() == SocketError::Shutdown);
}
*/

//In linux close doesn't allways unblock recv because of race condition on the reuse of the socket
//So it's better to call shutdown before close to unblock the thread
/*
TEST_F(Socket, ReceiveTest_ReceiveBeforeClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback(), TestUtils::mPort);
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveFromThread);
  receivingThread.Start(receivingSocket.ToObject());
  
  while (!receivingThread.IsAlive())
    Thread::Sleep(100);
  Thread::Sleep(100);
  
  receivingSocket->Close();
  
  receivingThread.Join();
  
  
  ASSERT_FALSE(Sp<Exception>::IsNullOrEmpty(mLastException));
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_EQ((Sp<Sockets::SocketException>(mLastException))->GetSocketError().ToInt32(), SocketError::Interrupted);
}
*/

TEST_F(Socket, ReceiveTest_ReceiveBeforeShutdownAndClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
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
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveThread);
  receivingSocket->Close();
  receivingThread.Start(receivingSocket.ToObject());
  receivingThread.Join();
  ASSERT_FALSE(mLastException.IsNull());
  ASSERT_TRUE(is<ObjectClosedException>(*mLastException));
}

TEST_F(Socket, SendToTest_ArrayOfBytes) {
  Sp<Sockets::Socket> socket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), 80);
  Array<byte> data = TestUtils::GetDataArray("Hello World!");
  EXPECT_EQ(socket->SendTo(data, endPoint), data.Length);
}

TEST_F(Socket, SendToTest_NativeArray) {
  Sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(TestUtils::GetRemoteIPAddress(), 80);
  string messageStr("Hello World!");
  uint8_t buffer[mBufferLength] = {0};
  Buffer::BlockCopy(IntPtr((void*)messageStr.ToCCharArray().Data()), messageStr.Length(), 0, buffer, mBufferLength, 0, messageStr.Length());
  EXPECT_EQ(socket->SendTo(buffer, mBufferLength, messageStr.Length(), Sockets::SocketFlags::None, endPoint), messageStr.Length());
}

TEST_F(Socket, ReceiveFromTest_ArrayOfBytes) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveFromThread);
  receivingThread.Start(receivingSocket.ToObject());
  // Send data to loopback address
  Sp<Sockets::Socket> sendingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
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
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveFromUsingNativeArrayThread);
  receivingThread.Start(receivingSocket.ToObject());
  // Send data to loopback address
  Sp<Sockets::Socket> sendingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
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
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveFromThread);
  
  receivingSocket->Shutdown(SocketShutdown::Both);
  
  receivingThread.Start(receivingSocket.ToObject());
  
  receivingThread.Join();
  
  //There are no exception in linux when shutdown during recv
  ASSERT_FALSE(Sp<Exception>::IsNullOrEmpty(mLastException));
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_TRUE((Sp<Sockets::SocketException>(mLastException))->GetSocketError() == SocketError::Shutdown);
}
*/

//In linux close doesn't allways unblock recv because of race condition on the reuse of the socket
//So it's better to call shutdown before close to unblock the thread
/*
TEST_F(Socket, ReceiveFromTest_ReceiveFromBeforeClose)
{
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback(), TestUtils::mPort);
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  
  Thread receivingThread(ReceiveFromThread);
  receivingThread.Start(receivingSocket.ToObject());
  
  while (!receivingThread.IsAlive())
    Thread::Sleep(100);
  Thread::Sleep(100);
  
  receivingSocket->Close();
  
  receivingThread.Join();
  
  ASSERT_FALSE(Sp<Exception>::IsNullOrEmpty(mLastException));
  ASSERT_TRUE(mLastException->GetError() == Error::Sockets::Socket);
  ASSERT_TRUE((Sp<Sockets::SocketException>(mLastException))->GetSocketError() == SocketError::Interrupted);
}
*/
TEST_F(Socket, ReceiveFromTest_ReceiveFromBeforeShutdownAndClose) {
  // Create socket on loopback address and create receiving thread
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
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
  Sp<Sockets::Socket> receivingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  receivingSocket->Bind(new IPEndPoint(endPoint));
  Thread receivingThread((ParameterizedThreadStart)ReceiveFromThread);
  receivingSocket->Close();
  receivingThread.Start(receivingSocket.ToObject());
  receivingThread.Join();
  ASSERT_FALSE(mLastException.IsNull());
  ASSERT_TRUE(is<ObjectClosedException>(*mLastException));
}

TEST_F(Socket, SelectTrivialIntegrationTest) {
  Sp<Sockets::Socket> socket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  List<Sp<Sockets::Socket>> checkRead;
  checkRead.Add(socket);
  List<Sp<Sockets::Socket>> checkWrite;
  checkWrite.Add(socket);
  List<Sp<Sockets::Socket>> checkError;
  checkError.Add(socket);
  EXPECT_TRUE(checkRead.Count == 1 && checkWrite.Count == 1 && checkError.Count == 1);
  Sockets::Socket::Select(checkRead, checkWrite, checkError, 0);
  ASSERT_TRUE(checkRead.Count == 0 && checkWrite.Count == 0 && checkError.Count == 0);
  socket->Close();
}

TEST_F(Socket, DISABLED_SelectAndReceive) {
  Sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  Sp<Sockets::Socket> socket2 = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint2(IPAddress::Loopback, TestUtils::mPort + 1);
  socket2->Bind(new IPEndPoint(endPoint2));
  socket2->Listen(64);
  Sp<Sockets::Socket> sendingSocket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  sendingSocket->SendTo(data, endPoint);
  List<Sp<Sockets::Socket>> checkRead;
  checkRead.Add(socket);
  checkRead.Add(socket2);
  List<Sp<Sockets::Socket>> checkWrite;
  checkWrite.Add(socket);
  List<Sp<Sockets::Socket>> checkError;
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
  Sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  ASSERT_FALSE(socket->Poll(0, Sockets::SelectMode::SelectRead));
  socket->Close();
}

TEST_F(Socket, PollAndReceiveIntegrationTest) {
  Sp<Sockets::Socket> socket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  IPEndPoint endPoint(IPAddress::Loopback, ++TestUtils::mPort);
  socket->Bind(new IPEndPoint(endPoint));
  socket->Listen(64);
  Sp<Sockets::Socket> sendingSocket =new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  string dataStr = "Hello World!";
  Array<byte> data = TestUtils::GetDataArray(dataStr);
  sendingSocket->SendTo(data, endPoint);
  ASSERT_TRUE(socket->Poll(-1, Sockets::SelectMode::SelectRead));
  socket->Close();
  sendingSocket->Close();
}

TEST_F(Socket, EnableBroadcastTest) {
  Sp<Sockets::Socket> socket = new Sockets::Socket(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  try {
    socket->SetEnableBroadcast(true);
  } catch (Sockets::SocketException& ex) {
    mLastException = Sp<Exception>::Create(ex);
  }
  ASSERT_TRUE(mLastException.IsNull());
}

TEST_F(Socket, ConstructorTest_TCP) { 
  Sp<Sockets::Socket> mySocket1;
  mySocket1 = Sp<Sockets::Socket>::Create(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Stream, Sockets::ProtocolType::Tcp);
  EXPECT_EQ(mySocket1->AddressFamily(), Sockets::AddressFamily::InterNetwork);
  EXPECT_EQ(mySocket1->SocketType(), Sockets::SocketType::Stream);
  EXPECT_EQ(mySocket1->ProtocolType(), Sockets::ProtocolType::Tcp);
}

TEST_F(Socket, ConstructorTest_UDP)
{
  Sp<Sockets::Socket> mySocket2;
  mySocket2 = Sp<Sockets::Socket>::Create(Sockets::AddressFamily::InterNetwork, Sockets::SocketType::Dgram, Sockets::ProtocolType::Udp);
  EXPECT_EQ(mySocket2->AddressFamily(), Sockets::AddressFamily::InterNetwork);
  EXPECT_EQ(mySocket2->SocketType(), Sockets::SocketType::Dgram);
  EXPECT_EQ(mySocket2->ProtocolType(), Sockets::ProtocolType::Udp);
}

}