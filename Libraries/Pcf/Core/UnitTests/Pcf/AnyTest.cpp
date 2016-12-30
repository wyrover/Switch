#include <Pcf/Any.h>
#include <Pcf/Unused.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class AnyTest : public TestFixture {
  protected:
    void HasValueOnEmpty() {
      any a;
      Assert::IsFalse(a.HasValue, pcf_current_information);
    }
    
    void ValueOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(pcf_delegate {
        const object& o = a.Value;
        Unused(o);
      }, pcf_current_information);
    }
    
    void AsInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(pcf_delegate {a.As<Int32>();}, pcf_current_information);
    }
    
    void AsStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(pcf_delegate {a.As<string>();}, pcf_current_information);
    }
    
    void EqualsOnEmpty() {
      any a;
      Assert::AreEqual(any(), a, pcf_current_information);
    }
    
    void GetHashCodeOnEmpty() {
      any a;
      Assert::AreEqual(0, a.GetHashCode(), pcf_current_information);
    }
    
    void IsInt32OnEmpty() {
      any a;
      Assert::IsFalse(a.Is<Int32>(), pcf_current_information);
    }
    
    void IsStringOnEmpty() {
      any a;
      Assert::IsFalse(a.Is<string>(), pcf_current_information);
    }
    
    void ToStringOnEmpty() {
      any a;
      Assert::AreEqual("", a.ToString(), pcf_current_information);
    }
    
    void ImplicitCastToInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(pcf_delegate {
        int i = a;
        Unused(i);
      }, pcf_current_information);
    }
    
    void ImplicitCastToStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(pcf_delegate {
        string s = a;
        Unused(s);
      }, pcf_current_information);
    }

    void HasValueOnInt32() {
      any a = 42;
      Assert::IsTrue(a.HasValue, pcf_current_information);
    }
    
    void ValueOnInt32() {
      any a = 42;
      Assert::AreEqual(42, as<Int32>(a.Value()), pcf_current_information);
    }
    
    void AsInt32OnInt32() {
      any a = 42;
      Assert::DoesNotThrows(pcf_delegate {a.As<Int32>();}, pcf_current_information);
    }
    
    void AsStringOnInt32() {
      any a = 42;
      Assert::Throws<InvalidCastException>(pcf_delegate {a.As<string>();}, pcf_current_information);
    }
    
    void EqualsOnInt32() {
      any a = 42;
      Assert::AreEqual(any(42), a, pcf_current_information);
      Assert::AreNotEqual(any(43), a, pcf_current_information);
    }
    
    void GetHashCodeOnInt32() {
      any a = 42;
      Assert::AreEqual(42, a.GetHashCode(), pcf_current_information);
    }
    
    void IsInt32OnInt32() {
      any a = 42;
      Assert::IsTrue(a.Is<Int32>(), pcf_current_information);
    }
    
    void IsStringOnInt32() {
      any a = 42;
      Assert::IsFalse(a.Is<string>(), pcf_current_information);
    }
    
    void ToStringOnInt32() {
      any a = 42;
      Assert::AreEqual("42", a.ToString(), pcf_current_information);
    }
    
    void ImplicitCastToInt32OnInt32() {
      any a = 42;
      int32 i = a;
      Assert::AreEqual(42, i, pcf_current_information);
    }
    
    void ImplicitCastToStringOnInt32() {
      any a = 42;
      string s = a;
      Assert::AreEqual("42", s, pcf_current_information);
    }
    
    void HasValueOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.HasValue, pcf_current_information);
    }
    
    void ValueOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a.Value()), pcf_current_information);
    }
    
    void AsInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(pcf_delegate {a.As<Int32>();}, pcf_current_information);
    }
    
    void AsStringOnString() {
      any a = "Forty two";
      Assert::DoesNotThrows(pcf_delegate {a.As<string>();}, pcf_current_information);
    }
    
    void EqualsOnString() {
      any a = "Forty two";
      Assert::AreEqual(any("Forty two"), a, pcf_current_information);
      Assert::AreNotEqual(any("Forty three"), a, pcf_current_information);
    }
    
    void GetHashCodeOnString() {
      any a = "Forty two";
      Assert::AreEqual(38242606, a.GetHashCode(), pcf_current_information);
    }
    
    void IsInt32OnString() {
      any a = "Forty two";
      Assert::IsFalse(a.Is<Int32>(), pcf_current_information);
    }
    
    void IsStringOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.Is<string>(), pcf_current_information);
    }
    
    void ToStringOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", a.ToString(), pcf_current_information);
    }
    
    void ImplicitCastToStringOnString() {
      any a = "Forty two";
      string s = a;
      Assert::AreEqual("Forty two", s, pcf_current_information);
    }
    
    void ImplicitCastToInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(pcf_delegate {
        int i = a;
        Unused(i);
      }, pcf_current_information);
    }
    
    void AnyFormInt32ThanFromString() {
      any a= 42;
      Assert::AreEqual(42, as<Int32>(a), pcf_current_information);
      a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a), pcf_current_information);
    }
  };
  
  pcf_test(AnyTest, HasValueOnEmpty);
  pcf_test(AnyTest, ValueOnEmpty);
  pcf_test(AnyTest, AsInt32OnEmpty);
  pcf_test(AnyTest, AsStringOnEmpty);
  pcf_test(AnyTest, EqualsOnEmpty);
  pcf_test(AnyTest, GetHashCodeOnEmpty);
  pcf_test(AnyTest, IsInt32OnEmpty);
  pcf_test(AnyTest, IsStringOnEmpty);
  pcf_test(AnyTest, ToStringOnEmpty);
  pcf_test(AnyTest, ImplicitCastToInt32OnEmpty);
  pcf_test(AnyTest, ImplicitCastToStringOnEmpty);
  pcf_test(AnyTest, HasValueOnInt32);
  pcf_test(AnyTest, ValueOnInt32);
  pcf_test(AnyTest, AsInt32OnInt32);
  pcf_test(AnyTest, AsStringOnInt32);
  pcf_test(AnyTest, EqualsOnInt32);
  pcf_test(AnyTest, GetHashCodeOnInt32);
  pcf_test(AnyTest, IsInt32OnInt32);
  pcf_test(AnyTest, IsStringOnInt32);
  pcf_test(AnyTest, ToStringOnInt32);
  pcf_test(AnyTest, ImplicitCastToInt32OnInt32);
  pcf_test(AnyTest, ImplicitCastToStringOnInt32);
  pcf_test(AnyTest, HasValueOnString);
  pcf_test(AnyTest, ValueOnString);
  pcf_test(AnyTest, AsInt32OnString);
  pcf_test(AnyTest, AsStringOnString);
  pcf_test(AnyTest, EqualsOnString);
  pcf_test(AnyTest, GetHashCodeOnString);
  pcf_test(AnyTest, IsInt32OnString);
  pcf_test(AnyTest, IsStringOnString);
  pcf_test(AnyTest, ToStringOnString);
  pcf_test(AnyTest, ImplicitCastToStringOnString);
  pcf_test(AnyTest, ImplicitCastToInt32OnString);
  pcf_test(AnyTest, AnyFormInt32ThanFromString);
}
