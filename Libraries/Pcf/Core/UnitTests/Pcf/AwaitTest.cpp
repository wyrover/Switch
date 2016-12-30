#include <Pcf/Await.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Threading::Tasks;
using namespace TUnit;

namespace PcfUnitTests {
  class AwaitTest : public TestFixture {
  protected:
    void RunningAsyncTaskAndAwait() {
      static string result;
      result = "";
      struct MyStruct {
        pcf_async(Task<>, AsyncTask, {result = "Forty two";});
      };
      
      MyStruct myStruct;
      pcf_await myStruct.AsyncTask;
      Assert::AreEqual("Forty two", result);
    }
    
    void RunningAsyncTaskInt32AndAwait() {
      struct MyStruct {
        pcf_async(Task<int32>, AsyncTask, {return 42;});
      };
      
      MyStruct myStruct;
      int32 result = pcf_await myStruct.AsyncTask;
      Assert::AreEqual(42, result);
    }
    
    void RunningAsyncTaskStringAndAwait() {
      struct MyStruct {
        pcf_async(Task<string>, AsyncTask, {return "Forty two";});
      };
      
      MyStruct myStruct;
      string result = pcf_await myStruct.AsyncTask;
      Assert::AreEqual("Forty two", result);
    }
  };
  
  pcf_test(AwaitTest, RunningAsyncTaskAndAwait);
  pcf_test(AwaitTest, RunningAsyncTaskInt32AndAwait);
  pcf_test(AwaitTest, RunningAsyncTaskStringAndAwait);
}
