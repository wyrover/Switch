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
      Assert::IsFalse(a.HasValue, _current_information);
    }
    
    void ValueOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        const object& o = a.Value;
        Unused(o);
      }, _current_information);
    }
    
    void AsInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<Int32>();}, _current_information);
    }
    
    void AsStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<string>();}, _current_information);
    }
    
    void EqualsOnEmpty() {
      any a;
      Assert::AreEqual(any(), a, _current_information);
    }
    
    void GetHashCodeOnEmpty() {
      any a;
      Assert::AreEqual(0, a.GetHashCode(), _current_information);
    }
    
    void IsInt32OnEmpty() {
      any a;
      Assert::IsFalse(a.Is<Int32>(), _current_information);
    }
    
    void IsStringOnEmpty() {
      any a;
      Assert::IsFalse(a.Is<string>(), _current_information);
    }
    
    void ToStringOnEmpty() {
      any a;
      Assert::AreEqual("", a.ToString(), _current_information);
    }
    
    void ImplicitCastToInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        int i = a;
        Unused(i);
      }, _current_information);
    }
    
    void ImplicitCastToStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        string s = a;
        Unused(s);
      }, _current_information);
    }

    void HasValueOnInt32() {
      any a = 42;
      Assert::IsTrue(a.HasValue, _current_information);
    }
    
    void ValueOnInt32() {
      any a = 42;
      Assert::AreEqual(42, as<Int32>(a.Value()), _current_information);
    }
    
    void AsInt32OnInt32() {
      any a = 42;
      Assert::DoesNotThrows(_delegate {a.As<Int32>();}, _current_information);
    }
    
    void AsStringOnInt32() {
      any a = 42;
      Assert::Throws<InvalidCastException>(_delegate {a.As<string>();}, _current_information);
    }
    
    void EqualsOnInt32() {
      any a = 42;
      Assert::AreEqual(any(42), a, _current_information);
      Assert::AreNotEqual(any(43), a, _current_information);
    }
    
    void GetHashCodeOnInt32() {
      any a = 42;
      Assert::AreEqual(42, a.GetHashCode(), _current_information);
    }
    
    void IsInt32OnInt32() {
      any a = 42;
      Assert::IsTrue(a.Is<Int32>(), _current_information);
    }
    
    void IsStringOnInt32() {
      any a = 42;
      Assert::IsFalse(a.Is<string>(), _current_information);
    }
    
    void ToStringOnInt32() {
      any a = 42;
      Assert::AreEqual("42", a.ToString(), _current_information);
    }
    
    void ImplicitCastToInt32OnInt32() {
      any a = 42;
      int32 i = a;
      Assert::AreEqual(42, i, _current_information);
    }
    
    void ImplicitCastToStringOnInt32() {
      any a = 42;
      string s = a;
      Assert::AreEqual("42", s, _current_information);
    }
    
    void HasValueOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.HasValue, _current_information);
    }
    
    void ValueOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a.Value()), _current_information);
    }
    
    void AsInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {a.As<Int32>();}, _current_information);
    }
    
    void AsStringOnString() {
      any a = "Forty two";
      Assert::DoesNotThrows(_delegate {a.As<string>();}, _current_information);
    }
    
    void EqualsOnString() {
      any a = "Forty two";
      Assert::AreEqual(any("Forty two"), a, _current_information);
      Assert::AreNotEqual(any("Forty three"), a, _current_information);
    }
    
    void GetHashCodeOnString() {
      any a = "Forty two";
      Assert::AreEqual(38242606, a.GetHashCode(), _current_information);
    }
    
    void IsInt32OnString() {
      any a = "Forty two";
      Assert::IsFalse(a.Is<Int32>(), _current_information);
    }
    
    void IsStringOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.Is<string>(), _current_information);
    }
    
    void ToStringOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", a.ToString(), _current_information);
    }
    
    void ImplicitCastToStringOnString() {
      any a = "Forty two";
      string s = a;
      Assert::AreEqual("Forty two", s, _current_information);
    }
    
    void ImplicitCastToInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {
        int i = a;
        Unused(i);
      }, _current_information);
    }
    
    void AnyFormInt32ThanFromString() {
      any a= 42;
      Assert::AreEqual(42, as<Int32>(a), _current_information);
      a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a), _current_information);
    }
  };
  
  _test(AnyTest, HasValueOnEmpty)
  _test(AnyTest, ValueOnEmpty)
  _test(AnyTest, AsInt32OnEmpty)
  _test(AnyTest, AsStringOnEmpty)
  _test(AnyTest, EqualsOnEmpty)
  _test(AnyTest, GetHashCodeOnEmpty)
  _test(AnyTest, IsInt32OnEmpty)
  _test(AnyTest, IsStringOnEmpty)
  _test(AnyTest, ToStringOnEmpty)
  _test(AnyTest, ImplicitCastToInt32OnEmpty)
  _test(AnyTest, ImplicitCastToStringOnEmpty)
  _test(AnyTest, HasValueOnInt32)
  _test(AnyTest, ValueOnInt32)
  _test(AnyTest, AsInt32OnInt32)
  _test(AnyTest, AsStringOnInt32)
  _test(AnyTest, EqualsOnInt32)
  _test(AnyTest, GetHashCodeOnInt32)
  _test(AnyTest, IsInt32OnInt32)
  _test(AnyTest, IsStringOnInt32)
  _test(AnyTest, ToStringOnInt32)
  _test(AnyTest, ImplicitCastToInt32OnInt32)
  _test(AnyTest, ImplicitCastToStringOnInt32)
  _test(AnyTest, HasValueOnString)
  _test(AnyTest, ValueOnString)
  _test(AnyTest, AsInt32OnString)
  _test(AnyTest, AsStringOnString)
  _test(AnyTest, EqualsOnString)
  _test(AnyTest, GetHashCodeOnString)
  _test(AnyTest, IsInt32OnString)
  _test(AnyTest, IsStringOnString)
  _test(AnyTest, ToStringOnString)
  _test(AnyTest, ImplicitCastToStringOnString)
  _test(AnyTest, ImplicitCastToInt32OnString)
  _test(AnyTest, AnyFormInt32ThanFromString)
}
