#include <Pcf/System/Net/Dns.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net::Sockets;
using namespace TUnit;

class Dns : public object, public testing::Test {
  
public:
  static void Run(Object& /*obj*/) {
    string hostName = Net::Dns::GetHostName();
    Array<Net::IPAddress> addresses = Net::Dns::GetHostAddresses(hostName);

    for (int i = 0; i < 10; i++) {
      Net::IPAddress a = addresses[0];
    }
  }
};

TEST_F(Dns, GetHostName) {
  EXPECT_NE(Net::Dns::GetHostName(), "");
}

TEST_F(Dns, GetHostAddresses) {
  Array<Net::IPAddress> Addresses = Net::Dns::GetHostAddresses("www.google.com");
  EXPECT_EQ(Addresses.Length, 1);
  EXPECT_EQ(Addresses[0].ToString(), "209.164.60.154");
}

/*
TEST(DnsTest, GetHostEntry) {
  IPHostEntry IPHostEntry = Net::Dns::GetHostEntry("www.google.com");
  EXPECT_EQ(IPHostEntry.GetHostName(), "www.l.google.com");
  EXPECT_EQ(IPHostEntry.GetAddressList().Length, 6);
  EXPECT_TRUE(IPHostEntry.GetAddressList().Contains(Net::IPAddress::Parse("173.194.65.99")));
  EXPECT_TRUE(IPHostEntry.GetAddressList().Contains(Net::IPAddress::Parse("173.194.65.103")));
  EXPECT_TRUE(IPHostEntry.GetAddressList().Contains(Net::IPAddress::Parse("173.194.65.104")));
  EXPECT_TRUE(IPHostEntry.GetAddressList().Contains(Net::IPAddress::Parse("173.194.65.105")));
  EXPECT_TRUE(IPHostEntry.GetAddressList().Contains(Net::IPAddress::Parse("173.194.65.106")));
  EXPECT_TRUE(IPHostEntry.GetAddressList().Contains(Net::IPAddress::Parse("173.194.65.147")));
  EXPECT_EQ(IPHostEntry.GetAliases().Length, 1);
  EXPECT_TRUE(IPHostEntry.GetAliases().Contains("www.google.com"));
}
 */

TEST_F(Dns, DISABLED_ConcurrentAccessIntegrationTest) {
  System::Threading::Thread t1((System::Threading::ParameterizedThreadStart)&Run);
  System::Threading::Thread t2((System::Threading::ParameterizedThreadStart)&Run);
  t1.Start(*this);
  t2.Start(*this);
  t1.Join();
  t2.Join();
}

