#include <Pcf/Async.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Threading::Tasks;
using namespace TUnit;

namespace PcfUnitTests {
  class AsyncTest : public TestFixture {
  protected:
    void RunningAsyncTask() {
      static string result;
      result = "";
      struct MyStruct {
        pcf_async(Task<>, AsyncTask, {result = "Forty two";});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual("Forty two", result);
    }
    
    void RunningAsyncTaskInt32() {
      struct MyStruct {
        pcf_async(Task<int32>, AsyncTask, {return 42;});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual(42, myStruct.AsyncTask().Result);
    }
    
    void RunningAsyncTaskString() {
      struct MyStruct {
        pcf_async(Task<string>, AsyncTask, {return "Forty two";});
      };
      
      MyStruct myStruct;
      myStruct.AsyncTask().Wait();
      Assert::AreEqual("Forty two", myStruct.AsyncTask().Result);
    }
  };
  
  pcf_test(AsyncTest, RunningAsyncTask)
  pcf_test(AsyncTest, RunningAsyncTaskInt32)
  pcf_test(AsyncTest, RunningAsyncTaskString)
}
