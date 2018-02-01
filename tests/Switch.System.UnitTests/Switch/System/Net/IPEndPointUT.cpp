#include <Switch/System/Net/IPEndPoint.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

namespace {
  TEST(IPEndPoint, Constructor) {
    ASSERT_EQ(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).ToString(), "172.16.10.30:11000");
    ASSERT_THROW(IPEndPoint(IPAddress(172, 16, 10, 30), IPEndPoint::MinPort - 1), ArgumentOutOfRangeException);
    ASSERT_THROW(IPEndPoint(IPAddress(172, 16, 10, 30), IPEndPoint::MaxPort + 1), ArgumentOutOfRangeException);
  }

  TEST(IPEndPoint, GetAddress) {
    ASSERT_EQ(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).Address().ToString(), "172.16.10.30");
    ASSERT_EQ(IPEndPoint(IPAddress::IPv6Loopback, 8080).Address().ToString(), "[0:0:0:0:0:0:0:1]");
  }

  TEST(IPEndPoint, GetAddressFamily) {
    ASSERT_EQ(Enum<Sockets::AddressFamily>(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).AddressFamily).ToString(), "InterNetwork");
    ASSERT_EQ(Enum<Sockets::AddressFamily>(IPEndPoint(IPAddress::IPv6Loopback, 8080).AddressFamily).ToString(), "InterNetworkV6");
  }

  TEST(IPEndPoint, GetPort) {
    ASSERT_EQ(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).Port(), 11000);
    ASSERT_EQ(IPEndPoint(IPAddress::IPv6Loopback, 8080).Port(), 8080);
  }

  TEST(IPEndPoint, SerializeIPv4) {
    SocketAddress socketAddress = IPEndPoint(IPAddress(172, 16, 10, 30), 11000).Serialize();
    ASSERT_EQ("InterNetwork:16:{42,248,172,16,10,30,0,0,0,0,0,0,0,0}", socketAddress.ToString());
  }

  TEST(IPEndPoint, SerializeIPv6) {
    SocketAddress socketAddress = IPEndPoint(IPAddress::IPv6Loopback, 8080).Serialize();
    ASSERT_EQ("InterNetworkV6:28:{31,144,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}", socketAddress.ToString());
    //                           {31,144,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}
    //                     30:28:{31,144,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}
  }

  TEST(IPEndPoint, Create) {
    Array<byte> buffer = {2, 0, 42, 248, 172, 16, 10, 30, 0, 0, 0, 0, 0, 0, 0, 0};
    SocketAddress address(buffer);

    IPEndPoint dummyEndPoint(0, 0);
    IPEndPoint endPoint = *as<IPEndPoint>(dummyEndPoint.Create(address));
    ASSERT_EQ(IPAddress(172, 16, 10, 30), endPoint.Address());
    ASSERT_EQ(11000, endPoint.Port());
  }

  TEST(IPEndPoint, SetAddress) {
    IPEndPoint IPEndPoint(IPAddress(172, 16, 10, 30), 11000);
    ASSERT_EQ(IPEndPoint.Address().ToString(), "172.16.10.30");
    IPEndPoint.Address = IPAddress(192, 168, 0, 1);
    ASSERT_EQ(IPEndPoint.Address().ToString(), "192.168.0.1");
  }

  TEST(IPEndPoint, SetPort) {
    IPEndPoint IPEndPoint(IPAddress(172, 16, 10, 30), 11000);
    ASSERT_EQ(IPEndPoint.Port(), 11000);
    IPEndPoint.Port(8080);
    ASSERT_EQ(IPEndPoint.Port(), 8080);
    ASSERT_THROW(IPEndPoint.Port(IPEndPoint::MinPort - 1), ArgumentOutOfRangeException);
    ASSERT_THROW(IPEndPoint.Port(IPEndPoint::MaxPort + 1), ArgumentOutOfRangeException);
  }

  TEST(IPEndPoint, OperatorEqual) {
    IPEndPoint endPoint(IPAddress(127, 0, 0, 1), 12365);
    IPEndPoint copy = endPoint;
    ASSERT_EQ(endPoint.ToString(), copy.ToString());
  }

  TEST(IPEndPoint, OperatorEqualTest_Create) {
    IPEndPoint endPoint(IPAddress(127, 0, 0, 1), 12365);
    SocketAddress sockaddr = endPoint.Serialize();
    refptr<EndPoint> created = endPoint.Create(sockaddr);
    ASSERT_EQ(endPoint.ToString(), created->ToString());
  }
}
