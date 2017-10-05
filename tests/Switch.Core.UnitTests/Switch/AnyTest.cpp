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
      Assert::IsFalse(a.HasValue, _caller);
    }
    
    void ValueOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        const object& o = a.Value;
        Unused(o);
      }, _caller);
    }
    
    void AsInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<Int32>();}, _caller);
    }
    
    void AsStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<string>();}, _caller);
    }
    
    void EqualsOnEmpty() {
      any a;
      Assert::AreEqual(any(), a, _caller);
    }
    
    void GetHashCodeOnEmpty() {
      any a;
      Assert::AreEqual(0, a.GetHashCode(), _caller);
    }
    
    void IsInt32OnEmpty() {
      any a;
      Assert::IsFalse(a.Is<Int32>(), _caller);
    }
    
    void IsStringOnEmpty() {
      any a;
      Assert::IsFalse(a.Is<string>(), _caller);
    }
    
    void ToStringOnEmpty() {
      any a;
      Assert::AreEqual("", a.ToString(), _caller);
    }
    
    void ImplicitCastToInt32OnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        int i = a;
        Unused(i);
      }, _caller);
    }
    
    void ImplicitCastToStringOnEmpty() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        string s = a;
        Unused(s);
      }, _caller);
    }

    void HasValueOnInt32() {
      any a = 42;
      Assert::IsTrue(a.HasValue, _caller);
    }
    
    void ValueOnInt32() {
      any a = 42;
      Assert::AreEqual(42, as<Int32>(a.Value()), _caller);
    }
    
    void AsInt32OnInt32() {
      any a = 42;
      Assert::DoesNotThrows(_delegate {a.As<Int32>();}, _caller);
    }
    
    void AsStringOnInt32() {
      any a = 42;
      Assert::Throws<InvalidCastException>(_delegate {a.As<string>();}, _caller);
    }
    
    void EqualsOnInt32() {
      any a = 42;
      Assert::AreEqual(any(42), a, _caller);
      Assert::AreNotEqual(any(43), a, _caller);
    }
    
    void GetHashCodeOnInt32() {
      any a = 42;
      Assert::AreEqual(42, a.GetHashCode(), _caller);
    }
    
    void IsInt32OnInt32() {
      any a = 42;
      Assert::IsTrue(a.Is<Int32>(), _caller);
    }
    
    void IsStringOnInt32() {
      any a = 42;
      Assert::IsFalse(a.Is<string>(), _caller);
    }
    
    void ToStringOnInt32() {
      any a = 42;
      Assert::AreEqual("42", a.ToString(), _caller);
    }
    
    void ImplicitCastToInt32OnInt32() {
      any a = 42;
      int32 i = a;
      Assert::AreEqual(42, i, _caller);
    }
    
    void ImplicitCastToStringOnInt32() {
      any a = 42;
      string s = a;
      Assert::AreEqual("42", s, _caller);
    }
    
    void HasValueOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.HasValue, _caller);
    }
    
    void ValueOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a.Value()), _caller);
    }
    
    void AsInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {a.As<Int32>();}, _caller);
    }
    
    void AsStringOnString() {
      any a = "Forty two";
      Assert::DoesNotThrows(_delegate {a.As<string>();}, _caller);
    }
    
    void EqualsOnString() {
      any a = "Forty two";
      Assert::AreEqual(any("Forty two"), a, _caller);
      Assert::AreNotEqual(any("Forty three"), a, _caller);
    }
    
    void GetHashCodeOnString() {
      any a = "Forty two";
      Assert::AreEqual(38242606, a.GetHashCode(), _caller);
    }
    
    void IsInt32OnString() {
      any a = "Forty two";
      Assert::IsFalse(a.Is<Int32>(), _caller);
    }
    
    void IsStringOnString() {
      any a = "Forty two";
      Assert::IsTrue(a.Is<string>(), _caller);
    }
    
    void ToStringOnString() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", a.ToString(), _caller);
    }
    
    void ImplicitCastToStringOnString() {
      any a = "Forty two";
      string s = a;
      Assert::AreEqual("Forty two", s, _caller);
    }
    
    void ImplicitCastToInt32OnString() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {
        int i = a;
        Unused(i);
      }, _caller);
    }
    
    void AnyFormInt32ThanFromString() {
      any a= 42;
      Assert::AreEqual(42, as<Int32>(a), _caller);
      a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a), _caller);
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
