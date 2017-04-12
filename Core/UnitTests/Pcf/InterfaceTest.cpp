#include <Pcf/Abstract.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {  
  class InterfaceTest : public TestFixture {
  protected:
    void CreateClassNotInheritedFromAnInterface() {
      static string result;
      result = "";
      struct NotAnInterface {
        ~NotAnInterface() {result += "~NotAnInterface";}
      };
      
      struct NotInheritedFromAnInterface : public NotAnInterface {
        ~NotInheritedFromAnInterface() {result += "~NotInheritedFromAnInterface";}
      };
      
      pcf_using (refptr<NotAnInterface> value = pcf_new<NotInheritedFromAnInterface>());
      Assert::AreEqual("~NotAnInterface", result);
    }

    void CreateClassInheritedFromAnInterface() {
      static string result;
      result = "";
      struct AnInterface pcf_abstract {
        ~AnInterface() {result += "~AnInterface";}
      };
      
      struct InheritedFromAnInterface : public AnInterface {
        ~InheritedFromAnInterface() {result += "~InheritedFromAnInterface";}
      };
      
      pcf_using (refptr<AnInterface> value = pcf_new<InheritedFromAnInterface>());
      Assert::AreEqual("~InheritedFromAnInterface~AnInterface", result);
    }
  };
  
  pcf_test(InterfaceTest, CreateClassNotInheritedFromAnInterface)
  pcf_test(InterfaceTest, CreateClassInheritedFromAnInterface)
}
