#include <Switch/System/IO/File.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  TEST(File, AppendAllLines) {
    IO::File::WriteAllLines("Test.txt", {"First line", "Second line", "", "Third line"});
    IO::File::AppendAllLines("Test.txt", Array<string> {"Fourth line", "Fifth line"});
    Array<string> lines = IO::File::ReadAllLines("Test.txt");
    EXPECT_EQ(6, lines.Length);
    int32 index = 0;
    EXPECT_EQ("First line", lines[index++]);
    EXPECT_EQ("Second line", lines[index++]);
    EXPECT_EQ("", lines[index++]);
    EXPECT_EQ("Third line", lines[index++]);
    EXPECT_EQ("Fourth line", lines[index++]);
    EXPECT_EQ("Fifth line", lines[index++]);
    IO::File::Delete("Test.txt");
  }
    
  TEST(File, AppendAllText) {
    IO::File::WriteAllText("Test.txt", "This is a text for a file !");
    IO::File::AppendAllText("Test.txt", " End the appended text is here !");
    string contents = IO::File::ReadAllText("Test.txt");
    EXPECT_EQ("This is a text for a file ! End the appended text is here !", contents);
    IO::File::Delete("Test.txt");
  }
    
  TEST(File, AppendText) {
    sw_using(IO::StreamWriter sw = IO::File::CreateText("Test.txt")) {
      sw.WriteLine("First line");
    }

    sw_using(IO::StreamWriter sw = IO::File::AppendText("Test.txt")) {
      sw.WriteLine("Second line");
    }

    sw_using(Array<string> lines = IO::File::ReadAllLines("Test.txt")) {
      EXPECT_EQ(2, lines.Length);
      int32 index = 0;
      EXPECT_EQ("First line", lines[index++]);
      EXPECT_EQ("Second line", lines[index++]);
    }

    IO::File::Delete("Test.txt");
  }

  TEST(File, Copy) {
    IO::File::WriteAllLines("2copy.txt", {"First line", "Second line", "", "Third line"});
    IO::File::Copy("2copy.txt", "copied.txt");
    EXPECT_TRUE(IO::File::Exists("2copy.txt"));
    EXPECT_TRUE(IO::File::Exists("copied.txt"));

    sw_using(Array<string> lines = IO::File::ReadAllLines("copied.txt")) {
      EXPECT_EQ(4, lines.Length);
      int32 index = 0;
      EXPECT_EQ("First line", lines[index++]);
      EXPECT_EQ("Second line", lines[index++]);
      EXPECT_EQ("", lines[index++]);
      EXPECT_EQ("Third line", lines[index++]);
    }

    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied.txt");
  }

  TEST(File, CopyWithOverwrite) {
    IO::File::WriteAllLines("2copy.txt", {"First line", "Second line", "", "Third line"});
    IO::File::WriteAllLines("copied.txt", {"Fourth line", "Fifth line", "", "Sixth line"});
    IO::File::Copy("2copy.txt", "copied.txt", true);
    EXPECT_TRUE(IO::File::Exists("2copy.txt"));
    EXPECT_TRUE(IO::File::Exists("copied.txt"));

    sw_using(Array<string> lines = IO::File::ReadAllLines("copied.txt")) {
      EXPECT_EQ(4, lines.Length);
      int32 index = 0;
      EXPECT_EQ("First line", lines[index++]);
      EXPECT_EQ("Second line", lines[index++]);
      EXPECT_EQ("", lines[index++]);
      EXPECT_EQ("Third line", lines[index++]);
    }

    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied.txt");
  }

  TEST(File, CopyWithoutOverwrite) {
    IO::File::WriteAllLines("2copy.txt", {"First line", "Second line", "", "Third line"});
    IO::File::WriteAllLines("copied.txt", {"Fourth line", "Fifth line", "", "Sixth line"});
    EXPECT_THROW(IO::File::Copy("2copy.txt", "copied.txt", false), System::IO::IOException);
    EXPECT_TRUE(IO::File::Exists("2copy.txt"));
    EXPECT_TRUE(IO::File::Exists("copied.txt"));
    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied.txt");
  }

  TEST(File, CreateText) {
    IO::File::CreateText("created.txt");
    EXPECT_TRUE(IO::File::Exists("created.txt"));
    IO::File::Delete("created.txt");
  }

  TEST(File, Move) {
    IO::File::WriteAllLines("2move.txt", {"First line", "Second line", "", "Third line"});
    IO::File::Move("2move.txt", "moved.txt");
    EXPECT_FALSE(IO::File::Exists("2move.txt"));
    EXPECT_TRUE(IO::File::Exists("moved.txt"));
    IO::File::Delete("moved.txt");
  }

  TEST(File, WriteAllLines) {
    IO::File::WriteAllLines("Test.txt", {"First line", "Second line", "", "Third line"});
    Array<string> lines = IO::File::ReadAllLines("Test.txt");
    EXPECT_EQ(4, lines.Length);
    int32 index = 0;
    EXPECT_EQ("First line", lines[index++]);
    EXPECT_EQ("Second line", lines[index++]);
    EXPECT_EQ("", lines[index++]);
    EXPECT_EQ("Third line", lines[index++]);
    IO::File::Delete("Test.txt");
  }
  
  TEST(File, WriteAllText) {
    IO::File::WriteAllText("Test.txt", "This is a text for a file !");
    string contents = IO::File::ReadAllText("Test.txt");
    EXPECT_EQ("This is a text for a file !", contents);
    IO::File::Delete("Test.txt");
  }

  TEST(File, CreateTextWithPlusCharInFileName) {
    IO::File::CreateText("created+.txt");
    EXPECT_TRUE(IO::File::Exists("created+.txt"));
    IO::File::Delete("created+.txt");
  }

  TEST(File, CopyWithPlusCharInFileName) {
    IO::File::CreateText("2copy.txt");
    IO::File::Copy("2copy.txt", "copied+.txt");
    EXPECT_TRUE(IO::File::Exists("2copy.txt"));
    EXPECT_TRUE(IO::File::Exists("copied+.txt"));
    IO::File::Delete("2copy.txt");
    IO::File::Delete("copied+.txt");
  }

  TEST(File, MoveWithPlusCharInFileName) {
    IO::File::CreateText("2move.txt");
    IO::File::Move("2move.txt", "moved+.txt");
    EXPECT_FALSE(IO::File::Exists("2move.txt"));
    EXPECT_TRUE(IO::File::Exists("moved+.txt"));
    IO::File::Delete("moved+.txt");
  }
}
