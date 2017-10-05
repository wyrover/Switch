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
        _async(Task<>, AsyncTask, {result = "Forty two";});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual("Forty two", result);
    }
    
    void RunningAsyncTaskInt32() {
      struct MyStruct {
        _async(Task<int32>, AsyncTask, {return 42;});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual(42, myStruct.AsyncTask().Result);
    }
    
    void RunningAsyncTaskString() {
      struct MyStruct {
        _async(Task<string>, AsyncTask, {return "Forty two";});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual("Forty two", myStruct.AsyncTask().Result);
    }
  };
  
  _test(AsyncTest, RunningAsyncTask)
  _test(AsyncTest, RunningAsyncTaskInt32)
  _test(AsyncTest, RunningAsyncTaskString)
}
