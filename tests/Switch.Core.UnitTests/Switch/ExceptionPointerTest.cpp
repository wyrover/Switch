#include <Switch/ExceptionPtr.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class ExceptionPointerTest : public TestFixture {
  protected:
    void CreateExceptionPointerEmptyThenRethrow() {
      ExceptionPtr ep;
      Assert::IsTrue(ep == null, _caller);
      Assert::DoesNotThrows(_delegate {ep.Rethrow();}, _caller);
    }
    
    void CreateKnownExceptionThenRethrow() {
      ExceptionPtr ep = ExceptionPtr::Create(InvalidCastException());
      Assert::IsFalse(ep == null);
      Assert::Throws<InvalidCastException>(_delegate {ep.Rethrow();}, _caller);
    }
    
    void CreateUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep = ExceptionPtr::Create(MyException());
      Assert::IsFalse(ep == null);
      Assert::Throws<MyException>(_delegate {ep.Rethrow();}, _caller);
    }
   
    void GetCurrentExceptionOnNullExceptionThenRethrow() {
      ExceptionPtr ep;
      {
        ep = ExceptionPtr::CurrentException();
      }
      Assert::IsTrue(ep == null, _caller);
      Assert::DoesNotThrows(_delegate {ep.Rethrow();}, _caller);
    }
    
    void GetCurrentExceptionOnKnownExceptionThenRethrow() {
      ExceptionPtr ep;
      {
        try {
          throw InvalidOperationException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException();
        }
      }
      Assert::IsFalse(ep == null, _caller);
      Assert::Throws<InvalidOperationException>(_delegate {ep.Rethrow();}, _caller);
    }
    
    void GetCurrentExceptionOnUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep;
      {
        try {
          throw MyException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException();
        }
      }
      Assert::IsFalse(ep == null, _caller);
      Assert::Throws<MyException>(_delegate {ep.Rethrow();}, _caller);
    }
  };
  
  _add_test (ExceptionPointerTest, CreateExceptionPointerEmptyThenRethrow)
  _add_test (ExceptionPointerTest, CreateKnownExceptionThenRethrow)
  _add_test (ExceptionPointerTest, CreateUnknownExceptionThenRethrow)
  _add_test (ExceptionPointerTest, GetCurrentExceptionOnNullExceptionThenRethrow)
  _add_test (ExceptionPointerTest, GetCurrentExceptionOnKnownExceptionThenRethrow)
  _add_test (ExceptionPointerTest, GetCurrentExceptionOnUnknownExceptionThenRethrow)
}
