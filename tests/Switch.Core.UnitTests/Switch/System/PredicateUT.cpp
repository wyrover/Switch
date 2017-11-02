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
        Assert::IsFalse(p("Not empty"), _caller);
        Assert::IsTrue(p(""), _caller);
      }
    }
    
    void Member() {
      MyClass m;
      _using(Predicate<const string&> p(m, &MyClass::IsNotEmpty)) {
        Assert::IsTrue(p("Not empty"), _caller);
        Assert::IsFalse(p(""), _caller);
      }
    }
    
    void Empty() {
      _using(Predicate<const string&> p) {
        Assert::DoesNotThrows(_delegate {p("Not empty");}, _caller);
        Assert::DoesNotThrows(_delegate {p("");}, _caller);
      }
    }
  };
  
  _add_test(PrediacateTest, Static)
  _add_test(PrediacateTest, Member)
  _add_test(PrediacateTest, Empty)
}
