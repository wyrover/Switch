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
  
  _add_test(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithPeriod)
  _add_test(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod)
  _add_test(Path, ChangeExtensionFileNameWithExtensionAndEmptyExtension)
  _add_test(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod)
  _add_test(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod)
  _add_test(Path, ChangeExtensionFileNameEndWithPeriodAndEmptyExtension)
  _add_test(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod)
  _add_test(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod)
  _add_test(Path, ChangeExtensionFileNameWithoutExtensionAndEmptyExtension)
  _add_test(Path, ChangeExtensionEmptyFileNameAndExtensionWithPeriod)
  _add_test(Path, ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod)
  _add_test(Path, ChangeExtensionElptyFileNameAndEmptyExtension)
  _add_test(Path, RootedPathGetPathRoot)
  _add_test(Path, RootedPathIsRooted)
  _add_test(Path, CombinePath1AndPath2)
  _add_test(Path, CombinePath1WithInvalidCharAndPath2)
  _add_test(Path, CombinePath1AndPath2WithInvalidChar)
  _add_test(Path, CombinePath1AndEmptyPath2)
  _add_test(Path, CombineEmptyPath1AndPath2)
  _add_test(Path, CombinePath1EndedWithDirectorySeparatorAndPath2)
  _add_test(Path, CombinePath1AndPath2EndedWithDirectorySeparator)
  _add_test(Path, CombinePath1StartedWithDirectorySeparatorAndPath2)
  _add_test(Path, CombinePath1AndPath2StartedWithDirectorySeparator)
  _add_test(Path, GetExtensionFromPath)
  _add_test(Path, GetExtensionFromAbsolutePath)
  _add_test(Path, GetExtensionFromFileWithoutExtension)
  _add_test(Path, GetExtensionFromFileWithExtension)
  _add_test(Path, GetExtensionFromPathFileWithExtension)
  _add_test(Path, GetExtensionFromMultiplePathFileWithExtension)
  _add_test(Path, GetExtensionFromAbsolutePathFileWithExtension)
  _add_test(Path, GetExtensionFromAbsoluteMultiplePathFileWithExtension)
  _add_test(Path, GetExtensionFromAbsolutePathFilePatternWithExtension)
  _add_test(Path, GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension)
  _add_test(Path, GetFileNameFromPath)
  _add_test(Path, GetFileNameFromAbsolutePath)
  _add_test(Path, GetFileNameFromFileWithoutExtension)
  _add_test(Path, GetFileNameFromFileWithExtension)
  _add_test(Path, GetFileNameExtensionFromPathFileWithExtension)
  _add_test(Path, GetFileNameExtensionFromMultiplePathFileWithExtension)
  _add_test(Path, GetFileNameFromAbsolutePathFileWithExtension)
  _add_test(Path, GetFileNameFromAbsoluteMultiplePathFileWithExtension)
  _add_test(Path, GetFileNameFromAbsolutePathFilePatternWithExtension)
  _add_test(Path, GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension)
  _add_test(Path, GetFileNameWithoutExtensionFromPath)
  _add_test(Path, GetFileNameWithoutExtensionFromAbsolutePath)
  _add_test(Path, GetFileNameWithoutExtensionFromFileWithoutExtension)
  _add_test(Path, GetFileNameWithoutExtensionFromFileWithExtension)
  _add_test(Path, GetFileNameWithoutExtensionFromPathFileWithExtension)
  _add_test(Path, GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension)
  _add_test(Path, GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension)
  _add_test(Path, GetDirectoryNameFromPath)
  _add_test(Path, GetDirectoryNameFromMultiplePath)
  _add_test(Path, GetDirectoryNameFromAbsolutePath)
  _add_test(Path, GetDirectoryNameFromAbsoluteMultiplePath)
  _add_test(Path, GetDirectoryNameFromFileWithoutExtension)
  _add_test(Path, GetDirectoryNameFromFileWithExtension)
  _add_test(Path, GetDirectoryNameFromPathFileWithExtension)
  _add_test(Path, GetDirectoryNameFromAbsolutePathFileWithExtension)
  _add_test(Path, GetDirectoryNameFromAbsolutePathFilePatternWithExtension)
  _add_test(Path, GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension)
  _add_test(Path, DirectorySeparatorChar)
  _add_test(Path, GetFullPathOnRelativePath)
}

