#include <Switch/System/Net/IPAddress.hpp>
#include <Switch/System/BitConverter.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

template<typename T, typename TArray>
void EXPECT_B4(T b1, T b2, T b3, T b4, TArray bytes) {
  ASSERT_EQ(4, bytes.Length);
  if (System::BitConverter::IsLittleEndian()) {
    ASSERT_EQ(b1, bytes[0]);
    ASSERT_EQ(b2, bytes[1]);
    ASSERT_EQ(b3, bytes[2]);
    ASSERT_EQ(b4, bytes[3]);
  } else {
    ASSERT_EQ(b1, bytes[3]);
    ASSERT_EQ(b2, bytes[2]);
    ASSERT_EQ(b3, bytes[1]);
    ASSERT_EQ(b4, bytes[0]);
  }
}

template<typename T, typename TArray>
void EXPECT_B16(T b1, T b2, T b3, T b4, T b5, T b6, T b7, T b8, T b9, T b10, T b11, T b12, T b13, T b14, T b15, T b16, TArray bytes) {
  ASSERT_EQ(16, bytes.Length);
  if (System::BitConverter::IsLittleEndian()) {
    ASSERT_EQ(b1, bytes[0]);
    ASSERT_EQ(b2, bytes[1]);
    ASSERT_EQ(b3, bytes[2]);
    ASSERT_EQ(b4, bytes[3]);
    ASSERT_EQ(b5, bytes[4]);
    ASSERT_EQ(b6, bytes[5]);
    ASSERT_EQ(b7, bytes[6]);
    ASSERT_EQ(b8, bytes[7]);
    ASSERT_EQ(b9, bytes[8]);
    ASSERT_EQ(b10, bytes[9]);
    ASSERT_EQ(b11, bytes[10]);
    ASSERT_EQ(b12, bytes[11]);
    ASSERT_EQ(b13, bytes[12]);
    ASSERT_EQ(b14, bytes[13]);
    ASSERT_EQ(b15, bytes[14]);
    ASSERT_EQ(b16, bytes[15]);
  } else {
    ASSERT_EQ(b1, bytes[7]);
    ASSERT_EQ(b2, bytes[6]);
    ASSERT_EQ(b3, bytes[5]);
    ASSERT_EQ(b4, bytes[4]);
    ASSERT_EQ(b5, bytes[3]);
    ASSERT_EQ(b6, bytes[2]);
    ASSERT_EQ(b7, bytes[1]);
    ASSERT_EQ(b8, bytes[0]);
    ASSERT_EQ(b9, bytes[15]);
    ASSERT_EQ(b10, bytes[14]);
    ASSERT_EQ(b11, bytes[13]);
    ASSERT_EQ(b12, bytes[12]);
    ASSERT_EQ(b13, bytes[11]);
    ASSERT_EQ(b14, bytes[10]);
    ASSERT_EQ(b15, bytes[9]);
    ASSERT_EQ(b16, bytes[8]);
  }
}

namespace {
  TEST(IPAddress, Constructor) {
    ASSERT_EQ("0.0.0.0", IPAddress::Any().ToString());
    ASSERT_EQ("255.255.255.255", IPAddress::Broadcast().ToString());
    ASSERT_EQ("[0:0:0:0:0:0:0:0]", IPAddress::IPv6Any().ToString());
    ASSERT_EQ("[0:0:0:0:0:0:0:1]", IPAddress::IPv6Loopback().ToString());
    ASSERT_EQ("[0:0:0:0:0:0:0:0]", IPAddress::IPv6None().ToString());
    ASSERT_EQ("127.0.0.1", IPAddress::Loopback().ToString());
    ASSERT_EQ("255.255.255.255", IPAddress::None().ToString());
    
    ASSERT_EQ("255.255.255.255", IPAddress().ToString());
    
    ASSERT_EQ("0.0.0.0", IPAddress(Int64(0x0000000000000000LL)).ToString());
    ASSERT_EQ("255.255.255.255", IPAddress(Int64(0x00000000FFFFFFFFLL)).ToString());
    ASSERT_EQ("172.0.10.35", IPAddress(Int64(0x00000000230A00ACLL)).ToString());
    
    ASSERT_EQ("0.0.0.0", IPAddress(IPAddress::Any).ToString());
    ASSERT_EQ("255.255.255.255", IPAddress(IPAddress::Broadcast).ToString());
    ASSERT_EQ("[0:0:0:0:0:0:0:0]", IPAddress(IPAddress::IPv6Any).ToString());
    ASSERT_EQ("[0:0:0:0:0:0:0:1]", IPAddress(IPAddress::IPv6Loopback).ToString());
    ASSERT_EQ("[0:0:0:0:0:0:0:0]", IPAddress(IPAddress::IPv6None).ToString());
    ASSERT_EQ("127.0.0.1", IPAddress(IPAddress::Loopback).ToString());
    ASSERT_EQ("255.255.255.255", IPAddress(IPAddress::None).ToString());
    
    ASSERT_EQ("172.16.10.30", IPAddress(Array<byte> {172, 16, 10, 30}).ToString());
    
    ASSERT_THROW(IPAddress(Array<byte> {172, 16}), ArgumentException);
    ASSERT_THROW(IPAddress(Array<byte> {172, 16, 10, 30, 25, 42}), ArgumentException);
    
    ASSERT_EQ("[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]", IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).ToString());
    ASSERT_EQ("[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15]", IPAddress({0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15).ToString());
    
    ASSERT_EQ("147.24.35.22", IPAddress(IPAddress(147, 24, 35, 22)).ToString());
    
    ASSERT_EQ("0.0.0.0", IPAddress(0, 0, 0, 0).ToString());
    ASSERT_EQ("10.11.12.35", IPAddress(10, 11, 12, 35).ToString());
    ASSERT_EQ("255.255.255.255", IPAddress(255, 255, 255, 255).ToString());
  }
  
  TEST(IPAddress, Equals) {
    ASSERT_TRUE(IPAddress(172, 16, 12, 24).Equals(IPAddress(172, 16, 12, 24)));
    ASSERT_FALSE(IPAddress(172, 16, 12, 24).Equals(IPAddress(172, 16, 12, 25)));
    
    IPAddress addr1(172, 16, 12, 24);
    IPAddress addr2(172, 16, 12, 25);
    Object* obj1 = &addr1;
    Object* obj2 = &addr2;
    ASSERT_TRUE(IPAddress(172, 16, 12, 24).Equals(*obj1));
    ASSERT_FALSE(IPAddress(172, 16, 12, 24).Equals(*obj2));
    ASSERT_FALSE(IPAddress(172, 16, 12, 24).Equals(string("172.16.12.24")));
  }
  
  TEST(IPAddress, GetAddressBytes) {
    EXPECT_B4(172, 16, 12, 24, IPAddress(172, 16, 12, 24).GetAddressBytes());
    EXPECT_B4(172, 16, 12, 24, IPAddress(int64(BitConverter::ToInt32({172, 16, 12, 24}, 0))).GetAddressBytes());
    EXPECT_B4(145, 32, 7, 18, IPAddress(145, 32, 7, 18).GetAddressBytes());
    
    EXPECT_B16(32, 1, 0, 0, 94, 245, 115, 184, 44, 44, 48, 40, 42, 78, 178, 131, IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).GetAddressBytes());
    
    byte quadPartAddress1, quadPartAddress2, quadPartAddress3, quadPartAddress4;
    IPAddress(172, 16, 12, 24).GetAddressBytes(quadPartAddress1, quadPartAddress2, quadPartAddress3, quadPartAddress4);
    ASSERT_EQ(quadPartAddress1, 172);
    ASSERT_EQ(quadPartAddress2, 16);
    ASSERT_EQ(quadPartAddress3, 12);
    ASSERT_EQ(quadPartAddress4, 24);
  }
  
  TEST(IPAddress, GetAddressFamily) {
    ASSERT_EQ(AddressFamily(AddressFamily::InterNetwork), IPAddress(Array<byte> {172, 16, 10, 30}).AddressFamily);
    ASSERT_EQ(AddressFamily(AddressFamily::InterNetworkV6), IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).AddressFamily);
  }
  
  TEST(IPAddress, GetScopeId) {
    ASSERT_THROW(IPAddress(Array<byte> {172, 16, 10, 30}).ScopeId(), SocketException);
    ASSERT_EQ(0, IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).ScopeId);
    ASSERT_EQ(15, IPAddress(Array<byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15).ScopeId);
  }
  
  TEST(IPAddress, IsIPv6LinkLocal) {
  
  }
  
  TEST(IPAddress, HostToNetworkOrder) {
    if (BitConverter::IsLittleEndian()) {
      ASSERT_EQ(int16(0x3412), IPAddress::HostToNetworkOrder(int16(0x1234)));
      ASSERT_EQ(int32(0x78563412), IPAddress::HostToNetworkOrder(int32(0x12345678)));
      ASSERT_EQ(int64(0xF0DEBC9A78563412), IPAddress::HostToNetworkOrder(int64(0x123456789ABCDEF0)));
    } else {
      ASSERT_EQ(int16(0x1234), IPAddress::HostToNetworkOrder(int16(0x1234)));
      ASSERT_EQ(int32(0x12345678), IPAddress::HostToNetworkOrder(int32(0x12345678)));
      ASSERT_EQ(int64(0x123456789ABCDEF0), IPAddress::HostToNetworkOrder(int64(0x123456789ABCDEF0)));
    }
  }
  
  TEST(IPAddress, IsLoopback) {
    ASSERT_FALSE(IPAddress::IsLoopback(IPAddress(172, 16, 12, 24)));
    ASSERT_FALSE(IPAddress::IsLoopback(IPAddress(0, 0, 0, 0)));
    ASSERT_TRUE(IPAddress::IsLoopback(IPAddress(127, 0, 0, 1)));
    ASSERT_TRUE(IPAddress::IsLoopback(IPAddress::Loopback));
    ASSERT_TRUE(IPAddress::IsLoopback(IPAddress::IPv6Loopback));
  }
  
  TEST(IPAddress, NetworkToHostOrder) {
    if (BitConverter::IsLittleEndian()) {
      ASSERT_EQ(int16(0x3412), IPAddress::NetworkToHostOrder(int16(0x1234)));
      ASSERT_EQ(int32(0x78563412), IPAddress::NetworkToHostOrder(int32(0x12345678)));
      ASSERT_EQ(int64(0xF0DEBC9A78563412), IPAddress::NetworkToHostOrder(int64(0x123456789ABCDEF0)));
    } else {
      ASSERT_EQ(int16(0x1234), IPAddress::NetworkToHostOrder(int16(0x1234)));
      ASSERT_EQ(int32(0x12345678), IPAddress::NetworkToHostOrder(int32(0x12345678)));
      ASSERT_EQ(int64(0x123456789ABCDEF0), IPAddress::NetworkToHostOrder(int64(0x123456789ABCDEF0)));
    }
  }
  
  TEST(IPAddress, Parse) {
    ASSERT_EQ("172.16.12.24", IPAddress::Parse("172.16.12.24").ToString());
  }
  
}
