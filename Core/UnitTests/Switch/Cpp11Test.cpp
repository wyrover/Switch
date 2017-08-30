#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class Cpp11Test : public TestFixture {
  protected:
    void Auto() {
      string str = "Test string";
      const char chars[] = "Test string";
      
      int32 i = 0;
      for (auto c : str)
        Assert::AreEqual(c, char32_t(chars[i++]), pcf_current_information);
    }
    
    void InitializerList() {
      Array<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      
      int32 i = 0;
      for (const auto& value : values)
        Assert::AreEqual(value, results[i++], pcf_current_information);
      Assert::AreEqual(10, i, pcf_current_information);
    }
    
    void Thread() {
      string result;

      std::thread t([&] {
        result = "thread launched";
      });
      
      Assert::True(t.joinable(), pcf_current_information);
      t.join();
      Assert::AreEqual("thread launched", result, pcf_current_information);
    }
  };
  
  pcf_test(Cpp11Test, Auto)
  pcf_test(Cpp11Test, InitializerList)
  pcf_test(Cpp11Test, Thread)
}
