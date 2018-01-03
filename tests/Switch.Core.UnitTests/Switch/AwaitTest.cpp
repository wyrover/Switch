#include <Switch/Await.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading::Tasks;

namespace SwitchUnitTests {
  TEST(AwaitTest, RunningAsyncTaskAndAwait) {
    static string result;
    result = "";
    struct MyStruct {
      async_(Task<>, AsyncTask, {result = "Forty two";});
    };

    MyStruct myStruct;
    await_ myStruct.AsyncTask;
    ASSERT_EQ("Forty two", result);
  }

  TEST(AwaitTest, RunningAsyncTaskInt32AndAwait) {
    struct MyStruct {
      async_(Task<int32>, AsyncTask, {return 42;});
    };

    MyStruct myStruct;
    int32 result = await_ myStruct.AsyncTask;
    ASSERT_EQ(42, result);
  }

  TEST(AwaitTest, RunningAsyncTaskStringAndAwait) {
    struct MyStruct {
      async_(Task<string>, AsyncTask, {return "Forty two";});
    };

    MyStruct myStruct;
    string result = await_ myStruct.AsyncTask;
    ASSERT_EQ("Forty two", result);
  }
}
