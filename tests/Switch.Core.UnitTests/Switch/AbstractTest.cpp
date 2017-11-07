#include <Switch/Abstract.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {  
  TEST(AbstractTest, CreateClassNotInheritedFromAnAbstract) {
    static string result;
    result = "";
    struct NotAnAbstract {
      ~NotAnAbstract() {result += "~NotAnAbstract";}
    };
    
    struct NotInheritedFromAnAbstract : public NotAnAbstract {
      ~NotInheritedFromAnAbstract() {result += "~NotInheritedFromAnAbstract";}
    };
    
    _using (refptr<NotAnAbstract> value = ref_new<NotInheritedFromAnAbstract>());
    GTEST_ASSERT_EQ("~NotAnAbstract", result);
  }
  
  TEST(AbstractTest, CreateClassInheritedFromAnAbstract) {
    static string result;
    result = "";
    struct AnAbstract _abstract {
      ~AnAbstract() {result += "~AnAbstract";}
    };
    
    struct InheritedFromAnAbstract : public AnAbstract {
      ~InheritedFromAnAbstract() {result += "~InheritedFromAnAbstract";}
    };
    
    _using (refptr<AnAbstract> value = ref_new<InheritedFromAnAbstract>());
    GTEST_ASSERT_EQ("~InheritedFromAnAbstract~AnAbstract", result);
  }
}
