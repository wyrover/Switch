#include <Switch/System/IO/MemoryStream.hpp>
#include <Switch/System/IO/StringReader.hpp>
#include <Switch/System/IO/StreamReader.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::IO;

namespace {
  TEST(StreamReaderTest, Read) {
    Array<byte> buffer = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    IO::MemoryStream s(buffer, false);
    IO::StreamReader reader(s);
    
    int32 idx = 0;
    int32 current = reader.Read();
    while(current != -1) {
      ASSERT_EQ(buffer[idx], current);
      idx++;
      current = reader.Read();
    }
  }
  
  TEST(StreamReaderTest, ReadLineUTF8) {
    Array<byte> utf8buffer = { 0x61, 0xC3, 0xA6, 0xC5, 0xA3, '\n', 0xCE, 0xA3, 0xDC, 0xA3, 0xE2, 0x96, 0x88, '\n', 0xE5, 0xA5, 0xBB, 0xF0, 0x9F, 0x90, 0xA8 };
    refptr<Text::Encoding> encoding = Text::Encoding::UTF8();
    IO::MemoryStream s(utf8buffer, false);
    IO::StreamReader reader(s, *encoding);
    
    string line = reader.ReadLine();
    ASSERT_EQ(3, line.Length());
    StringReader line1reader(line);
    ASSERT_EQ(0x61, line1reader.Read());
    ASSERT_EQ(0xE6, line1reader.Read());
    ASSERT_EQ(0x163, line1reader.Read());
    
    line = reader.ReadLine();
    ASSERT_EQ(3, line.Length());
    line = reader.ReadLine();
    ASSERT_EQ(2, line.Length());
    
  }
  
  TEST(StreamReaderTest, ReadToEndUTF8) {
    Array<byte> utf8buffer = { 0x61, 0xC3, 0xA6, 0xC5, 0xA3, '\n', 0xCE, 0xA3, 0xDC, 0xA3, 0xE2, 0x96, 0x88, '\n', 0xE5, 0xA5, 0xBB, 0xF0, 0x9F, 0x90, 0xA8 };
    refptr<Text::Encoding> encoding = Text::Encoding::UTF8();
    IO::MemoryStream s(utf8buffer, false);
    IO::StreamReader reader(s, *encoding);
    
    string all = reader.ReadToEnd();
    ASSERT_EQ(10, all.Length());
    
    StringReader allreader(all);
    ASSERT_EQ(0x61, allreader.Read());
    ASSERT_EQ(0xE6, allreader.Read());
    ASSERT_EQ(0x163, allreader.Read());
    ASSERT_EQ('\n', allreader.Read());
  }
  
  TEST(StreamReaderTest, ReadLine437) {
    Array<byte> buffer = { 0x61, 0x91, '\n', 0xE4, 0xDB};
    refptr<Text::Encoding> encoding = Text::Encoding::CreateEncoding(437);
    
    IO::MemoryStream s(buffer, false);
    IO::StreamReader reader(s, *encoding);
    
    string line = reader.ReadLine();
    
    ASSERT_EQ(2, line.Length());
    StringReader line1reader(line);
    ASSERT_EQ(0x61, line1reader.Read());
    ASSERT_EQ(0xE6, line1reader.Read());
    
    line = reader.ReadLine();
    ASSERT_EQ(2, line.Length());
    StringReader line2reader(line);
    ASSERT_EQ(0x3A3, line2reader.Read());
    ASSERT_EQ(0x2588, line2reader.Read());
    
  }
  
  TEST(StreamReaderTest, ReadToEnd437) {
    Array<byte> buffer = { 0x61, 0x91, '\n', 0xE4, 0xDB };
    refptr<Text::Encoding> encoding = Text::Encoding::CreateEncoding(437);
    
    IO::MemoryStream s(buffer, false);
    IO::StreamReader reader(s, *encoding);
    
    string all = reader.ReadToEnd();
    
    ASSERT_EQ(5, all.Length());
    
    StringReader allreader(all);
    ASSERT_EQ(0x61, allreader.Read());
    ASSERT_EQ(0xE6, allreader.Read());
    ASSERT_EQ('\n', allreader.Read());
    ASSERT_EQ(0x3A3, allreader.Read());
    ASSERT_EQ(0x2588, allreader.Read());
  }
}
