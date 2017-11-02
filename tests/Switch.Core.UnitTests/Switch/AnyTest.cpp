#include <Switch/Any.hpp>
#include <Switch/Unused.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class _test_fixture (AnyTest) {
    void _test (HasValueOnEmpty)() {
      any a;
      Assert::IsFalse(a.HasValue, _caller);
    }
    
    void _test (ValueOnEmpty)() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        const object& o = a.Value;
        Unused(o);
      }, _caller);
    }
    
    void _test (AsInt32OnEmpty)() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<Int32>();}, _caller);
    }
    
    void _test (AsStringOnEmpty)() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<string>();}, _caller);
    }
    
    void _test (EqualsOnEmpty)() {
      any a;
      Assert::AreEqual(any(), a, _caller);
    }
    
    void _test (GetHashCodeOnEmpty)() {
      any a;
      Assert::AreEqual(0, a.GetHashCode(), _caller);
    }
    
    void _test (IsInt32OnEmpty)() {
      any a;
      Assert::IsFalse(a.Is<Int32>(), _caller);
    }
    
    void _test (IsStringOnEmpty)() {
      any a;
      Assert::IsFalse(a.Is<string>(), _caller);
    }
    
    void _test (ToStringOnEmpty)() {
      any a;
      Assert::AreEqual("", a.ToString(), _caller);
    }
    
    void _test (ImplicitCastToInt32OnEmpty)() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        int i = a;
        Unused(i);
      }, _caller);
    }
    
    void _test (ImplicitCastToStringOnEmpty)() {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        string s = a;
        Unused(s);
      }, _caller);
    }

    void _test (HasValueOnInt32)() {
      any a = 42;
      Assert::IsTrue(a.HasValue, _caller);
    }
    
    void _test (ValueOnInt32)() {
      any a = 42;
      Assert::AreEqual(42, as<Int32>(a.Value()), _caller);
    }
    
    void _test (AsInt32OnInt32)() {
      any a = 42;
      Assert::DoesNotThrows(_delegate {a.As<Int32>();}, _caller);
    }
    
    void _test (AsStringOnInt32)() {
      any a = 42;
      Assert::Throws<InvalidCastException>(_delegate {a.As<string>();}, _caller);
    }
    
    void _test (EqualsOnInt32)() {
      any a = 42;
      Assert::AreEqual(any(42), a, _caller);
      Assert::AreNotEqual(any(43), a, _caller);
    }
    
    void _test (GetHashCodeOnInt32)() {
      any a = 42;
      Assert::AreEqual(42, a.GetHashCode(), _caller);
    }
    
    void _test (IsInt32OnInt32)() {
      any a = 42;
      Assert::IsTrue(a.Is<Int32>(), _caller);
    }
    
    void _test (IsStringOnInt32)() {
      any a = 42;
      Assert::IsFalse(a.Is<string>(), _caller);
    }
    
    void _test (ToStringOnInt32)() {
      any a = 42;
      Assert::AreEqual("42", a.ToString(), _caller);
    }
    
    void _test (ImplicitCastToInt32OnInt32)() {
      any a = 42;
      int32 i = a;
      Assert::AreEqual(42, i, _caller);
    }
    
    void _test (ImplicitCastToStringOnInt32)() {
      any a = 42;
      string s = a;
      Assert::AreEqual("42", s, _caller);
    }
    
    void _test (HasValueOnString)() {
      any a = "Forty two";
      Assert::IsTrue(a.HasValue, _caller);
    }
    
    void _test (ValueOnString)() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a.Value()), _caller);
    }
    
    void _test (AsInt32OnString)() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {a.As<Int32>();}, _caller);
    }
    
    void _test (AsStringOnString)() {
      any a = "Forty two";
      Assert::DoesNotThrows(_delegate {a.As<string>();}, _caller);
    }
    
    void _test (EqualsOnString)() {
      any a = "Forty two";
      Assert::AreEqual(any("Forty two"), a, _caller);
      Assert::AreNotEqual(any("Forty three"), a, _caller);
    }
    
    void _test (GetHashCodeOnString)() {
      any a = "Forty two";
      Assert::AreEqual(38242606, a.GetHashCode(), _caller);
    }
    
    void _test (IsInt32OnString)() {
      any a = "Forty two";
      Assert::IsFalse(a.Is<Int32>(), _caller);
    }
    
    void _test (IsStringOnString)() {
      any a = "Forty two";
      Assert::IsTrue(a.Is<string>(), _caller);
    }
    
    void _test (ToStringOnString)() {
      any a = "Forty two";
      Assert::AreEqual("Forty two", a.ToString(), _caller);
    }
    
    void _test (ImplicitCastToStringOnString)() {
      any a = "Forty two";
      string s = a;
      Assert::AreEqual("Forty two", s, _caller);
    }
    
    void _test (ImplicitCastToInt32OnString)() {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {
        int i = a;
        Unused(i);
      }, _caller);
    }
    
    void _test (AnyFormInt32ThanFromString)() {
      any a= 42;
      Assert::AreEqual(42, as<Int32>(a), _caller);
      a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a), _caller);
    }
  };
  
  _add_test_fixture (AnyTest)
  _add_test (AnyTest, HasValueOnEmpty)
  _add_test (AnyTest, ValueOnEmpty)
  _add_test (AnyTest, AsInt32OnEmpty)
  _add_test (AnyTest, AsStringOnEmpty)
  _add_test (AnyTest, EqualsOnEmpty)
  _add_test (AnyTest, GetHashCodeOnEmpty)
  _add_test (AnyTest, IsInt32OnEmpty)
  _add_test (AnyTest, IsStringOnEmpty)
  _add_test (AnyTest, ToStringOnEmpty)
  _add_test (AnyTest, ImplicitCastToInt32OnEmpty)
  _add_test (AnyTest, ImplicitCastToStringOnEmpty)
  _add_test (AnyTest, HasValueOnInt32)
  _add_test (AnyTest, ValueOnInt32)
  _add_test (AnyTest, AsInt32OnInt32)
  _add_test (AnyTest, AsStringOnInt32)
  _add_test (AnyTest, EqualsOnInt32)
  _add_test (AnyTest, GetHashCodeOnInt32)
  _add_test (AnyTest, IsInt32OnInt32)
  _add_test (AnyTest, IsStringOnInt32)
  _add_test (AnyTest, ToStringOnInt32)
  _add_test (AnyTest, ImplicitCastToInt32OnInt32)
  _add_test (AnyTest, ImplicitCastToStringOnInt32)
  _add_test (AnyTest, HasValueOnString)
  _add_test (AnyTest, ValueOnString)
  _add_test (AnyTest, AsInt32OnString)
  _add_test (AnyTest, AsStringOnString)
  _add_test (AnyTest, EqualsOnString)
  _add_test (AnyTest, GetHashCodeOnString)
  _add_test (AnyTest, IsInt32OnString)
  _add_test (AnyTest, IsStringOnString)
  _add_test (AnyTest, ToStringOnString)
  _add_test (AnyTest, ImplicitCastToStringOnString)
  _add_test (AnyTest, ImplicitCastToInt32OnString)
  _add_test (AnyTest, AnyFormInt32ThanFromString)
}
