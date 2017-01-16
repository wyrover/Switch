#include <Pcf/ExceptionPointer.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class ExceptionPointerTest : public TestFixture {
  protected:
    void CreateExceptionPointerEmptyThenRethrow() {
      ExceptionPointer ep;
      Assert::IsTrue(ep.IsNull(), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void CreateKnownExceptionThenRethrow() {
      ExceptionPointer ep = ExceptionPointer::Create(InvalidCastException());
      Assert::IsFalse(ep.IsNull());
      Assert::Throws<InvalidCastException>(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void CreateUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPointer ep = ExceptionPointer::Create(MyException());
      Assert::IsFalse(ep.IsNull());
      Assert::Throws<MyException>(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
   
    void GetCurrentExceptionOnNullExceptionThenRethrow() {
      ExceptionPointer ep;
      pcf_using() {
        ep = ExceptionPointer::CurrentException;
      }
      Assert::IsTrue(ep.IsNull(), pcf_current_information);
      Assert::DoesNotThrows(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void GetCurrentExceptionOnKnownExceptionThenRethrow() {
      ExceptionPointer ep;
      pcf_using() {
        try {
          throw InvalidOperationException();
        } catch(...) {
          ep = ExceptionPointer::CurrentException;
        }
      }
      Assert::IsFalse(ep.IsNull(), pcf_current_information);
      Assert::Throws<InvalidOperationException>(pcf_delegate {ep.Rethrow();}, pcf_current_information);
    }
    
    void GetCurrentExceptionOnUnknownExceptionThenRethrow() {
      struct MyException {};
      ExceptionPointer ep;
      pcf_using() {
        try {
          throw MyException();
        } catch(...) {
          ep = ExceptionPointer::CurrentException;
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
