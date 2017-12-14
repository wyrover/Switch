#include <Switch/System/IO/Path.hpp>
#include <Switch/System/Environment.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  class PathTest : public testing::Test {
  public:
    void SetUp() override {
      savedCurrentDirectory = Environment::CurrentDirectory;
      Environment::CurrentDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
    }

    void TearDown() override {
      Environment::CurrentDirectory = savedCurrentDirectory;
    }

    string savedCurrentDirectory;
  };

  TEST_F(PathTest, ChangeExtensionFileNameWithExtensionAndExtensionWithPeriod) {
    ASSERT_EQ("file.jpg", System::IO::Path::ChangeExtension("file.txt", ".jpg"));
  }

  TEST_F(PathTest, ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod) {
    ASSERT_EQ("file.jpg", System::IO::Path::ChangeExtension("file.txt", "jpg"));
  }

  TEST_F(PathTest, ChangeExtensionFileNameWithExtensionAndEmptyExtension) {
    ASSERT_EQ("file.", System::IO::Path::ChangeExtension("file.txt", ""));
  }

  TEST_F(PathTest, ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod) {
    ASSERT_EQ("file.jpg", System::IO::Path::ChangeExtension("file.", ".jpg"));
  }

  TEST_F(PathTest, ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod) {
    ASSERT_EQ("file.jpg", System::IO::Path::ChangeExtension("file.", "jpg"));
  }

  TEST_F(PathTest, ChangeExtensionFileNameEndWithPeriodAndEmptyExtension) {
    ASSERT_EQ("file.", System::IO::Path::ChangeExtension("file.", ""));
  }

  TEST_F(PathTest, ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod) {
    ASSERT_EQ("file.jpg", System::IO::Path::ChangeExtension("file", ".jpg"));
  }

  TEST_F(PathTest, ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod) {
    ASSERT_EQ("file.jpg", System::IO::Path::ChangeExtension("file", "jpg"));
  }

  TEST_F(PathTest, ChangeExtensionFileNameWithoutExtensionAndEmptyExtension) {
    ASSERT_EQ("file.", System::IO::Path::ChangeExtension("file", ""));
  }

  TEST_F(PathTest, ChangeExtensionEmptyFileNameAndExtensionWithPeriod) {
    ASSERT_EQ("", System::IO::Path::ChangeExtension("", ".jpg"));
  }

  TEST_F(PathTest, ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod) {
    ASSERT_EQ("", System::IO::Path::ChangeExtension("", "jpg"));
  }

  TEST_F(PathTest, ChangeExtensionElptyFileNameAndEmptyExtension) {
    ASSERT_EQ(".", System::IO::Path::ChangeExtension("", ""));
  }

  TEST_F(PathTest, RootedPathGetPathRoot) {
    ASSERT_EQ("/", System::IO::Path::GetPathRoot("/Path"));
  }

  TEST_F(PathTest, RootedPathIsRooted) {
    ASSERT_TRUE(System::IO::Path::IsPathRooted("/Path"));
  }

  TEST_F(PathTest, CombinePath1AndPath2) {
    ASSERT_EQ(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", "Path2"));
  }

  TEST_F(PathTest, CombinePath1WithInvalidCharAndPath2) {
    ASSERT_THROW(System::IO::Path::Combine("Path1\r", "Path2"), ArgumentException);
  }

  TEST_F(PathTest, CombinePath1AndPath2WithInvalidChar) {
    ASSERT_THROW(System::IO::Path::Combine("Path1", "Path2\r"), ArgumentException);
  }

  TEST_F(PathTest, CombinePath1AndEmptyPath2) {
    ASSERT_EQ(string::Format("Path1", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", ""));
  }

  TEST_F(PathTest, CombineEmptyPath1AndPath2) {
    ASSERT_EQ(string::Format("Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("", "Path2"));
  }

  TEST_F(PathTest, CombinePath1EndedWithDirectorySeparatorAndPath2) {
    ASSERT_EQ(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine(string::Format("Path1{0}", System::IO::Path::DirectorySeparatorChar()), "Path2"));
  }

  TEST_F(PathTest, CombinePath1AndPath2EndedWithDirectorySeparator) {
    ASSERT_EQ(string::Format("Path1{0}Path2{0}", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", string::Format("Path2{0}", System::IO::Path::DirectorySeparatorChar())));
  }

  TEST_F(PathTest, CombinePath1StartedWithDirectorySeparatorAndPath2) {
    ASSERT_EQ(string::Format("{0}Path1{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine(string::Format("{0}Path1", System::IO::Path::DirectorySeparatorChar()), "Path2"));
  }

  TEST_F(PathTest, CombinePath1AndPath2StartedWithDirectorySeparator) {
    ASSERT_EQ(string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar())));
  }

  TEST_F(PathTest, GetExtensionFromPath) {
    ASSERT_EQ("", System::IO::Path::GetExtension("Path/"));
  }

  TEST_F(PathTest, GetExtensionFromAbsolutePath) {
    ASSERT_EQ("", System::IO::Path::GetExtension("/Path/"));
  }

  TEST_F(PathTest, GetExtensionFromFileWithoutExtension) {
    ASSERT_EQ("", System::IO::Path::GetExtension("MyFile"));
  }

  TEST_F(PathTest, GetExtensionFromFileWithExtension) {
    ASSERT_EQ(".ext", System::IO::Path::GetExtension("MyFile.ext"));
  }

  TEST_F(PathTest, GetExtensionFromPathFileWithExtension) {
    ASSERT_EQ(".ext", System::IO::Path::GetExtension("Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetExtensionFromMultiplePathFileWithExtension) {
    ASSERT_EQ(".ext", System::IO::Path::GetExtension("Path/Path2/Path3/MyFile.ext"));
  }

  TEST_F(PathTest, GetExtensionFromAbsolutePathFileWithExtension) {
    ASSERT_EQ(".ext", System::IO::Path::GetExtension("/Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetExtensionFromAbsoluteMultiplePathFileWithExtension) {
    ASSERT_EQ(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.ext"));
  }

  TEST_F(PathTest, GetExtensionFromAbsolutePathFilePatternWithExtension) {
    ASSERT_EQ(".ext", System::IO::Path::GetExtension("/Path/MyFile.Pattern.ext"));
  }

  TEST_F(PathTest, GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension) {
    ASSERT_EQ(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.Pattern.ext"));
  }

  TEST_F(PathTest, GetFileNameFromPath) {
    ASSERT_EQ("", System::IO::Path::GetFileName("Path/"));
  }

  TEST_F(PathTest, GetFileNameFromAbsolutePath) {
    ASSERT_EQ("", System::IO::Path::GetFileName("/Path/"));
  }

  TEST_F(PathTest, GetFileNameFromFileWithoutExtension) {
    ASSERT_EQ("MyFile", System::IO::Path::GetFileName("MyFile"));
  }

  TEST_F(PathTest, GetFileNameFromFileWithExtension) {
    ASSERT_EQ("MyFile.ext", System::IO::Path::GetFileName("MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameExtensionFromPathFileWithExtension) {
    ASSERT_EQ("MyFile.ext", System::IO::Path::GetFileName("Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameExtensionFromMultiplePathFileWithExtension) {
    ASSERT_EQ("MyFile.ext", System::IO::Path::GetFileName("Path/Path2/Path3/MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameFromAbsolutePathFileWithExtension) {
    ASSERT_EQ("MyFile.ext", System::IO::Path::GetFileName("/Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameFromAbsoluteMultiplePathFileWithExtension) {
    ASSERT_EQ("MyFile.ext", System::IO::Path::GetFileName("/Path/Path2/Path3/MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameFromAbsolutePathFilePatternWithExtension) {
    ASSERT_EQ("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/MyFile.Pattern.ext"));
  }

  TEST_F(PathTest, GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension) {
    ASSERT_EQ("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/Path2/Path3/MyFile.Pattern.ext"));
  }

  TEST_F(PathTest, GetFileNameWithoutExtensionFromPath) {
    ASSERT_EQ("", System::IO::Path::GetFileNameWithoutExtension("Path/"));
  }

  TEST_F(PathTest, GetFileNameWithoutExtensionFromAbsolutePath) {
    ASSERT_EQ("", System::IO::Path::GetFileNameWithoutExtension("/Path/"));
  }

  TEST_F(PathTest, GetFileNameWithoutExtensionFromFileWithoutExtension) {
    ASSERT_EQ("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile"));
  }

  TEST_F(PathTest, GetFileNameWithoutExtensionFromFileWithExtension) {
    ASSERT_EQ("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameWithoutExtensionFromPathFileWithExtension) {
    ASSERT_EQ("MyFile", System::IO::Path::GetFileNameWithoutExtension("Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension) {
    ASSERT_EQ("MyFile", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension) {
    ASSERT_EQ("MyFile.Pattern", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.Pattern.ext"));
  }

  TEST_F(PathTest, GetDirectoryNameFromPath) {
    ASSERT_EQ("Path", System::IO::Path::GetDirectoryName("Path/"));
  }

  TEST_F(PathTest, GetDirectoryNameFromMultiplePath) {
    ASSERT_EQ("Path/Path2/Path3", System::IO::Path::GetDirectoryName("Path/Path2/Path3/"));
  }

  TEST_F(PathTest, GetDirectoryNameFromAbsolutePath) {
    ASSERT_EQ("/Path", System::IO::Path::GetDirectoryName("/Path/"));
  }

  TEST_F(PathTest, GetDirectoryNameFromAbsoluteMultiplePath) {
    ASSERT_EQ("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/"));
  }

  TEST_F(PathTest, GetDirectoryNameFromFileWithoutExtension) {
    ASSERT_EQ("", System::IO::Path::GetDirectoryName("MyFile"));
  }

  TEST_F(PathTest, GetDirectoryNameFromFileWithExtension) {
    ASSERT_EQ("", System::IO::Path::GetDirectoryName("MyFile.ext"));
  }

  TEST_F(PathTest, GetDirectoryNameFromPathFileWithExtension) {
    ASSERT_EQ("Path", System::IO::Path::GetDirectoryName("Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetDirectoryNameFromAbsolutePathFileWithExtension) {
    ASSERT_EQ("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.ext"));
  }

  TEST_F(PathTest, GetDirectoryNameFromAbsolutePathFilePatternWithExtension) {
    ASSERT_EQ("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.Pattern.ext"));
  }

  TEST_F(PathTest, GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension) {
    ASSERT_EQ("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/MyFile.Pattern.ext"));
  }

  TEST_F(PathTest, DirectorySeparatorChar) {
    if (Environment::OSVersion().Platform() == PlatformID::Unix || Environment::OSVersion().Platform() == PlatformID::MacOSX || Environment::OSVersion().Platform() == PlatformID::IOs || Environment::OSVersion().Platform() == PlatformID::Android)
      ASSERT_EQ(char32('/'), System::IO::Path::DirectorySeparatorChar());
    else
      ASSERT_EQ(char32('\\'), System::IO::Path::DirectorySeparatorChar());
  }

  TEST_F(PathTest, GetFullPathOnRelativePath) {
    ASSERT_EQ(System::IO::Path::Combine(Environment::CurrentDirectory, "MyFolder"), System::IO::Path::GetFullPath("MyFolder"));
  }
}
