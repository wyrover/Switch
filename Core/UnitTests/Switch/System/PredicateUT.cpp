#include <Pcf/System/Predicate.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

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
      pcf_using(Predicate<const string&> p(&MyClass::IsEmpty)) {
        Assert::IsFalse(p("Not empty"), pcf_current_information);
        Assert::IsTrue(p(""), pcf_current_information);
      }
    }
    
    void Member() {
      MyClass m;
      pcf_using(Predicate<const string&> p(m, &MyClass::IsNotEmpty)) {
        Assert::IsTrue(p("Not empty"), pcf_current_information);
        Assert::IsFalse(p(""), pcf_current_information);
      }
    }
    
    void Empty() {
      pcf_using(Predicate<const string&> p) {
        Assert::DoesNotThrows(pcf_delegate {p("Not empty");}, pcf_current_information);
        Assert::DoesNotThrows(pcf_delegate {p("");}, pcf_current_information);
      }
    }
  };
  
  pcf_test(PrediacateTest, Static)
  pcf_test(PrediacateTest, Member)
  pcf_test(PrediacateTest, Empty)
}
