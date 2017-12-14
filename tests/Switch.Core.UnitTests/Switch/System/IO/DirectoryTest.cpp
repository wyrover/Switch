#include <Switch/System/IO/Directory.hpp>
#include <Switch/System/IO/Path.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  class DirectoryTest : public testing::Test {
  public:
    void SetUp() override {
      System::IO::Directory::CreateDirectory(workingDirectory);
    }

    void TearDown() override {
      System::IO::Directory::Delete(workingDirectory, true);
    }

    string workingDirectory = System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), "UnitTest");
  };

  TEST_F(DirectoryTest, CreateDirectory) {
    string testPath = System::IO::Path::Combine(DirectoryTest::workingDirectory, "TestFolder");
    ASSERT_FALSE(System::IO::Directory::Exists(testPath));
    System::IO::Directory::CreateDirectory(testPath);
    ASSERT_TRUE(System::IO::Directory::Exists(testPath));
    System::IO::Directory::Delete(testPath);
    ASSERT_FALSE(System::IO::Directory::Exists(testPath));
  }

  TEST_F(DirectoryTest, CreateAndDeleteAnEmptyDirectory) {
    string testPath = System::IO::Path::Combine(DirectoryTest::workingDirectory, "TestFolder");
    ASSERT_FALSE(System::IO::Directory::Exists(testPath));
    System::IO::Directory::CreateDirectory(testPath);
    ASSERT_TRUE(System::IO::Directory::Exists(testPath));
    System::IO::Directory::Delete(testPath);
    ASSERT_FALSE(System::IO::Directory::Exists(testPath));
  }

  TEST_F(DirectoryTest, CreateAndDeleteANonEmptyDirectory) {
    string testPath = System::IO::Path::Combine(DirectoryTest::workingDirectory, "TestFolder");
    ASSERT_FALSE(System::IO::Directory::Exists(testPath));
    System::IO::Directory::CreateDirectory(testPath);
    System::IO::Directory::CreateDirectory(System::IO::Path::Combine(testPath, "Directory 1"));
    ASSERT_TRUE(System::IO::Directory::Exists(System::IO::Path::Combine(testPath, "Directory 1")));
    System::IO::Directory::Delete(testPath, true);
    ASSERT_FALSE(System::IO::Directory::Exists(testPath));
  }
}

