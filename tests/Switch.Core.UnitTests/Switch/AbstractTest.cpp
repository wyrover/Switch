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
      
      _using (refptr<NotAnAbstract> value = ref_new<NotInheritedFromAnAbstract>());
      Assert::AreEqual("~NotAnAbstract", result);
    }

    void CreateClassInheritedFromAnAbstract() {
      static string result;
      result = "";
      struct AnAbstract _abstract {
        ~AnAbstract() {result += "~AnAbstract";}
      };
      
      struct InheritedFromAnAbstract : public AnAbstract {
        ~InheritedFromAnAbstract() {result += "~InheritedFromAnAbstract";}
      };
      
      _using (refptr<AnAbstract> value = ref_new<InheritedFromAnAbstract>());
      Assert::AreEqual("~InheritedFromAnAbstract~AnAbstract", result);
    }
  };
  
  _test(AbstractTest, CreateClassNotInheritedFromAnAbstract)
  _test(AbstractTest, CreateClassInheritedFromAnAbstract)
}