#include <Switch/Abstract.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {  
  class AbstractTest : public TestFixture {
  protected:
    void CreateClassNotInheritedFromAnAbstract() {
      static string result;
      result = "";
      struct NotAnAbstract {
        ~NotAnAbstract() {result += "~NotAnAbstract";}
      };
      
      struct NotInheritedFromAnAbstract : public NotAnAbstract {
        ~NotInheritedFromAnAbstract() {result += "~NotInheritedFromAnAbstract";}
      };
      
      sw_using (refptr<NotAnAbstract> value = sw_new<NotInheritedFromAnAbstract>());
      Assert::AreEqual("~NotAnAbstract", result);
    }

    void CreateClassInheritedFromAnAbstract() {
      static string result;
      result = "";
      struct AnAbstract sw_abstract {
        ~AnAbstract() {result += "~AnAbstract";}
      };
      
      struct InheritedFromAnAbstract : public AnAbstract {
        ~InheritedFromAnAbstract() {result += "~InheritedFromAnAbstract";}
      };
      
      sw_using (refptr<AnAbstract> value = sw_new<InheritedFromAnAbstract>());
      Assert::AreEqual("~InheritedFromAnAbstract~AnAbstract", result);
    }
  };
  
  sw_test(AbstractTest, CreateClassNotInheritedFromAnAbstract)
  sw_test(AbstractTest, CreateClassInheritedFromAnAbstract)
}
