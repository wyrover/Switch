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
      _async(Task<>, AsyncTask, {result = "Forty two";});
    };
    
    MyStruct myStruct;
    _await myStruct.AsyncTask;
    ASSERT_EQ("Forty two", result);
  }
  
  TEST(AwaitTest, RunningAsyncTaskInt32AndAwait) {
    struct MyStruct {
      _async(Task<int32>, AsyncTask, {return 42;});
    };
    
    MyStruct myStruct;
    int32 result = _await myStruct.AsyncTask;
    ASSERT_EQ(42, result);
  }
  
  TEST(AwaitTest, RunningAsyncTaskStringAndAwait) {
    struct MyStruct {
      _async(Task<string>, AsyncTask, {return "Forty two";});
    };
    
    MyStruct myStruct;
    string result = _await myStruct.AsyncTask;
    ASSERT_EQ("Forty two", result);
  }
}
