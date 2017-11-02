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
      
      _using (refptr<NotAnInterface> value = ref_new<NotInheritedFromAnInterface>());
      Assert::AreEqual("~NotAnInterface", result);
    }

    void CreateClassInheritedFromAnInterface() {
      static string result;
      result = "";
      struct AnInterface _abstract {
        ~AnInterface() {result += "~AnInterface";}
      };
      
      struct InheritedFromAnInterface : public AnInterface {
        ~InheritedFromAnInterface() {result += "~InheritedFromAnInterface";}
      };
      
      _using (refptr<AnInterface> value = ref_new<InheritedFromAnInterface>());
      Assert::AreEqual("~InheritedFromAnInterface~AnInterface", result);
    }
  };
  
  _add_test (InterfaceTest, CreateClassNotInheritedFromAnInterface)
  _add_test (InterfaceTest, CreateClassInheritedFromAnInterface)
}
