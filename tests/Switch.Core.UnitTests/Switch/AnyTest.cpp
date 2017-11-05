#include <Switch/Any.hpp>
#include <Switch/Unused.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class _TestFixture(AnyTest) {
    void _Test(HasValueOnEmpty) {
      any a;
      Assert::IsFalse(a.HasValue, _caller);
    }
    
    void _Test(ValueOnEmpty) {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        const object& o = a.Value;
        Unused(o);
      }, _caller);
    }
    
    void _Test(AsInt32OnEmpty) {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<Int32>();}, _caller);
    }
    
    void _Test(AsStringOnEmpty) {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {a.As<string>();}, _caller);
    }
    
    void _Test(EqualsOnEmpty) {
      any a;
      Assert::AreEqual(any(), a, _caller);
    }
    
    void _Test(GetHashCodeOnEmpty) {
      any a;
      Assert::AreEqual(0, a.GetHashCode(), _caller);
    }
    
    void _Test(IsInt32OnEmpty) {
      any a;
      Assert::IsFalse(a.Is<Int32>(), _caller);
    }
    
    void _Test(IsStringOnEmpty) {
      any a;
      Assert::IsFalse(a.Is<string>(), _caller);
    }
    
    void _Test(ToStringOnEmpty) {
      any a;
      Assert::AreEqual("", a.ToString(), _caller);
    }
    
    void _Test(ImplicitCastToInt32OnEmpty) {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        int i = a;
        Unused(i);
      }, _caller);
    }
    
    void _Test(ImplicitCastToStringOnEmpty) {
      any a;
      Assert::Throws<InvalidOperationException>(_delegate {
        string s = a;
        Unused(s);
      }, _caller);
    }

    void _Test(HasValueOnInt32) {
      any a = 42;
      Assert::IsTrue(a.HasValue, _caller);
    }
    
    void _Test(ValueOnInt32) {
      any a = 42;
      Assert::AreEqual(42, as<Int32>(a.Value()), _caller);
    }
    
    void _Test(AsInt32OnInt32) {
      any a = 42;
      Assert::DoesNotThrows(_delegate {a.As<Int32>();}, _caller);
    }
    
    void _Test(AsStringOnInt32) {
      any a = 42;
      Assert::Throws<InvalidCastException>(_delegate {a.As<string>();}, _caller);
    }
    
    void _Test(EqualsOnInt32) {
      any a = 42;
      Assert::AreEqual(any(42), a, _caller);
      Assert::AreNotEqual(any(43), a, _caller);
    }
    
    void _Test(GetHashCodeOnInt32) {
      any a = 42;
      Assert::AreEqual(42, a.GetHashCode(), _caller);
    }
    
    void _Test(IsInt32OnInt32) {
      any a = 42;
      Assert::IsTrue(a.Is<Int32>(), _caller);
    }
    
    void _Test(IsStringOnInt32) {
      any a = 42;
      Assert::IsFalse(a.Is<string>(), _caller);
    }
    
    void _Test(ToStringOnInt32) {
      any a = 42;
      Assert::AreEqual("42", a.ToString(), _caller);
    }
    
    void _Test(ImplicitCastToInt32OnInt32) {
      any a = 42;
      int32 i = a;
      Assert::AreEqual(42, i, _caller);
    }
    
    void _Test(ImplicitCastToStringOnInt32) {
      any a = 42;
      string s = a;
      Assert::AreEqual("42", s, _caller);
    }
    
    void _Test(HasValueOnString) {
      any a = "Forty two";
      Assert::IsTrue(a.HasValue, _caller);
    }
    
    void _Test(ValueOnString) {
      any a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a.Value()), _caller);
    }
    
    void _Test(AsInt32OnString) {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {a.As<Int32>();}, _caller);
    }
    
    void _Test(AsStringOnString) {
      any a = "Forty two";
      Assert::DoesNotThrows(_delegate {a.As<string>();}, _caller);
    }
    
    void _Test(EqualsOnString) {
      any a = "Forty two";
      Assert::AreEqual(any("Forty two"), a, _caller);
      Assert::AreNotEqual(any("Forty three"), a, _caller);
    }
    
    void _Test(GetHashCodeOnString) {
      any a = "Forty two";
      Assert::AreEqual(38242606, a.GetHashCode(), _caller);
    }
    
    void _Test(IsInt32OnString) {
      any a = "Forty two";
      Assert::IsFalse(a.Is<Int32>(), _caller);
    }
    
    void _Test(IsStringOnString) {
      any a = "Forty two";
      Assert::IsTrue(a.Is<string>(), _caller);
    }
    
    void _Test(ToStringOnString) {
      any a = "Forty two";
      Assert::AreEqual("Forty two", a.ToString(), _caller);
    }
    
    void _Test(ImplicitCastToStringOnString) {
      any a = "Forty two";
      string s = a;
      Assert::AreEqual("Forty two", s, _caller);
    }
    
    void _Test(ImplicitCastToInt32OnString) {
      any a = "Forty two";
      Assert::Throws<InvalidCastException>(_delegate {
        int i = a;
        Unused(i);
      }, _caller);
    }
    
    void _Test(AnyFormInt32ThanFromString) {
      any a= 42;
      Assert::AreEqual(42, as<Int32>(a), _caller);
      a = "Forty two";
      Assert::AreEqual("Forty two", as<string>(a), _caller);
    }
  };
  
  _AddTestFixture(AnyTest)
  _AddTest(AnyTest, HasValueOnEmpty)
  _AddTest(AnyTest, ValueOnEmpty)
  _AddTest(AnyTest, AsInt32OnEmpty)
  _AddTest(AnyTest, AsStringOnEmpty)
  _AddTest(AnyTest, EqualsOnEmpty)
  _AddTest(AnyTest, GetHashCodeOnEmpty)
  _AddTest(AnyTest, IsInt32OnEmpty)
  _AddTest(AnyTest, IsStringOnEmpty)
  _AddTest(AnyTest, ToStringOnEmpty)
  _AddTest(AnyTest, ImplicitCastToInt32OnEmpty)
  _AddTest(AnyTest, ImplicitCastToStringOnEmpty)
  _AddTest(AnyTest, HasValueOnInt32)
  _AddTest(AnyTest, ValueOnInt32)
  _AddTest(AnyTest, AsInt32OnInt32)
  _AddTest(AnyTest, AsStringOnInt32)
  _AddTest(AnyTest, EqualsOnInt32)
  _AddTest(AnyTest, GetHashCodeOnInt32)
  _AddTest(AnyTest, IsInt32OnInt32)
  _AddTest(AnyTest, IsStringOnInt32)
  _AddTest(AnyTest, ToStringOnInt32)
  _AddTest(AnyTest, ImplicitCastToInt32OnInt32)
  _AddTest(AnyTest, ImplicitCastToStringOnInt32)
  _AddTest(AnyTest, HasValueOnString)
  _AddTest(AnyTest, ValueOnString)
  _AddTest(AnyTest, AsInt32OnString)
  _AddTest(AnyTest, AsStringOnString)
  _AddTest(AnyTest, EqualsOnString)
  _AddTest(AnyTest, GetHashCodeOnString)
  _AddTest(AnyTest, IsInt32OnString)
  _AddTest(AnyTest, IsStringOnString)
  _AddTest(AnyTest, ToStringOnString)
  _AddTest(AnyTest, ImplicitCastToStringOnString)
  _AddTest(AnyTest, ImplicitCastToInt32OnString)
  _AddTest(AnyTest, AnyFormInt32ThanFromString)
}
