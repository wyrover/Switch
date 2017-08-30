#include <Switch/System/IO/StringReader.hpp>
#include <Switch/System/ObjectClosedException.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::IO;
using namespace TUnit;

namespace {

  TEST(StringReader, Peek___Fails_On_Empty) {
    StringReader reader("");
    EXPECT_EQ(-1, reader.Peek());
  }

  TEST(StringReader, Peek) {
    StringReader reader("abc");
    EXPECT_EQ('a', reader.Peek());
  }

  TEST(StringReader, Peek___Throws_ObjectClosedException_When_Closed) {
    StringReader reader("abc");
    reader.Close();
    EXPECT_THROW(reader.Peek(), ObjectClosedException);
  }

  TEST(StringReader, Read___Fails_On_Empty) {
    StringReader reader("");
    EXPECT_EQ(-1, reader.Read());
  }

  TEST(StringReader, Read) {
    StringReader reader("abc");
    EXPECT_EQ('a', reader.Read());
  }

  TEST(StringReader, Read___Throws_ObjectClosedException_When_Closed) {
    StringReader reader("abc");
    reader.Close();
    EXPECT_THROW(reader.Read(), ObjectClosedException);
  }

  TEST(StringReader, ReadLine___Returns_Empty_On_Empty) {
    StringReader reader("");
    EXPECT_EQ("", reader.ReadLine());
    EXPECT_EQ(-1, reader.Peek());
  }

  TEST(StringReader, ReadLine) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    EXPECT_EQ("switch", reader.ReadLine());
    EXPECT_EQ("this is a second line", reader.ReadLine());
    EXPECT_EQ(-1, reader.Peek());
  }

  TEST(StringReader, ReadLine___Throws_ObjectClosedException_When_Closed) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    reader.Close();
    EXPECT_THROW(reader.ReadLine(), ObjectClosedException);
  }

  TEST(StringReader, ReadToEnd___Returns_Empty_On_Empty) {
    StringReader reader("");
    EXPECT_EQ("", reader.ReadToEnd());
  }

  TEST(StringReader, ReadToEnd___Throws_ObjectClosedException_When_Closed) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    reader.Close();
    EXPECT_THROW(reader.ReadToEnd(), ObjectClosedException);
  }

  TEST(StringReader, ReadToEnd) {
    StringReader reader("switch\r\nthis is a second line\r\n");
    EXPECT_EQ('s', reader.Peek());
    EXPECT_EQ('s', reader.Read());
    EXPECT_EQ("witch", reader.ReadLine());
    EXPECT_EQ('t', reader.Peek());
    EXPECT_EQ("this is a second line\r\n", reader.ReadToEnd());
    EXPECT_EQ(-1, reader.Peek());
  }

}
