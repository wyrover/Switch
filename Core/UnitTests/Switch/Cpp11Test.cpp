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
        Assert::AreEqual(c, char32_t(chars[index++]), _current_information);
    }
    
    void InitializerList() {
      Array<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      
      int32 index = 0;
      for (const auto& value : values)
        Assert::AreEqual(value, results[index++], _current_information);
      Assert::AreEqual(10, index, _current_information);
    }
    
    void Thread() {
      string result;

      std::thread t([&] {
        result = "thread launched";
      });
      
      Assert::True(t.joinable(), _current_information);
      t.join();
      Assert::AreEqual("thread launched", result, _current_information);
    }
  };
  
  _test(Cpp11Test, Auto)
  _test(Cpp11Test, InitializerList)
  _test(Cpp11Test, Thread)
}
