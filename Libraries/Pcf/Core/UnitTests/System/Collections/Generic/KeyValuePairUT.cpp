#include <Pcf/System/Collections/Generic/KeyValuePair.h>
#include <Pcf/System/ConsoleColor.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {

TEST(KeyValuePair, Constructor) {
  EXPECT_EQ("[, ]", (KeyValuePair<string, string> ()).ToString());
  EXPECT_EQ("[0, 0]", (KeyValuePair<Byte, SByte> ()).ToString());
  EXPECT_EQ("[Key, Value]", (KeyValuePair<string, string> ("Key", "Value")).ToString());
  EXPECT_EQ("[12, Eleven]", (KeyValuePair<Int32, string> (12, "Eleven")).ToString());
  EXPECT_EQ("[10, Green]", (KeyValuePair<UInt32, string> ((uint32)ConsoleColor::Green, "Green")).ToString());	
}

TEST(KeyValuePair, GetKey) {
  EXPECT_EQ((KeyValuePair<string, string>().Key()), "");
  EXPECT_EQ((KeyValuePair<UInt16, string>().Key()), 0);
  EXPECT_EQ((KeyValuePair<string, string>("Key", "Value").Key()), "Key");
  EXPECT_EQ((KeyValuePair<Int32, string>(12, "Eleven").Key()), 12);
}

TEST(KeyValuePair, GetValue) {
  EXPECT_EQ((KeyValuePair<string, string>().Value()), "");
  EXPECT_EQ((KeyValuePair<UInt16, Boolean>().Value()), false);
  EXPECT_EQ((KeyValuePair<string, string>("Key", "Value").Value()), "Value");
  EXPECT_EQ((KeyValuePair<Int32, string>(12, "Eleven").Value()), "Eleven");
  EXPECT_EQ((KeyValuePair<string, TimeSpan>("TimeSpan", TimeSpan(2978)).Value()).Ticks(), 2978);
}

TEST(KeyValuePair, ToString) {
  EXPECT_EQ(String("[12, Eleven]"), (KeyValuePair<Int32, string>(12, "Eleven").ToString()));
  EXPECT_EQ(String("[Byte::MinValue, " + Byte(Byte::MinValue).ToString() + "]"), (KeyValuePair<string, byte>("Byte::MinValue", Byte::MinValue).ToString()));
  EXPECT_EQ(String("[Byte::MaxValue, " + Byte(Byte::MaxValue).ToString() + "]"), (KeyValuePair<string, byte>("Byte::MaxValue", Byte::MaxValue).ToString()));
  EXPECT_EQ(String("[Char::MinValue, " + Char(Char::MinValue).ToString() + "]"), (KeyValuePair<string, char32>("Char::MinValue", Char::MinValue).ToString()));
  EXPECT_EQ(String("[Char::MaxValue, " + Char(Char::MaxValue).ToString() + "]"), (KeyValuePair<string, char32>("Char::MaxValue", Char::MaxValue).ToString()));
}

}
