#include <Pcf/System/IO/Path.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

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
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.txt", ".jpg"), pcf_current_information);
    }
    
    void ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.txt", "jpg"), pcf_current_information);
    }
    
    void ChangeExtensionFileNameWithExtensionAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file.txt", ""), pcf_current_information);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.", ".jpg"), pcf_current_information);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file.", "jpg"), pcf_current_information);
    }
    
    void ChangeExtensionFileNameEndWithPeriodAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file.", ""), pcf_current_information);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file", ".jpg"), pcf_current_information);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod() {
      Assert::AreEqual("file.jpg", System::IO::Path::ChangeExtension("file", "jpg"), pcf_current_information);
    }
    
    void ChangeExtensionFileNameWithoutExtensionAndEmptyExtension() {
      Assert::AreEqual("file.", System::IO::Path::ChangeExtension("file", ""), pcf_current_information);
    }
    
    void ChangeExtensionEmptyFileNameAndExtensionWithPeriod() {
      Assert::AreEqual("", System::IO::Path::ChangeExtension("", ".jpg"), pcf_current_information);
    }
    
    void ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod() {
      Assert::AreEqual("", System::IO::Path::ChangeExtension("", "jpg"), pcf_current_information);
    }
    
    void ChangeExtensionElptyFileNameAndEmptyExtension() {
      Assert::AreEqual(".", System::IO::Path::ChangeExtension("", ""), pcf_current_information);
    }
    
    void RootedPathGetPathRoot() {
      Assert::AreEqual("/", System::IO::Path::GetPathRoot("/Path"), pcf_current_information);
    }
    
    void RootedPathIsRooted() {
      Assert::IsTrue(System::IO::Path::IsPathRooted("/Path"), pcf_current_information);
    }
    
    void CombinePath1AndPath2() {
      Assert::AreEqual(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", "Path2"), pcf_current_information);
    }
    
    void CombinePath1WithInvalidCharAndPath2() {
      Assert::Throws<ArgumentException>([] {System::IO::Path::Combine("Path1\r", "Path2");}, pcf_current_information);
    }
    
    void CombinePath1AndPath2WithInvalidChar() {
      Assert::Throws<ArgumentException>([] {System::IO::Path::Combine("Path1", "Path2\r");}, pcf_current_information);
    }
    
    void CombinePath1AndEmptyPath2() {
      Assert::AreEqual(string::Format("Path1", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", ""), pcf_current_information);
    }
    
    void CombineEmptyPath1AndPath2() {
      Assert::AreEqual(string::Format("Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("", "Path2"), pcf_current_information);
    }
    
    void CombinePath1EndedWithDirectorySeparatorAndPath2() {
      Assert::AreEqual(string::Format("Path1{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine(string::Format("Path1{0}", System::IO::Path::DirectorySeparatorChar), "Path2"), pcf_current_information);
    }
    
    void CombinePath1AndPath2EndedWithDirectorySeparator() {
      Assert::AreEqual(string::Format("Path1{0}Path2{0}", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", string::Format("Path2{0}", System::IO::Path::DirectorySeparatorChar)), pcf_current_information);
    }
    
    void CombinePath1StartedWithDirectorySeparatorAndPath2() {
      Assert::AreEqual(string::Format("{0}Path1{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine(string::Format("{0}Path1", System::IO::Path::DirectorySeparatorChar), "Path2"), pcf_current_information);
    }
    
    void CombinePath1AndPath2StartedWithDirectorySeparator() {
      Assert::AreEqual(string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar), System::IO::Path::Combine("Path1", string::Format("{0}Path2", System::IO::Path::DirectorySeparatorChar)), pcf_current_information);
    }
    
    void GetExtensionFromPath() {
      Assert::AreEqual("", System::IO::Path::GetExtension("Path/"), pcf_current_information);
    }
    
    void GetExtensionFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetExtension("/Path/"), pcf_current_information);
    }
    
    void GetExtensionFromFileWithoutExtension() {
      Assert::AreEqual("", System::IO::Path::GetExtension("MyFile"), pcf_current_information);
    }
    
    void GetExtensionFromFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("MyFile.ext"), pcf_current_information);
    }
    
    void GetExtensionFromPathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetExtensionFromMultiplePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("Path/Path2/Path3/MyFile.ext"), pcf_current_information);
    }
    
    void GetExtensionFromAbsolutePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetExtensionFromAbsoluteMultiplePathFileWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.ext"), pcf_current_information);
    }
    
    void GetExtensionFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/MyFile.Pattern.ext"), pcf_current_information);
    }
    
    void GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual(".ext", System::IO::Path::GetExtension("/Path/Path2/Path3/MyFile.Pattern.ext"), pcf_current_information);
    }
    
    void GetFileNameFromPath() {
      Assert::AreEqual("", System::IO::Path::GetFileName("Path/"), pcf_current_information);
    }
    
    void GetFileNameFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetFileName("/Path/"), pcf_current_information);
    }
    
    void GetFileNameFromFileWithoutExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileName("MyFile"), pcf_current_information);
    }
    
    void GetFileNameFromFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameExtensionFromPathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameExtensionFromMultiplePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName("Path/Path2/Path3/MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName( "/Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameFromAbsoluteMultiplePathFileWithExtension() {
      Assert::AreEqual("MyFile.ext", System::IO::Path::GetFileName( "/Path/Path2/Path3/MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/MyFile.Pattern.ext"), pcf_current_information);
    }
    
    void GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern.ext", System::IO::Path::GetFileName("/Path/Path2/Path3/MyFile.Pattern.ext"), pcf_current_information);
    }
    
    void GetFileNameWithoutExtensionFromPath() {
      Assert::AreEqual("", System::IO::Path::GetFileNameWithoutExtension("Path/"), pcf_current_information);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePath() {
      Assert::AreEqual("", System::IO::Path::GetFileNameWithoutExtension("/Path/"), pcf_current_information);
    }
    
    void GetFileNameWithoutExtensionFromFileWithoutExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile"), pcf_current_information);
    }
    
    void GetFileNameWithoutExtensionFromFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameWithoutExtensionFromPathFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("MyFile", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("MyFile.Pattern", System::IO::Path::GetFileNameWithoutExtension("/Path/MyFile.Pattern.ext"), pcf_current_information);
    }
    
    void GetDirectoryNameFromPath() {
      Assert::AreEqual("Path", System::IO::Path::GetDirectoryName("Path/"), pcf_current_information);
    }
    
    void GetDirectoryNameFromMultiplePath() {
      Assert::AreEqual("Path/Path2/Path3", System::IO::Path::GetDirectoryName("Path/Path2/Path3/"), pcf_current_information);
    }
    
    void GetDirectoryNameFromAbsolutePath() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/"), pcf_current_information);
    }
    
    void GetDirectoryNameFromAbsoluteMultiplePath() {
      Assert::AreEqual("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/"), pcf_current_information);
    }
    
    void GetDirectoryNameFromFileWithoutExtension() {
      Assert::AreEqual("", System::IO::Path::GetDirectoryName("MyFile"), pcf_current_information);
    }
    
    void GetDirectoryNameFromFileWithExtension() {
      Assert::AreEqual("", System::IO::Path::GetDirectoryName("MyFile.ext"), pcf_current_information);
    }
    
    void GetDirectoryNameFromPathFileWithExtension() {
      Assert::AreEqual("Path", System::IO::Path::GetDirectoryName("Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetDirectoryNameFromAbsolutePathFileWithExtension() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.ext"), pcf_current_information);
    }
    
    void GetDirectoryNameFromAbsolutePathFilePatternWithExtension() {
      Assert::AreEqual("/Path", System::IO::Path::GetDirectoryName("/Path/MyFile.Pattern.ext"), pcf_current_information);
    }
    
    void GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension() {
      Assert::AreEqual("/Path/Path2/Path3", System::IO::Path::GetDirectoryName("/Path/Path2/Path3/MyFile.Pattern.ext"), pcf_current_information);
    }
    
    void DirectorySeparatorChar() {
      if (Environment::OSVersion().Platform() == PlatformID::Unix || Environment::OSVersion().Platform() == PlatformID::MacOSX || Environment::OSVersion().Platform() == PlatformID::IOs || Environment::OSVersion().Platform() == PlatformID::Android)
        Assert::AreEqual(char32('/'), System::IO::Path::DirectorySeparatorChar, pcf_current_information);
      else
        Assert::AreEqual(char32('\\'), System::IO::Path::DirectorySeparatorChar, pcf_current_information);
    }
    
    void GetFullPathOnRelativePath() {
      Assert::AreEqual(System::IO::Path::Combine(Environment::CurrentDirectory, "MyFolder"), System::IO::Path::GetFullPath("MyFolder"));
    }
    
  private:
    string savedCurrentDirectory;
  };
  
  pcf_test(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithPeriod);
  pcf_test(Path, ChangeExtensionFileNameWithExtensionAndExtensionWithoutPeriod);
  pcf_test(Path, ChangeExtensionFileNameWithExtensionAndEmptyExtension);
  pcf_test(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithPeriod);
  pcf_test(Path, ChangeExtensionFileNameEndWithPeriodAndExtensionWithoutPeriod);
  pcf_test(Path, ChangeExtensionFileNameEndWithPeriodAndEmptyExtension);
  pcf_test(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithPeriod);
  pcf_test(Path, ChangeExtensionFileNameWithoutExtensionAndExtensionWithoutPeriod);
  pcf_test(Path, ChangeExtensionFileNameWithoutExtensionAndEmptyExtension);
  pcf_test(Path, ChangeExtensionEmptyFileNameAndExtensionWithPeriod);
  pcf_test(Path, ChangeExtensionEmptyFileNameAndExtensionWithoutPeriod);
  pcf_test(Path, ChangeExtensionElptyFileNameAndEmptyExtension);
  pcf_test(Path, RootedPathGetPathRoot);
  pcf_test(Path, RootedPathIsRooted);
  pcf_test(Path, CombinePath1AndPath2);
  pcf_test(Path, CombinePath1WithInvalidCharAndPath2);
  pcf_test(Path, CombinePath1AndPath2WithInvalidChar);
  pcf_test(Path, CombinePath1AndEmptyPath2);
  pcf_test(Path, CombineEmptyPath1AndPath2);
  pcf_test(Path, CombinePath1EndedWithDirectorySeparatorAndPath2);
  pcf_test(Path, CombinePath1AndPath2EndedWithDirectorySeparator);
  pcf_test(Path, CombinePath1StartedWithDirectorySeparatorAndPath2);
  pcf_test(Path, CombinePath1AndPath2StartedWithDirectorySeparator);
  pcf_test(Path, GetExtensionFromPath);
  pcf_test(Path, GetExtensionFromAbsolutePath);
  pcf_test(Path, GetExtensionFromFileWithoutExtension);
  pcf_test(Path, GetExtensionFromFileWithExtension);
  pcf_test(Path, GetExtensionFromPathFileWithExtension);
  pcf_test(Path, GetExtensionFromMultiplePathFileWithExtension);
  pcf_test(Path, GetExtensionFromAbsolutePathFileWithExtension);
  pcf_test(Path, GetExtensionFromAbsoluteMultiplePathFileWithExtension);
  pcf_test(Path, GetExtensionFromAbsolutePathFilePatternWithExtension);
  pcf_test(Path, GetExtensionFromAbsoluteMultiplePathFilePatternWithExtension);
  pcf_test(Path, GetFileNameFromPath);
  pcf_test(Path, GetFileNameFromAbsolutePath);
  pcf_test(Path, GetFileNameFromFileWithoutExtension);
  pcf_test(Path, GetFileNameFromFileWithExtension);
  pcf_test(Path, GetFileNameExtensionFromPathFileWithExtension);
  pcf_test(Path, GetFileNameExtensionFromMultiplePathFileWithExtension);
  pcf_test(Path, GetFileNameFromAbsolutePathFileWithExtension);
  pcf_test(Path, GetFileNameFromAbsoluteMultiplePathFileWithExtension);
  pcf_test(Path, GetFileNameFromAbsolutePathFilePatternWithExtension);
  pcf_test(Path, GetFileNameFromAbsoluteMultiplePathFilePatternWithExtension);
  pcf_test(Path, GetFileNameWithoutExtensionFromPath);
  pcf_test(Path, GetFileNameWithoutExtensionFromAbsolutePath);
  pcf_test(Path, GetFileNameWithoutExtensionFromFileWithoutExtension);
  pcf_test(Path, GetFileNameWithoutExtensionFromFileWithExtension);
  pcf_test(Path, GetFileNameWithoutExtensionFromPathFileWithExtension);
  pcf_test(Path, GetFileNameWithoutExtensionFromAbsolutePathFileWithExtension);
  pcf_test(Path, GetFileNameWithoutExtensionFromAbsolutePathFilePatternWithExtension);
  pcf_test(Path, GetDirectoryNameFromPath);
  pcf_test(Path, GetDirectoryNameFromMultiplePath);
  pcf_test(Path, GetDirectoryNameFromAbsolutePath);
  pcf_test(Path, GetDirectoryNameFromAbsoluteMultiplePath);
  pcf_test(Path, GetDirectoryNameFromFileWithoutExtension);
  pcf_test(Path, GetDirectoryNameFromFileWithExtension);
  pcf_test(Path, GetDirectoryNameFromPathFileWithExtension);
  pcf_test(Path, GetDirectoryNameFromAbsolutePathFileWithExtension);
  pcf_test(Path, GetDirectoryNameFromAbsolutePathFilePatternWithExtension);
  pcf_test(Path, GetDirectoryNameFromAbsoluteMultiplePathFilePatternWithExtension);
  pcf_test(Path, DirectorySeparatorChar);
  pcf_test(Path, GetFullPathOnRelativePath);
}

