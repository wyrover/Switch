#include <Switch/System/Version.hpp>
#include <Switch/System/String.hpp>

#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(VersionTest, CreateVersionWithDefaultConstructor) {
    Version version;
    
    ASSERT_EQ(0, version.Major);
    ASSERT_EQ(0, version.Minor);
    ASSERT_EQ(-1, version.Build);
    ASSERT_EQ(-1, version.Revision);
  }
  
  TEST(VersionTest, CreateVersionWithSpecifiedMajorAndMinor) {
    Version version(4, 2);
    
    ASSERT_EQ(4, version.Major);
    ASSERT_EQ(2, version.Minor);
    ASSERT_EQ(-1, version.Build);
    ASSERT_EQ(-1, version.Revision);
  }
  
  TEST(VersionTest, CreateVersionWithSpecifiedMajorMinorAndRevision) {
    Version version(4, 2, 1);
    
    ASSERT_EQ(4, version.Major);
    ASSERT_EQ(2, version.Minor);
    ASSERT_EQ(1, version.Build);
    ASSERT_EQ(-1, version.Revision);
  }
  
  TEST(VersionTest, CreateVersionWithSpecifiedMajorMinorRevisionAndBuild) {
    Version version(4, 2, 1, 3);
    
    ASSERT_EQ(4, version.Major);
    ASSERT_EQ(2, version.Minor);
    ASSERT_EQ(1, version.Build);
    ASSERT_EQ(3, version.Revision);
  }
  
  TEST(VersionTest, CreateVersionWithSpecifiedMajorMinorRevisionAndBuildToZero) {
    Version version(0, 0, 0, 0);
    
    ASSERT_EQ(0, version.Major);
    ASSERT_EQ(0, version.Minor);
    ASSERT_EQ(0, version.Build);
    ASSERT_EQ(0, version.Revision);
  }
  
  TEST(VersionTest, Constructor) {
    ASSERT_EQ("0.0", Version().ToString());
    ASSERT_EQ("1.2", Version(1, 2).ToString());
    ASSERT_EQ("2147483647.2", Version(Int32::MaxValue, 2).ToString());
    ASSERT_EQ("1.2.3", Version(1, 2, 3).ToString());
    ASSERT_EQ("1.2.3.4", Version(1, 2, 3, 4).ToString());
    ASSERT_THROW(Version(-1, 0), ArgumentOutOfRangeException);
    ASSERT_THROW(Version(0, -25), ArgumentOutOfRangeException);
  }
  
  TEST(VersionTest, Parse) {
    ASSERT_EQ(Version(11, 0, 2), Version::Parse("11.0.2"));
    ASSERT_EQ(Version(11, 0, 2), Version::Parse("11.00.02"));
  }
}

