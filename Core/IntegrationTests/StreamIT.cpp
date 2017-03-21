#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

TEST(Stream, MemoryStreamReader) {
  int32 val = 0;
  EXPECT_EQ(0, val);
}