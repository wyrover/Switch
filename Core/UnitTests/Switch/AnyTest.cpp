#include <Switch/Any.hpp>
#include <Switch/Unused.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class AnyTest : public TestFixture {
  protected:
    void HasValueOnEmpty() {
      any a;
      Assert::IsFalse(a.HasValue, sw_current_information);
    }
    
    void ValueOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(sw_delegate {
        const object& o = a.Value;
        Unused(o);
      }, sw_current_information);
    }
    
    void AsInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(sw_delegate {a.As<Int32>();}, sw_current_information);
    }
    
    void AsStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(sw_delegate {a.As<string>();}, sw_current_information);
    }
    
    void EqualsOnEmpty() {
      any a;
      Assert::AreEqual(any(), a, sw_current_information);
    }
    
    void GetHashCodeOnEmpty() {
      any a;
      Assert::AreEqual(0, a.GetHashCode(), sw_current_information);
    }
    
    void IsInt32OnEmpty() {
      any a;
      Assert::IsFalse(a.Is<Int32>(), sw_current_information);
    }
    
    void IsStringOnEmpty() {
      any a;
      Assert::IsFalse(a.Is<string>(), sw_current_information);
    }
    
    void ToStringOnEmpty() {
      any a;
      Assert::AreEqual("", a.ToString(), sw_current_information);
    }
    
    void ImplicitCastToInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(sw_delegate {
        int i = a;
        Unused(i);
      }, sw_current_information);
    }
    
    void ImplicitCastToStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(sw_delegate {
        string s = a;
        Unused(s);
      }, sw_current_information);
    }

    void HasValueOnInt32() {
      any a = 42;
      Assert::IsTrue(a.HasValue, sw_current_information);
    }
    
    void ValueOnInt32() {
      any a = 42;
      Assert::AreEqual(42, as<Int32>(a.Value()), sw_current_information);
    }
    
    void AsInt32OnInt32() {
      any a = 42;
      Assert::DoesNotThrows(sw_delegate {a.As<Int32>();}, sw_current_information);
    }
    
    void AsStringOnInt32() {
      any a = 42;
      Assert::Throws<InvalidCastException>(sw_delegate {a.As<string>();}, sw_current_information);
    }
    
    void EqualsOnInt32() {
      any a = 42;
      Assert::AreEqual(any(42), a, sw_current_information);
      Assert::AreNotEqual(any(43), a, sw_current_information);
    }
    
    void GetHashCodeOnInt32() {
      any a = 42;
      Assert::AreEqual(42, a.GetHashCode(), sw_current_information);
    }
    
    void IsInt32OnInt32() {
      any a = 42;
      Assert::IsTrue(a.Is<Int32>(), sw_current_information);
    }
    
    void IsStringOnInt32() {
      any a = 42;
      Assert::IsFalse(a.Is<string>(), sw_current_information);
    }
    
    void ToStringOnInt32() {
      any a = 42;
      Assert::AreEqual("42", a.ToString(), sw_current_information);
    }
    
    void ImplicitCastToInt32OnInt32() {
      any a = 42;
      int32 i = a;
      Assert::AreEqual(42, i, sw_current_information);
    }
    
    void ImplicitCastToStringOnInt32() {
      any a = 42;
      string s = a;
      Assert::AreEqual("42", s, sw_current_information);
    }
    
    void HasValueOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.HasValue, sw_current_information);
    }
    
    void ValueOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a.Value()), sw_current_information);
    }
    
    void AsInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(sw_delegate {a.As<Int32>();}, sw_current_information);
    }
    
    void AsStringOnString() {
      any a = "Forty two";
      Assert::DoesNotThrows(sw_delegate {a.As<string>();}, sw_current_information);
    }
    
    void EqualsOnString() {
      any a = "Forty two";
      Assert::AreEqual(any("Forty two"), a, sw_current_information);
      Assert::AreNotEqual(any("Forty three"), a, sw_current_information);
    }
    
    void GetHashCodeOnString() {
      any a = "Forty two";
      Assert::AreEqual(38242606, a.GetHashCode(), sw_current_information);
    }
    
    void IsInt32OnString() {
      any a = "Forty two";
      Assert::IsFalse(a.Is<Int32>(), sw_current_information);
    }
    
    void IsStringOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.Is<string>(), sw_current_information);
    }
    
    void ToStringOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", a.ToString(), sw_current_information);
    }
    
    void ImplicitCastToStringOnString() {
      any a = "Forty two";
      string s = a;
      Assert::AreEqual("Forty two", s, sw_current_information);
    }
    
    void ImplicitCastToInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(sw_delegate {
        int i = a;
        Unused(i);
      }, sw_current_information);
    }
    
    void AnyFormInt32ThanFromString() {
      any a= 42;
      Assert::AreEqual(42, as<Int32>(a), sw_current_information);
      a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a), sw_current_information);
    }
  };
  
  sw_test(AnyTest, HasValueOnEmpty)
  sw_test(AnyTest, ValueOnEmpty)
  sw_test(AnyTest, AsInt32OnEmpty)
  sw_test(AnyTest, AsStringOnEmpty)
  sw_test(AnyTest, EqualsOnEmpty)
  sw_test(AnyTest, GetHashCodeOnEmpty)
  sw_test(AnyTest, IsInt32OnEmpty)
  sw_test(AnyTest, IsStringOnEmpty)
  sw_test(AnyTest, ToStringOnEmpty)
  sw_test(AnyTest, ImplicitCastToInt32OnEmpty)
  sw_test(AnyTest, ImplicitCastToStringOnEmpty)
  sw_test(AnyTest, HasValueOnInt32)
  sw_test(AnyTest, ValueOnInt32)
  sw_test(AnyTest, AsInt32OnInt32)
  sw_test(AnyTest, AsStringOnInt32)
  sw_test(AnyTest, EqualsOnInt32)
  sw_test(AnyTest, GetHashCodeOnInt32)
  sw_test(AnyTest, IsInt32OnInt32)
  sw_test(AnyTest, IsStringOnInt32)
  sw_test(AnyTest, ToStringOnInt32)
  sw_test(AnyTest, ImplicitCastToInt32OnInt32)
  sw_test(AnyTest, ImplicitCastToStringOnInt32)
  sw_test(AnyTest, HasValueOnString)
  sw_test(AnyTest, ValueOnString)
  sw_test(AnyTest, AsInt32OnString)
  sw_test(AnyTest, AsStringOnString)
  sw_test(AnyTest, EqualsOnString)
  sw_test(AnyTest, GetHashCodeOnString)
  sw_test(AnyTest, IsInt32OnString)
  sw_test(AnyTest, IsStringOnString)
  sw_test(AnyTest, ToStringOnString)
  sw_test(AnyTest, ImplicitCastToStringOnString)
  sw_test(AnyTest, ImplicitCastToInt32OnString)
  sw_test(AnyTest, AnyFormInt32ThanFromString)
}
