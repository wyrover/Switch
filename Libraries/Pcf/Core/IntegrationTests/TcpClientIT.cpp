#include "TestUtils.h"
#include <Pcf/System/Net/Sockets/TcpClient.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace TUnit;

namespace {

TEST(TcpClient, TestTheDefaultConstructorWithSP) {
  Sp<TcpClient> tcpClient;
  tcpClient = Sp<TcpClient>::Create();

	EXPECT_EQ(tcpClient->GetClient()->AddressFamily(), AddressFamily::InterNetwork);
  EXPECT_EQ(tcpClient->GetClient()->SocketType(), SocketType::Stream);
  EXPECT_EQ(tcpClient->GetClient()->ProtocolType(), ProtocolType::Tcp);
}

TEST(TcpClient, TestTheConstructorWithAddressFamilyEqualInterNetworkArgWithSP) {
	Sp<TcpClient> tcpClient;
	tcpClient = Sp<TcpClient>::Create(AddressFamily::InterNetwork);
	
	EXPECT_EQ(tcpClient->GetClient()->AddressFamily(), AddressFamily::InterNetwork);
	EXPECT_EQ(tcpClient->GetClient()->SocketType(), SocketType::Stream);
	EXPECT_EQ(tcpClient->GetClient()->ProtocolType(), ProtocolType::Tcp);
}

// TODO __APPLE__/__linux__
TEST(TcpClient, DISABLED_TestTheConstructorWithAddressFamilyEqualInterNetworkV6ArgWithSP) {
	Sp<TcpClient> tcpClient;
	tcpClient = Sp<TcpClient>::Create(AddressFamily::InterNetworkV6);

	EXPECT_EQ(tcpClient->GetClient()->AddressFamily(), AddressFamily::InterNetworkV6);
	EXPECT_EQ(tcpClient->GetClient()->SocketType(), SocketType::Stream);
	EXPECT_EQ(tcpClient->GetClient()->ProtocolType(), ProtocolType::IPv6);
}


TEST(TcpClient, TestTheConstructorWithIPEndPointWithSP) {
	Sp<IPEndPoint> ipEndPoint = new IPEndPoint(IPAddress::Loopback, 51000);
  ASSERT_FALSE(ipEndPoint.IsNull());
	Sp<TcpClient>  tcpClient  = new TcpClient(ipEndPoint); 
  ASSERT_FALSE(tcpClient.IsNull());
	EXPECT_EQ(tcpClient->GetClient()->AddressFamily(), AddressFamily::InterNetwork);
	EXPECT_EQ(tcpClient->GetClient()->SocketType(), SocketType::Stream);
	EXPECT_EQ(tcpClient->GetClient()->ProtocolType(), ProtocolType::Tcp);
}

TEST(TcpClient, TestTheDefaultConstructor) {
	TcpClient tcpClient;
	EXPECT_EQ(tcpClient.GetClient()->AddressFamily(), AddressFamily::InterNetwork);
	EXPECT_EQ(tcpClient.GetClient()->SocketType(), SocketType::Stream);
	EXPECT_EQ(tcpClient.GetClient()->ProtocolType(), ProtocolType::Tcp);
}

TEST(TcpClient, TestTheConstructorWithAddressFamilyEqualInterNetworkArg) {
	TcpClient tcpClient(AddressFamily::InterNetwork);
	EXPECT_EQ(tcpClient.GetClient()->AddressFamily(), AddressFamily::InterNetwork);
	EXPECT_EQ(tcpClient.GetClient()->SocketType(), SocketType::Stream);
	EXPECT_EQ(tcpClient.GetClient()->ProtocolType(), ProtocolType::Tcp);
}

TEST(TcpClient, TestActiveAfterCreation) {
	TcpClient tcpClient;
	EXPECT_EQ(tcpClient.GetActive(),false);
}

TEST(TcpClient, TestActiveAfterCreationWithSP) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	EXPECT_EQ(ptcpClient->GetActive(),false);
}

TEST(TcpClient, TestAvailableAfterCreation) {
	TcpClient tcpClient;
	EXPECT_EQ(tcpClient.GetAvailable(),0);
}

TEST(TcpClient, TestAvailableAfterCreationWithSP) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	EXPECT_EQ(ptcpClient->GetAvailable(),0);
}

TEST(TcpClient, TestAvailableAfterClose) {
  TcpClient client;
  client.Close();
  ASSERT_THROW(client.GetAvailable(), NullReferenceException);
}

TEST(TcpClient, TestGetConnectedAfterCreation) {
	TcpClient tcpClient;
	EXPECT_EQ(tcpClient.GetConnected(),false);
}

TEST(TcpClient, TestGetConnectedAfterCreationWithSP) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	EXPECT_EQ(ptcpClient->GetConnected(),false);
}

TEST(TcpClient, TestGetConnectedAfterCloseNoExecption) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  EXPECT_EQ(ptcpClient->GetConnected(),false);
}

// TODO __APPLE__
TEST(TcpClient, DISABLED_TestGetExclusiveAddressUseAfterCreation) {
	TcpClient tcpClient;
	EXPECT_EQ(tcpClient.GetExclusiveAddressUse(),false);
}

// TODO __APPLE__
TEST(TcpClient, DISABLED_TestGetExclusiveAddressUseAfterCreationWithSP) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	EXPECT_EQ(ptcpClient->GetExclusiveAddressUse(),false);
}

// TODO __APPLE__
TEST(TcpClient, DISABLED_TestSetExclusiveAddressUseUseAfterCreationWithSP) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	ptcpClient->SetExclusiveAddressUse(true);
	EXPECT_EQ(ptcpClient->GetExclusiveAddressUse(),true);
}

TEST(TcpClient, TestGetExclusiveAddressUseAfterClose) {
  TcpClient client;
  client.Close();
  ASSERT_THROW(client.GetExclusiveAddressUse(), NullReferenceException);
}

// TODO __APPLE__
TEST(TcpClient, DISABLED_TestSetGetNoDelayUseAfterCreation) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	ptcpClient->SetNoDelay(true);
	EXPECT_EQ(ptcpClient->GetNoDelay(),true);
}

TEST(TcpClient, TestGetNoDelayUseAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->GetNoDelay(), NullReferenceException);
}

// TODO __APPLE__
TEST(TcpClient, TestSetGetLingerStateUseAfterCreation) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  LingerOption lingerOption(true, 10);
  ASSERT_THROW(ptcpClient->SetLingerState(lingerOption), NotImplementedException);
}

TEST(TcpClient, TestSetGetLingerStateUseAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->GetLingerState(), NullReferenceException);
}

// TODO __APPLE__
TEST(TcpClient, DISABLED_TestSetGetReceiveBufferSizeUse8192AfterCreation) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	ptcpClient->SetReceiveBufferSize(8192);
	EXPECT_EQ(ptcpClient->GetReceiveBufferSize(),8192);
}

// TODO __linux__
TEST(TcpClient, DISABLED_TestSetGetReceiveBufferSizeUse10240AfterCreation) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	ptcpClient->SetReceiveBufferSize(10240);
	EXPECT_EQ(ptcpClient->GetReceiveBufferSize(),10240);
}

TEST(TcpClient, TestGetReceiveBufferSizeUseAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->GetReceiveBufferSize(), NullReferenceException);
}

// TODO __APPLE__
TEST(TcpClient, DISABLED_TestSetGetReceiveTimeoutAfterCreation) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	ptcpClient->SetReceiveTimeout(1000);
	EXPECT_EQ(ptcpClient->GetReceiveTimeout(),1000);
}

TEST(TcpClient, DISABLED_TestSetGetReceiveTimeoutAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->GetReceiveTimeout(), NullReferenceException);
}

// TODO __APPLE__
TEST(TcpClient, DISABLED_TestSetGetSendBufferSizeAfterCreation) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	ptcpClient->SetSendBufferSize(1000);
	EXPECT_EQ(ptcpClient->GetSendBufferSize(),1000);
}

TEST(TcpClient, TestSetGetSendBufferSizeAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->GetSendBufferSize(), NullReferenceException);
}

// TODO __APPLE__
TEST(TcpClient, TestSetGetSendTimeoutAfterCreation) {
	Sp<TcpClient> ptcpClient = new TcpClient();
	ptcpClient->SetSendTimeout(1000);
	EXPECT_EQ(ptcpClient->GetSendTimeout(),1000);
}

TEST(TcpClient, TestSetGetSendTimeoutAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->GetSendTimeout(), NullReferenceException);
}

 TEST(TcpClient, TestConnectNamePortAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->Connect(string("localhost"),51000), NullReferenceException);
}

TEST(TcpClient, TestConnectIPEndPointAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  Sp<IPEndPoint> ipEndPoint = new IPEndPoint(IPAddress::Loopback, 51000);
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->Connect(ipEndPoint), NullReferenceException);
}

TEST(TcpClient, TestConnectIpPortAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->Connect(IPAddress::Loopback,51000), NullReferenceException);
}

TEST(TcpClient, TestGetStreamAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_THROW(ptcpClient->GetStream(), NullReferenceException);
}

TEST(TcpClient, TestGetClientAfterClose) {
  Sp<TcpClient> ptcpClient = new TcpClient();
  ptcpClient->Close();
  ASSERT_NO_THROW(ptcpClient->GetClient());
}

}