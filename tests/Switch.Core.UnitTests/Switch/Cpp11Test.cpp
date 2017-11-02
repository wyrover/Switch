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
      
      int32 index = 0;
      for (auto c : str)
        Assert::AreEqual(c, char32_t(chars[index++]), _caller);
    }
    
    void InitializerList() {
      Array<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      
      int32 index = 0;
      for (const auto& value : values)
        Assert::AreEqual(value, results[index++], _caller);
      Assert::AreEqual(10, index, _caller);
    }
    
    void Thread() {
      string result;

      std::thread t([&] {
        result = "thread launched";
      });
      
      Assert::True(t.joinable(), _caller);
      t.join();
      Assert::AreEqual("thread launched", result, _caller);
    }
  };
  
  _add_test (Cpp11Test, Auto)
  _add_test (Cpp11Test, InitializerList)
  _add_test (Cpp11Test, Thread)
}
