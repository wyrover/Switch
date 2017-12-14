#include <Switch/System/IO/StringReader.hpp>
#include <Switch/System/ObjectDisposedException.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::IO;

namespace {
  TEST(StringReaderTest, Peek___Fails_On_Empty) {
    StringReader reader("");
    ASSERT_EQ(-1, reader.Peek());
  }

  TEST(StringReaderTest, Peek) {
    StringReader reader("abc");
    ASSERT_EQ('a', reader.Peek());
  }

  TEST(StringReaderTest, Peek___Throws_ObjectDisposedException_When_Closed) {
    StringReader reader("abc");
    reader.Close();
    ASSERT_THROW(reader.Peek(), ObjectDisposedException);
  }

  TEST(StringReaderTest, Read___Fails_On_Empty) {
    StringReader reader("");
    ASSERT_EQ(-1, reader.Read());
  }

  TEST(StringReaderTest, Read) {
    StringReader reader("abc");
    ASSERT_EQ('a', reader.Read());
  }

  TEST(StringReaderTest, Read___Throws_ObjectDisposedException_When_Closed) {
    StringReader reader("abc");
    reader.Close();
    ASSERT_THROW(reader.Read(), ObjectDisposedException);
  }

  TEST(StringReaderTest, ReadLine___Returns_Empty_On_Empty) {
    StringReader reader("");
    ASSERT_EQ("", reader.ReadLine());
    ASSERT_EQ(-1, reader.Peek());
  }

  TEST(StringReaderTest, ReadLine) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    ASSERT_EQ("switch", reader.ReadLine());
    ASSERT_EQ("this is a second line", reader.ReadLine());
    ASSERT_EQ(-1, reader.Peek());
  }

  TEST(StringReaderTest, ReadLine___Throws_ObjectDisposedException_When_Closed) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    reader.Close();
    ASSERT_THROW(reader.ReadLine(), ObjectDisposedException);
  }

  TEST(StringReaderTest, ReadToEnd___Returns_Empty_On_Empty) {
    StringReader reader("");
    ASSERT_EQ("", reader.ReadToEnd());
  }

  TEST(StringReaderTest, ReadToEnd___Throws_ObjectDisposedException_When_Closed) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    reader.Close();
    ASSERT_THROW(reader.ReadToEnd(), ObjectDisposedException);
  }

  TEST(StringReaderTest, ReadToEnd) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    ASSERT_EQ('s', reader.Peek());
    ASSERT_EQ('s', reader.Read());
    ASSERT_EQ("witch", reader.ReadLine());
    ASSERT_EQ('t', reader.Peek());
    ASSERT_EQ("this is a second line\r\n", reader.ReadToEnd());
    ASSERT_EQ(-1, reader.Peek());
  }

}
