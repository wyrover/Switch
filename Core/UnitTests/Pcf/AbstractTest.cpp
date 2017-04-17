#include <Pcf/Abstract.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {  
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
      
      pcf_using (refptr<NotAnAbstract> value = pcf_new<NotInheritedFromAnAbstract>());
      Assert::AreEqual("~NotAnAbstract", result);
    }

    void CreateClassInheritedFromAnAbstract() {
      static string result;
      result = "";
      struct AnAbstract pcf_abstract {
        ~AnAbstract() {result += "~AnAbstract";}
      };
      
      struct InheritedFromAnAbstract : public AnAbstract {
        ~InheritedFromAnAbstract() {result += "~InheritedFromAnAbstract";}
      };
      
      pcf_using (refptr<AnAbstract> value = pcf_new<InheritedFromAnAbstract>());
      Assert::AreEqual("~InheritedFromAnAbstract~AnAbstract", result);
    }
  };
  
  pcf_test(AbstractTest, CreateClassNotInheritedFromAnAbstract)
  pcf_test(AbstractTest, CreateClassInheritedFromAnAbstract)
}