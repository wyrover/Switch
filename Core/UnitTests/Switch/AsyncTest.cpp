#include <Switch/Async.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading::Tasks;
using namespace TUnit;

namespace SwitchUnitTests {
  class AsyncTest : public TestFixture {
  protected:
    void RunningAsyncTask() {
      static string result;
      result = "";
      struct MyStruct {
        sw_async(Task<>, AsyncTask, {result = "Forty two";});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual("Forty two", result);
    }
    
    void RunningAsyncTaskInt32() {
      struct MyStruct {
        sw_async(Task<int32>, AsyncTask, {return 42;});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual(42, myStruct.AsyncTask().Result);
    }
    
    void RunningAsyncTaskString() {
      struct MyStruct {
        sw_async(Task<string>, AsyncTask, {return "Forty two";});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual("Forty two", myStruct.AsyncTask().Result);
    }
  };
  
  sw_test(AsyncTest, RunningAsyncTask)
  sw_test(AsyncTest, RunningAsyncTaskInt32)
  sw_test(AsyncTest, RunningAsyncTaskString)
}
