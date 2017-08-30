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
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.txt", ".jpg"), sw_current_information);
    }
    
    void ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.txt", "jpg"), sw_current_information);
    }
    
    void ChangeExtensionFileNameWithExtensionAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file.txt", ""), sw_current_information);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.", ".jpg"), sw_current_information);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.", "jpg"), sw_current_information);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file.", ""), sw_current_information);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file", ".jpg"), sw_current_information);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file", "jpg"), sw_current_information);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file", ""), sw_current_information);
    }
    
    void ChangeExtensionEmptyFileNameAndExtensionWithPeriod() {
      Assert::AreEqual("", System::IO::Path::ChangeExtension("", ".jpg"), sw_current_information);
    }
    
    void ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod() {
      Assert::AreEqual("", System::IO::Path::ChangeExtension("", "jpg"), sw_current_information);
    }
    
    void ChangeExtensionElptyFileNameAndEmptyExtension() {
      Assert::AreEqual(".", System::IO::Path::ChangeExtension("", ""), sw_current_information);
    }
    
    void RootedPathGetPathRoot() {
      Assert::AreEqual("/", System::IO::Path::GetPathRoot("/Path"), sw_current_information);
    }
    
    void RootedPathIsRooted() {
      Assert::IsTrue(System::IO::Path::IsPathRooted("/Path"), sw_current_information);
    }
    
    void CombinePath1AndPath2() {
      Assert::AreEqual(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", "Path2"), sw_current_information);
    }
    
    void CombinePath1WithInvalidCharAndPath2() {
      Assert::Throws<ArgumentException>([] {System::IO::Path::Combine("Path1\r", "Path2");}, sw_current_information);
    }
    
    void CombinePath1AndPath2WithInvalidChar() {
      Assert::Throws<ArgumentException>([] {System::IO::Path::Combine("Path1", "Path2\r");}, sw_current_information);
    }
    
    void CombinePath1AndEmptyPath2() {
      Assert::AreEqual(string::Format("Path1", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", ""), sw_current_information);
    }
    
    void CombineEmptyPath1AndPath2() {
      Assert::AreEqual(string::Format("Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("", "Path2"), sw_current_information);
    }
    
    void CombinePath1EndedWithDirectorySeparatorAndPath2() {
      Assert::AreEqual(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine(string::Format("Path1{0}", System::IO::Path::DirectorySeparatorChar), "Path2"), sw_current_information);
    }
    
    void CombinePath1AndPath2EndedWithDirectorySeparator() {
      Assert::AreEqual(string::Format("Path1{0}Path2{0}", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", string::Format("Path2{0}", System::IO::Path::DirectorySeparatorChar)), sw_current_information);
    }
    
    void CombinePath1StartedWithDirectorySeparatorAndPath2() {
      Assert::AreEqual(string::Format("{0}Path1{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine(string::Format("{0}Path1", System::IO::Path::DirectorySeparatorChar), "Path2"), sw_current_information);
    }
    
    void CombinePath1AndPath2StartedWithDirectorySeparator() {
      Assert::AreEqual(string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar)), sw_current_information);
    }
    
    void GetExtensionFromPath() {
      Assert::AreEqual("", System::IO::Path::GetExtension("Path/"), sw_current_information);
    }
    
    void GetExtensionFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetExtension("/Path/"), sw_current_information);
    }
    
    void GetExtensionFromFileWithoutExtension() {
      Assert::AreEqual("", System::IO::Path::GetExtension("MyFile"), sw_current_information);
    }
    
    void GetExtensionFromFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("MyFile.ext"), sw_current_information);
    }
    
    void GetExtensionFromPathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("Path/MyFile.ext"), sw_current_information);
    }
    
    void GetExtensionFromMultiplePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("Path/Path2/Path3/MyFile.ext"), sw_current_information);
    }
    
    void GetExtensionFromAbsolutePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/MyFile.ext"), sw_current_information);
    }
    
    void GetExtensionFromAbsoluteMultiplePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.ext"), sw_current_information);
    }
    
    void GetExtensionFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/MyFile.Pattern.ext"), sw_current_information);
    }
    
    void GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.Pattern.ext"), sw_current_information);
    }
    
    void GetFileNameFromPath() {
      Assert::AreEqual("", System::IO::Path::GetFileName("Path/"), sw_current_information);
    }
    
    void GetFileNameFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetFileName("/Path/"), sw_current_information);
    }
    
    void GetFileNameFromFileWithoutExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileName("MyFile"), sw_current_information);
    }
    
    void GetFileNameFromFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameExtensionFromPathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("Path/MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameExtensionFromMultiplePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("Path/Path2/Path3/MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName( "/Path/MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameFromAbsoluteMultiplePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName( "/Path/Path2/Path3/MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/MyFile.Pattern.ext"), sw_current_information);
    }
    
    void GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/Path2/Path3/MyFile.Pattern.ext"), sw_current_information);
    }
    
    void GetFileNameWithoutExtensionFromPath() {
      Assert::AreEqual("", System::IO::Path::GetFileNameWithoutExtension("Path/"), sw_current_information);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetFileNameWithoutExtension("/Path/"), sw_current_information);
    }
    
    void GetFileNameWithoutExtensionFromFileWithoutExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile"), sw_current_information);
    }
    
    void GetFileNameWithoutExtensionFromFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameWithoutExtensionFromPathFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("Path/MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.ext"), sw_current_information);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.Pattern.ext"), sw_current_information);
    }
    
    void GetDirectoryNameFromPath() {
      Assert::AreEqual("Path", System::IO::Path::GetDirectoryName("Path/"), sw_current_information);
    }
    
    void GetDirectoryNameFromMultiplePath() {
      Assert::AreEqual("Path/Path2/Path3", System::IO::Path::GetDirectoryName("Path/Path2/Path3/"), sw_current_information);
    }
    
    void GetDirectoryNameFromAbsolutePath() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/"), sw_current_information);
    }
    
    void GetDirectoryNameFromAbsoluteMultiplePath() {
      Assert::AreEqual("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/"), sw_current_information);
    }
    
    void GetDirectoryNameFromFileWithoutExtension() {
      Assert::AreEqual("", System::IO::Path::GetDirectoryName("MyFile"), sw_current_information);
    }
    
    void GetDirectoryNameFromFileWithExtension() {
      Assert::AreEqual("", System::IO::Path::GetDirectoryName("MyFile.ext"), sw_current_information);
    }
    
    void GetDirectoryNameFromPathFileWithExtension() {
      Assert::AreEqual("Path", System::IO::Path::GetDirectoryName("Path/MyFile.ext"), sw_current_information);
    }
    
    void GetDirectoryNameFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.ext"), sw_current_information);
    }
    
    void GetDirectoryNameFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.Pattern.ext"), sw_current_information);
    }
    
    void GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/MyFile.Pattern.ext"), sw_current_information);
    }
    
    void DirectorySeparatorChar() {
      if (Environment::OSVersion().Platform() == PlatformID::Unix || Environment::OSVersion().Platform() == PlatformID::MacOSX || Environment::OSVersion().Platform() == PlatformID::IOs || Environment::OSVersion().Platform() == PlatformID::Android)
        Assert::AreEqual(char32('/'), System::IO::Path::DirectorySeparatorChar, sw_current_information);
      else
        Assert::AreEqual(char32('\\'), System::IO::Path::DirectorySeparatorChar, sw_current_information);
    }
    
    void GetFullPathOnRelativePath() {
      Assert::AreEqual(System::IO::Path::Combine(Environment::CurrentDirectory, "MyFolder"), System::IO::Path::GetFullPath("MyFolder"));
    }
    
  private:
    string savedCurrentDirectory;
  };
  
  sw_test(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithPeriod)
  sw_test(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod)
  sw_test(Path, ChangeExtensionFileNameWithExtensionAndEmptyExtension)
  sw_test(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod)
  sw_test(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod)
  sw_test(Path, ChangeExtensionFileNameEndWithPeriodAndEmptyExtension)
  sw_test(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod)
  sw_test(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod)
  sw_test(Path, ChangeExtensionFileNameWithoutExtensionAndEmptyExtension)
  sw_test(Path, ChangeExtensionEmptyFileNameAndExtensionWithPeriod)
  sw_test(Path, ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod)
  sw_test(Path, ChangeExtensionElptyFileNameAndEmptyExtension)
  sw_test(Path, RootedPathGetPathRoot)
  sw_test(Path, RootedPathIsRooted)
  sw_test(Path, CombinePath1AndPath2)
  sw_test(Path, CombinePath1WithInvalidCharAndPath2)
  sw_test(Path, CombinePath1AndPath2WithInvalidChar)
  sw_test(Path, CombinePath1AndEmptyPath2)
  sw_test(Path, CombineEmptyPath1AndPath2)
  sw_test(Path, CombinePath1EndedWithDirectorySeparatorAndPath2)
  sw_test(Path, CombinePath1AndPath2EndedWithDirectorySeparator)
  sw_test(Path, CombinePath1StartedWithDirectorySeparatorAndPath2)
  sw_test(Path, CombinePath1AndPath2StartedWithDirectorySeparator)
  sw_test(Path, GetExtensionFromPath)
  sw_test(Path, GetExtensionFromAbsolutePath)
  sw_test(Path, GetExtensionFromFileWithoutExtension)
  sw_test(Path, GetExtensionFromFileWithExtension)
  sw_test(Path, GetExtensionFromPathFileWithExtension)
  sw_test(Path, GetExtensionFromMultiplePathFileWithExtension)
  sw_test(Path, GetExtensionFromAbsolutePathFileWithExtension)
  sw_test(Path, GetExtensionFromAbsoluteMultiplePathFileWithExtension)
  sw_test(Path, GetExtensionFromAbsolutePathFilePatternWithExtension)
  sw_test(Path, GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension)
  sw_test(Path, GetFileNameFromPath)
  sw_test(Path, GetFileNameFromAbsolutePath)
  sw_test(Path, GetFileNameFromFileWithoutExtension)
  sw_test(Path, GetFileNameFromFileWithExtension)
  sw_test(Path, GetFileNameExtensionFromPathFileWithExtension)
  sw_test(Path, GetFileNameExtensionFromMultiplePathFileWithExtension)
  sw_test(Path, GetFileNameFromAbsolutePathFileWithExtension)
  sw_test(Path, GetFileNameFromAbsoluteMultiplePathFileWithExtension)
  sw_test(Path, GetFileNameFromAbsolutePathFilePatternWithExtension)
  sw_test(Path, GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension)
  sw_test(Path, GetFileNameWithoutExtensionFromPath)
  sw_test(Path, GetFileNameWithoutExtensionFromAbsolutePath)
  sw_test(Path, GetFileNameWithoutExtensionFromFileWithoutExtension)
  sw_test(Path, GetFileNameWithoutExtensionFromFileWithExtension)
  sw_test(Path, GetFileNameWithoutExtensionFromPathFileWithExtension)
  sw_test(Path, GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension)
  sw_test(Path, GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension)
  sw_test(Path, GetDirectoryNameFromPath)
  sw_test(Path, GetDirectoryNameFromMultiplePath)
  sw_test(Path, GetDirectoryNameFromAbsolutePath)
  sw_test(Path, GetDirectoryNameFromAbsoluteMultiplePath)
  sw_test(Path, GetDirectoryNameFromFileWithoutExtension)
  sw_test(Path, GetDirectoryNameFromFileWithExtension)
  sw_test(Path, GetDirectoryNameFromPathFileWithExtension)
  sw_test(Path, GetDirectoryNameFromAbsolutePathFileWithExtension)
  sw_test(Path, GetDirectoryNameFromAbsolutePathFilePatternWithExtension)
  sw_test(Path, GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension)
  sw_test(Path, DirectorySeparatorChar)
  sw_test(Path, GetFullPathOnRelativePath)
}

