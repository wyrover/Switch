#include <Switch/System/Collections/Generic/KeyValuePair.hpp>
#include <Switch/System/Byte.hpp>
#include <Switch/System/ConsoleColor.hpp>
#include <Switch/System/Int32.hpp>
#include <Switch/System/SByte.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/UInt16.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;

namespace {

  TEST(KeyValuePairTest, Constructor) {
    ASSERT_EQ("[, ]", (KeyValuePair<string, string> ()).ToString());
    ASSERT_EQ("[0, 0]", (KeyValuePair<Byte, SByte> ()).ToString());
    ASSERT_EQ("[Key, Value]", (KeyValuePair<string, string> ("Key", "Value")).ToString());
    ASSERT_EQ("[12, Eleven]", (KeyValuePair<Int32, string> (12, "Eleven")).ToString());
    ASSERT_EQ("[10, Green]", (KeyValuePair<UInt32, string> ((uint32)ConsoleColor::Green, "Green")).ToString());
  }
  
  TEST(KeyValuePairTest, GetKey) {
    ASSERT_EQ((KeyValuePair<string, string>().Key()), "");
    ASSERT_EQ((KeyValuePair<UInt16, string>().Key()), 0);
    ASSERT_EQ((KeyValuePair<string, string>("Key", "Value").Key()), "Key");
    ASSERT_EQ((KeyValuePair<Int32, string>(12, "Eleven").Key()), 12);
  }
  
  TEST(KeyValuePairTest, GetValue) {
    ASSERT_EQ((KeyValuePair<string, string>().Value()), "");
    ASSERT_EQ((KeyValuePair<UInt16, Boolean>().Value()), false);
    ASSERT_EQ((KeyValuePair<string, string>("Key", "Value").Value()), "Value");
    ASSERT_EQ((KeyValuePair<Int32, string>(12, "Eleven").Value()), "Eleven");
    ASSERT_EQ((KeyValuePair<string, TimeSpan>("TimeSpan", TimeSpan(2978)).Value()).Ticks(), 2978);
  }
  
  TEST(KeyValuePairTest, ToString) {
    ASSERT_EQ(String("[12, Eleven]"), (KeyValuePair<Int32, string>(12, "Eleven").ToString()));
    ASSERT_EQ(String("[Byte::MinValue, " + Byte(Byte::MinValue).ToString() + "]"), (KeyValuePair<string, byte>("Byte::MinValue", Byte::MinValue).ToString()));
    ASSERT_EQ(String("[Byte::MaxValue, " + Byte(Byte::MaxValue).ToString() + "]"), (KeyValuePair<string, byte>("Byte::MaxValue", Byte::MaxValue).ToString()));
    ASSERT_EQ(String("[Char::MinValue, " + Char(Char::MinValue).ToString() + "]"), (KeyValuePair<string, char32>("Char::MinValue", Char::MinValue).ToString()));
    ASSERT_EQ(String("[Char::MaxValue, " + Char(Char::MaxValue).ToString() + "]"), (KeyValuePair<string, char32>("Char::MaxValue", Char::MaxValue).ToString()));
  }
  
}
