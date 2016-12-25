#include <Pcf/System/Net/IPAddress.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace TUnit;

namespace {
  TEST(IPAddress, Constructor) {
    EXPECT_EQ("0.0.0.0", IPAddress::Any().ToString());
    EXPECT_EQ("255.255.255.255", IPAddress::Broadcast().ToString());
    EXPECT_EQ("[0:0:0:0:0:0:0:0]", IPAddress::IPv6Any().ToString());
    EXPECT_EQ("[0:0:0:0:0:0:0:1]", IPAddress::IPv6Loopback().ToString());
    EXPECT_EQ("[0:0:0:0:0:0:0:0]", IPAddress::IPv6None().ToString());
    EXPECT_EQ("127.0.0.1", IPAddress::Loopback().ToString());
    EXPECT_EQ("255.255.255.255", IPAddress::None().ToString());
    
    EXPECT_EQ("255.255.255.255", IPAddress().ToString());
    
    EXPECT_EQ("0.0.0.0", IPAddress(Int64(0x0000000000000000LL)).ToString());
    EXPECT_EQ("255.255.255.255", IPAddress(Int64(0x00000000FFFFFFFFLL)).ToString());
    EXPECT_EQ("172.0.10.35", IPAddress(Int64(0x00000000230A00ACLL)).ToString());
    
    EXPECT_EQ("0.0.0.0", IPAddress(IPAddress::Any).ToString());
    EXPECT_EQ("255.255.255.255", IPAddress(IPAddress::Broadcast).ToString());
    EXPECT_EQ("[0:0:0:0:0:0:0:0]", IPAddress(IPAddress::IPv6Any).ToString());
    EXPECT_EQ("[0:0:0:0:0:0:0:1]", IPAddress(IPAddress::IPv6Loopback).ToString());
    EXPECT_EQ("[0:0:0:0:0:0:0:0]", IPAddress(IPAddress::IPv6None).ToString());
    EXPECT_EQ("127.0.0.1", IPAddress(IPAddress::Loopback).ToString());
    EXPECT_EQ("255.255.255.255", IPAddress(IPAddress::None).ToString());
    
    EXPECT_EQ("172.16.10.30", IPAddress(Array<byte> {172, 16, 10, 30}).ToString());
    
    EXPECT_THROW(IPAddress(Array<byte> {172, 16}), ArgumentException);
    EXPECT_THROW(IPAddress(Array<byte> {172, 16, 10, 30, 25, 42}), ArgumentException);
    
    EXPECT_EQ("[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]", IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).ToString());
    EXPECT_EQ("[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15]", IPAddress({0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15).ToString());
    
    EXPECT_EQ("147.24.35.22", IPAddress(IPAddress(147, 24, 35, 22)).ToString());
    
    EXPECT_EQ("0.0.0.0", IPAddress(0, 0, 0, 0).ToString());
    EXPECT_EQ("10.11.12.35", IPAddress(10, 11, 12, 35).ToString());
    EXPECT_EQ("255.255.255.255", IPAddress(255, 255, 255, 255).ToString());
  }
  
  TEST(IPAddress, Equals) {
    EXPECT_TRUE(IPAddress(172, 16, 12, 24).Equals(IPAddress(172, 16, 12, 24)));
    EXPECT_FALSE(IPAddress(172, 16, 12, 24).Equals(IPAddress(172, 16, 12, 25)));
    
    IPAddress addr1(172, 16, 12, 24);
    IPAddress addr2(172, 16, 12, 25);
    Object* obj1 = &addr1;
    Object* obj2 = &addr2;
    EXPECT_TRUE(IPAddress(172, 16, 12, 24).Equals(*obj1));
    EXPECT_FALSE(IPAddress(172, 16, 12, 24).Equals(*obj2));
    EXPECT_FALSE(IPAddress(172, 16, 12, 24).Equals(string("172.16.12.24")));
  }
  
  TEST(IPAddress, GetAddressBytes) {
    EXPECT_B4(172, 16, 12, 24, IPAddress(172, 16, 12, 24).GetAddressBytes());
    EXPECT_B4(172, 16, 12, 24, IPAddress(int64(BitConverter::ToInt32({172, 16, 12, 24}, 0))).GetAddressBytes());
    EXPECT_B4(145, 32, 7, 18, IPAddress(145, 32, 7, 18).GetAddressBytes());
    
    EXPECT_B16(32, 1, 0, 0, 94, 245, 115, 184, 44, 44, 48, 40, 42, 78, 178, 131, IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).GetAddressBytes());
    
    byte quadPartAddress1, quadPartAddress2, quadPartAddress3, quadPartAddress4;
    IPAddress(172, 16, 12, 24).GetAddressBytes(quadPartAddress1, quadPartAddress2, quadPartAddress3, quadPartAddress4);
    EXPECT_EQ(quadPartAddress1, 172);
    EXPECT_EQ(quadPartAddress2, 16);
    EXPECT_EQ(quadPartAddress3, 12);
    EXPECT_EQ(quadPartAddress4, 24);    
  }
  
  TEST(IPAddress, GetAddressFamily) {
    EXPECT_EQ(AddressFamily(AddressFamily::InterNetwork), IPAddress(Array<byte> {172, 16, 10, 30}).AddressFamily);
    EXPECT_EQ(AddressFamily(AddressFamily::InterNetworkV6), IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).AddressFamily);
  }
  
  TEST(IPAddress, GetScopeId) {
    EXPECT_THROW(IPAddress(Array<byte> {172, 16, 10, 30}).ScopeId(), SocketException);
    EXPECT_EQ(0, IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).ScopeId);
    EXPECT_EQ(15, IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15).ScopeId);
  }
  
  TEST(IPAddress, IsIPv6LinkLocal) {
    
  }
  
  TEST(IPAddress, HostToNetworkOrder) {
    if (BitConverter::IsLittleEndian()) {
      EXPECT_EQ(int16(0x3412), IPAddress::HostToNetworkOrder(int16(0x1234)));
      EXPECT_EQ(int32(0x78563412), IPAddress::HostToNetworkOrder(int32(0x12345678)));
      EXPECT_EQ(int64(0xF0DEBC9A78563412), IPAddress::HostToNetworkOrder(int64(0x123456789ABCDEF0)));
    } else {
      EXPECT_EQ(int16(0x1234), IPAddress::HostToNetworkOrder(int16(0x1234)));
      EXPECT_EQ(int32(0x12345678), IPAddress::HostToNetworkOrder(int32(0x12345678)));
      EXPECT_EQ(int64(0x123456789ABCDEF0), IPAddress::HostToNetworkOrder(int64(0x123456789ABCDEF0)));
    }
  }
  
  TEST(IPAddress, IsLoopback) {
    EXPECT_FALSE(IPAddress::IsLoopback(IPAddress(172, 16, 12, 24)));
    EXPECT_FALSE(IPAddress::IsLoopback(IPAddress(0, 0, 0, 0)));
    EXPECT_TRUE(IPAddress::IsLoopback(IPAddress(127, 0, 0, 1)));
    EXPECT_TRUE(IPAddress::IsLoopback(IPAddress::Loopback));
    EXPECT_TRUE(IPAddress::IsLoopback(IPAddress::IPv6Loopback));
  }
  
  TEST(IPAddress, NetworkToHostOrder) {
    if (BitConverter::IsLittleEndian()) {
      EXPECT_EQ(int16(0x3412), IPAddress::NetworkToHostOrder(int16(0x1234)));
      EXPECT_EQ(int32(0x78563412), IPAddress::NetworkToHostOrder(int32(0x12345678)));
      EXPECT_EQ(int64(0xF0DEBC9A78563412), IPAddress::NetworkToHostOrder(int64(0x123456789ABCDEF0)));
    } else {
      EXPECT_EQ(int16(0x1234), IPAddress::NetworkToHostOrder(int16(0x1234)));
      EXPECT_EQ(int32(0x12345678), IPAddress::NetworkToHostOrder(int32(0x12345678)));
      EXPECT_EQ(int64(0x123456789ABCDEF0), IPAddress::NetworkToHostOrder(int64(0x123456789ABCDEF0)));
    }
  }
  
  TEST(IPAddress, Parse) {
    EXPECT_EQ("172.16.12.24", IPAddress::Parse("172.16.12.24").ToString());
  }
  
}
