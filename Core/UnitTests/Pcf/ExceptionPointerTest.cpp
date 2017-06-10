#include <Pcf/ExceptionPtr.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class ExceptionPointerTest : public TestFixture {
  protected:
    void CreateExceptionPointerEmptyThenRethrow() {
      ExceptionPtr ep;
      Assert::IsTrue(ep.IsNull(), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void CreateKnownExceptionThenRethrow() {
      ExceptionPtr ep = ExceptionPtr::Create(InvalidCastException());
      Assert::IsFalse(ep.IsNull());
      Assert::Throws<InvalidCastException>(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void CreateUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep = ExceptionPtr::Create(MyException());
      Assert::IsFalse(ep.IsNull());
      Assert::Throws<MyException>(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
   
    void GetCurrentExceptionOnNullExceptionThenRethrow() {
      ExceptionPtr ep;
      pcf_using() {
        ep = ExceptionPtr::CurrentException;
      }
      Assert::IsTrue(ep.IsNull(), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void GetCurrentExceptionOnKnownExceptionThenRethrow() {
      ExceptionPtr ep;
      pcf_using() {
        try {
          throw InvalidOperationException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException;
        }
      }
      Assert::IsFalse(ep.IsNull(), pcf_current_information);
      Assert::Throws<InvalidOperationException>(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void GetCurrentExceptionOnUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPtr ep;
      pcf_using() {
        try {
          throw MyException();
        } catch(...) {
          ep = ExceptionPtr::CurrentException;
        }
      }
      Assert::IsFalse(ep.IsNull(), pcf_current_information);
      Assert::Throws<MyException>(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
  };
  
  pcf_test(ExceptionPointerTest, CreateExceptionPointerEmptyThenRethrow)
  pcf_test(ExceptionPointerTest, CreateKnownExceptionThenRethrow)
  pcf_test(ExceptionPointerTest, CreateUnknownExceptionThenRethrow)
  pcf_test(ExceptionPointerTest, GetCurrentExceptionOnNullExceptionThenRethrow)
  pcf_test(ExceptionPointerTest, GetCurrentExceptionOnKnownExceptionThenRethrow)
  pcf_test(ExceptionPointerTest, GetCurrentExceptionOnUnknownExceptionThenRethrow)
}
