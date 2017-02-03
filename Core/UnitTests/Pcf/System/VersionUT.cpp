#include <Pcf/System/Version.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {

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