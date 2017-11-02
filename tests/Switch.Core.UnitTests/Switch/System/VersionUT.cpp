#include <Switch/System/Version.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class VersionTest : public TestFixture {
  protected:
    void CreateVersionWithDefaultConstructor() {
      Version version;
      
      Assert::AreEqual(0, version.Major, _caller);
      Assert::AreEqual(0, version.Minor, _caller);
      Assert::AreEqual(-1, version.Build, _caller);
      Assert::AreEqual(-1, version.Revision, _caller);
    }
    
    void CreateVersionWithSpecifiedMajorAndMinor() {
      Version version(4, 2);
      
      Assert::AreEqual(4, version.Major, _caller);
      Assert::AreEqual(2, version.Minor, _caller);
      Assert::AreEqual(-1, version.Build, _caller);
      Assert::AreEqual(-1, version.Revision, _caller);
    }
    
    void CreateVersionWithSpecifiedMajorMinorAndRevision() {
      Version version(4, 2, 1);
      
      Assert::AreEqual(4, version.Major, _caller);
      Assert::AreEqual(2, version.Minor, _caller);
      Assert::AreEqual(1, version.Build, _caller);
      Assert::AreEqual(-1, version.Revision, _caller);
    }
    
    void CreateVersionWithSpecifiedMajorMinorRevisionAndBuild() {
      Version version(4, 2, 1, 3);
      
      Assert::AreEqual(4, version.Major, _caller);
      Assert::AreEqual(2, version.Minor, _caller);
      Assert::AreEqual(1, version.Build, _caller);
      Assert::AreEqual(3, version.Revision, _caller);
    }
    
    void CreateVersionWithSpecifiedMajorMinorRevisionAndBuildToZero() {
      Version version(0, 0, 0, 0);
      
      Assert::AreEqual(0, version.Major, _caller);
      Assert::AreEqual(0, version.Minor, _caller);
      Assert::AreEqual(0, version.Build, _caller);
      Assert::AreEqual(0, version.Revision, _caller);
    }
  };

  _add_test (VersionTest, CreateVersionWithDefaultConstructor)
  _add_test (VersionTest, CreateVersionWithSpecifiedMajorAndMinor)
  _add_test (VersionTest, CreateVersionWithSpecifiedMajorMinorAndRevision)
  _add_test (VersionTest, CreateVersionWithSpecifiedMajorMinorRevisionAndBuild)
  _add_test (VersionTest, CreateVersionWithSpecifiedMajorMinorRevisionAndBuildToZero)

  TEST(Version, Constructor) {
    EXPECT_EQ(Version().ToString(), "0.0");
    EXPECT_EQ(Version(1, 0).ToString(), "1.0");
    EXPECT_EQ(Version(1, 2).ToString(), "1.2");
    EXPECT_EQ(Version(Int32::MaxValue, 2).ToString(), "2147483647.2");
    EXPECT_EQ(Version(1, 2, 3).ToString(), "1.2.3");
    EXPECT_EQ(Version(1, 2, 3, 4).ToString(), "1.2.3.4");
    EXPECT_THROW(Version(-1, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(Version(0, -25), ArgumentOutOfRangeException);
  }

  TEST(Version, Parse) {
    EXPECT_EQ(Version::Parse("11.0.2"), Version(11, 0, 2));
    EXPECT_EQ(Version::Parse("11.00.02"), Version(11, 0, 2));
  }

}
