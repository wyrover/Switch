#include <Switch/System/IO/Directory.hpp>
#include <Switch/System/IO/Path.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class DirectoryTest : public TestFixture {
  protected:
    void SetUp() override {
      System::IO::Directory::CreateDirectory(workingDirectory);
    }
    
    void TearDown() override {
      System::IO::Directory::Delete(workingDirectory, true);
    }
    
    void CreateDirectory() {
      string testPath = System::IO::Path::Combine(workingDirectory, "TestFolder");
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
      System::IO::Directory::CreateDirectory(testPath);
      TUnit::Assert::IsTrue(System::IO::Directory::Exists(testPath));
    }
    
    void CreateAndDeleteAnEmptyDirectory() {
      string testPath = System::IO::Path::Combine(workingDirectory, "TestFolder");
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
      System::IO::Directory::CreateDirectory(testPath);
      TUnit::Assert::IsTrue(System::IO::Directory::Exists(testPath));
      System::IO::Directory::Delete(testPath);
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
    }
    
    void CreateAndDeleteANonEmptyDirectory() {
      string testPath = System::IO::Path::Combine(workingDirectory, "TestFolder");
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
      System::IO::Directory::CreateDirectory(testPath);
      System::IO::Directory::CreateDirectory(System::IO::Path::Combine(testPath, "Directory 1"));
      TUnit::Assert::IsTrue(System::IO::Directory::Exists(System::IO::Path::Combine(testPath, "Directory 1")));
      System::IO::Directory::Delete(testPath, true);
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
    }
    
  private:
    string workingDirectory = System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), "UnitTest");
  };
  
  _add_test (DirectoryTest, CreateDirectory)
  _add_test (DirectoryTest, CreateAndDeleteAnEmptyDirectory)
  _add_test (DirectoryTest, CreateAndDeleteANonEmptyDirectory)
}
