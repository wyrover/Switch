#include <Switch/System/Predicate.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class PrediacateTest : public TestFixture {
  protected:
    class MyClass : public object {
    public:
      static bool IsEmpty(const string& str) { return string::IsNullOrEmpty(str); }
      bool IsNotEmpty(const string& str) { return !string::IsNullOrEmpty(str); }
    };
    
    void Static() {
      sw_using(Predicate<const string&> p(&MyClass::IsEmpty)) {
        Assert::IsFalse(p("Not empty"), sw_current_information);
        Assert::IsTrue(p(""), sw_current_information);
      }
    }
    
    void Member() {
      MyClass m;
      sw_using(Predicate<const string&> p(m, &MyClass::IsNotEmpty)) {
        Assert::IsTrue(p("Not empty"), sw_current_information);
        Assert::IsFalse(p(""), sw_current_information);
      }
    }
    
    void Empty() {
      sw_using(Predicate<const string&> p) {
        Assert::DoesNotThrows(sw_delegate {p("Not empty");}, sw_current_information);
        Assert::DoesNotThrows(sw_delegate {p("");}, sw_current_information);
      }
    }
  };
  
  sw_test(PrediacateTest, Static)
  sw_test(PrediacateTest, Member)
  sw_test(PrediacateTest, Empty)
}
