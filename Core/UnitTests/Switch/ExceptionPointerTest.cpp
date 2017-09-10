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
      Assert::IsTrue(ep == null, _current_information);
      Assert::DoesNotThrows(_delegate {ep.Rethrow();}, _current_information);
    }
    
    void CreateKnownExceptionThenRethrow() {
      ExceptionPtr ep = ExceptionPtr::Create(InvalidCastException());
      Assert::IsFalse(ep == null);
      Assert::Throws<InvalidCastException>(_delegate {ep.Rethrow();}, _current_information);
    }
    
    void CreateUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep = ExceptionPtr::Create(MyException());
      Assert::IsFalse(ep == null);
      Assert::Throws<MyException>(_delegate {ep.Rethrow();}, _current_information);
    }
   
    void GetCurrentExceptionOnNullExceptionThenRethrow() {
      ExceptionPtr ep;
      _using() {
        ep = ExceptionPtr::CurrentException;
      }
      Assert::IsTrue(ep == null, _current_information);
      Assert::DoesNotThrows(_delegate {ep.Rethrow();}, _current_information);
    }
    
    void GetCurrentExceptionOnKnownExceptionThenRethrow() {
      ExceptionPtr ep;
      _using() {
        try {
          throw InvalidOperationException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException;
        }
      }
      Assert::IsFalse(ep == null, _current_information);
      Assert::Throws<InvalidOperationException>(_delegate {ep.Rethrow();}, _current_information);
    }
    
    void GetCurrentExceptionOnUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep;
      _using() {
        try {
          throw MyException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException;
        }
      }
      Assert::IsFalse(ep == null, _current_information);
      Assert::Throws<MyException>(_delegate {ep.Rethrow();}, _current_information);
    }
  };
  
  _test(ExceptionPointerTest, CreateExceptionPointerEmptyThenRethrow)
  _test(ExceptionPointerTest, CreateKnownExceptionThenRethrow)
  _test(ExceptionPointerTest, CreateUnknownExceptionThenRethrow)
  _test(ExceptionPointerTest, GetCurrentExceptionOnNullExceptionThenRethrow)
  _test(ExceptionPointerTest, GetCurrentExceptionOnKnownExceptionThenRethrow)
  _test(ExceptionPointerTest, GetCurrentExceptionOnUnknownExceptionThenRethrow)
}
