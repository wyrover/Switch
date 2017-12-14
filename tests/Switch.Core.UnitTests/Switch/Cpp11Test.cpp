#include <Switch/System/Threading/Thread.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(Cpp11Test, Auto) {
    string str = "Test string";
    const char chars[] = "Test string";

    int32 index = 0;
    for (auto c : str)
      ASSERT_EQ(c, char32_t(chars[index++]));
  }

  TEST(Cpp11Test, InitializerList) {
    Array<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int32 index = 0;
    for (const auto& value : values)
      ASSERT_EQ(value, results[index++]);
    ASSERT_EQ(10, index);
  }

  TEST(Cpp11Test, Thread) {
    string result;

    std::thread t([&] {
      result = "thread launched";
    });

    ASSERT_TRUE(t.joinable());
    t.join();
    ASSERT_EQ("thread launched", result);
  }
}

