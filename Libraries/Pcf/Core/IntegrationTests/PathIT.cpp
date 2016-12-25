#include <Pcf/System/IO/Path.h>
#include <Pcf/System/IO/DriveInfo.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

// To use a test fixture, derive a class from testing::Test.  
class Path : public testing::Test {  

protected: 
  void SetUp() override {
    this->nullString = null;
    this->nullString2 = null;
    
    Array<IO::DriveInfo> drives = IO::DriveInfo::GetDrives();
    int32 nbDrives = drives.Length;
    EXPECT_TRUE(nbDrives > 0);
    for (int32_t k=nbDrives-1; k>=0; k--) { //take the last drive to build path
      IO::DriveType driveType = drives[k].DriveType();
      if (driveType == IO::DriveType::Fixed || driveType == IO::DriveType::Removable) {
        this->pathRoot = drives[k].Name();
        break;
      }
    }
    if (!string::IsNullOrEmpty(this->pathRoot)) {
      string pathSeparator = Char(IO::Path::DirectorySeparatorChar).ToString();

      // Path separator always at the end of the path root
      if (!this->pathRoot.EndsWith(pathSeparator))
        this->pathRoot += pathSeparator;

      this->extension = string(".txt");
      this->fileNameWithoutExtension = string("TestFile");
      this->dirName = pathSeparator + string("Temp") + pathSeparator + string("Path") + pathSeparator;
      
      this->dirPath = this->pathRoot + "Temp" + pathSeparator + "Path";
      this->otherDirPath = this->dirPath + pathSeparator;
      this->dirPath.ToCCharArray()[3] = 34;
      this->invalidDirPath = string(this->dirPath.ToCCharArray().Data());
      //Console::WriteLine("invalidDirPath: " + this->invalidDirPath);
 
      this->fileName = string("TestFile.txt");
      this->invalidFileName = string("TestFile" + Char(60) + "txt");

      this->fullPath = this->dirPath + pathSeparator + this->fileName;
      this->invalidFullPath = this->invalidDirPath + pathSeparator + this->invalidFileName;
    }
  }

  void TearDown() override {

  }

  // Declares the variables your tests want to use.  
  string* nullString;  
  string* nullString2;
  string dirPath;
  string otherDirPath;
  string invalidDirPath;
  string fileName;
  string invalidFileName;
  string fullPath;
  string invalidFullPath;
  string dirName;
  string extension;
  string fileNameWithoutExtension;
  string pathRoot;
};  

TEST_F(Path, Combine) {
  EXPECT_THROW(IO::Path::Combine(*this->nullString, this->fileName), ArgumentException);
  EXPECT_THROW(IO::Path::Combine(dirPath, *this->nullString2), ArgumentException);
  EXPECT_THROW(IO::Path::Combine(this->invalidDirPath, this->fileName), ArgumentException);
  EXPECT_THROW(IO::Path::Combine(dirPath, this->invalidFileName), ArgumentException);
  EXPECT_TRUE(IO::Path::Combine(dirPath, string::Empty) == dirPath);
  EXPECT_TRUE(IO::Path::Combine(string::Empty, this->fileName) == this->fileName);
  EXPECT_TRUE(IO::Path::Combine(dirPath, this->fileName) == this->fullPath);
  EXPECT_TRUE(IO::Path::Combine(this->otherDirPath, this->fileName) == this->fullPath);
}

TEST_F(Path, GetDirectoryName) {
  EXPECT_THROW(IO::Path::GetDirectoryName(*this->nullString), ArgumentException);
  EXPECT_THROW(IO::Path::GetDirectoryName(this->invalidFullPath), ArgumentException);
  EXPECT_TRUE(IO::Path::GetDirectoryName(this->fullPath).EndsWith(this->dirName));
}

TEST_F(Path, GetExtension) {
  EXPECT_THROW(IO::Path::GetExtension(*this->nullString), ArgumentException);
  EXPECT_THROW(IO::Path::GetExtension(this->invalidFileName), ArgumentException);
  EXPECT_TRUE(IO::Path::GetExtension(this->fileName) == this->extension);
}

TEST_F(Path, GetFileName) {
  EXPECT_THROW(IO::Path::GetFileName(*this->nullString), ArgumentException);
  EXPECT_THROW(IO::Path::GetFileName(this->invalidFullPath), ArgumentException);
  EXPECT_TRUE(IO::Path::GetFileName(this->fullPath) == this->fileName);
  EXPECT_TRUE(IO::Path::GetFileName(this->fileName) == this->fileName);
}

TEST_F(Path, GetFileNameWithoutExtension) {
  EXPECT_THROW(IO::Path::GetFileNameWithoutExtension(*this->nullString), ArgumentException);
  EXPECT_THROW(IO::Path::GetFileNameWithoutExtension(this->invalidFullPath), ArgumentException);
  EXPECT_TRUE(IO::Path::GetFileNameWithoutExtension(this->fullPath) == this->fileNameWithoutExtension);
  EXPECT_TRUE(IO::Path::GetFileNameWithoutExtension(this->fileName) == this->fileNameWithoutExtension);
}

TEST_F(Path, GetFullPath) {
  EXPECT_THROW(IO::Path::GetFullPath(*this->nullString), ArgumentException);
  EXPECT_THROW(IO::Path::GetFullPath(this->invalidFullPath), ArgumentException);
  EXPECT_TRUE(IO::Path::GetFullPath(this->fullPath) == this->fullPath);
  EXPECT_TRUE(IO::Path::GetFullPath(this->fileName) == IO::Path::Combine(Environment::CurrentDirectory(), this->fileName));
  EXPECT_NO_THROW(IO::Path::GetFullPath("."));
}

TEST_F(Path, GetPathRoot) {
  EXPECT_THROW(IO::Path::GetPathRoot(*this->nullString), ArgumentException);
  EXPECT_THROW(IO::Path::GetPathRoot(this->invalidFullPath), ArgumentException);
  EXPECT_TRUE(IO::Path::GetPathRoot(this->fullPath) == this->pathRoot);
  EXPECT_TRUE(IO::Path::GetPathRoot(dirPath) == this->pathRoot);
}

}
