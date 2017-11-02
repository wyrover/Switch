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
        _async(Task<>, AsyncTask, {result = "Forty two";});
      };
      
      MyStruct myStruct;
      _await myStruct.AsyncTask;
      Assert::AreEqual("Forty two", result);
    }
    
    void RunningAsyncTaskInt32AndAwait() {
      struct MyStruct {
        _async(Task<int32>, AsyncTask, {return 42;});
      };
      
      MyStruct myStruct;
      int32 result = _await myStruct.AsyncTask;
      Assert::AreEqual(42, result);
    }
    
    void RunningAsyncTaskStringAndAwait() {
      struct MyStruct {
        _async(Task<string>, AsyncTask, {return "Forty two";});
      };
      
      MyStruct myStruct;
      string result = _await myStruct.AsyncTask;
      Assert::AreEqual("Forty two", result);
    }
  };
  
  _add_test (AwaitTest, RunningAsyncTaskAndAwait)
  _add_test (AwaitTest, RunningAsyncTaskInt32AndAwait)
  _add_test (AwaitTest, RunningAsyncTaskStringAndAwait)
}
