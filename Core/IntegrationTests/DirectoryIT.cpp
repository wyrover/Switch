#include <Pcf/System/IO/Directory.h>
#include <Pcf/System/IO/File.h>
#include <Pcf/System/IO/Path.h>
#include <Pcf/System/IO/StreamWriter.h>
#include <Pcf/System/Console.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading;
using namespace TUnit;

// To use a test fixture, derive a class from testing::Test.  
class Directory : public testing::Test {  
protected: 
  void SetUp() override {
    this->pathDir1 = IO::Path::Combine(IO::Directory::GetCurrentDirectory(), "DirTest1");
    this->pathDir2 = IO::Path::Combine(this->pathDir1, "DirTest2");
  }    

  void TearDown() override {
    if (IO::Directory::Exists(this->pathDir1))
      IO::Directory::Delete(this->pathDir1, true);
  }

  string pathDir1;
  string pathDir2;
};  

TEST_F(Directory, GetName) {
  IO::DirectoryInfo info(this->pathDir1);
  string dirName(info.Name());
  EXPECT_FALSE(string::IsNullOrEmpty(dirName));
  EXPECT_FALSE(IO::Path::IsPathRooted(dirName));
  EXPECT_EQ("DirTest1", dirName);
}

TEST_F(Directory, CreateDeleteExist) {
  EXPECT_TRUE(IO::Directory::GetCurrentDirectory() == Environment::CurrentDirectory());
  IO::DirectoryInfo directoryInfo(this->pathDir1);
  EXPECT_FALSE(directoryInfo.Exists());
  directoryInfo.Create();
  EXPECT_TRUE(directoryInfo.Exists());
  directoryInfo.Delete();
  EXPECT_FALSE(directoryInfo.Exists());

  directoryInfo = IO::Directory::CreateDirectory(this->pathDir1);
  EXPECT_TRUE(directoryInfo.Exists());
  IO::DirectoryInfo subDirectoryInfo = IO::Directory::CreateDirectory(IO::Path::Combine(directoryInfo.FullName(), "DirTestYfi"));
  EXPECT_TRUE(subDirectoryInfo.Exists());
  EXPECT_TRUE(subDirectoryInfo.Parent().Equals(directoryInfo));
  IO::Directory::Delete(subDirectoryInfo.FullName());
  EXPECT_FALSE(subDirectoryInfo.Exists());
  subDirectoryInfo = IO::Directory::CreateDirectory(IO::Path::Combine(directoryInfo.FullName(), "DirTestJYfi"));
  EXPECT_TRUE(subDirectoryInfo.Exists());
  IO::Directory::Delete(directoryInfo.FullName(), true);
  EXPECT_FALSE(directoryInfo.Exists());
}

TEST_F(Directory, DirectoryTime) {
  IO::DirectoryInfo directoryInfo(this->pathDir1);
  EXPECT_FALSE(directoryInfo.Exists());
  DateTime now = DateTime::Now;
  directoryInfo.Create();
  EXPECT_TRUE(directoryInfo.Exists());

  DateTime creationTime = IO::Directory::GetCreationTime(this->pathDir1);
  Console::WriteLine("CreationTime = {0}", creationTime);
  TimeSpan elapsedTime = now.Subtract(creationTime);
  double totalMillSeconds = elapsedTime.TotalMilliseconds();
  EXPECT_LT(Convert::ToInt32(totalMillSeconds), 5000);
}

TEST_F(Directory, CreateSubDirectoryAndDeleteRecursive) {
  IO::DirectoryInfo directoryInfo(this->pathDir1);
  directoryInfo.Create();
  IO::DirectoryInfo subDir = directoryInfo.CreateSubdirectory("DirTest3");
  EXPECT_TRUE(subDir.Exists());
  directoryInfo.Delete(true);
  EXPECT_FALSE(directoryInfo.Exists());
}

TEST_F(Directory, GetDirectories) {
  IO::DirectoryInfo directoryInfo(this->pathDir1);
  directoryInfo.Create();
  EXPECT_TRUE(directoryInfo.Exists());
  IO::DirectoryInfo subDir1 = directoryInfo.CreateSubdirectory("DirTest1");
  IO::DirectoryInfo subDir2 = directoryInfo.CreateSubdirectory("DirTest2");
  IO::DirectoryInfo subDir3 = directoryInfo.CreateSubdirectory("DirTes3");
  EXPECT_TRUE(subDir1.Exists());
  EXPECT_TRUE(subDir2.Exists());
  EXPECT_TRUE(subDir3.Exists());

  Array<IO::DirectoryInfo> dirInfo;
  dirInfo = directoryInfo.GetDirectories();
  EXPECT_TRUE(dirInfo.Length == 3);
  dirInfo = directoryInfo.GetDirectories("DirTest*");
  EXPECT_TRUE(dirInfo.Length == 2);
  dirInfo = directoryInfo.GetDirectories("yfi*");
  EXPECT_TRUE(dirInfo.Length == 0);
}

TEST_F(Directory, DISABLED_MoveAndListDirectoriesFiles) {
  IO::DirectoryInfo directoryInfo(this->pathDir1);
  EXPECT_THROW(directoryInfo.MoveTo(this->pathDir2), IO::IOException);
  directoryInfo.Create();
  EXPECT_THROW(directoryInfo.MoveTo(this->pathDir2), IO::IOException);
  EXPECT_THROW(directoryInfo.MoveTo(directoryInfo.FullName()), IO::IOException);

  IO::DirectoryInfo subDirInfo = directoryInfo.CreateSubdirectory("DirTest3");
  IO::DirectoryInfo subDirInfo2 = subDirInfo.CreateSubdirectory("DirTest4");

  // Create a file
  pcf_using(IO::StreamWriter streamWriter1 = IO::File::CreateText(IO::Path::Combine(subDirInfo2.FullName(), "TestFile.txt"))) {
    streamWriter1.WriteLine(string("Test1"));
    streamWriter1.WriteLine(string("Test2"));
  }

  pcf_using(IO::StreamWriter streamWriter2 = IO::File::CreateText(IO::Path::Combine(subDirInfo2.FullName(), "TestFile2.txt"))) {
    streamWriter2.WriteLine(string("Test1"));
    streamWriter2.WriteLine(string("Test2"));
  }

  subDirInfo.MoveTo(IO::Directory::GetCurrentDirectory());
  EXPECT_TRUE(subDirInfo.Exists());

  Array<IO::DirectoryInfo> dirInfo;
  dirInfo = subDirInfo.GetDirectories();
  EXPECT_TRUE(dirInfo.Length == 1);

  Array<IO::FileInfo> fileInfo;
  fileInfo = dirInfo[0].GetFiles("TestFile*");
  EXPECT_TRUE(fileInfo.Length == 2);
  EXPECT_TRUE(fileInfo[0].FullName().Contains("TestFile"));

  subDirInfo.Delete(true);
  EXPECT_FALSE(subDirInfo.Exists());
}

