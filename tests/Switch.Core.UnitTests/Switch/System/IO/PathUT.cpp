#include <Switch/System/IO/Path.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class Path : public TestFixture {
  protected:
    void SetUp() override {
      savedCurrentDirectory = Environment::CurrentDirectory;
      Environment::CurrentDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
    }
    
    void TearDown() override {
      Environment::CurrentDirectory = savedCurrentDirectory;
    }
    
    void ChangeExtensionFileNameWithExtensionAndExtensionWithPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.txt", ".jpg"), _caller);
    }
    
    void ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.txt", "jpg"), _caller);
    }
    
    void ChangeExtensionFileNameWithExtensionAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file.txt", ""), _caller);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.", ".jpg"), _caller);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.", "jpg"), _caller);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file.", ""), _caller);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file", ".jpg"), _caller);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file", "jpg"), _caller);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file", ""), _caller);
    }
    
    void ChangeExtensionEmptyFileNameAndExtensionWithPeriod() {
      Assert::AreEqual("", System::IO::Path::ChangeExtension("", ".jpg"), _caller);
    }
    
    void ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod() {
      Assert::AreEqual("", System::IO::Path::ChangeExtension("", "jpg"), _caller);
    }
    
    void ChangeExtensionElptyFileNameAndEmptyExtension() {
      Assert::AreEqual(".", System::IO::Path::ChangeExtension("", ""), _caller);
    }
    
    void RootedPathGetPathRoot() {
      Assert::AreEqual("/", System::IO::Path::GetPathRoot("/Path"), _caller);
    }
    
    void RootedPathIsRooted() {
      Assert::IsTrue(System::IO::Path::IsPathRooted("/Path"), _caller);
    }
    
    void CombinePath1AndPath2() {
      Assert::AreEqual(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", "Path2"), _caller);
    }
    
    void CombinePath1WithInvalidCharAndPath2() {
      Assert::Throws<ArgumentException>([] {System::IO::Path::Combine("Path1\r", "Path2");}, _caller);
    }
    
    void CombinePath1AndPath2WithInvalidChar() {
      Assert::Throws<ArgumentException>([] {System::IO::Path::Combine("Path1", "Path2\r");}, _caller);
    }
    
    void CombinePath1AndEmptyPath2() {
      Assert::AreEqual(string::Format("Path1", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", ""), _caller);
    }
    
    void CombineEmptyPath1AndPath2() {
      Assert::AreEqual(string::Format("Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("", "Path2"), _caller);
    }
    
    void CombinePath1EndedWithDirectorySeparatorAndPath2() {
      Assert::AreEqual(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine(string::Format("Path1{0}", System::IO::Path::DirectorySeparatorChar()), "Path2"), _caller);
    }
    
    void CombinePath1AndPath2EndedWithDirectorySeparator() {
      Assert::AreEqual(string::Format("Path1{0}Path2{0}", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", string::Format("Path2{0}", System::IO::Path::DirectorySeparatorChar())), _caller);
    }
    
    void CombinePath1StartedWithDirectorySeparatorAndPath2() {
      Assert::AreEqual(string::Format("{0}Path1{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine(string::Format("{0}Path1", System::IO::Path::DirectorySeparatorChar()), "Path2"), _caller);
    }
    
    void CombinePath1AndPath2StartedWithDirectorySeparator() {
      Assert::AreEqual(string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar()), System::IO::Path::Combine("Path1", string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar())), _caller);
    }
    
    void GetExtensionFromPath() {
      Assert::AreEqual("", System::IO::Path::GetExtension("Path/"), _caller);
    }
    
    void GetExtensionFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetExtension("/Path/"), _caller);
    }
    
    void GetExtensionFromFileWithoutExtension() {
      Assert::AreEqual("", System::IO::Path::GetExtension("MyFile"), _caller);
    }
    
    void GetExtensionFromFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("MyFile.ext"), _caller);
    }
    
    void GetExtensionFromPathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("Path/MyFile.ext"), _caller);
    }
    
    void GetExtensionFromMultiplePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("Path/Path2/Path3/MyFile.ext"), _caller);
    }
    
    void GetExtensionFromAbsolutePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/MyFile.ext"), _caller);
    }
    
    void GetExtensionFromAbsoluteMultiplePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.ext"), _caller);
    }
    
    void GetExtensionFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/MyFile.Pattern.ext"), _caller);
    }
    
    void GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.Pattern.ext"), _caller);
    }
    
    void GetFileNameFromPath() {
      Assert::AreEqual("", System::IO::Path::GetFileName("Path/"), _caller);
    }
    
    void GetFileNameFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetFileName("/Path/"), _caller);
    }
    
    void GetFileNameFromFileWithoutExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileName("MyFile"), _caller);
    }
    
    void GetFileNameFromFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("MyFile.ext"), _caller);
    }
    
    void GetFileNameExtensionFromPathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("Path/MyFile.ext"), _caller);
    }
    
    void GetFileNameExtensionFromMultiplePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("Path/Path2/Path3/MyFile.ext"), _caller);
    }
    
    void GetFileNameFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName( "/Path/MyFile.ext"), _caller);
    }
    
    void GetFileNameFromAbsoluteMultiplePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName( "/Path/Path2/Path3/MyFile.ext"), _caller);
    }
    
    void GetFileNameFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/MyFile.Pattern.ext"), _caller);
    }
    
    void GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/Path2/Path3/MyFile.Pattern.ext"), _caller);
    }
    
    void GetFileNameWithoutExtensionFromPath() {
      Assert::AreEqual("", System::IO::Path::GetFileNameWithoutExtension("Path/"), _caller);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetFileNameWithoutExtension("/Path/"), _caller);
    }
    
    void GetFileNameWithoutExtensionFromFileWithoutExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile"), _caller);
    }
    
    void GetFileNameWithoutExtensionFromFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile.ext"), _caller);
    }
    
    void GetFileNameWithoutExtensionFromPathFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("Path/MyFile.ext"), _caller);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.ext"), _caller);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.Pattern.ext"), _caller);
    }
    
    void GetDirectoryNameFromPath() {
      Assert::AreEqual("Path", System::IO::Path::GetDirectoryName("Path/"), _caller);
    }
    
    void GetDirectoryNameFromMultiplePath() {
      Assert::AreEqual("Path/Path2/Path3", System::IO::Path::GetDirectoryName("Path/Path2/Path3/"), _caller);
    }
    
    void GetDirectoryNameFromAbsolutePath() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/"), _caller);
    }
    
    void GetDirectoryNameFromAbsoluteMultiplePath() {
      Assert::AreEqual("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/"), _caller);
    }
    
    void GetDirectoryNameFromFileWithoutExtension() {
      Assert::AreEqual("", System::IO::Path::GetDirectoryName("MyFile"), _caller);
    }
    
    void GetDirectoryNameFromFileWithExtension() {
      Assert::AreEqual("", System::IO::Path::GetDirectoryName("MyFile.ext"), _caller);
    }
    
    void GetDirectoryNameFromPathFileWithExtension() {
      Assert::AreEqual("Path", System::IO::Path::GetDirectoryName("Path/MyFile.ext"), _caller);
    }
    
    void GetDirectoryNameFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.ext"), _caller);
    }
    
    void GetDirectoryNameFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.Pattern.ext"), _caller);
    }
    
    void GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/MyFile.Pattern.ext"), _caller);
    }
    
    void DirectorySeparatorChar() {
      if (Environment::OSVersion().Platform() == PlatformID::Unix || Environment::OSVersion().Platform() == PlatformID::MacOSX || Environment::OSVersion().Platform() == PlatformID::IOs || Environment::OSVersion().Platform() == PlatformID::Android)
        Assert::AreEqual(char32('/'), System::IO::Path::DirectorySeparatorChar(), _caller);
      else
        Assert::AreEqual(char32('\\'), System::IO::Path::DirectorySeparatorChar(), _caller);
    }
    
    void GetFullPathOnRelativePath() {
      Assert::AreEqual(System::IO::Path::Combine(Environment::CurrentDirectory, "MyFolder"), System::IO::Path::GetFullPath("MyFolder"));
    }
    
  private:
    string savedCurrentDirectory;
  };
  
  _AddTest(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithPeriod)
  _AddTest(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod)
  _AddTest(Path, ChangeExtensionFileNameWithExtensionAndEmptyExtension)
  _AddTest(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod)
  _AddTest(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod)
  _AddTest(Path, ChangeExtensionFileNameEndWithPeriodAndEmptyExtension)
  _AddTest(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod)
  _AddTest(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod)
  _AddTest(Path, ChangeExtensionFileNameWithoutExtensionAndEmptyExtension)
  _AddTest(Path, ChangeExtensionEmptyFileNameAndExtensionWithPeriod)
  _AddTest(Path, ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod)
  _AddTest(Path, ChangeExtensionElptyFileNameAndEmptyExtension)
  _AddTest(Path, RootedPathGetPathRoot)
  _AddTest(Path, RootedPathIsRooted)
  _AddTest(Path, CombinePath1AndPath2)
  _AddTest(Path, CombinePath1WithInvalidCharAndPath2)
  _AddTest(Path, CombinePath1AndPath2WithInvalidChar)
  _AddTest(Path, CombinePath1AndEmptyPath2)
  _AddTest(Path, CombineEmptyPath1AndPath2)
  _AddTest(Path, CombinePath1EndedWithDirectorySeparatorAndPath2)
  _AddTest(Path, CombinePath1AndPath2EndedWithDirectorySeparator)
  _AddTest(Path, CombinePath1StartedWithDirectorySeparatorAndPath2)
  _AddTest(Path, CombinePath1AndPath2StartedWithDirectorySeparator)
  _AddTest(Path, GetExtensionFromPath)
  _AddTest(Path, GetExtensionFromAbsolutePath)
  _AddTest(Path, GetExtensionFromFileWithoutExtension)
  _AddTest(Path, GetExtensionFromFileWithExtension)
  _AddTest(Path, GetExtensionFromPathFileWithExtension)
  _AddTest(Path, GetExtensionFromMultiplePathFileWithExtension)
  _AddTest(Path, GetExtensionFromAbsolutePathFileWithExtension)
  _AddTest(Path, GetExtensionFromAbsoluteMultiplePathFileWithExtension)
  _AddTest(Path, GetExtensionFromAbsolutePathFilePatternWithExtension)
  _AddTest(Path, GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension)
  _AddTest(Path, GetFileNameFromPath)
  _AddTest(Path, GetFileNameFromAbsolutePath)
  _AddTest(Path, GetFileNameFromFileWithoutExtension)
  _AddTest(Path, GetFileNameFromFileWithExtension)
  _AddTest(Path, GetFileNameExtensionFromPathFileWithExtension)
  _AddTest(Path, GetFileNameExtensionFromMultiplePathFileWithExtension)
  _AddTest(Path, GetFileNameFromAbsolutePathFileWithExtension)
  _AddTest(Path, GetFileNameFromAbsoluteMultiplePathFileWithExtension)
  _AddTest(Path, GetFileNameFromAbsolutePathFilePatternWithExtension)
  _AddTest(Path, GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension)
  _AddTest(Path, GetFileNameWithoutExtensionFromPath)
  _AddTest(Path, GetFileNameWithoutExtensionFromAbsolutePath)
  _AddTest(Path, GetFileNameWithoutExtensionFromFileWithoutExtension)
  _AddTest(Path, GetFileNameWithoutExtensionFromFileWithExtension)
  _AddTest(Path, GetFileNameWithoutExtensionFromPathFileWithExtension)
  _AddTest(Path, GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension)
  _AddTest(Path, GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension)
  _AddTest(Path, GetDirectoryNameFromPath)
  _AddTest(Path, GetDirectoryNameFromMultiplePath)
  _AddTest(Path, GetDirectoryNameFromAbsolutePath)
  _AddTest(Path, GetDirectoryNameFromAbsoluteMultiplePath)
  _AddTest(Path, GetDirectoryNameFromFileWithoutExtension)
  _AddTest(Path, GetDirectoryNameFromFileWithExtension)
  _AddTest(Path, GetDirectoryNameFromPathFileWithExtension)
  _AddTest(Path, GetDirectoryNameFromAbsolutePathFileWithExtension)
  _AddTest(Path, GetDirectoryNameFromAbsolutePathFilePatternWithExtension)
  _AddTest(Path, GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension)
  _AddTest(Path, DirectorySeparatorChar)
  _AddTest(Path, GetFullPathOnRelativePath)
}

