#include <Switch/Abstract.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {  
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
      
      sw_using (refptr<NotAnInterface> value = sw_new<NotInheritedFromAnInterface>());
      Assert::AreEqual("~NotAnInterface", result);
    }

    void CreateClassInheritedFromAnInterface() {
      static string result;
      result = "";
      struct AnInterface sw_abstract {
        ~AnInterface() {result += "~AnInterface";}
      };
      
      struct InheritedFromAnInterface : public AnInterface {
        ~InheritedFromAnInterface() {result += "~InheritedFromAnInterface";}
      };
      
      sw_using (refptr<AnInterface> value = sw_new<InheritedFromAnInterface>());
      Assert::AreEqual("~InheritedFromAnInterface~AnInterface", result);
    }
  };
  
  sw_test(InterfaceTest, CreateClassNotInheritedFromAnInterface)
  sw_test(InterfaceTest, CreateClassInheritedFromAnInterface)
}
