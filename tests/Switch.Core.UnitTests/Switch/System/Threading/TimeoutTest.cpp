#include <Switch/System/Threading/Timeout.hpp>
#include <Switch/System/Threading/AutoResetEvent.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading;

namespace {
  TEST(TimeoutTest, TimeoutIninite) {
    ASSERT_EQ(-1, Timeout::Infinite);
  }

  TEST(TimeoutTest, TimeoutIniniteTimeSpan) {
    ASSERT_EQ(TimeSpan::FromMilliseconds(-1), Timeout::InfiniteTimeSpan);
    ASSERT_EQ("-00:00:00.0010000", Timeout::InfiniteTimeSpan.ToString());
  }
}
