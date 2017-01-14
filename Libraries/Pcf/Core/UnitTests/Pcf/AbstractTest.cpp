#include <Pcf/Abstract.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {  
  class AbstractTest : public TestFixture {
  protected:
    void CreateClassInheritedFromAnAbstract() {
      static string result;
      result = "";
      struct AnAbstract pcf_abstract {
        ~AnAbstract() {result += "~AnAbstract";}
      };
      
      struct InheritedFromAnAbstract : public AnAbstract {
        ~InheritedFromAnAbstract() {result += "~InheritedFromAnAbstract";}
      };
      
      pcf_using (up<AnAbstract> value = new InheritedFromAnAbstract());
      Assert::AreEqual("~InheritedFromAnAbstract~AnAbstract", result);
    }

    void CreateClassInheritedFromNotAnAbstract() {
      static string result;
      result = "";
      struct NotAnAbstract {
        ~NotAnAbstract() {result += "~NotAnAbstract";}
      };
      
      struct InheritedFromNotAnAbstract : public NotAnAbstract {
        ~InheritedFromNotAnAbstract() {result += "~InheritedFromNotAnAbstract";}
      };
      
      pcf_using (up<NotAnAbstract> value = new InheritedFromNotAnAbstract());
      Assert::AreEqual("~NotAnAbstract", result);
    }
  };
  
  pcf_test(AbstractTest, CreateClassInheritedFromAnAbstract)
  pcf_test(AbstractTest, CreateClassInheritedFromNotAnAbstract)
}
