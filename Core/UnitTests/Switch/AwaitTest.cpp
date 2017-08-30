#include <Switch/Await.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading::Tasks;
using namespace TUnit;

namespace SwitchUnitTests {
  class AwaitTest : public TestFixture {
  protected:
    void RunningAsyncTaskAndAwait() {
      static string result;
      result = "";
      struct MyStruct {
        sw_async(Task<>, AsyncTask, {result = "Forty two";});
      };
      
      MyStruct myStruct;
      sw_await myStruct.AsyncTask;
      Assert::AreEqual("Forty two", result);
    }
    
    void RunningAsyncTaskInt32AndAwait() {
      struct MyStruct {
        sw_async(Task<int32>, AsyncTask, {return 42;});
      };
      
      MyStruct myStruct;
      int32 result = sw_await myStruct.AsyncTask;
      Assert::AreEqual(42, result);
    }
    
    void RunningAsyncTaskStringAndAwait() {
      struct MyStruct {
        sw_async(Task<string>, AsyncTask, {return "Forty two";});
      };
      
      MyStruct myStruct;
      string result = sw_await myStruct.AsyncTask;
      Assert::AreEqual("Forty two", result);
    }
  };
  
  sw_test(AwaitTest, RunningAsyncTaskAndAwait)
  sw_test(AwaitTest, RunningAsyncTaskInt32AndAwait)
  sw_test(AwaitTest, RunningAsyncTaskStringAndAwait)
}
