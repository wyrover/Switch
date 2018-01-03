#include <Switch/Async.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Threading::Tasks;

namespace SwitchUnitTests {
  TEST(AsyncTest, RunningAsyncTask) {
    static string result;
    result = "";
    struct MyStruct {
      async_(Task<>, AsyncTask, {result = "Forty two";});
    };

    MyStruct myStruct;
    myStruct.AsyncTask().Wait();
    ASSERT_EQ("Forty two", result);
  }

  TEST(AsyncTest, RunningAsyncTaskInt32) {
    struct MyStruct {
      async_(Task<int32>, AsyncTask, {return 42;});
    };

    MyStruct myStruct;
    myStruct.AsyncTask().Wait();
    ASSERT_EQ(42, myStruct.AsyncTask().Result);
  }

  TEST(AsyncTest, RunningAsyncTaskString) {
    struct MyStruct {
      async_(Task<string>, AsyncTask, {return "Forty two";});
    };

    MyStruct myStruct;
    myStruct.AsyncTask().Wait();
    ASSERT_EQ("Forty two", myStruct.AsyncTask().Result);
  }
}
