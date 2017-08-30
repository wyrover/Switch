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
      Assert::IsTrue(ep.IsNull(), sw_current_information);
      Assert::DoesNotThrows(sw_delegate {ep.Rethrow();}, sw_current_information);
    }
    
    void CreateKnownExceptionThenRethrow() {
      ExceptionPtr ep = ExceptionPtr::Create(InvalidCastException());
      Assert::IsFalse(ep.IsNull());
      Assert::Throws<InvalidCastException>(sw_delegate {ep.Rethrow();}, sw_current_information);
    }
    
    void CreateUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep = ExceptionPtr::Create(MyException());
      Assert::IsFalse(ep.IsNull());
      Assert::Throws<MyException>(sw_delegate {ep.Rethrow();}, sw_current_information);
    }
   
    void GetCurrentExceptionOnNullExceptionThenRethrow() {
      ExceptionPtr ep;
      sw_using() {
        ep = ExceptionPtr::CurrentException;
      }
      Assert::IsTrue(ep.IsNull(), sw_current_information);
      Assert::DoesNotThrows(sw_delegate {ep.Rethrow();}, sw_current_information);
    }
    
    void GetCurrentExceptionOnKnownExceptionThenRethrow() {
      ExceptionPtr ep;
      sw_using() {
        try {
          throw InvalidOperationException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException;
        }
      }
      Assert::IsFalse(ep.IsNull(), sw_current_information);
      Assert::Throws<InvalidOperationException>(sw_delegate {ep.Rethrow();}, sw_current_information);
    }
    
    void GetCurrentExceptionOnUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep;
      sw_using() {
        try {
          throw MyException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException;
        }
      }
      Assert::IsFalse(ep.IsNull(), sw_current_information);
      Assert::Throws<MyException>(sw_delegate {ep.Rethrow();}, sw_current_information);
    }
  };
  
  sw_test(ExceptionPointerTest, CreateExceptionPointerEmptyThenRethrow)
  sw_test(ExceptionPointerTest, CreateKnownExceptionThenRethrow)
  sw_test(ExceptionPointerTest, CreateUnknownExceptionThenRethrow)
  sw_test(ExceptionPointerTest, GetCurrentExceptionOnNullExceptionThenRethrow)
  sw_test(ExceptionPointerTest, GetCurrentExceptionOnKnownExceptionThenRethrow)
  sw_test(ExceptionPointerTest, GetCurrentExceptionOnUnknownExceptionThenRethrow)
}
