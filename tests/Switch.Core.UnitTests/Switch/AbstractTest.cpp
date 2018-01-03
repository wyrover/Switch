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

    using_(refptr<NotAnAbstract> value = ref_new<NotInheritedFromAnAbstract>());
    GTEST_ASSERT_EQ("~NotAnAbstract", result);
  }

  TEST(AbstractTest, CreateClassInheritedFromAnAbstract) {
    static string result;
    result = "";
    struct AnAbstract abstract_ {
      ~AnAbstract() {result += "~AnAbstract";}
    };

    struct InheritedFromAnAbstract : public AnAbstract {
      ~InheritedFromAnAbstract() {result += "~InheritedFromAnAbstract";}
    };

    using_(refptr<AnAbstract> value = ref_new<InheritedFromAnAbstract>());
    GTEST_ASSERT_EQ("~InheritedFromAnAbstract~AnAbstract", result);
  }
}
