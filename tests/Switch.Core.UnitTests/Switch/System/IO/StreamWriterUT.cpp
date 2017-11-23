#include <Switch/System/IO/StreamWriter.hpp>
#include <Switch/System/IO/StreamReader.hpp>
#include <Switch/System/IO/StringReader.hpp>
#include <Switch/System/IO/MemoryStream.hpp>
#include <gtest/gtest.h>

#include <Switch/System/IO/Path.hpp>

using namespace System;
using namespace System::IO;

namespace {
  TEST(StreamWriterTest, WriteIn32) {
    IO::MemoryStream s(10);
    IO::StreamWriter writer(s);
    
    Array<int32> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(int32 item : data)
      writer.Write(item);
      
    IO::StreamReader reader(s);
    int32 index = 0;
    for(int32 current = reader.Read(); current != -1; current = reader.Read())
      ASSERT_EQ(data[index++], Int32::Parse(Char(current).ToString()));
  }
  
  TEST(StreamWriterTest, WriteUTF8) {
    string unicodeString = "Pi " + Char(928) + " ma " + Char(931) + " KOALA " + Char(128040);
    refptr<Text::Encoding> encoding = Text::Encoding::UTF8();
    IO::MemoryStream s;
    IO::StreamWriter writer(s, *encoding);
    writer.Write(unicodeString);
    
    StringReader sreader(unicodeString);
    IO::StreamReader reader(s, *encoding);
    
    for(int32 data = sreader.Read(), current = reader.Read(); current != -1 && data != -1; data = sreader.Read(), current = reader.Read())
      ASSERT_EQ(data, current);
  }
  
  TEST(StreamWriterTest, Write437) {
    string unicodeString = "a" + Char(0XE6) + "\n" + Char(0x3A3) + Char(0x2588);
    IO::MemoryStream s;
    refptr<Text::Encoding> encoding = Text::Encoding::CreateEncoding(437);
    IO::StreamWriter writer(s, *encoding);
    
    writer.Write(unicodeString);
    
    s.Position = 0;
    ASSERT_EQ(0x61, s.ReadByte());
    ASSERT_EQ(0x91, s.ReadByte());
    ASSERT_EQ('\n', s.ReadByte());
    ASSERT_EQ(0xE4, s.ReadByte());
    ASSERT_EQ(0xDB, s.ReadByte());
    
    StringReader sreader(unicodeString);
    IO::StreamReader reader(s, *encoding);
    
    for(int32 data = sreader.Read(), current = reader.Read(); current != -1 && data != -1; data = sreader.Read(), current = reader.Read())
      ASSERT_EQ(data, current);
  }
  
}
