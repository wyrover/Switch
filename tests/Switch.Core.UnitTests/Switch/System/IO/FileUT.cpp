#include <Switch/System/IO/File.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(FileTest, AppendAllLines) {
    IO::File::WriteAllLines("Test.txt", {"First line", "Second line", "", "Third line"});
    IO::File::AppendAllLines("Test.txt", Array<string> {"Fourth line", "Fifth line"});
    Array<string> lines = IO::File::ReadAllLines("Test.txt");
    ASSERT_EQ(6, lines.Length);
    int32 index = 0;
    ASSERT_EQ("First line", lines[index++]);
    ASSERT_EQ("Second line", lines[index++]);
    ASSERT_EQ("", lines[index++]);
    ASSERT_EQ("Third line", lines[index++]);
    ASSERT_EQ("Fourth line", lines[index++]);
    ASSERT_EQ("Fifth line", lines[index++]);
    IO::File::Delete("Test.txt");
  }
  
  TEST(FileTest, AppendAllText) {
    IO::File::WriteAllText("Test.txt", "This is a text for a file !");
    IO::File::AppendAllText("Test.txt", " End the appended text is here !");
    string contents = IO::File::ReadAllText("Test.txt");
    ASSERT_EQ("This is a text for a file ! End the appended text is here !", contents);
    IO::File::Delete("Test.txt");
  }
  
  TEST(FileTest, AppendText) {
    _using(IO::StreamWriter sw = IO::File::CreateText("Test.txt")) {
      sw.WriteLine("First line");
    }
    
    _using(IO::StreamWriter sw = IO::File::AppendText("Test.txt")) {
      sw.WriteLine("Second line");
    }
    
    _using(Array<string> lines = IO::File::ReadAllLines("Test.txt")) {
      ASSERT_EQ(2, lines.Length);
      int32 index = 0;
      ASSERT_EQ("First line", lines[index++]);
      ASSERT_EQ("Second line", lines[index++]);
    }
    
    IO::File::Delete("Test.txt");
  }
  
  TEST(FileTest, Copy) {
    IO::File::WriteAllLines("2copy.txt", {"First line", "Second line", "", "Third line"});
    IO::File::Copy("2copy.txt", "copied.txt");
    ASSERT_TRUE(IO::File::Exists("2copy.txt"));
    ASSERT_TRUE(IO::File::Exists("copied.txt"));
    
    _using(Array<string> lines = IO::File::ReadAllLines("copied.txt")) {
      ASSERT_EQ(4, lines.Length);
      int32 index = 0;
      ASSERT_EQ("First line", lines[index++]);
      ASSERT_EQ("Second line", lines[index++]);
      ASSERT_EQ("", lines[index++]);
      ASSERT_EQ("Third line", lines[index++]);
    }
    
    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied.txt");
  }
  
  TEST(FileTest, CopyWithOverwrite) {
    IO::File::WriteAllLines("2copy.txt", {"First line", "Second line", "", "Third line"});
    IO::File::WriteAllLines("copied.txt", {"Fourth line", "Fifth line", "", "Sixth line"});
    IO::File::Copy("2copy.txt", "copied.txt", true);
    ASSERT_TRUE(IO::File::Exists("2copy.txt"));
    ASSERT_TRUE(IO::File::Exists("copied.txt"));
    
    _using(Array<string> lines = IO::File::ReadAllLines("copied.txt")) {
      ASSERT_EQ(4, lines.Length);
      int32 index = 0;
      ASSERT_EQ("First line", lines[index++]);
      ASSERT_EQ("Second line", lines[index++]);
      ASSERT_EQ("", lines[index++]);
      ASSERT_EQ("Third line", lines[index++]);
    }
    
    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied.txt");
  }
  
  TEST(FileTest, CopyWithoutOverwrite) {
    IO::File::WriteAllLines("2copy.txt", {"First line", "Second line", "", "Third line"});
    IO::File::WriteAllLines("copied.txt", {"Fourth line", "Fifth line", "", "Sixth line"});
    ASSERT_THROW(IO::File::Copy("2copy.txt", "copied.txt", false), System::IO::IOException);
    ASSERT_TRUE(IO::File::Exists("2copy.txt"));
    ASSERT_TRUE(IO::File::Exists("copied.txt"));
    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied.txt");
  }
  
  TEST(FileTest, CreateText) {
    IO::File::CreateText("created.txt");
    ASSERT_TRUE(IO::File::Exists("created.txt"));
    IO::File::Delete("created.txt");
  }
  
  TEST(FileTest, Move) {
    IO::File::WriteAllLines("2move.txt", {"First line", "Second line", "", "Third line"});
    IO::File::Move("2move.txt", "moved.txt");
    ASSERT_FALSE(IO::File::Exists("2move.txt"));
    ASSERT_TRUE(IO::File::Exists("moved.txt"));
    IO::File::Delete("moved.txt");
  }
  
  TEST(FileTest, WriteAllLines) {
    IO::File::WriteAllLines("Test.txt", {"First line", "Second line", "", "Third line"});
    Array<string> lines = IO::File::ReadAllLines("Test.txt");
    ASSERT_EQ(4, lines.Length);
    int32 index = 0;
    ASSERT_EQ("First line", lines[index++]);
    ASSERT_EQ("Second line", lines[index++]);
    ASSERT_EQ("", lines[index++]);
    ASSERT_EQ("Third line", lines[index++]);
    IO::File::Delete("Test.txt");
  }
  
  TEST(FileTest, WriteAllText) {
    IO::File::WriteAllText("Test.txt", "This is a text for a file !");
    string contents = IO::File::ReadAllText("Test.txt");
    ASSERT_EQ("This is a text for a file !", contents);
    IO::File::Delete("Test.txt");
  }
  
  TEST(FileTest, CreateTextWithPlusCharInFileName) {
    IO::File::CreateText("created+.txt");
    ASSERT_TRUE(IO::File::Exists("created+.txt"));
    IO::File::Delete("created+.txt");
  }
  
  TEST(FileTest, CopyWithPlusCharInFileName) {
    IO::File::CreateText("2copy.txt");
    IO::File::Copy("2copy.txt", "copied+.txt");
    ASSERT_TRUE(IO::File::Exists("2copy.txt"));
    ASSERT_TRUE(IO::File::Exists("copied+.txt"));
    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied+.txt");
  }
  
  TEST(FileTest, MoveWithPlusCharInFileName) {
    IO::File::CreateText("2move.txt");
    IO::File::Move("2move.txt", "moved+.txt");
    ASSERT_FALSE(IO::File::Exists("2move.txt"));
    ASSERT_TRUE(IO::File::Exists("moved+.txt"));
    IO::File::Delete("moved+.txt");
  }
}
