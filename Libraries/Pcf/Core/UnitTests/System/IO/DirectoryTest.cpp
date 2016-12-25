#include <Pcf/System/IO/Directory.h>
#include <Pcf/System/IO/Path.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class DirectoryTest : public TestFixture {
  protected:
    void SetUp() override {
      System::IO::Directory::CreateDirectory(workingDirectory);
    }
    
    void TearDown() override {
      System::IO::Directory::Delete(workingDirectory, true);
    }
    
    void CreateDirectory() {
      string testPath = System::IO::Path::Combine(workingDirectory, "Test");
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
      System::IO::Directory::CreateDirectory(testPath);
      TUnit::Assert::IsTrue(System::IO::Directory::Exists(testPath));
    }
    
    void CreateAndDeleteAnEmptyDirectory() {
      string testPath = System::IO::Path::Combine(workingDirectory, "Test");
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
      System::IO::Directory::CreateDirectory(testPath);
      TUnit::Assert::IsTrue(System::IO::Directory::Exists(testPath));
      System::IO::Directory::Delete(testPath);
      TUnit::Assert::IsFalse(System::IO::Directory::Exists(testPath));
    }
    
    void CreateAndDeleteANonEmptyDirectory() {
      string testPath = System::IO::Path::Combine(workingDirectory, "Test");
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
  
  pcf_test(DirectoryTest, CreateDirectory);
  pcf_test(DirectoryTest, CreateAndDeleteAnEmptyDirectory);
  pcf_test(DirectoryTest, CreateAndDeleteANonEmptyDirectory);
}
