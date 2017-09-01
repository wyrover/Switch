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
      _using(Predicate<const string&> p(&MyClass::IsEmpty)) {
        Assert::IsFalse(p("Not empty"), _current_information);
        Assert::IsTrue(p(""), _current_information);
      }
    }
    
    void Member() {
      MyClass m;
      _using(Predicate<const string&> p(m, &MyClass::IsNotEmpty)) {
        Assert::IsTrue(p("Not empty"), _current_information);
        Assert::IsFalse(p(""), _current_information);
      }
    }
    
    void Empty() {
      _using(Predicate<const string&> p) {
        Assert::DoesNotThrows(_delegate {p("Not empty");}, _current_information);
        Assert::DoesNotThrows(_delegate {p("");}, _current_information);
      }
    }
  };
  
  _test(PrediacateTest, Static)
  _test(PrediacateTest, Member)
  _test(PrediacateTest, Empty)
}
